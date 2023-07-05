#include "global.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/server.h"

#include "archive.h"
#include "pokemon.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/misc.h"
#include "constants/species.h"

static u16 __attribute__((long_call)) Server_CalcPowerMod(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attackerParams,
    struct CalcParams *defenderParams,
    u16 moveID,
    u16 movePower,
    u8 moveType,
    u8 movePSS,
    u8 typeModified
);

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

static inline void Calc_BoostOffensiveItem(struct CalcParams *params, u16 *attack, u16 *spAttack, u16 *movePower, u8 moveType, u8 movePSS)
{
    // Check for the type-boosting items first
    for (unsigned int i = 0; i < NELEMS(sHeldItemTypeBoostTable); i++) {
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

static inline void Calc_BoostDefensiveItem(struct CalcParams *params, u16 *defense, u16 *spDefense)
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

static inline BOOL Calc_CheckPartnerAbility(struct BattleServer *server, int battler, int ability)
{
    int partner = (battler + 2) % 4;

    return server->activePokemon[partner].ability == ability;
}

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

#define DIV_ROUNDUP(val, roundBy)(((val) / (roundBy)) + (((val) % (roundBy)) ? 1 : 0))

/*
 * Starting with the damage formula overhaul in Generation 5, if multiple factors apply to
 * a move's effective power computation, they are chained together in a specific order by
 * starting at 4096 and multiplying by each applicable modifier in succession (rounding up
 * at 0.5). The final result of this chain is then multiplied by the move's base power and
 * divided by 4096, rounding down at 0.5.
 * 
 * This routine provides consideration for all effects as of Generation 9, subject to the
 * Generation 5 formula.
 * 
 * There is a slight quirk in the formula where, if multiple modifiers take effect, they
 * should be chained together in the order of each source's unmodified Speed stat. This
 * routine does NOT consider such cases, but this only truly matters for a niche case
 * wherein the attacker and its ally each have Steely Spirit.
 */
static u16 Server_CalcPowerMod(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attackerParams,
    struct CalcParams *defenderParams,
    u16 moveID,
    u16 movePower,
    u8 moveType,
    u8 movePSS,
    u8 typeModified
) {
    u16 powerMod = 4096;

    /*
     * Certain moves are expected to input some multipliers as part of their effect scripts:
     *  - Facade, if the user is burned/paralyzed/poisoned
     *  - Brine, if the target's current HP is half or less of its maximum (rounded down)
     *  - Venoshock and Barb Barrage, if the target is poisoned
     *  - Retaliate, if a Pokemon in the user's party fainted last turn
     *  - Fusion Flare/Bolt, if the most recently used move in the turn was the opposite move
     *  - Lash Out, if any of the attacker's stats were lowered on this turn
     *  - Solar Beam/Blade, if the weather is an active rain/sand/snow/fog effect
     *  - Knock Off, if the target is holding an item when the move is executed
     *  - Grav Apple, if Gravity is in effect
     *  - Misty Explosion, if the user is grounded on Misty Terrain
     *  - Expanding Force, if the user is grounded on Psychic Terrain
     *  - Psyblade, if the user is grounded on Electric Terrain
     * 
     * This multiplier is passed as a value which is expected to be divided by 10.
     */
    powerMod = powerMod * server->moveMultiplier;
    powerMod = DIV_ROUNDUP(powerMod, 10);

    // If the attacker is under the effect of Charge and the used move is Electric-type, 2x power.
    if ((server->activePokemon[server->attacker].moveEffectsMask & MOVE_EFFECT_CHARGED) && (moveType == TYPE_ELECTRIC)){
        powerMod = powerMod << 1;
    }

    // If the move was stolen via Me First, 1.5x power.
    if ((server->activePokemon[server->attacker].moveEffects.meFirstActive)) {
        // Turn has been taken for the calling attacker
        if (server->meFirstTotalTurnOrder == server->activePokemon[server->attacker].moveEffects.meFirstTurnCount) {
            server->activePokemon[server->attacker].moveEffects.meFirstTurnCount--;
        }

        if (server->meFirstTotalTurnOrder - server->activePokemon[server->attacker].moveEffects.meFirstTurnCount < 2) {
            powerMod = powerMod * 15;
            powerMod = DIV_ROUNDUP(powerMod, 10);
        } else {
            server->activePokemon[server->attacker].moveEffects.meFirstActive = 0;
        }
    }

    // If the attacker's ally used Helping Hand, 1.5x power.
    if (server->stFX[server->attacker].helpingHand) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    }

    // If Mud or Water Sport are in effect and the used move is Electric or Fire-type (respectively), 0.33x power.
    // TODO: These need to be moved to field conditions instead of being move effects
    if ((Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_MUD_SPORT) && (moveType == TYPE_ELECTRIC))
            || (Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_WATER_SPORT) && (moveType == TYPE_FIRE))) {
        powerMod = powerMod * 1352;
        powerMod = DIV_ROUNDUP(powerMod, 4096);
    }

    // TODO: Grounded on Electric, Grassy, or Psychic terrain

    // Time to check a bunch of abilities.
    // If the attacker's ability is Rivalry and the target is of the same gender (but not genderless), 1.25x power.
    // If the attacker's ability is Rivalry and the target is of the opposite gender (but not genderless), 0.75x power.
    if ((attackerParams->ability == ABILITY_RIVALRY)
            && (attackerParams->gender != 2)
            && (defenderParams->gender != 2)) {
        if (attackerParams->gender == defenderParams->gender) {
            powerMod = powerMod * 25;
        } else {
            powerMod = powerMod * 15;
        }

        powerMod = DIV_ROUNDUP(powerMod, 20);
    // TODO: Supreme Overlord
    } else if (FALSE) {

    // If the attacker's ability is Reckless and the used move deals recoil damage, 1.2x power.
    // This also boosts the power of Jump Kick and High Jump Kick, but explicitly excludes Struggle.
    } else if ((attackerParams->ability == ABILITY_RECKLESS) && Moves_BoostedByReckless(moveID)) {
        powerMod = powerMod * 4915;
        powerMod = DIV_ROUNDUP(powerMod, 4096);
    // If the attacker's ability is Iron Fist and the used move is classified as a punching move, 1.2x power.
    } else if ((attackerParams->ability == ABILITY_IRON_FIST) && Moves_IsPunching(moveID)) {
        powerMod = powerMod * 4915;
        powerMod = DIV_ROUNDUP(powerMod, 4096);
    // If the attacker's ability is Normalize and the used move is affected by it, 1.2x power.
    } else if ((attackerParams->ability == ABILITY_NORMALIZE) && Moves_CanNormalize(moveID)) {
        powerMod = powerMod * 4915;
        powerMod = DIV_ROUNDUP(powerMod, 4096);
    // If the move's original type was Normal and the attacker's ability is one of the -ate abilities, 1.2x power.
    } else if (typeModified) {
        if ((attackerParams->ability == ABILITY_AERILATE)
                || (attackerParams->ability == ABILITY_GALVANIZE)
                || (attackerParams->ability == ABILITY_PIXILATE)
                || (attackerParams->ability == ABILITY_REFRIGERATE)) {
            powerMod = powerMod * 4915;
            powerMod = DIV_ROUNDUP(powerMod, 4096);
        }
    // TODO: Conditions
    // If the attacker's ability is Analytic and the target has already moved this turn, 1.3x power.
    } else if (attackerParams->ability == ABILITY_ANALYTIC) {
    
    // If the attacker's ability is Sand Force, the used move is Ground/Rock/Steel-type, and the active weather
    // is an unsuppressed Sandstorm, 1.3x power.
    } else if ((attackerParams->ability == ABILITY_SAND_FORCE)
            && ((moveType == TYPE_GROUND)
                || (moveType == TYPE_ROCK)
                || (moveType == TYPE_STEEL))) {
        if ((server->fieldConditions.raw & FIELD_CONDITION_SANDSTORM)
                && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == FALSE)
                && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == FALSE)) {
            powerMod = powerMod * 5325;
            powerMod = DIV_ROUNDUP(powerMod, 4096);
        }
    // If the attacker's ability is Sheer Force and the used move has an additional effect, 1.3x power.
    } else if (attackerParams->ability == ABILITY_SHEER_FORCE) {

    // If the attacker's ability is Tough Claws and the used move makes contact, 1.3x power.
    } else if ((attackerParams->ability == ABILITY_TOUGH_CLAWS)
            && (server->aiWork.moveTable[moveID].flag & MOVE_FLAG_MAKES_CONTACT)) {
        powerMod = powerMod * 5325;
        powerMod = DIV_ROUNDUP(powerMod, 4096);
    }

    // Break here for some ally abilities
    // If the attacker's ally's ability is Power Spot, or is Battery and the used move is Special, 1.3x power.
    int partner = server->attacker + 2 % 4;
    u16 partnerAbility = BattlePokemon_Get(server, partner, BATTLE_MON_PARAM_ABILITY, NULL);
    if ((partnerAbility == ABILITY_POWER_SPOT)
            || ((partnerAbility == ABILITY_BATTERY) && (movePSS == PSS_SPECIAL))) {
        powerMod = powerMod * 5325;
        powerMod = DIV_ROUNDUP(powerMod, 4096);
    }

    // If the attacker's ability is Punk Rock and the used move is Sound-based, 1.3x power.
    // Fuck Game Freak for sticking this right here btw.
    if ((attackerParams->ability == ABILITY_PUNK_ROCK) && Moves_IsSound(moveID)) {
        powerMod = powerMod * 5325;
        powerMod = DIV_ROUNDUP(powerMod, 4096);
    }

    // TODO: Fairy Aura, Dark Aura, Aura Break

    // Now back to our regularly-scheduled exclusive if-else tree
    // If the attacker's ability is Strong Jaw and the used move is a bite, 1.5x power.
    if ((attackerParams->ability == ABILITY_STRONG_JAW) && Moves_IsBiting(moveID)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    // If the attacker's ability is Mega Launcher and the used move is affected, 1.5x power.
    } else if ((attackerParams->ability == ABILITY_MEGA_LAUNCHER) && Moves_IsAuraOrPulse(moveID)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    // If the attacker's ability is Technician and the used move's base power is 60 or less, 1.5x power.
    } else if ((attackerParams->ability == ABILITY_TECHNICIAN) && (movePower <= 60)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    // If the attacker's ability is Toxic Boost, the attacker is poisoned, and the used move is physical,
    // 1.5x power.
    } else if ((attackerParams->ability == ABILITY_TOXIC_BOOST)
            && (attackerParams->condition & CONDITION_POISON_ALL)
            && (movePSS == PSS_PHYSICAL)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    // If the attacker's ability is Flare Boost, the attacker is burned, and the used move is special,
    // 1.5x power.
    } else if ((attackerParams->ability == ABILITY_FLARE_BOOST)
            && (attackerParams->condition & CONDITION_BURNED)
            && (movePSS == PSS_SPECIAL)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    // If the attacker's ability is Steely Spirit and the used move is Steel-type, 1.5x power.
    } else if ((attackerParams->ability == ABILITY_STEELY_SPIRIT) && (moveType == TYPE_STEEL)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    }

    // Check for Steely Spirit on the partner, too.
    if ((partnerAbility == ABILITY_STEELY_SPIRIT) && (moveType == TYPE_STEEL)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    }

    // If the used move is Fire-type, check the defender for Heatproof or Dry Skin (accounting
    // for the attacker having a Mold Breaker effect).
    if (moveType == TYPE_FIRE) {
        // If the target's ability is Heatproof, 0.5x power.
        if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_HEATPROOF)) {
            powerMod = powerMod * 5;
            powerMod = DIV_ROUNDUP(powerMod, 10);
        // If the target's ability is Dry Skin, 1.25x power.
        } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_DRY_SKIN)) {
            powerMod = powerMod * 25;
            powerMod = DIV_ROUNDUP(powerMod, 20);
        }
    }

    // If the used move is a slashing move and the attacker's ability is Sharpness, 1.5x power.
    if ((attackerParams->ability == ABILITY_SHARPNESS) && Moves_IsSlashing(moveID)) {
        powerMod = powerMod * 15;
        powerMod = DIV_ROUNDUP(powerMod, 10);
    }

    // Now let's check some items. These will all be slightly inaccurate due to Platinum's paradigm
    // for how to store the power modifier for these items.
    // If the used move is Physical and the attacker is holding a Muscle Band, increase power.
    if ((attackerParams->heldItemEffect == HOLD_EFFECT_BOOST_PHYSICAL) && (movePSS == PSS_PHYSICAL)) {
        goto _BoostItem;
    // If the used move is Special and the attacker is holding Wise Glasses, increase power.
    } else if ((attackerParams->heldItemEffect == HOLD_EFFECT_BOOST_SPECIAL) && (movePSS == PSS_SPECIAL)) {
        goto _BoostItem;
    // If the attacker is holding a generic type-boosting item and the used move is of its matching
    // type, increase power.
    } else if ((attackerParams->heldItemEffect == sTypeBoostingItems[moveType])
            || (attackerParams->heldItemEffect == sTypePlates[moveType])) {
        goto _BoostItem;
    // If the attacker is one of Giratina, Dialga, Palkia, Latias, or Latios, is holding a Griseous
    // Orb, Adamant Orb, Lustrous Orb, or Soul Dew respectively, and the used move is either Dragon-type
    // or Ghost/Steel/Water/Psychic-type (respectively), increase power.
    } else if (((attackerParams->species == SPECIES_LATIAS) || (attackerParams->species == SPECIES_LATIOS))
            && (attackerParams->heldItemEffect == HOLD_EFFECT_SOUL_DEW)
            && ((moveType == TYPE_DRAGON) || (moveType == TYPE_PSYCHIC))) {
        goto _BoostItem;
    } else if ((attackerParams->species == SPECIES_DIALGA)
            && (attackerParams->heldItemEffect == HOLD_EFFECT_ADAMANT_ORB)
            && ((moveType == TYPE_DRAGON) || (moveType == TYPE_STEEL))) {
        goto _BoostItem;
    } else if ((attackerParams->species == SPECIES_PALKIA)
            && (attackerParams->heldItemEffect == HOLD_EFFECT_LUSTROUS_ORB)
            && ((moveType == TYPE_DRAGON) || (moveType == TYPE_WATER))) {
        goto _BoostItem;
    } else if ((attackerParams->species == SPECIES_GIRATINA)
            && (attackerParams->heldItemEffect == HOLD_EFFECT_GRISEOUS_ORB)
            && ((moveType == TYPE_DRAGON) || (moveType == TYPE_GHOST))) {
        goto _BoostItem;
    // If the attacker is holding a Gem and the used move is of its matching type, increase power.
    } else if (attackerParams->heldItemEffect == sGems[moveType]) {
        goto _BoostItem;
    // If the attacker is holding a Punching Glove and the used move is a punching move, increase power.
    } else if ((attackerParams->heldItemEffect == HOLD_EFFECT_BOOST_PUNCHING_MOVES) && Moves_IsPunching(moveID)) {
        goto _BoostItem;
    // None of the above items are equipped, so move along.
    } else {
        goto _AllBoostsApplied;
    }

_BoostItem:
    powerMod = powerMod * (100 + attackerParams->heldItemPower);
    powerMod = DIV_ROUNDUP(powerMod, 100);

_AllBoostsApplied:
    return powerMod;
}

inline u16 Calc_StatWithStages(u16 stat, u8 stage)
{
    u16 effective = stat * gStatModifierTable[stage][0];
    return DIV_ROUNDUP(effective, gStatModifierTable[stage][1]);
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

/*
 * This routine is responsible for calculating the base damage for a particular move, which
 * is determined using the following formula:
 * 
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
static s32 Server_CalcBaseDamage(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender
) {
    u32 attackerLevel = BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_LEVEL, NULL);
    u8  movePSS       = server->aiWork.moveTable[server->moveIDCurr].pss;  // TODO: change to new move table
    u8  moveType      = Calc_MoveType(server, attacker, server->moveIDCurr, server->moveType);
    u16 movePower     = (server->movePower == 0) ? server->aiWork.moveTable[server->moveIDCurr].power : server->movePower; // TODO: change to new move table
    movePower         = movePower * Server_CalcPowerMod(
        battle,
        server,
        attacker,
        defender,
        server->moveIDCurr,
        movePower,
        moveType,
        movePSS,
        moveType != server->moveType
    );
    movePower        = DIV_ROUNDUP(movePower, 4096);
    server->moveType = moveType;    // reassign the type from this point; we're done with any -ate checks

    /*
     * Compute the effective value for each stat in advance, *only* accounting for stages on each stat.
     *
     * We do this ahead of time so that we can apply abilities and items which further modify the
     * effective attacking stats afterwards. These are separated to account for effects which use
     * different stats, e.g. Foul Play, Body Press, etc.
     *
     * Additionally, account for the presence of a critical hit or Unaware where necessary.
     */
    u16 effectiveAttack, effectiveDefense;
    BOOL isCritical = server->critical > 1;
    BOOL attackerUnaware = attacker->ability == ABILITY_UNAWARE;
    BOOL defenderUnaware = Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_UNAWARE);
    if (server->moveIDCurr == MOVE_SHELL_SIDE_ARM) {
        // Fuck this move.
        //
        // For Shell Side Arm, we have to calculate whichever damage is higher: Physical or Special.
        // This will also change some properties of the move; Physical Shell Side Arm is considered
        // a contact move, while Special Shell Side Arm is not.
        //
        // The strategy here is to calculate the whole chain of effective attack and defense for
        // either case, then determine the ratio of each pair and use the effective stats that
        // result in a greater ratio. Unlike vanilla games, I'm choosing to implement this as
        // always preferring to be a Special move in the event of a tie.
    } else {
        // All other moves follow (mostly) normal rules. We can get an effective stat pair and then
        // chain on top of that stat pair.
        if (server->moveIDCurr == MOVE_PHOTON_GEYSER) {
            // For Photon Geyser, if the user's stage-modified Attack stat is strictly higher than its
            // stage-modified SpAttack stat, the move becomes a physical move.
            //
            // This only takes into account stat stages; abilities and items are not considered.
            // Unaware is ignored during Photon Geyser, and stat stages are always considered.
            effectiveAttack = Calc_AttackerStat(attacker->stats.attack, attacker->stages.attack, FALSE, FALSE);

            if (Calc_AttackerStat(attacker->stats.spAttack, attacker->stages.spAttack, FALSE, FALSE) >= effectiveAttack) {
                effectiveAttack  = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack,  FALSE, isCritical);
                effectiveDefense = Calc_DefenderStat(defender->stats.spDefense, defender->stages.spDefense, FALSE, isCritical);
                movePSS = PSS_SPECIAL;
            } else {
                effectiveAttack  = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.attack,  FALSE, isCritical);
                effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, FALSE, isCritical);
                movePSS = PSS_PHYSICAL;
            }
        } else if (server->moveIDCurr == MOVE_FOUL_PLAY) {
            // For Foul Play, we use the target's Attack stat and stages, but all other modifiers to
            // the effective attacking stat from the attacker.
            //
            // e.g., Foul Play damage will be scaled if the attacker has Huge Power, but does not scale
            // further if the target has Huge Power.
            //
            // Since Foul Play uses the target's Attack stat, it is wholly unaffected by a target
            // possessing Unaware.
            effectiveAttack  = Calc_AttackerStat(defender->stats.attack,  defender->stages.attack,  FALSE,           isCritical);
            effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, isCritical);
        } else if (server->moveIDCurr == MOVE_BODY_PRESS) {
            // For Body Press, we use the attacker's Defense stat and stages and then scale it with
            // all other modifiers as if that were the Attack stat.
            //
            // e.g., Body Press damage will be scaled by Huge Power, but not by Fur Coat.
            //
            // Since Body Press uses the attacker's Defense stat, it is wholly unaffected by a target
            // possessing Unaware.
            effectiveAttack  = Calc_AttackerStat(attacker->stats.defense, attacker->stages.defense, FALSE,           isCritical);
            effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, isCritical);
        } else if (server->moveIDCurr == MOVE_PSYSHOCK) {
            // For these moves, explicitly get effective Defense, no matter the split category.
            // TODO: Check a move effect, since this is shared by Psystrike and Secret Sword.
            effectiveAttack  = Calc_AttackerStat(attacker->stats.spAttack, attacker->stages.spAttack, defenderUnaware, isCritical);
            effectiveDefense = Calc_DefenderStat(defender->stats.defense,  defender->stages.defense,  attackerUnaware, isCritical);
        } else {
            // For all other moves, we can just get the effective attack and defense stats based on the
            // move's PSS category.
            if (movePSS == PSS_PHYSICAL) {
                effectiveAttack  = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.attack,  defenderUnaware, isCritical);
                effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, isCritical);
            } else {
                effectiveAttack  = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack,  defenderUnaware, isCritical);
                effectiveDefense = Calc_DefenderStat(defender->stats.spDefense, defender->stages.spDefense, attackerUnaware, isCritical);
            }
        }

        effectiveAttack  = Calc_ChainAttackingStatModifiers(battle, server, attacker, effectiveAttack,  moveType, movePSS);
        effectiveDefense = Calc_ChainDefendingStatModifiers(battle, server, defender, effectiveDefense, moveType, movePSS);
    }

    s32 damage = (2 * attackerLevel);
    damage     = DIV_ROUNDUP(damage, 5) + 2;
    damage     = damage * movePower * effectiveAttack;
    damage     = DIV_ROUNDUP(damage, effectiveDefense);
    damage     = DIV_ROUNDUP(damage, 50) + 2;              // final base damage

    return damage;
}

static u16 Calc_ChainAttackingStatModifiers(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    u16 stat,
    u8 moveType,
    u8 movePSS
) {
    u16 chainedStat = stat;

    // Check personal abilities first.
    // PSS-agnostic abilities are at the top so that we can split based on the move's
    // PSS category later if we are yet to have a match.
    if (attacker->ability == ABILITY_BLAZE) {
        // If the move is Fire-type and the user has less than or equal to 1/3 of its
        // maxmimum HP remaining, increase the attacking stat by 50%.
        if ((moveType == TYPE_FIRE) && (attacker->currHP <= (attacker->maxHP / 3))) {
            goto _IncreaseBy50P;
        }
    } else if (attacker->ability == ABILITY_OVERGROW) {
        // If the move is Grass-type and the user has less than or equal to 1/3 of its
        // maxmimum HP remaining, increase the attacking stat by 50%.
        if ((moveType == TYPE_GRASS) && (attacker->currHP <= (attacker->maxHP / 3))) {
            goto _IncreaseBy50P;
        }
    } else if (attacker->ability == ABILITY_SWARM) {
        // If the move is Bug-type and the user has less than or equal to 1/3 of its
        // maxmimum HP remaining, increase the attacking stat by 50%.
        if ((moveType == TYPE_BUG) && (attacker->currHP <= (attacker->maxHP / 3))) {
            goto _IncreaseBy50P;
        }
    } else if (attacker->ability == ABILITY_TORRENT) {
        // If the move is Water-type and the user has less than or equal to 1/3 of its
        // maxmimum HP remaining, increase the attacking stat by 50%.
        if ((moveType == TYPE_WATER) && (attacker->currHP <= (attacker->maxHP / 3))) {
            goto _IncreaseBy50P;
        }
    } else if (server->activePokemon[server->attacker].moveEffects.flashFireActive) {
        // If the move is Fire-type and the user has previously activated Flash Fire,
        // increase the attacking stat by 50%.
        if (moveType == TYPE_FIRE) {
            goto _IncreaseBy50P;
        }
    } else if (movePSS == PSS_PHYSICAL) {
        // Check for some Physical-only abilities
        if (attacker->ability == ABILITY_GUTS) {
            // If the attacker is Burned, Poisoned, Paralyzed, or Asleep, increase Attack
            // by 50%.
            if (attacker->condition & CONDITION_BOOST_GUTS) {
                goto _IncreaseBy50P;
            }
        } else if ((attacker->ability == ABILITY_HUGE_POWER)
                || (attacker->ability == ABILITY_PURE_POWER)) {
            // Double Attack.
            goto _Double;
        } else if (attacker->ability == ABILITY_HUSTLE) {
            // Increase Attack by 50%.
            goto _IncreaseBy50P;
        } else if (attacker->ability == ABILITY_ORICHALCUM_PULSE) {
            // If Sunny weather is active, increase Attack by 33%.
            // This applies even if the attacker is holding a Utility Umbrella.
            if ((Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
                    && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0)
                    && (server->fieldConditions.raw & FIELD_CONDITION_SUNNY)) {
                goto _IncreaseBy33P;
            }
        } else {
            goto _AfterAbilityChaining;
        }
    } else if (movePSS == PSS_SPECIAL) {
        // Check for some Special-only abilities
        if (attacker->ability == ABILITY_HADRON_ENGINE) {
            // If Electric Terrain is active, increase SpAttack by 33%.
            // This applies even if the attacker is not grounded.
            goto _IncreaseBy33P;
        } else if ((attacker->ability == ABILITY_PLUS) || (attacker->ability == ABILITY_MINUS)) {
            // If the attacker's partner has Plus or Minus, increase SpAttack by 50%.
            u8 partner = (server->attacker + 2) % 4;
            if ((server->activePokemon[partner].ability == ABILITY_PLUS)
                    || (server->activePokemon[partner].ability == ABILITY_MINUS)) {
                goto _IncreaseBy50P;
            }
        } else if (attacker->ability == ABILITY_SOLAR_POWER) {
            // If Sunny weather is active, increase SpAttack by 50%.
            if ((Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
                    && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0)
                    && (server->fieldConditions.raw & FIELD_CONDITION_SUNNY)) {
                goto _IncreaseBy50P;
            }
        } else {
            goto _AfterAbilityChaining;
        }
    } else {
        goto _AfterAbilityChaining;
    }

_IncreaseBy50P:
    chainedStat = chainedStat * 3;
    chainedStat = DIV_ROUNDUP(chainedStat, 2);
    goto _AfterAbilityChaining;

_Double:
    chainedStat = chainedStat * 2;
    goto _AfterAbilityChaining;

_IncreaseBy33P:
    chainedStat = chainedStat * 5461;
    chainedStat = DIV_ROUNDUP(chainedStat, 4096);

_AfterAbilityChaining:
    // One more self-ability check: Flower Gift checks for its partner but does not stack with
    // it, so it must be checked last.
    // 
    // If Sunny weather is active and at least one of the attacker or its ally has Flower
    // Gift, increase Attack by 50%. This effect ignores Utility Umbrella.
    // Vanilla technically only lets this happen on Cherrim, but that interaction is so
    // niche that no one should care. (It's more fun this way.)
    if ((movePSS == PSS_PHYSICAL)
            // Someone on our side has Flower Gift
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_ON_MY_SIDE, server->attacker, ABILITY_FLOWER_GIFT))
            // Sunny weather is active
            && (server->fieldConditions.raw & FIELD_CONDITION_SUNNY)
            // No weather-negating effects are in play
            && ((Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
                || (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0))) {
        chainedStat = chainedStat * 3;
        chainedStat = DIV_ROUNDUP(chainedStat, 2);
    }

    // We also need to check for a few abilities on the target which affect the attacking stat.
    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_THICK_FAT)) {
        if ((moveType == TYPE_FIRE) || (moveType == TYPE_ICE)) {
            chainedStat = DIV_ROUNDUP(chainedStat, 2);
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_PURIFYING_SALT)) {
        if (moveType == TYPE_GHOST) {
            chainedStat = DIV_ROUNDUP(chainedStat, 2);
        }
    }

    // Now we can actually check some items.
    if ((attacker->species == SPECIES_PIKACHU) && (attacker->heldItemEffect == HOLD_EFFECT_LIGHT_BALL)) {
        goto _IncreaseBy50P_Item;
    } else if (movePSS == PSS_PHYSICAL) {
        if (attacker->heldItemEffect == HOLD_EFFECT_CHOICE_BAND) {
            goto _IncreaseBy50P_Item;
        } else if ((attacker->heldItemEffect == HOLD_EFFECT_THICK_CLUB)
                && ((attacker->species == SPECIES_CUBONE) || (attacker->species == SPECIES_MAROWAK))) {
            goto _Double_Item;
        } else {
            goto _AfterItemChaining;
        }
    } else if (movePSS == PSS_SPECIAL) {
        if (attacker->heldItemEffect == HOLD_EFFECT_CHOICE_SPECS) {
            goto _IncreaseBy50P_Item;
        } else if ((attacker->heldItemEffect == HOLD_EFFECT_DEEP_SEA_TOOTH)
                && (attacker->species == SPECIES_CLAMPERL)) {
            goto _Double_Item;
        }
    }

_IncreaseBy50P_Item:
    chainedStat = chainedStat * 3;
    chainedStat = DIV_ROUNDUP(chainedStat, 2);
    goto _AfterItemChaining;

_Double_Item:
    chainedStat = chainedStat << 1;

_AfterItemChaining:
    return chainedStat;
}

static u16 Calc_ChainDefendingStatModifiers(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *defender,
    u16 stat,
    u8 moveType,
    u8 movePSS
) {
    u16 chainedStat = stat;

    if (movePSS == PSS_PHYSICAL) {
        if (defender->ability == ABILITY_GRASS_PELT) {
            chainedStat = chainedStat * 3;
            chainedStat = DIV_ROUNDUP(chainedStat, 2);
        } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FUR_COAT)) {
            chainedStat = chainedStat * 2;
        }

        if ((defender->heldItemEffect == HOLD_EFFECT_BOOST_DEFENSE_DITTO) && (defender->species == SPECIES_DITTO)) {
            chainedStat = chainedStat * 2;
        }
    } else if ((movePSS == PSS_SPECIAL)) {
        // The attacker does NOT have a Mold Breaker effect
        if ((server->activePokemon[server->attacker].moldBreakerShown == 0)
                // Someone on the targeted side has Flower Gift
                && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_ON_MY_SIDE, server->defender, ABILITY_FLOWER_GIFT))
                // Sunny weather is active
                && (server->fieldConditions.raw & FIELD_CONDITION_SUNNY)
                // No weather-negating effects are in play
                && ((Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
                    || (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0))) {
            chainedStat = chainedStat * 3;
            chainedStat = DIV_ROUNDUP(chainedStat, 2);
        }

        if (defender->heldItemEffect == HOLD_EFFECT_BOOST_SPD_NO_STATUS_MOVES) {
            chainedStat = chainedStat * 3;
            chainedStat = DIV_ROUNDUP(chainedStat, 2);
        } else if ((defender->heldItemEffect == HOLD_EFFECT_DEEP_SEA_SCALE) && (defender->species == SPECIES_CLAMPERL)) {
            chainedStat = chainedStat * 2;
        }
    }

    // Check Eviolite separately, since it always boosts the defensive stat
    // TODO: Pokemon_IsNFE needs to be un-stubbed for this to function.
    if ((defender->heldItemEffect == HOLD_EFFECT_EVIOLITE)
            && Pokemon_IsNFE(defender->species, server->activePokemon[server->defender].formNum)) {
        chainedStat = chainedStat * 3;
        chainedStat = DIV_ROUNDUP(chainedStat, 2);
    }

    return chainedStat;
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
    s32 damage = Server_CalcBaseDamage(battle, server, &attackerParams, &defenderParams);

    // Step 2: Multiply by 3/4 if the move has more than one target upon execution.
    u32 battleType = Battle_Type(battle);
    if ((battleType & BATTLE_TYPE_DOUBLES) && (Server_HitCount(battle, server, 0, server->defender) > 1)) {
        damage = damage * 3 / 4;
    }

    // Step 3: Divide by 4 if the move is the second-strike of Parental Bond.
    // TODO

    // Step 4: Multiply by 3/2 if the active weather is Sun or Rain and the move is Fire or Water type, respectively.
    //         Divide by 2 if the active weather is Sun or Rain and the move is Water or Fire type, respectively.
    if ((Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0)) {
        if (server->fieldConditions.raw & FIELD_CONDITION_SUNNY) {
            if (server->moveType == TYPE_FIRE) {
                damage = (damage * 3) >> 1;
            } else if (server->moveType == TYPE_WATER) {
                damage = damage >> 1;
            }
        } else if (server->fieldConditions.raw & FIELD_CONDITION_RAINING) {
            if (server->moveType == TYPE_WATER) {
                damage = (damage * 3) >> 1;
            } else if (server->moveType == TYPE_FIRE) {
                damage = damage >> 1;
            }
        }
    }

    // Step 5: Multiply by 2 if the defender used Glaive Rush last turn (or this turn) and the move does
    // not have a fixed damage value.
    // TODO

    // Step 6: Multiply by the critical hit factor.
    //  - 3/2 if the move was a critical hit
    //  - 9/4 if the move was a critical hit and the attacker has Sniper
    if (server->critical == 2) {        // Normal criticals
        damage = (damage * 3) >> 1;
    } else if (server->critical == 3) { // Sniper criticals
        damage = (damage * 9) >> 2;
    }

    // Step 7: Multiply by 3/2 if the attacker shares a type with the move.
    // TODO: Handle Soak, Forest's Curse, Trick-or-Treat.
    if ((server->moveType == attackerParams.type1) || (server->moveType || attackerParams.type2)) {
        damage = (damage * 3) >> 1;
    }

    // Step 8: Apply overall type effectiveness; multiply/divide by 2 according to each effectiveness
    // matchup of the move's type vs the defender's types.
    //
    // TODO: Forest's Curse and Trick-or-Treat add types to a Pokemon, so three types need to be checked.

    // Step 9: Divide by 2 if the attacker is burned and does not have Guts nor is using Facade.

    // Step 10: Finish up remaining modifiers, in-order:
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
