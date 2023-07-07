#include "global.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/server.h"

#include "archive.h"
#include "pokemon.h"
#include "q412.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/misc.h"
#include "constants/species.h"

struct CalcStats {
    u16 attack;
    u16 defense;
    u16 spAttack;
    u16 spDefense;
};

struct CalcStages {
    u8  attack;
    u8  defense;
    u8  spAttack;
    u8  spDefense;
};

struct CalcParams {
    u16 species;
    s16 currHP;
    u16 maxHP;
    u16 ability;

    int heldItemEffect;
    int heldItemPower;

    u32 condition;

    struct CalcStats  stats;
    struct CalcStages stages;

    u8  gender;
    u8  type1;
    u8  type2;
    u8  _padding;
};

extern const u8 gStatModifierTable[][2];  // 0x0226EBE0
extern const u8 gCriticalRateTable[];     // 0x0226EBA0

static u8 sTypeBoostingItems[] = {
    [TYPE_NORMAL]       = HOLD_EFFECT_BOOST_NORMAL,
    [TYPE_FIGHTING]     = HOLD_EFFECT_BOOST_FIGHTING,
    [TYPE_FLYING]       = HOLD_EFFECT_BOOST_FLYING,
    [TYPE_POISON]       = HOLD_EFFECT_BOOST_POISON,
    [TYPE_GROUND]       = HOLD_EFFECT_BOOST_GROUND,
    [TYPE_ROCK]         = HOLD_EFFECT_BOOST_ROCK,
    [TYPE_BUG]          = HOLD_EFFECT_BOOST_BUG,
    [TYPE_GHOST]        = HOLD_EFFECT_BOOST_GHOST,
    [TYPE_STEEL]        = HOLD_EFFECT_BOOST_STEEL,
    [TYPE_FAIRY]        = 0xFF,
    [TYPE_FIRE]         = HOLD_EFFECT_BOOST_FIRE,
    [TYPE_WATER]        = HOLD_EFFECT_BOOST_WATER,
    [TYPE_GRASS]        = HOLD_EFFECT_BOOST_GRASS,
    [TYPE_ELECTRIC]     = HOLD_EFFECT_BOOST_ELECTRIC,
    [TYPE_PSYCHIC]      = HOLD_EFFECT_BOOST_PSYCHIC,
    [TYPE_ICE]          = HOLD_EFFECT_BOOST_ICE,
    [TYPE_DRAGON]       = HOLD_EFFECT_BOOST_DRAGON,
    [TYPE_DARK]         = HOLD_EFFECT_BOOST_DARK,
};

static u8 sTypePlates[] = {
    [TYPE_NORMAL]       = 0xFF,
    [TYPE_FIGHTING]     = HOLD_EFFECT_BOOST_FIGHTING_PLATE,
    [TYPE_FLYING]       = HOLD_EFFECT_BOOST_FLYING_PLATE,
    [TYPE_POISON]       = HOLD_EFFECT_BOOST_POISON_PLATE,
    [TYPE_GROUND]       = HOLD_EFFECT_BOOST_GROUND_PLATE,
    [TYPE_ROCK]         = HOLD_EFFECT_BOOST_ROCK_PLATE,
    [TYPE_BUG]          = HOLD_EFFECT_BOOST_BUG_PLATE,
    [TYPE_GHOST]        = HOLD_EFFECT_BOOST_GHOST_PLATE,
    [TYPE_STEEL]        = HOLD_EFFECT_BOOST_STEEL_PLATE,
    [TYPE_FAIRY]        = HOLD_EFFECT_BOOST_FAIRY_PLATE,
    [TYPE_FIRE]         = HOLD_EFFECT_BOOST_FIRE_PLATE,
    [TYPE_WATER]        = HOLD_EFFECT_BOOST_WATER_PLATE,
    [TYPE_GRASS]        = HOLD_EFFECT_BOOST_GRASS_PLATE,
    [TYPE_ELECTRIC]     = HOLD_EFFECT_BOOST_ELECTRIC_PLATE,
    [TYPE_PSYCHIC]      = HOLD_EFFECT_BOOST_PSYCHIC_PLATE,
    [TYPE_ICE]          = HOLD_EFFECT_BOOST_ICE_PLATE,
    [TYPE_DRAGON]       = HOLD_EFFECT_BOOST_DRAGON_PLATE,
    [TYPE_DARK]         = HOLD_EFFECT_BOOST_DARK_PLATE,
};

static u8 sGems[] = {
    [TYPE_NORMAL]       = HOLD_EFFECT_GEM_NORMAL,
    [TYPE_FIGHTING]     = HOLD_EFFECT_GEM_FIGHTING,
    [TYPE_FLYING]       = HOLD_EFFECT_GEM_FLYING,
    [TYPE_POISON]       = HOLD_EFFECT_GEM_POISON,
    [TYPE_GROUND]       = HOLD_EFFECT_GEM_GROUND,
    [TYPE_ROCK]         = HOLD_EFFECT_GEM_ROCK,
    [TYPE_BUG]          = HOLD_EFFECT_GEM_BUG,
    [TYPE_GHOST]        = HOLD_EFFECT_GEM_GHOST,
    [TYPE_STEEL]        = HOLD_EFFECT_GEM_STEEL,
    [TYPE_FAIRY]        = HOLD_EFFECT_GEM_FAIRY,
    [TYPE_FIRE]         = HOLD_EFFECT_GEM_FIRE,
    [TYPE_WATER]        = HOLD_EFFECT_GEM_WATER,
    [TYPE_GRASS]        = HOLD_EFFECT_GEM_GRASS,
    [TYPE_ELECTRIC]     = HOLD_EFFECT_GEM_ELECTRIC,
    [TYPE_PSYCHIC]      = HOLD_EFFECT_GEM_PSYCHIC,
    [TYPE_ICE]          = HOLD_EFFECT_GEM_ICE,
    [TYPE_DRAGON]       = HOLD_EFFECT_GEM_DRAGON,
    [TYPE_DARK]         = HOLD_EFFECT_GEM_DARK,
};

static inline s32 Calc_Damage(u16 attack, u8 attackStage, u16 defense, u8 defenseStage, u16 movePower, u8 attackerLevel, u8 critical)
{
    s32 damage;
    if ((critical > 1) && (attackStage <= 6)) { // ignore negative offensive stat changes on crits
        damage = attack;
    } else {
        damage = attack * gStatModifierTable[attackStage][0] / gStatModifierTable[attackStage][1];
    }

    damage = damage * movePower * (attackerLevel * 2 / 5 + 2);

    s32 damageDenom;
    if ((critical > 1) && (defenseStage >= 6)) { // ignore positive defensive stat changes on crits
        damageDenom = defense;
    } else {
        damageDenom = defense * gStatModifierTable[defenseStage][0] / gStatModifierTable[defenseStage][1];
    }

    return damage / damageDenom / 50;
}

static inline u8  Calc_MoveType(struct BattleServer *server, struct CalcParams *attacker, u16 moveID, u8 inputType)
{
    // TODO: Account for Ion Deluge, etc.
    if ((attacker->ability == ABILITY_NORMALIZE) && (Moves_CanNormalize(moveID))) {
        return TYPE_NORMAL;
    } else if (inputType == TYPE_NORMAL) {
        if ((attacker->ability == ABILITY_LIQUID_VOICE) && Moves_IsSound(moveID)) {
            return TYPE_WATER;
        } else if (attacker->ability == ABILITY_AERILATE) {
            return TYPE_FLYING;
        } else if (attacker->ability == ABILITY_GALVANIZE) {
            return TYPE_ELECTRIC;
        } else if (attacker->ability == ABILITY_PIXILATE) {
            return TYPE_FAIRY;
        } else if (attacker->ability == ABILITY_REFRIGERATE) {
            return TYPE_ICE;
        } else {
            return server->aiWork.moveTable[moveID].type;   // TODO: move reference to new table
        }
    } else {
        return inputType & 0x3F;
    }
}

static inline BOOL WeatherIsActive(struct Battle *battle, struct BattleServer *server, u32 weatherMask)
{
    return (server->fieldConditions.raw & weatherMask)
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0);
}

static inline BOOL AllyHasAbility(struct Battle *battle, struct BattleServer *server, int battler, u16 ability)
{
    // Ally is the battler which has the same parity as ours
    // Just get the battler which has the input ability, XOR it with the requesting battler,
    // and check that bit 0 of the result is 0
    //
    //  XOR | 0 | 1 | 2 | 3 |
    //  ----|---|---|---|---|
    //    0 | X | 1 | 0 | 1 |
    //    1 | 1 | X | 1 | 0 |
    //    2 | 0 | 1 | X | 1 |
    //    3 | 1 | 0 | 1 | X |
    return (Server_CheckAbility(battle, server, CHECK_ABILITY_EXISTS_CLIENT_NOT_MINE, battler, ability) ^ battler) & 1 == 0;
}

/**
 * @brief Computes the modified base power for a move, considering all abilities of the attacker
 * attacker's partner, and defender as well as all items which would affect it.
 * 
 * @param battle 
 * @param server 
 * @param attacker 
 * @param defender 
 * @param moveID 
 * @param movePower 
 * @param moveType 
 * @param movePSS 
 * @param isAteAbility 
 * @return u16 
 */
static u16 Calc_ModifiedBasePower(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender,
    u16 moveID,
    u16 movePower,
    u8 movePSS,
    u8 moveType,
    BOOL isAteAbility
)
{
    /*
     * Certain moves are expected to input some multipliers as part of their effect scripts:
     *  - Facade, if the user is burned/paralyzed/poisoned
     *  - Brine, if the target's current HP is half or less of its maximum (rounded down)
     *  - Venoshock and Barb Barrage, if the target is poisoned
     *  - Retaliate, if a Pokemon in the user's party fainted last turn
     *  - Fusion Flare/Bolt, if the most recently used move in the turn was the opposite move
     *  - Lash Out, if any of the attacker's stats were lowered on this turn
     *  - Solar Beam/Blade, if the weather is an active rain/sand/snow/fog effect
     *  - Knock Off, if the target is holding an item that can be removed when the move is executed
     *  - Grav Apple, if Gravity is in effect
     *  - Misty Explosion, if the user is grounded on Misty Terrain
     *  - Expanding Force, if the user is grounded on Psychic Terrain
     *  - Psyblade, if the user is grounded on Electric Terrain
     * 
     * This multiplier is passed as a value which is expected to be in Q4.12 format.
     */
    u16 powerMod = server->powerModifier;
    
    // 2x if the attacker is under the effect of Charge and the used move is Electric-type.
    if ((server->activePokemon[server->attacker].moveEffectsMask & MOVE_EFFECT_CHARGED) && (moveType == TYPE_ELECTRIC)) {
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__2_0);
    }

    // 1.5x if the used move was stolen via Me First.
    if ((server->activePokemon[server->attacker].moveEffects.meFirstActive)) {
        // Turn has been taken for the calling attacker
        if (server->meFirstTotalTurnOrder == server->activePokemon[server->attacker].moveEffects.meFirstTurnCount) {
            server->activePokemon[server->attacker].moveEffects.meFirstTurnCount--;
        }

        if (server->meFirstTotalTurnOrder - server->activePokemon[server->attacker].moveEffects.meFirstTurnCount < 2) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
        }
    }

    // 1.5x if the attacker's ally used Helping Hand.
    //
    // Technically this breaks for Triple Battles if one ally uses Helping Hand
    // and another uses Instruct, but lol. lmao.
    if (server->stFX[server->attacker].helpingHand) {
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
    }

    // 0.33x if Mud or Water Sport are in effect and the used move is Electric or Fire-type (respectively).
    // TODO: These need to be moved to field conditions instead of being move effects
    if ((Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_MUD_SPORT) && (moveType == TYPE_ELECTRIC))
            || (Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_WATER_SPORT) && (moveType == TYPE_FIRE))) {
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__0_33);
    }

    // TODO
    // 0.5x if Grassy Terrain is in effect and the used move is Earthquake, Magnitude, or Bulldoze.
    // 0.5x if Misty Terrain is in effect and the used move is Dragon-type.

    // TODO
    // 1.3x if Electric Terrain is in effect, the attacker is grounded, and the used move is Electric-type.
    // 1.3x if Grassy Terrain is in effect, the attacker is grounded, and the used move is Grass-type.
    // 1.3x if Psychic Terrain is in effect, the attacker is grounded, and the used move is Psychic-type.

    // ==================== START OF ABILITY CHAIN ==================== //

    if (attacker->ability == ABILITY_RIVALRY) {
        // 1.25x if the attacker's ability is Rivalry and the target is of the same gender.
        // 0.75x if the attacker's ability is Rivalry and the target is of the opposite gender.
        // No muliplier if either Pokemon is genderless.
        if ((attacker->gender == 2) || (defender->gender == 2)) {
            powerMod = powerMod;
        } else if (attacker->gender == defender->gender) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_25);
        } else {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__0_75);
        }
    } else if (attacker->ability == ABILITY_SUPREME_OVERLORD) {
        // TODO
        // 1 + 0.1n if the attacker's ability is Supreme Overlord, where n is the number of Pokemon
        // on the attacker's party which have previously fainted.
    } else if (attacker->ability == ABILITY_RECKLESS) {
        if (Moves_BoostedByReckless(moveID)) {
            // 1.2x if the attacker's ability is Reckless and the used move is applicable (deals recoil damage,
            // or is High Jump Kick or Jump Kick, but is _not_ Struggle).
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
        }
    } else if (attacker->ability == ABILITY_IRON_FIST
            && Moves_IsPunching(moveID)) {
        // 1.2x if the attacker's ability is Iron Fist and the used move is a punching move.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
    } else if (attacker->ability == ABILITY_NORMALIZE) {
        if (Moves_CanNormalize(moveID)) {
            // 1.2x if the attacker's ability is Normalize and the used move is affected.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
        }
    } else if (isAteAbility) {
        // 1.2x if the attacker's ability is an -ate ability and was the used move was affected.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
    } else if (attacker->ability == ABILITY_ANALYTIC) {
        // 1.3x if the attacker's ability is Analytic and it moves last in turn order.
        // Check all the other living Pokemon; if any of them would have moved after the attacker, break out.
        int i;
        for (i = 0; i < 4; i++) {
            if (server->attacker != i
                    && server->activePokemon[i].curHP != 0
                    /* && SpeedCheck*/) {
                break;
            }
        }

        if (i == 4) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_3);
        }
    } else if (attacker->ability == ABILITY_SAND_FORCE) {
        // 1.3x if the attacker's ability is Sand Force, the weather is sandstorm, and the used move is
        // Ground, Rock, or Steel-type.
        if (WeatherIsActive(battle, server, FIELD_CONDITION_SANDSTORM)
                && ((moveType == TYPE_GROUND) || (moveType == TYPE_ROCK) || (moveType == TYPE_STEEL))) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_3);
        }
    } else if (attacker->ability == ABILITY_SHEER_FORCE) {
        // 1.3x if the attacker's ability is Sheer Froce and the used move has an additional effect.
        // TODO
    } else if (attacker->ability == ABILITY_TOUGH_CLAWS) {
        if (server->aiWork.moveTable[moveID].flag & MOVE_FLAG_MAKES_CONTACT) {
            // 1.3x if the attacker's ability is Tough Claws and the used move makes contact.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_3);
        }
    }

    // Battery and Power Spot are not technically exclusive in the scope of Triple Battles,
    // but they are mutually exclusive in doubles.
    if (AllyHasAbility(battle, server, server->attacker, ABILITY_BATTERY) && movePSS == PSS_SPECIAL) {
        // 1.3x if our ally has Battery and the used move is Special-split.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_3);
    } else if (AllyHasAbility(battle, server, server->attacker, ABILITY_POWER_SPOT)) {
        // 1.3x if our ally has Power Spot.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_3);
    }

    if (attacker->ability == ABILITY_PUNK_ROCK && Moves_IsSound(moveID)) {
        // 1.3x if the attacker's ability is Punk Rock and the used move is sound-based.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_3);
    }

    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_FAIRY_AURA)
            && (moveType == TYPE_FAIRY)
            && (attacker->ability != ABILITY_MOLD_BREAKER)
            && (attacker->ability != ABILITY_TERAVOLT)
            && (attacker->ability != ABILITY_TURBOBLAZE)) {
        // 1.33x if Fairy Aura is in effect, the used move is Fairy-type, and the attacker's ability is not
        // Mold Breaker. If Aura Break is also in effect, instead 0.75x.
        if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AURA_BREAK)) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__0_75);
        } else {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_33);
        }
    }

    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_DARK_AURA)
            && (moveType == TYPE_DARK)
            && (attacker->ability != ABILITY_MOLD_BREAKER)
            && (attacker->ability != ABILITY_TERAVOLT)
            && (attacker->ability != ABILITY_TURBOBLAZE)) {
        // 1.33x if Dark Aura is in effect, the used move is Dark-type, and the attacker's ability is not
        // Mold Breaker. If Aura Break is also in effect, instead 0.75x.
        if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AURA_BREAK)) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__0_75);
        } else {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_33);
        }
    }

    if (attacker->ability == ABILITY_STRONG_JAW) {
        if (Moves_IsBiting(moveID)) {
            // 1.5x if the attacker's ability is Strong Jaw and the used move is a biting move.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_MEGA_LAUNCHER) {
        if (Moves_IsAuraOrPulse(moveID)) {
            // 1.5x if the attacker's ability is Mega Launcher and the used move is aura or pulse-based.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_TECHNICIAN) {
        if ((movePower <= 60) && (moveID != MOVE_STRUGGLE)) {
            // 1.5x if the attacker's ability is Technician, the used move's power is less than or equal
            // to 60, and the move is _not_ Struggle.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_TOXIC_BOOST) {
        if ((movePSS == PSS_PHYSICAL) && (attacker->condition & CONDITION_POISON_ALL)) {
            // 1.5x if the attacker's ability is Toxic Boost, the used move is Physical-split, and the
            // attacker is poisoned.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_FLARE_BOOST) {
        if ((movePSS == PSS_SPECIAL) && (attacker->condition & CONDITION_BURNED)) {
            // 1.5x if the attacker's ability is Flare Boost, the used move is Special-split, and the
            // attacker is burned.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_STEELY_SPIRIT) {
        if (moveType == TYPE_STEEL) {
            // 1.5x if the attacker's ability is Steely Spirit and the used move is Steel-type.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
        }
    }

    if (AllyHasAbility(battle, server, server->attacker, ABILITY_STEELY_SPIRIT)
            && moveType == TYPE_STEEL) {
        // 1.5x if the attacker's ally has Steely Spirit and the used move is Steel-type.
        // Note that this modifier stacks with the attacker itself having Steely Spirit.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
    }

    if (moveType == TYPE_FIRE) {
        if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_HEATPROOF)) {
            // 0.5x if the target's ability is Heatproof, the used move is Fire-type, and the
            // target's ability is not ignored.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__0_5);
        } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_DRY_SKIN)) {
            // 1.25x if the target's ability is Dry Skin, the used move is Fire-type, and the
            // target's ability is not ignored.
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_25);
        }
    }

    if (attacker->ability == ABILITY_SHARPNESS && Moves_IsSlashing(moveID)) {
        // 1.5x if the attacker's ability is Sharpness and the used move is slashing-based.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_5);
    }

    // ==================== END OF ABILITY CHAIN ==================== //
    // ==================== START OF ITEM CHECKS ==================== //

    if (attacker->heldItemEffect == HOLD_EFFECT_BOOST_PHYSICAL) {
        // 1.1x if the attacker is holding a Muscle Band and the used move is Physical.
        if (movePSS == PSS_PHYSICAL) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_1);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_BOOST_SPECIAL) {
        // 1.1x if the attacker is holding Wise Glasses and the used move is Special.
        if (movePSS == PSS_SPECIAL) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_1);
        }
    } else if (attacker->heldItemEffect == sTypeBoostingItems[moveType]
            || attacker->heldItemEffect == sTypePlates[moveType]) {
        // 1.1x if the attacker is holding a type-boosting item, Incense, or Plate which matches
        // the used move's type.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_1);
    } else if (attacker->heldItemEffect == HOLD_EFFECT_ADAMANT_ORB) {
        // 1.2x if the attacker is holding an Adamant Orb, the attacker is Dialga, and the used
        // move is Dragon or Steel-type.
        if (attacker->species == SPECIES_DIALGA
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_STEEL))) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_LUSTROUS_ORB) {
        // 1.2x if the attacker is holding a Lustrous Orb, the attacker is Palkia, and the used
        // move is Dragon or Water-type.
        if (attacker->species == SPECIES_PALKIA
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_WATER))) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_GRISEOUS_ORB) {
        // 1.2x if the attacker is holding a Griseous Orb, the attacker is Giratina, and the used
        // move is Dragon or Ghost-type.
        if (attacker->species == SPECIES_GIRATINA
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_GHOST))) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_GRISEOUS_ORB) {
        // 1.2x if the attacker is holding a Soul Dew, the attacker is Lati@s, and the used
        // move is Dragon or Psychic-type.
        if (((attacker->species == SPECIES_LATIOS) || (attacker->species == SPECIES_LATIAS))
                && ((moveType == TYPE_DRAGON) || (moveType == TYPE_PSYCHIC))) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_2);
        }
    } else if (attacker->heldItemEffect == sGems[moveType]) {
        // 1.3x if the attacker is holding a Gem and the used move is of a matching type.
        powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_3);
    } else if (attacker->heldItemEffect == HOLD_EFFECT_BOOST_PUNCHING_MOVES) {
        // 1.1x if the attacker is holding a Punching Glove and the used move is punching-based.
        if (Moves_IsPunching(moveID)) {
            powerMod = UQ412_Mul_RoundUp(powerMod, UQ412__1_1);
        }
    }

    /*
     * Now we apply the final modifier to the move's base power.
     *
     * Note that this procedure limits the input base power to
     * 4095, but that does not really matter as no move comes
     * close to that value (maximum is Explosion at 250).
     */
    u32 modifiedPower = UQ412_Mul_IntByQ_RoundDown(movePower, powerMod);
    return (modifiedPower < 1) ? 1 : modifiedPower;         // power can never be less than 1
}

/**
 * @brief Computes the base damage for a particular move, which is determined using the
 * following formula:
 * 
 *   ( (2 * level)     )           effectiveAtk
 *   ( ----------- + 2 ) * power * ------------
 *   (      5          )           effectiveDef
 *   ------------------------------------------ + 2
 *                      50
 * 
 * Values for each operation in calculating the base damage are subject to
 * standard rounding, rounding up at 0.5.
 */
static u16 Calc_BaseDamage(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender
)
{
    // Start by gathering/discerning some necessary data points.
    u16  moveID        = server->moveIDCurr;
    u16  moveBasePower = server->movePower;
    u8   movePSS       = server->aiWork.moveTable[moveID].pss;
    u8   moveType      = server->moveType;
    BOOL isCritical    = server->critical > 1;
    BOOL isAteAbility  = FALSE;

    if (attacker->ability == ABILITY_NORMALIZE) {
        if (Moves_CanNormalize(moveID)) {
            moveType = TYPE_NORMAL;
        }
    } else if (attacker->ability == ABILITY_AERILATE) {
        // Aerilate turns Normal-type sound moves into Flying-type.
        if (moveType == TYPE_NORMAL) {
            moveType         = TYPE_FLYING;
            server->moveType = moveType;
            isAteAbility     = TRUE;
        }
    } else if (attacker->ability == ABILITY_GALVANIZE) {
        // Galvanize turns Normal-type sound moves into Electric-type.
        if (moveType == TYPE_NORMAL) {
            moveType         = TYPE_ELECTRIC;
            server->moveType = moveType;
            isAteAbility     = TRUE;
        }
    } else if (attacker->ability == ABILITY_PIXILATE) {
        // Pixilate turns Normal-type sound moves into Fairy-type.
        if (moveType == TYPE_NORMAL) {
            moveType         = TYPE_FAIRY;
            server->moveType = moveType;
            isAteAbility     = TRUE;
        }
    } else if (attacker->ability == ABILITY_REFRIGERATE) {
        // Refrigerate turns Normal-type sound moves into Ice-type.
        if (moveType == TYPE_NORMAL) {
            moveType         = TYPE_ICE;
            server->moveType = moveType;
            isAteAbility     = TRUE;
        }
    } else if (attacker->ability == ABILITY_LIQUID_VOICE) {
        // Liquid Voice turns Normal-type sound moves into Water-type.
        if (moveType == TYPE_NORMAL && Moves_IsSound(moveID)) {
            moveType         = TYPE_WATER;
            server->moveType = moveType;
        }
    } else if (moveType == TYPE_NORMAL) {
        // If the move was specified Normal type, double-check it.
        moveType = server->aiWork.moveTable[moveID].type;
    }

    // Calc the modified base power first.
    u16 modifiedBasePower = Calc_ModifiedBasePower(
        battle,
        server,
        attacker,
        defender,
        moveID,
        moveBasePower,
        movePSS,
        moveType,
        isAteAbility
    );

    // Treat Shell Side Arm moves differently
    if (moveID == MOVE_SHELL_SIDE_ARM) {
        return 0;
    }

    // Compute the effective offensive + defensive stats
    // Some moves alter this process slightly
    u16 effectiveOffense, effectiveDefense;
    BOOL attackerUnaware = attacker->ability == ABILITY_UNAWARE;
    BOOL defenderUnaware = Server_CheckDefenderAbility(server, attacker, defender, ABILITY_UNAWARE);
    if (moveID == MOVE_PHOTON_GEYSER) {
        /* 
         * If the user's Attack stat is higher than its Special Attack stat, Photon Geyser
         * becomes a Physical move; otherwise, it is a special move.
         *
         * During the execution of Photon Geyser, all ignorable Abilities are ignored.
         *
         * When determining which stat is higher, stat stage modifiers are taken into
         * account, but other effects (held items, abilities, etc.) are not.
         */
        u16 boostedAttack   = Calc_AttackerStat(attacker->stats.attack,   attacker->stages.attack,   FALSE, FALSE);
        u16 boostedSpAttack = Calc_AttackerStat(attacker->stats.spAttack, attacker->stages.spAttack, FALSE, FALSE);
        if (boostedAttack > boostedSpAttack) {
            // Now recalc everything accounting for crits.
            effectiveOffense = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.attack,  FALSE, isCritical);
            effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, FALSE, isCritical);
            movePSS = PSS_PHYSICAL;
        } else {
            effectiveOffense = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack,  FALSE, isCritical);
            effectiveDefense = Calc_DefenderStat(defender->stats.spDefense, defender->stages.spDefense, FALSE, isCritical);
        }
    } else if (moveID == MOVE_BODY_PRESS) {
        /*
         * When calculating damage, Body Press uses the user's Defense stat instead of its
         * Attack stat. Defense stat-stage modifiers are applied, but Attack modifiers are
         * used thereafter.
         *
         * Since the user's Defense stat is used for calculating damage, Body Press does
         * not consider Unaware when calculating the offensive stat.
         */
        effectiveOffense = Calc_AttackerStat(attacker->stats.defense, attacker->stages.defense, FALSE,           isCritical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, isCritical);
    } else if (moveID == MOVE_FOUL_PLAY) {
        /*
         * When calculating damage, Foul Play uses the target's Attack stat instead of its
         * user's Attack stat. The target's Attack stat-stage modifiers are applied (rather
         * than the user's), but the user's Attack modifiers are used thereafter.
         * 
         * Since the target's Attack stat is used for calculating damage, Foul Play does
         * not consider Unaware when calculating the offensive stat.
         */
        effectiveOffense = Calc_AttackerStat(defender->stats.defense, defender->stages.defense, FALSE,           isCritical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, isCritical);
    } else if ((moveID == MOVE_PSYSHOCK)
            || (moveID == MOVE_PSYSTRIKE)
            || (moveID == MOVE_SECRET_SWORD)) {
        /*
         * Moves with this effect use the target's Defense stat instead of its Special
         * Defense stat during damage calculation. The move, however, still deals Special
         * damage.
         */
        effectiveOffense = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack, defenderUnaware, isCritical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense,   defender->stages.defense,  attackerUnaware, isCritical);
    } else if (moveID == MOVE_SACRED_SWORD) {
        /*
         * When calculating damage, Sacred Sword ignores the target's Defense stat stages.
         */
        effectiveOffense = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.defense, defenderUnaware, isCritical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, TRUE,            isCritical);
    } else {
        /*
         * All other moves determine offensive/defensive stats depending on the PSS-split.
         */
        if (movePSS == PSS_PHYSICAL) {
            effectiveOffense = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.attack,  defenderUnaware, isCritical);
            effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, isCritical);
        } else {
            effectiveOffense = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack,  defenderUnaware, isCritical);
            effectiveDefense = Calc_DefenderStat(defender->stats.spDefense, defender->stages.spDefense, attackerUnaware, isCritical);
        }
    }

    // Unlike all other offensive modifiers, Hustle is applied directly to the 
    // Attack stat.
    if (attacker->ability == ABILITY_HUSTLE && movePSS == PSS_PHYSICAL) {
        effectiveOffense = UQ412_Mul_IntByQ_RoundDown(effectiveOffense, UQ412__1_5);
    }

    // Unlike all other defensive modifiers, Sandstorm SpD boost gets applied
    // directly.
    // Note: this is also where Snow's Def boost for Ice-types goes.
    if (WeatherIsActive(battle, server, MOVE_SANDSTORM)
            && ((defender->type1 == TYPE_ROCK) || (defender->type2 == TYPE_ROCK))
            && (movePSS == PSS_SPECIAL)) {
        effectiveDefense = UQ412_Mul_IntByQ_RoundDown(effectiveDefense, UQ412__1_5);
    }

    // Other stat modifiers are applied as a chain.
    effectiveOffense = Calc_ChainOffenseMods(battle, server, attacker, defender, effectiveOffense, moveType, movePSS);
    effectiveDefense = Calc_ChainDefenseMods(battle, server, attacker, defender, effectiveOffense, moveType, movePSS);

    // All of these divisions are integer-division.
    s32 baseDamage = 2 * BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_LEVEL, NULL);
    baseDamage = baseDamage / 5 + 2;
    baseDamage = baseDamage * modifiedBasePower;
    baseDamage = baseDamage * effectiveOffense;
    baseDamage = baseDamage / effectiveDefense;

    return baseDamage / 50 + 2;
}

// this needs to be refactored
inline u16 Calc_StatWithStages(u16 stat, u8 stage)
{
    return stat * gStatModifierTable[stage][0] / gStatModifierTable[stage][1];
}

static u16 Calc_AttackerStat(u16 stat, u8 stage, BOOL unaware, BOOL critical)
{
    /*
     * Ignore stat stages if Unaware is active for this stat.
     *
     * Ignore detrimental stages on criticals.
     *
     * Also shortcut for neutral stat.
     */
    if ((stage == 6) || unaware || (critical && (stage < 6))) {
        return stat;
    }

    return Calc_StatWithStages(stat, stage);
}

static u16 Calc_DefenderStat(u16 stat, u8 stage, BOOL unaware, BOOL critical)
{
    /*
     * Ignore stat stages if Unaware is active for this stat.
     *
     * Ignore beneficial stages on criticals.
     *
     * Also shortcut for neutral stat.
     */
    if ((stage == 6) || unaware || (critical && (stage > 6))) {
        return stat;
    }

    return Calc_StatWithStages(stat, stage);
}

inline BOOL SlowStartActive(struct Battle *battle, struct BattleServer *server)
{
    return Server_Get(battle, server, SERVER_PARAM_TOTAL_TURNS, NULL)
            - BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_SLOW_START_INIT_TURN, NULL)
            < 5;
}

static u16 Calc_ChainOffenseMods(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender,
    u16 stat,
    u8 moveType,
    u8 movePSS
)
{
    u16 statMod = UQ412__1_0;
    if (attacker->ability == ABILITY_SLOW_START) {
        // Slow Start halves the Attack stat during the first five turns that a Pokemon
        // is in battle.
        if (movePSS == PSS_PHYSICAL && SlowStartActive(battle, server)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_5);
        }
    } else if (attacker->ability == ABILITY_DEFEATIST) {
        // Deafeatist halves all offensive stats when the attacker has HP less than or
        // equal to half of its maximum HP.
        if (attacker->currHP <= (attacker->maxHP / 2)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_5);
        }
    } else if (attacker->ability == ABILITY_SOLAR_POWER) {
        // Solar Power increases SpAttack by 50% during harsh sunlight.
        if (movePSS == PSS_SPECIAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_FLOWER_GIFT) {
        // Flower Gift increases Attack by 50% during harsh sunlight.
        // Flower Gift does not stack with itself, so skip past the Ally check below.
        if (movePSS == PSS_PHYSICAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
        goto _SkipAttackAllyFlowerCheck;
    } else if (attacker->ability == ABILITY_GORILLA_TACTICS) {
        // Gorilla Tactics increases Attack by 50%.
        if (movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    }

    // Check for ally Flower Gift here separately, but not if the attacker has Flower Gift.
    if (AllyHasAbility(battle, server, server->attacker, ABILITY_FLOWER_GIFT)) {
        if (movePSS == PSS_PHYSICAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    }

_SkipAttackAllyFlowerCheck:
    if (attacker->ability == ABILITY_GUTS) {
        // Guts increases Attack by 50% if the attacker is statused.
        //
        // This is technically incorrect compared to vanilla, where the boost
        // does not activate if frozen and using a move which thaws the user out.
        // But I don't care lol.
        if (movePSS == PSS_PHYSICAL && attacker->condition) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_BLAZE) {
        // Blaze increases offensive stats by 50% if the attacker's current HP is less
        // than or equal to 1/3 of its maximum and the used move is Fire-type.
        if (moveType == TYPE_FIRE && (attacker->currHP < attacker->maxHP / 3)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_OVERGROW) {
        // Overgrow increases offensive stats by 50% if the attacker's current HP is less
        // than or equal to 1/3 of its maximum and the used move is Grass-type.
        if (moveType == TYPE_GRASS && (attacker->currHP < attacker->maxHP / 3)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_SWARM) {
        // Swarm increases offensive stats by 50% if the attacker's current HP is less
        // than or equal to 1/3 of its maximum and the used move is Bug-type.
        if (moveType == TYPE_BUG && (attacker->currHP < attacker->maxHP / 3)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_TORRENT) {
        // Torrent increases offensive stats by 50% if the attacker's current HP is less
        // than or equal to 1/3 of its maximum and the used move is Water-type.
        if (moveType == TYPE_WATER && (attacker->currHP < attacker->maxHP / 3)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_FLASH_FIRE) {
        // Flash Fire increases offensive stats by 50% if the attacker was previously
        // hit by a Fire-type move while possessing Flash Fire and the used move is
        // Fire-type.
        if (moveType == TYPE_FIRE
                && server->activePokemon[server->attacker].moveEffects.flashFireActive) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_STEELWORKER) {
        // Steelworker increases offensive stats by 50% if the used move is Steel-type.
        if (moveType == TYPE_STEEL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_DRAGONS_MAW) {
        // Dragon's Maw increases offensive stats by 50% if the used move is Dragon-type.
        if (moveType == TYPE_DRAGON) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_ROCKY_PAYLOAD) {
        // Rocky Payload increases offensive stats by 50% if the used move is Rock-type.
        if (moveType == TYPE_ROCK) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_TRANSISTOR) {
        // Transistor increases offensive stats by 50% if the used move is Electric-type.
        if (moveType == TYPE_ELECTRIC) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->ability == ABILITY_STAKEOUT) {
        // Stakeout doubles offensive stats if the target switched in this turn.
        // TODO: need a way to know which clients switched in this turn
        if (FALSE) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    } else if (attacker->ability == ABILITY_WATER_BUBBLE) {
        // Water Bubble doubles offensive stats if the used move is Water-type.
        if (moveType == TYPE_WATER) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    } else if (attacker->ability == ABILITY_HUGE_POWER || attacker->ability == ABILITY_PURE_POWER) {
        // Huge/Pure Power doubles the Attack stat.
        if (moveType == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    }

    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_THICK_FAT)) {
        // Thick Fat halves the attacking stats if the used move is Fire or Ice-type.
        if (moveType == TYPE_FIRE || moveType == TYPE_ICE) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_5);
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_WATER_BUBBLE)) {
        // Water Bubble halves the attacking stats if the used move is Fire-type.
        if (moveType == TYPE_FIRE) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_5);
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_PURIFYING_SALT)) {
        // Purifying Salt halves the attacking stats if the used move is Ghost-type.
        if (moveType == TYPE_GHOST) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_5);
        }
    }
    
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->attacker, ABILITY_TABLETS_OF_RUIN)) {
        // Tablets of Ruin decreases the Attack stat of all Pokemon on the field other
        // than its bearer by 25% so long as the attacker does not also have Tablets of
        // Ruin.
        if (attacker->ability != ABILITY_TABLETS_OF_RUIN && movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_75);
        }
    }
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->attacker, ABILITY_VESSEL_OF_RUIN)) {
        // Vessel of Ruin decreases the SpAttack stat of all Pokemon on the field other
        // than its bearer by 25% so long as the attacker does not also have Vessel of
        // Ruin.
        if (attacker->ability != ABILITY_VESSEL_OF_RUIN && movePSS == PSS_SPECIAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_75);
        }
    }

    // TODO: Protosynthesis, Quark Drive go here
    if (attacker->ability == ABILITY_HADRON_ENGINE) {
        // Hadron Engine increases SpAttack by 33% on Electric Terrain, even if the
        // attacker is not grounded.
        //
        // TODO: Electric Terrain
        if (FALSE) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_3333);
        }
    } else if (attacker->ability == ABILITY_ORICHALCUM_PULSE) {
        // Orichalcum Pulse increases Attack by 33% during harsh sunlight, even if
        // the attacker is holding a Utility Umbrella.
        if (WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_3333);
        }
    }

    if (attacker->heldItemEffect == HOLD_EFFECT_THICK_CLUB) {
        // Thick Club doubles the Attack stat of Cubone and Marowak.
        if (movePSS == PSS_PHYSICAL
                && (attacker->species == SPECIES_CUBONE || attacker->species == SPECIES_MAROWAK)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_DEEP_SEA_TOOTH) {
        // Deep Sea Tooth doubles the SpAttack stat of Clamperl.
        if (movePSS == PSS_SPECIAL && attacker->species == SPECIES_CLAMPERL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_LIGHT_BALL) {
        // Light Ball doubles the attacking stats of Pikachu.
        if (attacker->species == SPECIES_PIKACHU) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_CHOICE_BAND) {
        // Choice Band increases the Attack stat by 50%.
        if (movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_CHOICE_SPECS) {
        // Choice Specs increases the Attack stat by 50%.
        if (movePSS == PSS_SPECIAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    }

    return UQ412_Mul_IntByQ_RoundDown(stat, statMod);
}

static u16 Calc_ChainDefenseMods(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender,
    u16 stat,
    u8 moveType,
    u8 movePSS
)
{
    u16 statMod = UQ412__1_0;
    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_MARVEL_SCALE)) {
        // Marvel Scale increases Defense by 50% if the bearer has a status condition.
        if (defender->condition && movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FLOWER_GIFT)) {
        // Flower Gift increases SpDefense by 50% during harsh sunlight.
        if (movePSS == PSS_SPECIAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
        goto _SkipDefenseAllyFlowerGift;
    } else if (defender->ability == ABILITY_GRASS_PELT) {
        // Grass Pelt increases Defense by 50% while Grassy Terrain is active. It is
        // not ignored by Mold Breaker.
        //
        // TODO: Grassy Terrain
        if (movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FUR_COAT)) {
        // Fur Coat doubles the Defense stat.
        if (movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    }

    if (Server_CheckDefenderAbility(server, server->attacker, ((server->defender + 2) % 4), ABILITY_FLOWER_GIFT)) {
        // Flower Gift increases ally's SpDefense by 50% during harsh sunlight.
        if (movePSS == PSS_SPECIAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    }

_SkipDefenseAllyFlowerGift:
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->defender, ABILITY_SWORD_OF_RUIN)) {
        // Sword of Ruin decreases the Defense stat of all Pokemon on the field other
        // than its bearer by 25% so long as the defender does not also have Sword of
        // Ruin.
        if (defender->ability != ABILITY_SWORD_OF_RUIN && movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_75);
        }
    }
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->defender, ABILITY_BEADS_OF_RUIN)) {
        // Beads of Ruin decreases the SpDefense stat of all Pokemon on the field other
        // than its bearer by 25% so long as the defender does not also have Beads of
        // Ruin.
        if (defender->ability != ABILITY_BEADS_OF_RUIN && movePSS == PSS_SPECIAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__0_75);
        }
    }

    // TODO: Protosynthesis, Quark Drive

    if (defender->heldItemEffect == HOLD_EFFECT_BOOST_DEFENSE_DITTO) {
        // Metal Powder doubles the Defense of Ditto.
        if (defender->species == SPECIES_DITTO && movePSS == PSS_PHYSICAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    } else if (defender->heldItemEffect == HOLD_EFFECT_DEEP_SEA_SCALE) {
        // Deep Sea Scale doubles the SpDefense of Clamperl.
        if (defender->species == SPECIES_CLAMPERL && movePSS == PSS_SPECIAL) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__2_0);
        }
    } else if (defender->heldItemEffect == HOLD_EFFECT_EVIOLITE) {
        // Eviolite increases defensive stats by 50% if the defender is not fully evolved.
        if (Pokemon_IsNFE(defender->species, server->activePokemon[server->defender].formNum)) {
            statMod = UQ412_Mul_RoundUp(statMod, UQ412__1_5);
        }
    }

    return UQ412_Mul_IntByQ_RoundDown(stat, statMod);
}

// https://bulbapedia.bulbagarden.net/wiki/Damage#Generation_V_onward
void Server_CalcMoveDamage(struct Battle *battle, struct BattleServer *server)
{
    struct CalcParams attackerParams = {
        .species        = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_SPECIES,          NULL),
        .currHP         = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_HP_CURRENT,       NULL),
        .maxHP          = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_HP_MAX,           NULL),
        .ability        = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_ABILITY,          NULL),
        .condition      = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_CONDITION,        NULL),
        .gender         = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_GENDER,           NULL),
        .type1          = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_TYPE_1,           NULL),
        .type2          = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_TYPE_2,           NULL),
        .stats          = {
            .attack     = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_ATTACK,           NULL),
            .defense    = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_DEFENSE,          NULL),
            .spAttack   = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_SPATTACK,         NULL),
            .spDefense  = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_SPDEFENSE,        NULL),
        },
        .stages         = {
            .attack     = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_ATTACK_STAGES,    NULL),
            .defense    = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_DEFENSE_STAGES,   NULL),
            .spAttack   = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_SPATTACK_STAGES,  NULL),
            .spDefense  = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_SPDEFENSE_STAGES, NULL),
        },
        .heldItemEffect = Server_HeldItemEffect(server, server->attacker),
        .heldItemPower  = Server_HeldItemPower(server, server->attacker, 0),
    };
    struct CalcParams defenderParams = {
        .species        = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_SPECIES,          NULL),
        .currHP         = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_HP_CURRENT,       NULL),
        .maxHP          = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_HP_MAX,           NULL),
        .ability        = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_ABILITY,          NULL),
        .condition      = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_CONDITION,        NULL),
        .gender         = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_GENDER,           NULL),
        .type1          = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_1,           NULL),
        .type2          = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_2,           NULL),
        .stats          = {
            .attack     = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_ATTACK,           NULL),
            .defense    = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_DEFENSE,          NULL),
            .spAttack   = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_SPATTACK,         NULL),
            .spDefense  = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_SPDEFENSE,        NULL),
        },
        .stages         = {
            .attack     = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_ATTACK_STAGES,    NULL),
            .defense    = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_DEFENSE_STAGES,   NULL),
            .spAttack   = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_SPATTACK_STAGES,  NULL),
            .spDefense  = BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_SPDEFENSE_STAGES, NULL),
        },
        .heldItemEffect = Server_HeldItemEffect(server, server->defender),
        .heldItemPower  = Server_HeldItemPower(server, server->defender, 0),
    };

    u32 battleType = Battle_Type(battle);

    // Step 1: Calculate the base damage value.
    s32 damage = Calc_BaseDamage(battle, server, &attackerParams, &defenderParams);

    // Step 2: 0.75x if the move has more than one target upon execution.
    u32 battleType = Battle_Type(battle);
    if ((battleType & BATTLE_TYPE_DOUBLES) && (Server_HitCount(battle, server, 0, server->defender) > 1)) {
        damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__0_75);
    }

    // Step 3: Divide by 4 if the move is the second-strike of Parental Bond.
    // TODO

    // Step 4: 1.5x if the active weather is Sun or Rain and the move is Fire or Water type, respectively.
    //         0.5x if the active weather is Sun or Rain and the move is Water or Fire type, respectively.
    // Neither applies if the defender is holding a Utility Umbrella.
    if (WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)
            && defenderParams.heldItemEffect != HOLD_EFFECT_UNAFFECTED_BY_RAIN_OR_SUN) {
        if (server->moveType == TYPE_FIRE) {
            damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__1_5);
        } else if (server->moveType == TYPE_WATER) {
            damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__0_5);
        }
    } else if (WeatherIsActive(battle, server, FIELD_CONDITION_RAINING)
            && defenderParams.heldItemEffect != HOLD_EFFECT_UNAFFECTED_BY_RAIN_OR_SUN) {
        if (server->moveType == TYPE_WATER) {
            damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__1_5);
        } else if (server->moveType == TYPE_FIRE) {
            damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__0_5);
        }
    }

    // Step 5: 2x if the defender used Glaive Rush last turn (or this turn) and the move does
    // not have a fixed damage value.
    // TODO

    // Step 6: Multiply by the critical hit factor.
    //  - 1.5x  if the move was a critical hit
    //  - 2.25x if the move was a critical hit and the attacker has Sniper
    if (server->critical == 2) {        // Normal criticals
        damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__1_5);
    } else if (server->critical == 3) { // Sniper criticals
        damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__2_25);
    }

    // Step 7: Apply random damage fluctuation.
    // TODO

    // Step 8: 1.5x if the attacker shares a type with the move.
    // TODO: Handle Soak, Forest's Curse, Trick-or-Treat.
    u16 stabMod = UQ412__1_0;
    if ((server->moveType == attackerParams.type1) || (server->moveType == attackerParams.type2)) {
        stabMod = stabMod + UQ412__0_5;
    } else if ((attackerParams.ability == ABILITY_PROTEAN) || (attackerParams.ability == ABILITY_LIBERO)) {
        // This one is only here for the AI.
        stabMod = stabMod + UQ412__0_5;
    }

    if ((attackerParams.ability == ABILITY_ADAPTABILITY)
            && ((attackerParams.type1 == server->moveType) || (attackerParams.type2 == server->moveType))) {
        stabMod = stabMod + UQ412__0_5;
    }

    damage = Q412_Mul_IntByQ_RoundDown(damage, stabMod);

    // Step 9: Apply overall type effectiveness; multiply/divide by 2 according to each effectiveness
    // matchup of the move's type vs the defender's types.
    //
    // TODO: Forest's Curse and Trick-or-Treat add types to a Pokemon, so three types need to be checked.

    // Step 10: Divide by 2 if the attacker is burned and does not have Guts nor is using Facade.
    if (server->aiWork.moveTable[server->moveIDCurr].pss == PSS_PHYSICAL) {
        if ((attackerParams.condition & CONDITION_BURNED)
                && ((attackerParams.ability != ABILITY_GUTS) && (server->moveIDCurr != MOVE_FACADE))) {
            damage = Q412_Mul_IntByQ_RoundDown(damage, UQ412__0_5);
        }
    }

    // Step 11: Finish up remaining modifiers, in-order:
    //  - various moves interacting with Minimize
    //  - Earthquake and Magnitude, if the opponent is semi-invulnerable via Dig    
    //  - Surf and Whirlpool, if the opponent is semi-invulnerable via Dive
    //  - Reflect, Light Screen, and Aurora Veil
    //  - Collision Course and Electro Drift
    //  - Multiscale and Shadow Shield, if the target is at full health
    //  - Various abilites for the target: Fluffy, Punk Rock, Ice Scales
    //  - Friend Guard, if the target's ally has it
    //  - More abilities for the target: Filter, Prism Armor, Solid Rock
    //  - Some attacker abilities: Neuroforce, Sniper, Tinted Lens
    //  - Fluffy, if the used move is Fire-type
    //  - Type-resist berries
    //  - Expert Belt, Life Orb, and Metronome

    // Step 11: Divide by 4 if the used move is a Z-move and the target is trying to Protect itself.
    // TODO: Z-moves

    // And we're done.
    server->damage = damage;
}

int Server_CalcCritical(
    struct Battle *battle,
    struct BattleServer *server,
    int attacker,
    int defender,
    int critStages,
    u32 sideConditions
) {
    int ret = 1;

    u16 species            = server->activePokemon[attacker].species;
    u32 volatileConditions = server->activePokemon[attacker].condition2;
    u32 moveEffects        = server->activePokemon[defender].moveEffectsMask;
    u8  ability            = server->activePokemon[attacker].ability;
    u16 itemEffect         = Server_HeldItemEffect(server, attacker);

    u16 effectiveStages = (
        critStages
        + (itemEffect == HOLD_EFFECT_BOOST_CRIT_RATE)
        + (ability == ABILITY_SUPER_LUCK)
        + (((volatileConditions & CONDITION_V_PUMPED) != 0) * 2)
        + (((itemEffect == HOLD_EFFECT_BOOST_CRIT_RATE_CHANSEY) && (species == SPECIES_CHANSEY)) * 2)
        + (((itemEffect == HOLD_EFFECT_BOOST_CRIT_RATE_FARFETCHD) && (species == SPECIES_FARFETCHD)) * 2)   // TODO: Farfetch'd-G, Sirfetch'd
    );

    effectiveStages = (effectiveStages > 4) ? 4 : effectiveStages;  // crit stages max out at +4

    // TODO: Effect check here for auto-critical?
    // there's an argument to pass critStages == 4, but that might fuck with people
    // trying to change the crit ratios

    if (Battle_Random(battle) % gCriticalRateTable[effectiveStages] == 0) {
        if ((Server_CheckDefenderAbility(server, attacker, defender, ABILITY_BATTLE_ARMOR) == FALSE)
                && (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_SHELL_ARMOR) == FALSE)
                && ((sideConditions & SIDE_CONDITION_LUCKY_CHANT) == FALSE)
                && ((moveEffects & MOVE_EFFECT_NO_CRITICAL) == FALSE)) {
            ret = 2;
        }
    }

    if ((ret == 2) && (Server_Ability(server, attacker) == ABILITY_SNIPER)) {
        ret = 3;
    }

    return ret;
}
