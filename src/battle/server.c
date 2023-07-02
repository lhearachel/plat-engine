#include "global.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/server.h"

#include "archive.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/misc.h"
#include "constants/species.h"

struct CalcParams {
    u16 species;
    s16 currHP;
    u16 maxHP;
    u16 _padding;

    int heldItemEffect;
    int heldItemPower;

    u32 condition;

    u8  ability,
        gender,
        type1,
        type2;
};

static const u8 sHeldItemTypeBoostTable[][2] = {
    {}
};

int Server_CalcMoveDamage(
    struct Battle *battle,
    struct BattleServer *server,
    int moveID,
    u32 sideConditions,
    u32 fieldConditions,
    u16 power,
    u8 type,
    u8 attacker,
    u8 defender,
    u8 critStages
) {
    u32 battleType = Battle_Type(battle);

    u16 attack          = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_ATTACK,           NULL);
    u8  attackStages    = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_ATTACK_STAGES,    NULL);
    u16 defense         = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_DEFENSE,          NULL);
    u8  defenseStages   = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_DEFENSE_STAGES,   NULL);
    u16 spAttack        = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_SPATTACK,         NULL);
    u8  spAttackStages  = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_SPATTACK_STAGES,  NULL);
    u16 spDefense       = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_SPDEFENSE,        NULL);
    u8  spDefenseStages = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_SPDEFENSE_STAGES, NULL);
    u8  attackerLevel   = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_LEVEL,            NULL);

    struct CalcParams attackerParams = {
        .species        = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_SPECIES,    NULL),
        .currHP         = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_HP_CURRENT, NULL),
        .maxHP          = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_HP_MAX,     NULL),
        .condition      = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_CONDITION,  NULL),
        .ability        = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_ABILITY,    NULL),
        .gender         = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_GENDER,     NULL),
        .type1          = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_TYPE_1,     NULL),
        .type2          = BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_TYPE_2,     NULL),
        .heldItemEffect = Server_HeldItemEffect(server, attacker),
        .heldItemPower  = Server_HeldItemPower(server, attacker, 0),
    };
    struct CalcParams defenderParams = {
        .species        = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_SPECIES,    NULL),
        .currHP         = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_HP_CURRENT, NULL),
        .maxHP          = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_HP_MAX,     NULL),
        .condition      = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_CONDITION,  NULL),
        .ability        = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_ABILITY,    NULL),
        .gender         = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_GENDER,     NULL),
        .type1          = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_TYPE_1,     NULL),
        .type2          = BattlePokemon_Get(server, defender, BATTLE_MON_PARAM_TYPE_2,     NULL),
        .heldItemEffect = Server_HeldItemEffect(server, defender),
        .heldItemPower  = Server_HeldItemPower(server, defender, 0),
    };

    // Now lets actually start applying some of this data.
    u8  moveType, movePSS;
    u16 movePower;

    // Get the move's power; prefer the value that's passed in as a parameter
    // Account for Normalize, etc.
    if (attackerParams.ability == ABILITY_NORMALIZE
            && Moves_CanNormalize(moveID)) {
        moveType = TYPE_NORMAL;
    } else if (type == 0) {
        moveType = server->moveTable[moveID].type;
    } else {
        moveType = type & 0x3F;
    }

    // Get the move's base power; prefer the value that's passed in as a parameter
    if (power == 0) {
        movePower = server->moveTable[moveID].power;
    } else {
        movePower = power;
    }

    // Adjust the retrieved power by the current move multiplier and apply some initial
    // multipliers: Charge, Helping Hand, Technician
    movePower = movePower * server->moveMultiplier / 10;

    if ((server->activePokemon[attacker].moveEffectsMask & MOVE_EFFECT_CHARGED)
            && (moveType == TYPE_ELECTRIC)) {
        movePower = movePower * 2;
    }

    if (server->stFX[attacker].helpingHand) {
        movePower = movePower * 15 / 10;
    }

    // check for some initial abilities: Technician, Huge Power, Slow Start
    switch (attackerParams.ability) {
        // TODO: Technician needs to be reworked a bit for gen5+
        // No longer takes into account base power modifiers (Charge, Helping Hand)
        // but still considers variable base power
        case ABILITY_TECHNICIAN:
            if (movePower <= 60) {
                movePower = movePower * 15 / 10;
            }
            break;
        case ABILITY_HUGE_POWER:
        case ABILITY_PURE_POWER:
            attack = attack * 2;
            break;
        case ABILITY_SLOW_START:
            if (Server_Get(battle, server, SERVER_PARAM_TOTAL_TURNS, NULL)
                    - BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_SLOW_START_INIT_TURN, NULL) < 5) {
                attack = attack / 2;
            }
        default:
            break;
    }

    // Apply offensive and defensive boosts from items
    Calc_BoostOffensiveItem(&attackerParams, &attack, &spAttack, &movePower, moveType, movePSS);
    Calc_BoostDefensiveItem(&defenderParams, &defense, &spDefense);

    // check for other abilities: Thick Fat, Hustle, Guts, Marvel Scale, Plus/Minus
    if        (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_THICK_FAT)
            && ((moveType == TYPE_FIRE) || (moveType == TYPE_ICE))) {
        // Halve the attacker's attack/spAttack
        // This is slightly different from how vanilla updated the move's power, but
        // the effect is virtually identical
        attack = attack / 2;
        spAttack = spAttack / 2;
    } else if (attackerParams.ability == ABILITY_HUSTLE) {
        attack = attack * 150 / 100;
    } else if ((attackerParams.ability == ABILITY_GUTS) && (attackerParams.condition)) {
        attack = attack * 150 / 100;
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_MARVEL_SCALE)
            && defenderParams.condition) {
        defense = defense * 150 / 100;
    } else if (((attackerParams.ability == ABILITY_PLUS) || (attackerParams.ability == ABILITY_MINUS))
            && (Calc_CheckPartnerAbility(server, attacker, ABILITY_PLUS)
                || Calc_CheckPartnerAbility(server, attacker, ABILITY_MINUS))) {
        // Increase attacker's spAttack by 50%
        // Generation 5: Functions for any ally with either Plus or Minus
        spAttack = spAttack * 150 / 100;
    }

    // check for some field effects: Mud Sport, Water Sport
    if (Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_MUD_SPORT) && (moveType == TYPE_ELECTRIC)) {
        movePower = movePower / 2;
    }
    if (Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_WATER_SPORT) && (moveType == TYPE_FIRE)) {
        movePower = movePower / 2;
    }

    // check for more abilities: Overgrow, Blaze, Torrent, Swarm, Heatproof, Dry Skin, Unaware, Rivalry, Iron Fist
    if        ((attackerParams.ability == ABILITY_OVERGROW)
            && (moveType == TYPE_GRASS)
            && (attackerParams.currHP <= (attackerParams.maxHP / 3))) {
        movePower = movePower * 150 / 100;
    } else if ((attackerParams.ability == ABILITY_BLAZE)
            && (moveType == TYPE_FIRE)
            && (attackerParams.currHP <= (attackerParams.maxHP / 3))) {
        movePower = movePower * 150 / 100;
    } else if ((attackerParams.ability == ABILITY_TORRENT)
            && (moveType == TYPE_WATER)
            && (attackerParams.currHP <= (attackerParams.maxHP / 3))) {
        movePower = movePower * 150 / 100;
    } else if ((attackerParams.ability == ABILITY_SWARM)
            && (moveType == TYPE_BUG)
            && (attackerParams.currHP <= (attackerParams.maxHP / 3))) {
        movePower = movePower * 150 / 100;
    } else if (attackerParams.ability == ABILITY_UNAWARE) {
        defenseStages = 6;
        spDefenseStages = 6;
    } else if ((attackerParams.ability == ABILITY_RIVALRY)
            && (attackerParams.gender != 2)
            && (defenderParams.gender != 2)) {
        if (attackerParams.gender == defenderParams.gender) {
            movePower = movePower * 125 / 100;
        } else {
            movePower = movePower * 75 / 100;
        }
    } else if ((attackerParams.ability == ABILITY_IRON_FIST)
            && Moves_IsPunching(moveID)) {
        movePower = movePower * 12 / 10;
    }

    if        (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_HEATPROOF)
            && (moveType == TYPE_FIRE)) {
        movePower = movePower / 2;
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_DRY_SKIN)
            && (moveType == TYPE_FIRE)) {
        movePower = movePower * 125 / 100;
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_UNAWARE)) {
        attackStages = 6;
        spAttackStages = 6;
    }

    // check for weather
    if ((Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0)) {
        if        (fieldConditions & FIELD_CONDITION_SUNNY) {
            if (attackerParams.ability == ABILITY_SOLAR_POWER) {
                // Solar Power: increase Special Attack by 50% under harsh sunlight
                spAttack = spAttack * 150 / 100;
            } else if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_ON_MY_SIDE, attacker, ABILITY_FLOWER_GIFT)) {
                // Flower Gift attack boost
                attack = attack * 150 / 100;
            } else if ((attackerParams.ability != ABILITY_MOLD_BREAKER)
                    && Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_ON_MY_SIDE, defender, ABILITY_FLOWER_GIFT)) {
                spDefense = spDefense * 150 / 100;
            }
        } else if ((fieldConditions & FIELD_CONDITION_SANDSTORM)
                && ((defenderParams.type1 == TYPE_ROCK) || (defenderParams.type2 == TYPE_ROCK))) {
            // Rock-type Pokemon have their Special Defense increased by 50% during Sandstorm
            spDefense = spDefense * 150 / 100;
        }
    }

    // check for Explosion/Self-Destruct exists here in Vanilla
    // removed for gen5+ compatibility

    // lets actually calc some damage now
    s32 damage;
    if (movePSS == PSS_PHYSICAL) {
        damage = Calc_Damage(attack, attackStages, defense, defenseStages, movePower, attackerLevel, critStages);

        // Generation 6: Facade now ignores the damage reduction from Burn
        if ((attackerParams.condition & CONDITION_BURNED)
                && (attackerParams.ability != ABILITY_GUTS)
                && (moveID != MOVE_FACADE)) {
            damage = damage / 2;
        }

        if ((sideConditions & SIDE_CONDITION_REFLECT)
                && (critStages == 1)
                && (server->moveTable[moveID].effect != 186)) { // TODO: constant-ize the move effects
            // Generation 5: screens no longer care about how many Pokemon are being protected at once
            // from a single damaging move.
            if (battleType & BATTLE_TYPE_DOUBLES) {
                damage = damage * 2 / 3;
            } else {
                damage = damage / 2;
            }
        }
    } else if (movePSS == PSS_SPECIAL) {
        // TODO: will need a check here for Psyshock's effect
        damage = Calc_Damage(spAttack, spAttackStages, spDefense, spDefenseStages, movePower, attackerLevel, critStages);

        if ((sideConditions & SIDE_CONDITION_LIGHT_SCREEN)
                && (critStages == 1)
                && (server->moveTable[moveID].effect != 186)) { // TODO: constant-ize the move effects
            // Generation 5: screens no longer care about how many Pokemon are being protected at once
            // from a single damaging move.
            if (battleType & BATTLE_TYPE_DOUBLES) {
                damage = damage * 2 / 3;
            } else {
                damage = damage / 2;
            }
        }
    }

    // Now time for some damage modifiers
    if (battleType & BATTLE_TYPE_DOUBLES) {
        if ((server->moveTable[moveID].target == 4) // TODO: constant-ize
                && (Server_HitCount(battle, server, 1, defender) == 2)) {
            damage = damage * 3 / 4;
        } else if ((server->moveTable[moveID].target == 8)
                && (Server_HitCount(battle, server, 0, defender) >= 2)) {
            damage = damage * 3 / 4;
        }
    }

    if ((Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0)) {
        if (fieldConditions & FIELD_CONDITION_RAINING) {
            if (moveType == TYPE_FIRE) {
                damage = damage / 2;
            } else if (moveType == TYPE_WATER) {
                damage = damage * 150 / 100;
            }
        } else if (fieldConditions & FIELD_CONDITION_SUNNY) {
            if (moveType == TYPE_FIRE) {
                damage = damage * 150 / 100;
            } else if (moveType == TYPE_WATER) {
                damage = damage / 2;
            }
        }

        if ((fieldConditions & FIELD_CONDITION_ANTI_SOLAR) && (moveID = MOVE_SOLAR_BEAM)) {
            damage = damage / 2;
        }
    }

    if ((BattlePokemon_Get(server, attacker, BATTLE_MON_PARAM_FLASH_FIRE_ACTIVE, NULL)
            && (moveType == TYPE_FIRE))) {
        damage = damage * 150 / 100;
    }

    return damage + 2;
}

inline void Calc_BoostOffensiveItem(struct CalcParams *params, int *attack, int *spAttack, int *movePower, int moveType, int movePSS)
{
    // Check for the type-boosting items first
    for (int i = 0; i < NELEMS(sHeldItemTypeBoostTable); i++) {
        if ((params->heldItemEffect == sHeldItemTypeBoostTable[i][0])
                && (moveType == sHeldItemTypeBoostTable[i][1])) {
            // If we match the item, apply the power increase and return immediately
            // No sense in checking the remaining items
            *movePower = *movePower * (100 + params->heldItemPower) / 100;
            return;
        }
    }

    // TODO: Gems go here?

    if        (params->heldItemEffect == HOLD_EFFECT_CHOICE_BAND) {
        *attack = *attack * 150 / 100;
    } else if (params->heldItemEffect == HOLD_EFFECT_CHOICE_SCARF) {
        *spAttack = *spAttack * 150 / 100;
    } else if (params->heldItemEffect == HOLD_EFFECT_SOUL_DEW) {
        // Generation 7 Soul Dew change
        // Vanilla generation 4 also has a check here for Battle Tower which was removed
        // Boosts the power of Dragon and Psychic type moves for Latias/Latios by 20%
        if (((params->species == SPECIES_LATIAS) || (params->species == SPECIES_LATIOS))
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_PSYCHIC))) {
            *movePower = *movePower * 120 / 100;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_DEEP_SEA_TOOTH) {
        // Double Clamperl's Special Attack
        if (params->species == SPECIES_CLAMPERL) {
            *spAttack = *spAttack * 2;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_LIGHT_BALL) {
        // Generation 5 Light Ball change
        // Double Pikachu's Attack and Special Attack
        // TODO: Support Pikachu forms
        if (params->species == SPECIES_PIKACHU) {
            *attack = *attack * 2;
            *spAttack = *spAttack * 2;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_THICK_CLUB) {
        // Double Cubone and Marowak's attack stat
        // TODO: Support Alolan forms
        if ((params->species == SPECIES_CUBONE) || (params->species == SPECIES_MAROWAK)) {
            *attack = *attack * 2;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_ADAMANT_ORB) {
        // Increase the power of Dragon and Steel type moves for Dialga by 20%
        if ((params->species == SPECIES_DIALGA)
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_STEEL))) {
            *movePower = *movePower * 120 / 100;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_LUSTROUS_ORB) {
        // Increase the power of Dragon and Water type moves for Palkia by 20%
        if ((params->species == SPECIES_PALKIA)
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_WATER))) {
            *movePower = *movePower * 120 / 100;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_GRISEOUS_ORB) {
        // Vanilla also has a check here for if the Pokemon transformed into
        // Giratina, which is extraneous and has been removed, as only Giratina
        // can hold a Griseous Orb in vanilla Platinum.
        // Increase the power of Dragon and Ghost type moves for Giratina by 20%
        if ((params->species == SPECIES_GIRATINA)
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_GHOST))) {
            *movePower = *movePower * 120 / 100;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_BOOST_PHYSICAL) {
        if (movePSS == PSS_PHYSICAL) {
            *movePower = *movePower * (100 + params->heldItemPower) / 100;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_BOOST_SPECIAL) {
        if (movePSS == PSS_SPECIAL) {
            *movePower = *movePower * (100 + params->heldItemPower) / 100;
        }
    }
}

inline void Calc_BoostDefensiveItem(struct CalcParams *params, int *defense, int *spDefense)
{
    if        (params->heldItemEffect == HOLD_EFFECT_DEEP_SEA_SCALE) {
        // Double Clamperl's Special Defense
        if (params->species == SPECIES_CLAMPERL) {
            *spDefense = *spDefense * 2;
        }
    } else if (params->heldItemEffect == HOLD_EFFECT_BOOST_DEFENSE_DITTO) {
        // Double Ditto's Defense
        if (params->species == SPECIES_DITTO) {
            *defense = *defense * 2;
        }
    }
}

inline BOOL Calc_CheckPartnerAbility(struct BattleServer *server, int battler, int ability)
{
    int partner = (battler + 2) % 4;
    return server->activePokemon[partner].ability == ability;
}

static u8 sStatStages[][2] = {
    // numerator, denominator
    { 10, 40 },     // -6: 1/4
    { 10, 35 },     // -5: 2/7
    { 10, 30 },     // -4: 1/3
    { 10, 25 },     // -3: 2/5
    { 10, 20 },     // -2: 1/2
    { 10, 15 },     // -1: 2/3
    { 10, 10 },     //  0:   1
    { 15, 10 },     // +1: 3/2
    { 20, 10 },     // +2:   2
    { 25, 10 },     // +3: 5/2
    { 30, 10 },     // +4:   3
    { 35, 10 },     // +5: 7/2
    { 40, 10 }      // +6:   4
};

inline s32 Calc_Damage(u16 attack, u8 attackStage, u16 defense, u8 defenseStage, u16 movePower, u8 attackerLevel, u8 critical)
{
    s32 damage;
    if ((critical > 1) && (attackStage <= 6)) { // ignore negative offensive stat changes on crits
        damage = attack;
    } else {
        damage = attack * sStatStages[attackStage][0] / sStatStages[attackStage][1];
    }

    damage = damage * movePower * (attackerLevel * 2 / 5 + 2);

    s32 damageDenom;
    if ((critical > 1) && (defenseStage >= 6)) { // ignore positive defensive stat changes on crits
        damageDenom = defense;
    } else {
        damageDenom = defense * sStatStages[defenseStage][0] / sStatStages[defenseStage][1];
    }

    return damage / damageDenom / 50;
}

#if 0

static BOOL Server_CheckHitForMoveEffect(struct Battle *battle, struct BattleServer *server, int attacker, int defender, int moveID)
{
    // Charging moves do not check accuracy on their first turn
    if (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) {
        return FALSE;
    }

    // if ((server->stFX[defender].protected)
    //         && (server->moveTable[moveID].flag & 0x02)) {
    //     if ((moveID != ))
    // }
}

// ST_ServerHukitobasiCheck
// https://bulbapedia.bulbagarden.net/wiki/Whirlwind_(move)
// https://bulbapedia.bulbagarden.net/wiki/Roar_(move)
static BOOL Server_CheckWhirlwind(struct Battle *battle, struct BattleServer *server)
{
    return (
            // In Trainer battles, Whirlwind will now succeed if it hits, regardless of either Pokémon's level.
            (Battle_Type(battle) & BATTLE_TYPE_TRAINER)
            // In wild Pokémon battles, Whirlwind will now always fail if the user's level is less than the target's.
        ||  (server->activePokemon[server->attacker].level >= server->activePokemon[server->defender].level)
    );
}

enum PokeConditionCheck {
    CONDITION_CHECK_INGRAIN,        // no changes
    CONDITION_CHECK_AQUA_RING,      // no changes
    CONDITION_CHECK_ABILITY,        // Speed Boost, Shed Skin (separate function)
    CONDITION_CHECK_BERRY,          // separate function: restore HP, restore % HP, restore status, restore PP, pinch boosts, herbs (NOT Custap Berry)
    CONDITION_CHECK_LEFTOVERS,      // separate function; also black sludge
    CONDITION_CHECK_LEECH_SEED,     // no changes
    CONDITION_CHECK_POISON,         // no changes (here)
    CONDITION_CHECK_TOXIC,          // no changes
    CONDITION_CHECK_BURN,           // no changes (here)
    CONDITION_CHECK_NIGHTMARE,      // no changes (here)
    CONDITION_CHECK_CURSE,          // no changes (here)
    CONDITION_CHECK_TRAPPED,        // need to hook on this one to change the damage amount (and account for Binding Band)
    CONDITION_CHECK_BAD_DREAMS,     // no changes
    CONDITION_CHECK_UPROAR,         // script change to last exactly 3 turns
    CONDITION_CHECK_THRASH,         // hook here to account for missing on the final turn and still get confused
    CONDITION_CHECK_DISABLE,
    CONDITION_CHECK_ENCORE,
    CONDITION_CHECK_LOCK_ON,
    CONDITION_CHECK_GRAVITY,
    CONDITION_CHECK_TAUNT,
    CONDITION_CHECK_MAGNET_RISE,
    CONDITION_CHECK_HEAL_BLOCK,
    CONDITION_CHECK_EMBARGO,
    CONDITION_CHECK_YAWN,
    CONDITION_CHECK_STATUS_ORB,
    CONDITION_CHECK_STICKY_BARB,
    CONDITION_CHECK_END
};

#define CONDITION_V_CLAMPED_DEC 0x00002000

// Hook this into branch_224d394 and branch down to Function_224d972 when done
// r0 = server, r1 = client
// server is at 0x10 on the stack
// client comes in as r5?
static u8 Server_ClampDamage(struct BattleServer *server, int client)
{
    if ((server->activePokemon[client].condition2 & CONDITION_V_CLAMPED)
        && (server->activePokemon[client].curHP != 0)) {
        // TODO: Figure out how to make this support 7 total turns for Grip Claw
        // Reduce the turn count by 1
        server->activePokemon[client].condition2 -= CONDITION_V_CLAMPED_DEC;

        // If still bound, deal damage; else, call the cleanup subscript
        if (server->activePokemon[client].condition2 & CONDITION_V_CLAMPED) {
            int divFactor = 8;
            // ST_ServerSoubiEqpGet
            if (Server_HeldItemEffect(server, client) == HOLD_EFFECT_INCREASE_TRAPPING_DAMAGE) {
                divFactor = 6;
            }

            server->hpCalcWork = Server_Divide(server->activePokemon[client].maxHP * -1, divFactor);
            // ST_ServerSequenceLoad
            Server_LoadSequence(server, ARC_SUBSCR, SUBSCR_CLAMP_DAMAGE);
        } else {
            Server_LoadSequence(server, ARC_SUBSCR, SUBSCR_CLAMP_END);
        }
        
        server->moveWork      = server->activePokemon[client].moveEffects.bindingMove;
        server->clientWork    = client;
        server->serverSeqNext = server->serverSeqNum;
        server->serverSeqNum  = 21;     // TODO: Constant

        return 1;
    }

    return 0;
}

#endif
