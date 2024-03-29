#include "config.h"
#include "debug.h"
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

#ifdef DEBUG_DAMAGE_CALC
static u8 *sTypeStrings[] = {
    [TYPE_NORMAL]   = "Normal",
    [TYPE_FIGHTING] = "Fighting",
    [TYPE_FLYING]   = "Flying",
    [TYPE_POISON]   = "Poison",
    [TYPE_GROUND]   = "Ground",
    [TYPE_ROCK]     = "Rock",
    [TYPE_BUG]      = "Bug",
    [TYPE_GHOST]    = "Ghost",
    [TYPE_STEEL]    = "Steel",
    [TYPE_FAIRY]    = "Fairy",
    [TYPE_FIRE]     = "Fire",
    [TYPE_WATER]    = "Water",
    [TYPE_GRASS]    = "Grass",
    [TYPE_ELECTRIC] = "Electric",
    [TYPE_PSYCHIC]  = "Psychic",
    [TYPE_ICE]      = "Ice",
    [TYPE_DRAGON]   = "Dragon",
    [TYPE_DARK]     = "Dark",
    [TYPE_NONE]     = "None",
};
#endif

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
);
static u16 Calc_ChainOffenseMods(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender,
    u16 stat,
    u8 moveType,
    u8 movePSS
);
static u16 Calc_ChainDefenseMods(
    struct Battle *battle,
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender,
    u16 stat,
    u8 moveType,
    u8 movePSS
);
static u16  Calc_BaseDamage(struct Battle *battle, struct BattleServer *server, struct CalcParams *attacker, struct CalcParams *defender);
static u16  Calc_TypeModifier(struct BattleServer *server, struct CalcParams *attacker, struct CalcParams *defender);
static BOOL Calc_ImmunityActive(struct BattleServer *server, struct CalcParams *attacker, struct CalcParams *defender, u8 moveType);
static u16  Calc_ChainOtherModifiers(struct BattleServer *server, struct CalcParams *attacker, struct CalcParams *defender, u32 battleType, u16 moveID, u8 moveType, u8 movePSS);

extern const u8 gStatModifierTable[][2];  // 0x0226EBE0
extern const u8 gCriticalRateTable[];     // 0x0226EBA0

#define __NORM     0
#define _IMMUN  0x7F
#define _NVEFF    -1
#define _SPEFF     1

/**
 * NxN matrix, modeled as an attacking type vs a defensive type. Each
 * value S in the matrix is one of the following values:
 *   -    0 -> no modifier
 *   -    1 -> attacking type is super effective
 *   -   -1 -> attacking type is not very effective
 *   - 0x7F -> defending type is immune
 * 
 * These values can be interpreted as the leftward shift to apply to
 * UQ412__1_0 for a particular matchup. e.g., if an attacking type is
 * super effective against the defending type, the type modifier becomes
 * UQ412__1_0 << 1, which is equivalent to UQ412__2_0. If the defender is
 * dual-type and its second type resists the attacking type, then the
 * final modifier would then be UQ412__2_0 >> 1, which is UQ412__1_0.
 * 
 * If the value stored is 0xFF (an immunity), then other special cases
 * need to be handled elsewhere (e.g. Scrappy, Foresight, Roost).
 *
 * This table as provided is up-to-date as of generation 9.
 */
static const s8 sTypeEffectiveness[NUM_TYPES][NUM_TYPES] = {
    // attacking type    vs:  NORM,  FIGHT, FLYING, POISON, GROUND,   ROCK,    BUG,  GHOST,  STEEL,  FAIRY,   FIRE,  WATER,  GRASS, ELECTR, PSYCHC,    ICE, DRAGON,   DARK
    [TYPE_NORMAL]       = { __NORM, __NORM, __NORM, __NORM, __NORM, _NVEFF, __NORM, _IMMUN, _NVEFF, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM },
    [TYPE_FIGHTING]     = { _SPEFF, __NORM, _NVEFF, _NVEFF, __NORM, _SPEFF, _NVEFF, _IMMUN, _SPEFF, _NVEFF, __NORM, __NORM, __NORM, __NORM, _NVEFF, _SPEFF, __NORM, _SPEFF },
    [TYPE_FLYING]       = { __NORM, _SPEFF, __NORM, __NORM, __NORM, _NVEFF, _SPEFF, __NORM, _NVEFF, __NORM, __NORM, __NORM, _SPEFF, __NORM, __NORM, __NORM, __NORM, __NORM },
    [TYPE_POISON]       = { __NORM, __NORM, __NORM, _NVEFF, _NVEFF, _NVEFF, __NORM, _NVEFF, _IMMUN, _SPEFF, __NORM, __NORM, _SPEFF, __NORM, __NORM, __NORM, __NORM, __NORM },
    [TYPE_GROUND]       = { __NORM, __NORM, _IMMUN, _SPEFF, __NORM, _SPEFF, _NVEFF, __NORM, _SPEFF, __NORM, _SPEFF, __NORM, _NVEFF, _SPEFF, __NORM, __NORM, __NORM, __NORM },
    [TYPE_ROCK]         = { __NORM, _NVEFF, _SPEFF, __NORM, _NVEFF, __NORM, _SPEFF, __NORM, _NVEFF, __NORM, _SPEFF, __NORM, __NORM, __NORM, __NORM, _SPEFF, __NORM, __NORM },
    [TYPE_BUG]          = { __NORM, _NVEFF, _NVEFF, _NVEFF, __NORM, __NORM, __NORM, _NVEFF, _NVEFF, _NVEFF, _NVEFF, __NORM, _SPEFF, __NORM, _SPEFF, __NORM, __NORM, _SPEFF },
    [TYPE_GHOST]        = { _IMMUN, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, _SPEFF, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, _SPEFF, __NORM, __NORM, _NVEFF },
    [TYPE_STEEL]        = { __NORM, __NORM, __NORM, __NORM, __NORM, _SPEFF, __NORM, __NORM, _NVEFF, _SPEFF, _NVEFF, _NVEFF, __NORM, _NVEFF, __NORM, _SPEFF, __NORM, __NORM },
    [TYPE_FAIRY]        = { __NORM, _SPEFF, __NORM, _NVEFF, __NORM, __NORM, __NORM, __NORM, _NVEFF, __NORM, _NVEFF, __NORM, __NORM, __NORM, __NORM, __NORM, _SPEFF, _SPEFF },
    [TYPE_FIRE]         = { __NORM, __NORM, __NORM, __NORM, __NORM, _NVEFF, _SPEFF, __NORM, _SPEFF, __NORM, _NVEFF, _NVEFF, _SPEFF, __NORM, __NORM, _SPEFF, _NVEFF, __NORM },
    [TYPE_WATER]        = { __NORM, __NORM, __NORM, __NORM, _SPEFF, _SPEFF, __NORM, __NORM, __NORM, __NORM, _SPEFF, _NVEFF, _NVEFF, __NORM, __NORM, __NORM, _NVEFF, __NORM },
    [TYPE_GRASS]        = { __NORM, __NORM, _NVEFF, _NVEFF, _SPEFF, _SPEFF, _NVEFF, __NORM, _NVEFF, __NORM, _NVEFF, _SPEFF, _NVEFF, __NORM, __NORM, __NORM, _NVEFF, __NORM },
    [TYPE_ELECTRIC]     = { __NORM, __NORM, _SPEFF, __NORM, _IMMUN, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, _SPEFF, _NVEFF, _NVEFF, __NORM, __NORM, _NVEFF, __NORM },
    [TYPE_PSYCHIC]      = { __NORM, _SPEFF, __NORM, _SPEFF, __NORM, __NORM, __NORM, __NORM, _NVEFF, __NORM, __NORM, __NORM, __NORM, __NORM, _NVEFF, __NORM, __NORM, _IMMUN },
    [TYPE_ICE]          = { __NORM, __NORM, _SPEFF, __NORM, _SPEFF, __NORM, __NORM, __NORM, _NVEFF, __NORM, _NVEFF, _NVEFF, _SPEFF, __NORM, __NORM, _NVEFF, _SPEFF, __NORM },
    [TYPE_DRAGON]       = { __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, _NVEFF, _IMMUN, __NORM, __NORM, __NORM, __NORM, __NORM, __NORM, _SPEFF, __NORM },
    [TYPE_DARK]         = { __NORM, _NVEFF, __NORM, __NORM, __NORM, __NORM, __NORM, _SPEFF, __NORM, _NVEFF, __NORM, __NORM, __NORM, __NORM, _SPEFF, __NORM, __NORM, _NVEFF },
};

static const u8 sTypeBoostingItems[] = {
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

static const u8 sTypePlates[] = {
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

static const u8 sGems[] = {
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

static const u8 sResistBerries[] = {
    [TYPE_NORMAL]       = HOLD_EFFECT_WEAKEN_NORMAL,
    [TYPE_FIGHTING]     = HOLD_EFFECT_WEAKEN_SE_FIGHTING,
    [TYPE_FLYING]       = HOLD_EFFECT_WEAKEN_SE_FLYING,
    [TYPE_POISON]       = HOLD_EFFECT_WEAKEN_SE_POISON,
    [TYPE_GROUND]       = HOLD_EFFECT_WEAKEN_SE_GROUND,
    [TYPE_ROCK]         = HOLD_EFFECT_WEAKEN_SE_ROCK,
    [TYPE_BUG]          = HOLD_EFFECT_WEAKEN_SE_BUG,
    [TYPE_GHOST]        = HOLD_EFFECT_WEAKEN_SE_GHOST,
    [TYPE_STEEL]        = HOLD_EFFECT_WEAKEN_SE_STEEL,
    [TYPE_FAIRY]        = HOLD_EFFECT_WEAKEN_SE_FAIRY,
    [TYPE_FIRE]         = HOLD_EFFECT_WEAKEN_SE_FIRE,
    [TYPE_WATER]        = HOLD_EFFECT_WEAKEN_SE_WATER,
    [TYPE_GRASS]        = HOLD_EFFECT_WEAKEN_SE_GRASS,
    [TYPE_ELECTRIC]     = HOLD_EFFECT_WEAKEN_SE_ELECTRIC,
    [TYPE_PSYCHIC]      = HOLD_EFFECT_WEAKEN_SE_PSYCHIC,
    [TYPE_ICE]          = HOLD_EFFECT_WEAKEN_SE_ICE,
    [TYPE_DRAGON]       = HOLD_EFFECT_WEAKEN_SE_DRAGON,
    [TYPE_DARK]         = HOLD_EFFECT_WEAKEN_SE_DARK,
};

static inline BOOL WeatherIsActive(struct Battle *battle, struct BattleServer *server, u32 weatherMask)
{
    return (server->fieldConditions.raw & weatherMask)
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE) == 0)
            && (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK) == 0);
}

static inline BOOL AllyHasAbility(struct BattleServer *server, int battler, u16 ability)
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
    return server->activePokemon[PARTNER(battler)].ability == ability;
}

// this needs to be refactored
static inline u16 Calc_StatWithStages(u16 stat, u8 stage)
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

static inline BOOL SlowStartActive(struct Battle *battle, struct BattleServer *server)
{
    return Server_Get(battle, server, SERVER_PARAM_TOTAL_TURNS, 0)
            - BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_SLOW_START_INIT_TURN, NULL)
            < 5;
}

static inline BOOL CheckResistBerry(int heldItemEffect, u8 moveType)
{
    return sResistBerries[moveType] == heldItemEffect;
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
     * Certain moves are expected to input some multipliers as part of their effect scripts, e.g.:
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
    #ifdef DEBUG_DAMAGE_CALC
    u8 buf[128];
    sprintf(buf, "[PLAT-ENGINE] Initial power mod: %d\n", powerMod);
    debugsyscall(buf);
    #endif

    // 2x if the attacker is under the effect of Charge and the used move is Electric-type.
    if ((server->activePokemon[server->attacker].moveEffectsMask & MOVE_EFFECT_FLAG_CHARGED) && (moveType == TYPE_ELECTRIC)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Charge active: 2x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__2_0);
    }

    // 1.5x if the used move was stolen via Me First.
    if ((server->activePokemon[server->attacker].moveEffects.meFirstActive)) {
        // Turn has been taken for the calling attacker
        if (server->meFirstTotalTurnOrder == server->activePokemon[server->attacker].moveEffects.meFirstTurnCount) {
            server->activePokemon[server->attacker].moveEffects.meFirstTurnCount--;
        }

        if (server->meFirstTotalTurnOrder - server->activePokemon[server->attacker].moveEffects.meFirstTurnCount < 2) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Me First active: 1.5x\n");
            debugsyscall(buf);
            #endif

            powerMod = QMul_RoundUp(powerMod, UQ412__1_5);
        }
    }

    // 1.5x if the attacker's ally used Helping Hand.
    //
    // Technically this breaks for Triple Battles if one ally uses Helping Hand
    // and another uses Instruct, but lol. lmao.
    if (server->stFX[server->attacker].helpingHand) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Helping Hand active: 1.5x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__1_5);
    }

    // 0.33x if Mud or Water Sport are in effect and the used move is Electric or Fire-type (respectively).
    // TODO: These need to be moved to field conditions instead of being move effects
    if ((Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_FLAG_MUD_SPORT) && (moveType == TYPE_ELECTRIC))
            || (Server_CheckActiveMoveEffect(battle, server, MOVE_EFFECT_FLAG_WATER_SPORT) && (moveType == TYPE_FIRE))) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Mud/Water Sport active: 0.33x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__0_33);
    }

    // TODO
    // 0.5x if Grassy Terrain is in effect and the used move is Earthquake, Magnitude, or Bulldoze.
    // 0.5x if Misty Terrain is in effect and the used move is Dragon-type.

    // TODO
    // 1.3x if Electric Terrain is in effect, the attacker is grounded, and the used move is Electric-type.
    // 1.3x if Grassy Terrain is in effect, the attacker is grounded, and the used move is Grass-type.
    // 1.3x if Psychic Terrain is in effect, the attacker is grounded, and the used move is Psychic-type.

    // ==================== START OF ABILITY CHAIN ==================== //

    // Exclusive set 1
    u16 nextMod = UQ412__1_0;
    switch (attacker->ability) {
        case ABILITY_RIVALRY:
            /*
             * 1.25x if the attacker's ability is Rivalry and the target is of the same gender.
             * 0.75x if the attacker's ability is Rivalry and the target is of the opposite gender.
             * No muliplier if either Pokemon is genderless.
             */
            if (attacker->gender == 2 || defender->gender == 2) {
                // do nothing
            } else if (attacker->gender == defender->gender) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Rivalry active, same gender: 1.25x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_25;
            } else {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Rivalry active, diff gender: 0.75x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__0_75;
            }
            break;
    
        case ABILITY_SUPREME_OVERLORD:
            /*
             * 1 + 0.1n if the attacker's ability is Supreme Overlord, where n is the number of Pokemon
             * on the attacker's party which have previously fainted.
             * 
             * TODO: Implement
             */
            break;

        case ABILITY_RECKLESS:
            /*
             * 1.2x if the attacker's ability is Reckless and the used move is applicable (deals recoil damage,
             * or is High Jump Kick or Jump Kick, but is _not_ Struggle).
             */
            if (Moves_BoostedByReckless(moveID)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Reckless active: 1.2x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_2;
            }
            break;

        case ABILITY_IRON_FIST:
            /*
             * 1.2x if the attacker's ability is Iron Fist and the used move is a punching move.
             */
            if (Moves_IsPunching(moveID)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Iron Fist active: 1.2x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_2;
            }
            break;

        case ABILITY_NORMALIZE:
            /*
             * 1.2x if the attacker's ability is Normalize and the used move is affected.
             */
            if (Moves_CanNormalize(moveID)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Normalize active: 1.2x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_2;
            }
            break;

        case ABILITY_AERILATE:
        case ABILITY_GALVANIZE:
        case ABILITY_PIXILATE:
        case ABILITY_REFRIGERATE:
            /*
             * 1.2x if the attacker's ability is an -ate ability and the move's type was altered.
             */
            if (isAteAbility) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- -ate ability active: 1.2x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_2;
            }
            break;

        case ABILITY_ANALYTIC:
            /*
             * 1.3x if the attacker's ability is Analytic and it moves last in turn order.
             *
             * TODO: Implement
             */
            break;

        case ABILITY_SAND_FORCE:
            /*
             * 1.3x if the attacker's ability is Sand Force, the weather is sandstorm, and the used
             * move is Ground-, Rock-, or Steel-type.
             */
            if (WeatherIsActive(battle, server, FIELD_CONDITION_SANDSTORM)
                    && (moveType == TYPE_GROUND || moveType == TYPE_ROCK || moveType == TYPE_STEEL)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Sand Force active: 1.3x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_3;
            }
            break;

        case ABILITY_SHEER_FORCE:
            /*
             * 1.3x if the attacker's ability is Sheer Force and the used move has an additional effect.
             *
             * TODO: Implement
             */
            break;

        case ABILITY_TOUGH_CLAWS:
            /*
             * 1.3x if the attacker's ability is Tough Claws and the used move makes contact.
             */
            if (server->aiWork.moveTable[moveID].flag & MOVE_FLAG_MAKES_CONTACT) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Tough Claws active: 1.3x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_3;
            }
            break;

        default:
            break;
    }
    powerMod = QMul_RoundUp(powerMod, nextMod);

    // Battery and Power Spot are not technically exclusive in the scope of Triple Battles,
    // but they are mutually exclusive in doubles.
    if (AllyHasAbility(server, server->attacker, ABILITY_BATTERY) && movePSS == PSS_SPECIAL) {
        // 1.3x if our ally has Battery and the used move is Special-split.
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Battery active: 1.3x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__1_3);
    } else if (AllyHasAbility(server, server->attacker, ABILITY_POWER_SPOT)) {
        // 1.3x if our ally has Power Spot.
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Power Spot active: 1.2x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__1_3);
    }

    if (attacker->ability == ABILITY_PUNK_ROCK && Moves_IsSound(moveID)) {
        // 1.3x if the attacker's ability is Punk Rock and the used move is sound-based.
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Punk Rock active: 1.3x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__1_3);
    }

    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_FAIRY_AURA)
            && (moveType == TYPE_FAIRY)
            && (attacker->ability != ABILITY_MOLD_BREAKER)
            && (attacker->ability != ABILITY_TERAVOLT)
            && (attacker->ability != ABILITY_TURBOBLAZE)) {
        // 1.33x if Fairy Aura is in effect, the used move is Fairy-type, and the attacker's ability is not
        // Mold Breaker. If Aura Break is also in effect, instead 0.75x.
        if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AURA_BREAK)) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Fairy Aura broken: 0.75x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__0_75;
        } else {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Fairy Aura active: 1.33x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__1_33;
        }

        powerMod = QMul_RoundUp(powerMod, nextMod);
    }

    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_DARK_AURA)
            && (moveType == TYPE_DARK)
            && (attacker->ability != ABILITY_MOLD_BREAKER)
            && (attacker->ability != ABILITY_TERAVOLT)
            && (attacker->ability != ABILITY_TURBOBLAZE)) {
        // 1.33x if Dark Aura is in effect, the used move is Dark-type, and the attacker's ability is not
        // Mold Breaker. If Aura Break is also in effect, instead 0.75x.
        if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AURA_BREAK)) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Dark Aura broken: 1.33x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__0_75;
        } else {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Dark Aura active: 1.33x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__1_33;
        }
        
        powerMod = QMul_RoundUp(powerMod, nextMod);
    }

    // exclusive set 2
    nextMod = UQ412__1_0;
    switch (attacker->ability) {
        case ABILITY_STRONG_JAW:
            /*
             * 1.5x if the attacker's ability is Strong Jaw and the used move is a biting move.
             */
            if (Moves_IsBiting(moveID)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Strong Jaw active: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;
        case ABILITY_MEGA_LAUNCHER:
            /*
             * 1.5x if the attacker's ability is Mega Launcher and the used move is Aura or
             * Pulse-based.
             */
            if (Moves_IsAuraOrPulse(moveID)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Mega Launcher active: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_TECHNICIAN:
            /*
             * 1.5x if the attacker's ability is Technician, the used move's power is less than or
             * equal to 60, and the used move is _not_ Struggle.
             */
            if (movePower <= 60 && moveID != MOVE_STRUGGLE) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Technician active: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_TOXIC_BOOST:
            /*
             * 1.5x if the attacker's ability is Toxic Boost, the used move is Physical, and the
             * attacker is poisoned.
             */
            if (movePSS == PSS_PHYSICAL && (attacker->condition & CONDITION_POISON_ALL)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Toxic Boost active: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_FLARE_BOOST:
            /*
             * 1.5x if the attacker's ability is Flare Boost, the used move is Special, and the
             * attacker is burned.
             */
            if (movePSS == PSS_SPECIAL && (attacker->condition & CONDITION_BURNED)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Flare Boost active: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_STEELY_SPIRIT:
            /*
             * 1.5x if the attacker's ability is Steely Spirit and the used move is Steel-type.
             */
            if (moveType == TYPE_STEEL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Self Steely Spirit active: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        default:
            break;
    }
    powerMod = QMul_RoundUp(powerMod, nextMod);

    if (AllyHasAbility(server, server->attacker, ABILITY_STEELY_SPIRIT)
            && moveType == TYPE_STEEL) {
        // 1.5x if the attacker's ally has Steely Spirit and the used move is Steel-type.
        // Note that this modifier stacks with the attacker itself having Steely Spirit.
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Ally Steely Spirit active: 1.5x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__1_5);
    }

    if (moveType == TYPE_FIRE) {
        if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_HEATPROOF)) {
            // 0.5x if the target's ability is Heatproof, the used move is Fire-type, and the
            // target's ability is not ignored.
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Opp has Heatproof: 0.5x\n");
            debugsyscall(buf);
            #endif

            powerMod = QMul_RoundUp(powerMod, UQ412__0_5);
        } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_DRY_SKIN)) {
            // 1.25x if the target's ability is Dry Skin, the used move is Fire-type, and the
            // target's ability is not ignored.
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Opp has Dry Skin: 1.25x\n");
            debugsyscall(buf);
            #endif

            powerMod = QMul_RoundUp(powerMod, UQ412__1_25);
        }
    }

    if (attacker->ability == ABILITY_SHARPNESS && Moves_IsSlashing(moveID)) {
        // 1.5x if the attacker's ability is Sharpness and the used move is slashing-based.
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Sharpness active: 1.5x\n");
        debugsyscall(buf);
        #endif

        powerMod = QMul_RoundUp(powerMod, UQ412__1_5);
    }

    // ==================== END OF ABILITY CHAIN ==================== //
    // ==================== START OF ITEM CHECKS ==================== //

    // these are easily defined in a switch
    u16 tableLookup = UQ412__1_0;
    switch (attacker->heldItemEffect) {
        case HOLD_EFFECT_MUSCLE_BAND:
            if (movePSS == PSS_PHYSICAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Muscle Band active: 1.1x\n");
                debugsyscall(buf);
                #endif

                goto LookupItemPower;
            }
            goto SkipLookupItemPower;

        case HOLD_EFFECT_WISE_GLASSES:
            if (movePSS == PSS_SPECIAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Wise Glasses active: 1.1x\n");
                debugsyscall(buf);
                #endif

                goto LookupItemPower;
            }
            goto SkipLookupItemPower;

        case HOLD_EFFECT_ADAMANT_ORB:
            if (attacker->species == SPECIES_DIALGA
                    && (moveType == TYPE_DRAGON || moveType == TYPE_STEEL)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Adamant Orb active: 1.2x\n");
                debugsyscall(buf);
                #endif

                goto LookupItemPower;
            }
            goto SkipLookupItemPower;

        case HOLD_EFFECT_LUSTROUS_ORB:
            if (attacker->species == SPECIES_PALKIA
                    && (moveType == TYPE_DRAGON || moveType == TYPE_WATER)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Lustrous Orb active: 1.2x\n");
                debugsyscall(buf);
                #endif

                goto LookupItemPower;
            }
            goto SkipLookupItemPower;

        case HOLD_EFFECT_GRISEOUS_ORB:
            if (attacker->species == SPECIES_GIRATINA
                    && (moveType == TYPE_DRAGON || moveType == TYPE_GHOST)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Griseous Orb active: 1.2x\n");
                debugsyscall(buf);
                #endif

                goto LookupItemPower;
            }
            goto SkipLookupItemPower;

        case HOLD_EFFECT_SOUL_DEW:
            if ((attacker->species == SPECIES_LATIAS || attacker->species == SPECIES_LATIOS)
                    && (moveType == TYPE_DRAGON || moveType == TYPE_PSYCHIC)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Soul Dew active: 1.2x\n");
                debugsyscall(buf);
                #endif

                goto LookupItemPower;
            }
            goto SkipLookupItemPower;

        case HOLD_EFFECT_BOOST_PUNCHING_MOVES:
            if (Moves_IsPunching(moveID)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] -- Punching Glove active: 1.1x\n");
                debugsyscall(buf);
                #endif

                goto LookupItemPower;
            }
            goto SkipLookupItemPower;

        default:
            break;
    }

    // Check the tables for type-boosting items and Gems
    if (sTypeBoostingItems[moveType] == attacker->heldItemEffect
            || sTypePlates[moveType] == attacker->heldItemEffect) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Type Item active: 1.2x\n");
        debugsyscall(buf);
        #endif

        goto LookupItemPower;
    } else if (sGems[moveType] == attacker->heldItemEffect) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Type Gem active: 1.5x\n");
        debugsyscall(buf);
        #endif

        goto LookupItemPower;
    }

    goto SkipLookupItemPower;

LookupItemPower:
    tableLookup = UQ412__1_0 + QPercent(attacker->heldItemPower);
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Item lookup modifier: %d\n", tableLookup);
    debugsyscall(buf);
    #endif

SkipLookupItemPower:
    powerMod = QMul_RoundUp(powerMod, tableLookup);

    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] Final power modifier: %d\n\n", powerMod);
    debugsyscall(buf);
    #endif

    u32 modifiedPower = QMul_RoundDown(movePower, powerMod);
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
    BOOL isAteAbility  = FALSE;

    if (moveBasePower == 0) {
        moveBasePower = server->aiWork.moveTable[moveID].power;
    }

    switch (attacker->ability) {
        case ABILITY_NORMALIZE:
            if (Moves_CanNormalize(moveID)) {
                moveType = TYPE_NORMAL;
            }
            break;

        case ABILITY_AERILATE:
            if (moveType == TYPE_NORMAL) {
                moveType = TYPE_FLYING;
                isAteAbility = TRUE;
            }
            break;

        case ABILITY_GALVANIZE:
            if (moveType == TYPE_NORMAL) {
                moveType = TYPE_ELECTRIC;
                isAteAbility = TRUE;
            }
            break;

        case ABILITY_PIXILATE:
            if (moveType == TYPE_NORMAL) {
                moveType = TYPE_FAIRY;
                isAteAbility = TRUE;
            }
            break;

        case ABILITY_REFRIGERATE:
            if (moveType == TYPE_NORMAL) {
                moveType = TYPE_ICE;
                isAteAbility = TRUE;
            }
            break;

        case ABILITY_LIQUID_VOICE:
            if (moveType == TYPE_NORMAL && Moves_IsSound(moveID)) {
                moveType = TYPE_WATER;
            }
            break;

        default:
            if (moveType == TYPE_NORMAL) {
                moveType = server->aiWork.moveTable[moveID].type;
            }
            break;
    }
    server->moveType = moveType;

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
    #ifdef DEBUG_DAMAGE_CALC
    u8 buf[128];
    sprintf(buf, "[PLAT-ENGINE] Modified base power: %d\n", modifiedBasePower);
    debugsyscall(buf);
    #endif

    // Treat Shell Side Arm moves differently
    if (moveID == MOVE_SHELL_SIDE_ARM) {
        return 0;
    }

    // Compute the effective offensive + defensive stats
    // Some moves alter this process slightly
    u16 effectiveOffense, effectiveDefense;
    BOOL attackerUnaware = attacker->ability == ABILITY_UNAWARE;
    BOOL defenderUnaware = Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_UNAWARE);
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
            effectiveOffense = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.attack,  FALSE, server->critical);
            effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, FALSE, server->critical);
            movePSS = PSS_PHYSICAL;
        } else {
            effectiveOffense = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack,  FALSE, server->critical);
            effectiveDefense = Calc_DefenderStat(defender->stats.spDefense, defender->stages.spDefense, FALSE, server->critical);
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
        effectiveOffense = Calc_AttackerStat(attacker->stats.defense, attacker->stages.defense, FALSE,           server->critical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, server->critical);
    } else if (moveID == MOVE_FOUL_PLAY) {
        /*
         * When calculating damage, Foul Play uses the target's Attack stat instead of its
         * user's Attack stat. The target's Attack stat-stage modifiers are applied (rather
         * than the user's), but the user's Attack modifiers are used thereafter.
         * 
         * Since the target's Attack stat is used for calculating damage, Foul Play does
         * not consider Unaware when calculating the offensive stat.
         */
        effectiveOffense = Calc_AttackerStat(defender->stats.defense, defender->stages.defense, FALSE,           server->critical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, server->critical);
    } else if ((moveID == MOVE_PSYSHOCK)
            || (moveID == MOVE_PSYSTRIKE)
            || (moveID == MOVE_SECRET_SWORD)) {
        /*
         * Moves with this effect use the target's Defense stat instead of its Special
         * Defense stat during damage calculation. The move, however, still deals Special
         * damage.
         */
        effectiveOffense = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack, defenderUnaware, server->critical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense,   defender->stages.defense,  attackerUnaware, server->critical);
    } else if (moveID == MOVE_SACRED_SWORD) {
        /*
         * When calculating damage, Sacred Sword ignores the target's Defense stat stages.
         */
        effectiveOffense = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.defense, defenderUnaware, server->critical);
        effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, TRUE,            server->critical);
    } else {
        /*
         * All other moves determine offensive/defensive stats depending on the PSS-split.
         */
        if (movePSS == PSS_PHYSICAL) {
            effectiveOffense = Calc_AttackerStat(attacker->stats.attack,  attacker->stages.attack,  defenderUnaware, server->critical);
            effectiveDefense = Calc_DefenderStat(defender->stats.defense, defender->stages.defense, attackerUnaware, server->critical);
        } else {
            effectiveOffense = Calc_AttackerStat(attacker->stats.spAttack,  attacker->stages.spAttack,  defenderUnaware, server->critical);
            effectiveDefense = Calc_DefenderStat(defender->stats.spDefense, defender->stages.spDefense, attackerUnaware, server->critical);
        }
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] A/D Stats:\n");
        debugsyscall(buf);
        sprintf(buf, "[PLAT-ENGINE] -- Attack:  %d\n", effectiveOffense);
        debugsyscall(buf);
        sprintf(buf, "[PLAT-ENGINE] -- Defense: %d\n", effectiveDefense);
        debugsyscall(buf);
        #endif
    }

    // Unlike all other offensive modifiers, Hustle is applied directly to the 
    // Attack stat.
    if (attacker->ability == ABILITY_HUSTLE && movePSS == PSS_PHYSICAL) {
        effectiveOffense = QMul_RoundDown(effectiveOffense, UQ412__1_5);
    }

    // Unlike all other defensive modifiers, Sandstorm SpD boost gets applied
    // directly.
    // Note: this is also where Snow's Def boost for Ice-types goes.
    if (WeatherIsActive(battle, server, MOVE_SANDSTORM)
            && ((defender->type1 == TYPE_ROCK) || (defender->type2 == TYPE_ROCK))
            && (movePSS == PSS_SPECIAL)) {
        effectiveDefense = QMul_RoundDown(effectiveDefense, UQ412__1_5);
    }

    // Other stat modifiers are applied as a chain.
    effectiveOffense = Calc_ChainOffenseMods(battle, server, attacker, defender, effectiveOffense, moveType, movePSS);
    effectiveDefense = Calc_ChainDefenseMods(battle, server, attacker, defender, effectiveDefense, moveType, movePSS);

    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Attack w/Mods:  %d\n", effectiveOffense);
    debugsyscall(buf);
    sprintf(buf, "[PLAT-ENGINE] -- Defense w/Mods: %d\n\n", effectiveDefense);
    debugsyscall(buf);
    #endif

    // All of these divisions are integer-division.
    s32 baseDamage = 2 * BattlePokemon_Get(server, server->attacker, BATTLE_MON_PARAM_LEVEL, NULL);

    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] Base Damage Calcs:\n");
    debugsyscall(buf);
    sprintf(buf, "[PLAT-ENGINE] -- Level x 2:       %ld\n", baseDamage);
    debugsyscall(buf);
    #endif

    baseDamage = baseDamage / 5 + 2;
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Div by 5, + 2:   %ld\n", baseDamage);
    debugsyscall(buf);
    #endif

    baseDamage = baseDamage * modifiedBasePower;
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Mul by BP:       %ld\n", baseDamage);
    debugsyscall(buf);
    #endif

    baseDamage = baseDamage * effectiveOffense;
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Mul by Attack:   %ld\n", baseDamage);
    debugsyscall(buf);
    #endif

    baseDamage = baseDamage / effectiveDefense;
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Div by Defense:  %ld\n", baseDamage);
    debugsyscall(buf);
    #endif

    baseDamage = baseDamage / 50 + 2;
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Div by 50, + 2:  %ld\n\n", baseDamage);
    debugsyscall(buf);
    #endif

    return baseDamage;
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
    u16 nextMod = UQ412__1_0;
    #ifdef DEBUG_DAMAGE_CALC
    u8 buf[128];
    sprintf(buf, "[PLAT-ENGINE] -- Offense Mods Chain:\n");
    debugsyscall(buf);
    #endif

    switch (attacker->ability) {
        case ABILITY_SLOW_START:
            /*
             * Halves the Attack stat during the first five turns that a Pokemon
             * is in battle.
             */
            if (movePSS == PSS_PHYSICAL && SlowStartActive(battle, server)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Slow Start: 0.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__0_5;
            }
            break;

        case ABILITY_DEFEATIST:
            /*
             * Halves all offensive stats when the attacker's HP is less than or
             * equal to half of its maximum.
             */
            if (attacker->currHP <= (attacker->maxHP / 2)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Defeatist: 0.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__0_5;
            }
            break;

        case ABILITY_SOLAR_POWER:
            /*
             * Increases Special Attack by 50% during harsh sunlight.
             */
            if (movePSS == PSS_SPECIAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Solar Power: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_FLOWER_GIFT:
            /*
             * Increases Attack by 50% during harsh sunlight.
             */
            if (movePSS == PSS_PHYSICAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Flower Gift (self): 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            // Flower Gift does not stack with itself if both the attacker and an ally have it.
            goto SkipAllyFlowerGift;

        case ABILITY_GORILLA_TACTICS:
            /*
             * Increases Attack by 50%.
             */
            if (movePSS == PSS_PHYSICAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Gorilla Tactics: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;
        
        case ABILITY_GUTS:
            /*
             * Increases Attack by 50% if the attacker is statused (but not frozen).
             */
            if (movePSS == PSS_PHYSICAL && (attacker->condition & ~CONDITION_FROZEN)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Guts: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_BLAZE:
            /*
             * Increases all offensive stats by 50% if the attacker's HP is less
             * than or equal to 1/3 of its maximum and the used move is Fire-type.
             */
            if (moveType == TYPE_FIRE && (attacker->currHP < (attacker->maxHP / 3))) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Blaze: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_OVERGROW:
            /*
             * Increases all offensive stats by 50% if the attacker's HP is less
             * than or equal to 1/3 of its maximum and the used move is Grass-type.
             */
            if (moveType == TYPE_GRASS && (attacker->currHP < (attacker->maxHP / 3))) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Overgrow: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_SWARM:
            /*
             * Increases all offensive stats by 50% if the attacker's HP is less
             * than or equal to 1/3 of its maximum and the used move is Bug-type.
             */
            if (moveType == TYPE_BUG && (attacker->currHP < (attacker->maxHP / 3))) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Swarm: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_TORRENT:
            /*
             * Increases all offensive stats by 50% if the attacker's HP is less
             * than or equal to 1/3 of its maximum and the used move is Water-type.
             */
            if (moveType == TYPE_WATER && (attacker->currHP < (attacker->maxHP / 3))) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Torrent: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_FLASH_FIRE:
            /*
             * Increases all offensive stats by 50% if the attacker previously
             * activated Flash Fire and the used move is Fire-type.
             */
            if (moveType == TYPE_FIRE
                    && server->activePokemon[server->attacker].moveEffects.flashFireActive) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Flash Fire: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_STEELWORKER:
            /*
             * Increases all offensive stats by 50% if the used move is Steel-type.
             */
            if (moveType == TYPE_STEEL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Steelworker: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_DRAGONS_MAW:
            /*
             * Increases all offensive stats by 50% if the used move is Dragon-type.
             */
            if (moveType == TYPE_DRAGON) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Dragon's Maw: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_ROCKY_PAYLOAD:
            /*
             * Increases all offensive stats by 50% if the used move is Rock-type.
             */
            if (moveType == TYPE_ROCK) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Solar Power: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case ABILITY_TRANSISTOR:
            /*
             * Increases all offensive stats by 30% if the used move is Electric-type.
             */
            if (moveType == TYPE_ELECTRIC) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Transistor: 1.3x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_3;
            }
            break;

        case ABILITY_STAKEOUT:
            /*
             * Doubles all offensive stats if the target switched in this turn.
             *
             * TODO: Implement.
             */
            break;

        case ABILITY_WATER_BUBBLE:
            /*
             * Doubles all offensive stats if the used move is Water-type.
             */
            if (moveType == TYPE_WATER) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Water Bubble (self): 2.0x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__2_0;
            }
            break;

        case ABILITY_PURE_POWER:
            // fallthrough
        case ABILITY_HUGE_POWER:
            /*
             * Doubles Attack.
             */
            if (movePSS == PSS_PHYSICAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Huge Power: 2.0x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__2_0;
            }
            break;
        
        case ABILITY_PROTOSYNTHESIS:
            // fallthrough
        case ABILITY_QUARK_DRIVE:
            /*
             * Increases the highest stat by 30% (if an attacking stat).
             *
             * TODO: Implement.
             */
            break;
        
        case ABILITY_HADRON_ENGINE:
            /*
             * Increases Special Attack by 33% on Electric Terrain.
             *
             * TODO: Terrain implementation.
             */
            break;

        case ABILITY_ORICHALCUM_PULSE:
            /*
             * Increases Attack by 33% in harsh sunlight.
             */
            if (movePSS == PSS_PHYSICAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Orichalcum Pulse: 1.3333x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_3333;
            }
            break;

        default:
            break;
    }

    if (AllyHasAbility(server, server->attacker, ABILITY_FLOWER_GIFT)) {
        if (movePSS == PSS_PHYSICAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Flower Gift (ally): 1.5x\n");
            debugsyscall(buf);
            #endif

            statMod = QMul_RoundUp(statMod, nextMod);   // Apply the previous modifier before stacking ally Flower Gift
            nextMod = UQ412__1_5;
        }
    }

SkipAllyFlowerGift:
    statMod = QMul_RoundUp(statMod, nextMod);

CheckDefenderAbility:
    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_THICK_FAT)) {
        // Halves the attacking stats if the used move is Fire- or Ice-type.
        if (moveType == TYPE_FIRE || moveType == TYPE_ICE) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Thick Fat: 0.5x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__0_5;
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_WATER_BUBBLE)) {
        // Halves the attacking stats if the used move is Fire-type.
        if (moveType == TYPE_FIRE) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Water Bubble (target): 0.5x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__0_5;
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_PURIFYING_SALT)) {
        // Halves the attacking stats if the used move is Ghost-type.
        if (moveType == TYPE_GHOST) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Purifying Salt: 0.5x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__0_5;
        }
    }
    statMod = QMul_RoundUp(statMod, nextMod);

CheckRuinEffects: 
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->attacker, ABILITY_TABLETS_OF_RUIN)) {
        /*
         * Decreases the Attack stat of all Pokemon on the field other than the ability
         * bearer by 25%. Does not apply if the attacker also has Tablets of Ruin.
         */
        if (attacker->ability != ABILITY_TABLETS_OF_RUIN && movePSS == PSS_PHYSICAL) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Tablets of Ruin: 0.75x\n");
            debugsyscall(buf);
            #endif

            statMod = QMul_RoundUp(statMod, UQ412__0_75);
        }
    }
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->attacker, ABILITY_VESSEL_OF_RUIN)) {
        /*
         * Decreases the SpAttack stat of all Pokemon on the field other than the ability
         * bearer by 25%. Does not apply if the attacker also has Vessel of Ruin.
         */
        if (attacker->ability != ABILITY_VESSEL_OF_RUIN && movePSS == PSS_SPECIAL) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Vessel of Ruin: 0.75x\n");
            debugsyscall(buf);
            #endif

            statMod = QMul_RoundUp(statMod, UQ412__0_75);
        }
    }

CheckItems:
    nextMod = UQ412__1_0;
    switch (attacker->heldItemEffect) {
        case HOLD_EFFECT_THICK_CLUB:
            /*
             * Doubles the Attack of Cubone and Marowak.
             */
            if (movePSS == PSS_PHYSICAL
                    && (attacker->species == SPECIES_CUBONE || attacker->species == SPECIES_MAROWAK)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Thick Club: 2.0x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__2_0;
            }
            break;

        case HOLD_EFFECT_DEEP_SEA_TOOTH:
            /*
             * Doubles the Special Attack of Clamperl.
             */
            if (movePSS == PSS_SPECIAL && attacker->species == SPECIES_CLAMPERL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Deep Sea Tooth: 2.0x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__2_0;
            }
            break;

        case HOLD_EFFECT_LIGHT_BALL:
            /*
             * Doubles the offensive stats of Pikachu.
             */
            if (attacker->species == SPECIES_PIKACHU) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Light Ball: 2.0x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__2_0;
            }
            break;

        case HOLD_EFFECT_CHOICE_BAND:
            /*
             * Increases the Attack stat by 50%.
             */
            if (movePSS == PSS_PHYSICAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Choice Band: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        case HOLD_EFFECT_CHOICE_SPECS:
            /*
             * Increases the Special Attack stat by 50%.
             */
            if (movePSS == PSS_SPECIAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Choice Specs: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        default:
            break;
    }
    statMod = QMul_RoundUp(statMod, nextMod);
    
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Final Offense Mod: %d\n\n", statMod);
    debugsyscall(buf);
    #endif

    return QMul_RoundDown(stat, statMod);
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
    u16 nextMod = UQ412__1_0;
    #ifdef DEBUG_DAMAGE_CALC
    u8 buf[128];
    sprintf(buf, "[PLAT-ENGINE] -- Defense Mods Chain:\n");
    debugsyscall(buf);
    #endif

    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_MARVEL_SCALE)) {
        /*
         * Increases Defense by 50% if the defender is statused.
         */
        if (defender->condition && movePSS == PSS_PHYSICAL) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Marvel Scale: 1.5x\n");
            debugsyscall(buf);
            #endif

            nextMod = UQ412__1_5;
        }
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FLOWER_GIFT)) {
        /*
         * Increases Special Defense by 50% during harsh sunlight.
         */
        if (movePSS == PSS_SPECIAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Flower Gift (self): 1.5x\n");
            debugsyscall(buf);
            #endif
            
            nextMod = UQ412__1_5;
        }

        // Flower Gift does not stack with itself, so skip ahead.
        goto CheckDefensiveRuins;
    } else if (defender->ability == ABILITY_GRASS_PELT) {
        /*
         * Increases Defense by 50% while Grassy Terrain is active. Not ignorable.
         *
         * TODO: Terrain implementation.
         */
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FUR_COAT)) {
        /*
         * Doubles Defense.
         */
        if (movePSS == PSS_PHYSICAL) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Fur Coat: 2.0x\n");
            debugsyscall(buf);
            #endif
            
            nextMod = UQ412__2_0;
        }
    }

    if (Server_CheckDefenderAbility(server, server->attacker, PARTNER(server->defender), ABILITY_FLOWER_GIFT)) {
        // Flower Gift increases ally's SpDefense by 50% during harsh sunlight.
        if (movePSS == PSS_SPECIAL && WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Flower Gift (ally): 1.5x\n");
            debugsyscall(buf);
            #endif

            statMod = QMul_RoundUp(statMod, nextMod);
            nextMod = UQ412__1_5;
        }
    }

CheckDefensiveRuins:
    statMod = QMul_RoundUp(statMod, nextMod);
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->defender, ABILITY_SWORD_OF_RUIN)) {
        /*
         * Decreases the Defense stat of all Pokemon on the field other than the
         * ability's bearer by 25%. Ignored if the Defender also has Sword of Ruin.
         */
        if (defender->ability != ABILITY_SWORD_OF_RUIN && movePSS == PSS_PHYSICAL) {
            #ifdef DEBUG_DAMAGE_CALC
            u8 buf[128];
            sprintf(buf, "[PLAT-ENGINE] ---- Sword of Ruin: 0.75x\n");
            debugsyscall(buf);
            #endif

            statMod = QMul_RoundUp(statMod, UQ412__0_75);
        }
    }
    if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE_NOT_MINE, server->defender, ABILITY_BEADS_OF_RUIN)) {
        /*
         * Decreases the SpDefense stat of all Pokemon on the field other than the
         * ability's bearer by 25%. Ignored if the Defender also has Beads of Ruin.
         */
        if (defender->ability != ABILITY_BEADS_OF_RUIN && movePSS == PSS_SPECIAL) {
            #ifdef DEBUG_DAMAGE_CALC
            u8 buf[128];
            sprintf(buf, "[PLAT-ENGINE] ---- Beads of Ruin: 0.75x\n");
            debugsyscall(buf);
            #endif

            statMod = QMul_RoundUp(statMod, UQ412__0_75);
        }
    }

    // TODO: Protosynthesis, Quark Drive

CheckDefensiveItems:
    nextMod = UQ412__1_0;

    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Checking defender's item: %d\n", defender->heldItemEffect);
    debugsyscall(buf);
    #endif
    switch (defender->heldItemEffect) {
        case HOLD_EFFECT_METAL_POWDER:
            /*
             * Doubles the Defense of Ditto.
             */
            if (defender->species == SPECIES_DITTO && movePSS == PSS_PHYSICAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Metal Powder: 2.0x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__2_0;
            }
            break;

        case HOLD_EFFECT_DEEP_SEA_SCALE:
            /*
             * Doubles the Special Defense of Clamperl.
             */
            if (defender->species == SPECIES_CLAMPERL && movePSS == PSS_SPECIAL) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Deep Sea Scale: 2.0x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__2_0;
            }
            break;

        case HOLD_EFFECT_EVIOLITE:
            /*
             * Increases all defensive stats by 50% if the defender is not
             * fully-evolved.
             */
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Eviolite found\n");
            debugsyscall(buf);
            #endif

            if (Pokemon_IsNFE(defender->species, server->activePokemon[server->defender].formNum)) {
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Eviolite: 1.5x\n");
                debugsyscall(buf);
                #endif

                nextMod = UQ412__1_5;
            }
            break;

        default:
            break;
    }
    statMod = QMul_RoundUp(statMod, nextMod);

    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Final Defense Mod: %d\n\n", statMod);
    debugsyscall(buf);
    #endif

    return QMul_RoundDown(stat, statMod);
}

/**
 * @brief Calculates the type-effectiveness modifier.
 * 
 * @param server 
 * @param attacker 
 * @param defender 
 * @return u16 
 */
static u16 Calc_TypeModifier(struct BattleServer *server, struct CalcParams *attacker, struct CalcParams *defender)
{
    #ifdef DEBUG_DAMAGE_CALC
    u8 buf[128];
    sprintf(buf, "[PLAT-ENGINE] Type Modifier:\n");
    debugsyscall(buf);
    #endif 

    // Ground can have additional immunities ahead of typing:
    //  - Levitate
    //  - Magnet Rise
    //  - TODO: Air Balloon
    //  - TODO: Telekinesis
    // Effects that break Ground-type immunities also break these.
    if (server->moveType == TYPE_GROUND
            && !Calc_ImmunityActive(server, attacker, defender, TYPE_GROUND)) {
        if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_LEVITATE)) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Defender has Levitate\n");
            debugsyscall(buf);
            #endif

            server->moveStatusFlag = server->moveStatusFlag | MOVE_STATUS_FLAG_MISSED_BY_ABILITY;
        } else if (server->activePokemon[server->defender].moveEffects.magnetRiseTurns) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Defender has Magnet Rise\n");
            debugsyscall(buf);
            #endif

            server->moveStatusFlag = server->moveStatusFlag | MOVE_STATUS_FLAG_MISSED_BY_MAGNET_RISE;
        }

        return 0;
    }

    // TODO: Check for Burn Up, Double Shock on these types
    // TODO: Forest's Curse, Trick-or-Treat
    u8 type1 = defender->type1;
    u8 type2 = defender->type2;

    // If the defending Pokemon is Roosting, ignore its Flying type for the purpose of type-checks.
    // This is subject to the following rules:
    //   - If the Pokemon is mono-Flying, then it should be treated as Normal type.
    //   - If the Pokemon is a dual-typing that lost its other type due to some effect (e.g.,
    //     a Fire/Flying-type which previously used Burn Up), then it should be treated as typeless.
    //   - If the Pokemon is mono-Flying but was previously hit with an effect which bestows an
    //     additional type upon it (e.g., Forest's Curse), then its Flying type will be replaced
    //     by the Normal type, but its additional "third" typing will remain.
    if (server->stFX[server->defender].roosting) {
        // Handle dual-types with a Flying sub-type.
        if ((type1 == TYPE_FLYING) && (type2 != TYPE_FLYING)) {
            type1 = TYPE_NONE;
        } else if ((type1 != TYPE_FLYING) && (type2 == TYPE_FLYING)) {
            type2 = TYPE_NONE;
        } else if ((type1 == TYPE_FLYING) && (type2 == TYPE_FLYING)) {
            type1 = TYPE_NORMAL;
            type2 = TYPE_NORMAL;
        }
    }

    // Now we can check for effectiveness on the types.
    u16 typeMod = UQ412__1_0;
    const s8 *typeMatchups = sTypeEffectiveness[server->moveType];
    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] -- Attacking type: %s\n", sTypeStrings[server->moveType]);
    debugsyscall(buf);
    #endif

    if (type1 != TYPE_NONE) {
        s8 type1Matchup = typeMatchups[type1];
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- vs. Type 1:  %s\n", sTypeStrings[type1]);
        debugsyscall(buf);
        #endif

        switch (type1Matchup) {
            case    0:                          // normal effectiveness
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Neutral\n");
                debugsyscall(buf);
                #endif

                break;
            case    1:                          // super effective
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Weakness: 2x\n");
                debugsyscall(buf);
                #endif

                typeMod = typeMod << 1;
                break;
            case   -1:                          // not very effective
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Resisted: 0.5x\n");
                debugsyscall(buf);
                #endif

                typeMod = typeMod >> 1;
                break;
            default:                            // immune
                if (Calc_ImmunityActive(server, attacker, defender, server->moveType)) {
                    #ifdef DEBUG_DAMAGE_CALC
                    sprintf(buf, "[PLAT-ENGINE] ---- Immune: 0x\n");
                    debugsyscall(buf);
                    #endif

                    typeMod = 0;
                }
                break;
        }
    }

    // mono-type mons are technically double of the one type
    if (type1 != type2 && type2 != TYPE_NONE) {
        s8 type2Matchup = typeMatchups[type2];
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- vs. Type 2:  %s\n", sTypeStrings[type2]);
        debugsyscall(buf);
        #endif

        switch (type2Matchup) {
            case    0:                          // normal damage
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Neutral\n");
                debugsyscall(buf);
                #endif

                break;
            case    1:                          // super effective
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Weakness: 2x\n");
                debugsyscall(buf);
                #endif

                typeMod = typeMod << 1;
                break;
            case   -1:                          // not very effective
                #ifdef DEBUG_DAMAGE_CALC
                sprintf(buf, "[PLAT-ENGINE] ---- Resisted: 0.5x\n");
                debugsyscall(buf);
                #endif

                typeMod = typeMod >> 1;
                break;
            default:                            // immune
                if (Calc_ImmunityActive(server, attacker, defender, server->moveType)) {
                    #ifdef DEBUG_DAMAGE_CALC
                    sprintf(buf, "[PLAT-ENGINE] ---- Immune: 0x\n");
                    debugsyscall(buf);
                    #endif

                    typeMod = 0;
                }
                break;
        }
    }

    // Wonder Guard override check goes here
    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_WONDER_GUARD)
            && Server_CheckTwoTurnMove(server, server->moveIDCurr)
            && typeMod < UQ412__2_0) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Defender has Wonder Guard; immune\n\n");
        debugsyscall(buf);
        #endif

        server->moveStatusFlag = server->moveStatusFlag | MOVE_STATUS_FLAG_PROTECTED_BY_WONDER_GUARD;
        return 0;
    }

    // If the type-effectiveness ignorance flag is in play, default back to 1x (unless already 0x)
    // This has to happen after all checks to account for moves like Night Shade and Dragon Rage
    // dealing fixed damage but still having immunities
    if ((server->serverStatusFlag & SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS) && (typeMod != 0)) {
        server->moveStatusFlag = server->moveStatusFlag | ~MOVE_STATUS_FLAG_SUPER_EFFECTIVE;
        server->moveStatusFlag = server->moveStatusFlag | ~MOVE_STATUS_FLAG_NOT_VERY_EFFECTIVE;
        return UQ412__1_0;
    }

    if (typeMod == 0) {
        server->moveStatusFlag = server->moveStatusFlag | MOVE_STATUS_FLAG_DOES_NOT_AFFECT;
    }

    if (typeMod > UQ412__1_0) {
        server->moveStatusFlag = server->moveStatusFlag | MOVE_STATUS_FLAG_SUPER_EFFECTIVE;
    }
    
    if (typeMod < UQ412__1_0) {
        server->moveStatusFlag = server->moveStatusFlag | MOVE_STATUS_FLAG_NOT_VERY_EFFECTIVE;
    }

    return typeMod;
}

/**
 * @brief Checks if an immunity is active.
 * 
 * @param server 
 * @param attacker 
 * @param defender 
 * @param moveType 
 * @return BOOL 
 */
static BOOL Calc_ImmunityActive(struct BattleServer *server, struct CalcParams *attacker, struct CalcParams *defender, u8 moveType)
{
    switch (moveType) {
        case TYPE_NORMAL:
        case TYPE_FIGHTING:
            // Stuff that removes existing immunities to Normal and Fighting:
            //   - Foresight / Odor Sleuth (same effect)
            //   - Scrappy
            if ((attacker->ability == ABILITY_SCRAPPY)
                    || (server->activePokemon[server->defender].condition2 & CONDITION_V_IDENTIFIED)) {
                return FALSE;
            }
            break;
        case TYPE_GROUND:
            // Stuff that removes existing immunities to Ground:
            //   - Iron Ball
            //   - Ingrain
            //   - Roost
            //   - Gravity
            //   - TODO: Smack Down, Thousand Arrows
            if ((defender->heldItemEffect == HOLD_EFFECT_IRON_BALL)
                    || (server->activePokemon[server->defender].moveEffectsMask & MOVE_EFFECT_FLAG_INGRAINED)
                    || (server->stFX[server->defender].roosting)
                    || (server->fieldConditions.raw & FIELD_CONDITION_GRAVITY)) {
                return FALSE;
            }
            break;
        case TYPE_PSYCHIC:
            // Check for Miracle Eye
            if (server->activePokemon[server->defender].moveEffectsMask & MOVE_EFFECT_FLAG_MIRACLE_EYE) {
                return FALSE;
            }
            break;
        default:
            return TRUE;
    }

    return TRUE;
}

/*
 * TODO: is there a way to make the move-specific stuff set modifiers in the scripts?
 */
static u16 Calc_ChainOtherModifiers(
    struct BattleServer *server,
    struct CalcParams *attacker,
    struct CalcParams *defender,
    u32 battleType,
    u16 moveID,
    u8 moveType,
    u8 movePSS
)
{
    u16 chainMod = UQ412__1_0;

    #ifdef DEBUG_DAMAGE_CALC
    u8 buf[128];
    sprintf(buf, "[PLAT-ENGINE] Final Mods Chain:\n");
    debugsyscall(buf);
    #endif

    // TODO: Dynamax stuff goes here if we ever implement it (Behemoth Blade, Behemoth Bash, Dynamax Cannon)

    if ((server->activePokemon[server->defender].moveEffectsMask & MOVE_EFFECT_FLAG_MINIMIZED)
            && Moves_BoostedByMinimize(moveID)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Defender is Minimized: 2x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__2_0);
    }
    
    if (((moveID == MOVE_EARTHQUAKE) || (moveID == MOVE_MAGNITUDE))
            && server->activePokemon[server->defender].moveEffectsMask & MOVE_EFFECT_FLAG_UNDERGROUND) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Defender is Underground: 2x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__2_0);
    }
    
    if (((moveID == MOVE_SURF) || (moveID == MOVE_WHIRLPOOL))
            && server->activePokemon[server->defender].moveEffectsMask & MOVE_EFFECT_FLAG_UNDERWATER) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Defender is Underwater: 2x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__2_0);
    }

    if (((moveID == MOVE_TWISTER) || (moveID == MOVE_GUST))
            && server->activePokemon[server->defender].moveEffectsMask & MOVE_EFFECT_FLAG_AIRBORNE) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Defender is Airborne: 2x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__2_0);
    }

    // Reflect / Light Screen / Aurora Veil checks
    if (attacker->ability == ABILITY_INFILTRATOR) {
        goto _NoScreenReduction;
    }

    u32 defendingSideConditions = server->sideConditions.raw[server->defender & 1];
    if (movePSS == PSS_PHYSICAL) {
        if (defendingSideConditions & SIDE_CONDITION_REFLECT) {
            goto _ScreenReduction;
        }
    } else {
        if (defendingSideConditions & SIDE_CONDITION_LIGHT_SCREEN) {
            goto _ScreenReduction;
        }
    }

    goto _NoScreenReduction;

_ScreenReduction:
    if (battleType & BATTLE_TYPE_DOUBLES) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Doubles Screen: 0.6666x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__0_6666);
    } else {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Singles Screen: 0.5x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__0_5);
    }

_NoScreenReduction:
    // TODO: Collision Course, Electro Drift

    // 0.5x if the target has Multiscale (ignorable) or Shadow Shield and is at full HP.
    if ((defender->currHP == defender->maxHP)
            && (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_MULTISCALE)
                    || defender->ability == ABILITY_SHADOW_SHIELD)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Multiscale: 0.5x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__0_5);
    }

    // 0.5x if the target has Fluffy, the move makes contact, and the attacker does not have Long Reach.
    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FLUFFY)
            && (attacker->ability != ABILITY_LONG_REACH)
            && (server->aiWork.moveTable[moveID].flag & MOVE_FLAG_MAKES_CONTACT)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Fluffy (contact): 0.5x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__0_5);
    }

    // 0.5x if the target has Punk Rock and the used move is sound-based.
    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_PUNK_ROCK)
            && Moves_IsSound(moveID)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Punk Rock: 0.5x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__0_5);
    }

    // 0.5x if the target has Ice Scales and the used move is Special.
    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_ICE_SCALES)
            && (movePSS == PSS_SPECIAL)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Ice Scales: 0.5x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__0_5);
    }

    if (Server_CheckDefenderAbility(server, server->attacker, PARTNER(server->defender), ABILITY_FRIEND_GUARD)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Friend Guard: 0.5x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__0_75);
    }

    if (server->moveStatusFlag & MOVE_STATUS_FLAG_SUPER_EFFECTIVE) {
        if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FILTER)
                || Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_SOLID_ROCK)
                || defender->ability == ABILITY_PRISM_ARMOR) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Filter: 0.75x\n");
            debugsyscall(buf);
            #endif

            chainMod = QMul_RoundUp(chainMod, UQ412__0_75);
        }

        if (attacker->ability == ABILITY_NEUROFORCE) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Neuroforce: 1.25x\n");
            debugsyscall(buf);
            #endif

            chainMod = QMul_RoundUp(chainMod, UQ412__1_25);
        }
    }

    if (server->critical && attacker->ability == ABILITY_SNIPER) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Sniper: 1.5x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__1_5);
    }

    if ((server->moveStatusFlag & MOVE_STATUS_FLAG_NOT_VERY_EFFECTIVE) && attacker->ability == ABILITY_TINTED_LENS) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Tinted Lens: 2.0x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__2_0);
    }

    if (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_FLUFFY)
            && moveType == TYPE_FIRE) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Fluffy (fire): 2.0x\n");
        debugsyscall(buf);
        #endif

        chainMod = QMul_RoundUp(chainMod, UQ412__2_0);
    }

    if (((moveType == TYPE_NORMAL) && (defender->heldItemEffect == HOLD_EFFECT_WEAKEN_NORMAL))
            || ((server->moveStatusFlag & MOVE_STATUS_FLAG_SUPER_EFFECTIVE) && CheckResistBerry(defender->heldItemEffect, moveType))) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Resist Berry for type: %s\n", sTypeStrings[moveType]);
        debugsyscall(buf);
        #endif

        if (defender->ability == ABILITY_RIPEN) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Ripen: 0.25x\n");
            debugsyscall(buf);
            #endif

            chainMod = QMul_RoundUp(chainMod, UQ412__0_25);
        } else {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] ---- Normal: 0.5x\n");
            debugsyscall(buf);
            #endif

            chainMod = QMul_RoundUp(chainMod, UQ412__0_5);
        }
    }

    if (attacker->heldItemEffect == HOLD_EFFECT_EXPERT_BELT) {
        if (server->moveStatusFlag & MOVE_STATUS_FLAG_SUPER_EFFECTIVE) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Expert Belt: 1.2x\n");
            debugsyscall(buf);
            #endif

            chainMod = QMul_RoundUp(chainMod, UQ412__1_2);
        }
    } else if (attacker->heldItemEffect == HOLD_EFFECT_LIFE_ORB) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Life Orb: 1.3x\n");
        debugsyscall(buf);
        #endif
        
        chainMod = QMul_RoundUp(chainMod, UQ412__1_3);
    } else if (attacker->heldItemEffect == HOLD_EFFECT_METRONOME) {
        u8 metronomeCount = server->activePokemon[server->attacker].moveEffects.metronome;
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Metronome Count: %d\n", metronomeCount);
        debugsyscall(buf);
        #endif

        u16 metronomeMod;
        if (metronomeCount < 6) {
            metronomeMod = QMul_RoundUp(chainMod, UQ412__1_0 + (UQ412__0_2 * (metronomeCount - 1)));
        } else {
            metronomeMod = UQ412__2_0;
        }

        chainMod = QMul_RoundUp(chainMod, metronomeMod);
    }

    #ifdef DEBUG_DAMAGE_CALC
    sprintf(buf, "[PLAT-ENGINE] Final modifier: %d\n\n", chainMod);
    debugsyscall(buf);
    #endif

    return chainMod;
}

// https://bulbapedia.bulbagarden.net/wiki/Damage#Generation_V_onward
void Calc_MoveDamage(struct Battle *battle, struct BattleServer *server)
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

    // Step 1: Calculate the base damage value.
    u32 damage = Calc_BaseDamage(battle, server, &attackerParams, &defenderParams);
    #ifdef DEBUG_DAMAGE_CALC
    u8 buf[128];
    sprintf(buf, "[PLAT-ENGINE] Base damage: %d\n", damage);
    debugsyscall(buf);
    #endif


    // Step 2: 0.75x if the move has more than one target upon execution.
    u32 battleType = Battle_Type(battle);
    if ((battleType & BATTLE_TYPE_DOUBLES) && (Server_HitCount(battle, server, 0, server->defender) > 1)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Spread damage: 0.75x\n");
        debugsyscall(buf);
        #endif

        damage = QMul_RoundDown(damage, UQ412__0_75);
    }

    // Step 3: Divide by 4 if the move is the second-strike of Parental Bond.
    // TODO

    // Step 4: 1.5x if the active weather is Sun or Rain and the move is Fire or Water type, respectively.
    //         0.5x if the active weather is Sun or Rain and the move is Water or Fire type, respectively.
    // Neither applies if the defender is holding a Utility Umbrella.
    if (WeatherIsActive(battle, server, FIELD_CONDITION_SUNNY)
            && defenderParams.heldItemEffect != HOLD_EFFECT_UNAFFECTED_BY_RAIN_OR_SUN) {
        if (server->moveType == TYPE_FIRE) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Fire move in Sun: 1.5x\n");
            debugsyscall(buf);
            #endif

            damage = QMul_RoundDown(damage, UQ412__1_5);
        } else if (server->moveType == TYPE_WATER) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Water move in Sun: 0.5x\n");
            debugsyscall(buf);
            #endif

            damage = QMul_RoundDown(damage, UQ412__0_5);
        }
    } else if (WeatherIsActive(battle, server, FIELD_CONDITION_RAINING)
            && defenderParams.heldItemEffect != HOLD_EFFECT_UNAFFECTED_BY_RAIN_OR_SUN) {
        if (server->moveType == TYPE_WATER) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Water move in Rain: 1.5x\n");
            debugsyscall(buf);
            #endif

            damage = QMul_RoundDown(damage, UQ412__1_5);
        } else if (server->moveType == TYPE_FIRE) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Fire move in Rain: 0.5x\n");
            debugsyscall(buf);
            #endif

            damage = QMul_RoundDown(damage, UQ412__0_5);
        }
    }

    // Step 5: 2x if the defender used Glaive Rush last turn (or this turn) and the move does
    // not have a fixed damage value.
    // TODO

    // Step 6: 1.5x if the attack was a critical hit.
    #if !defined(CRITICAL_DAMAGE_MULTIPLIER) || CRITICAL_DAMAGE_MULTIPLIER >= GEN6
    if (server->critical) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Critical Hit: 1.5x\n");
        debugsyscall(buf);
        #endif

        damage = QMul_RoundDown(damage, UQ412__1_5);
    }
    #else   // Gen5 critical damage
    if (server->critical) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Critical Hit: 2.0x\n");
        debugsyscall(buf);
        #endif

        damage = QMul_RoundDown(damage, UQ412__2_0);
    }
    #endif

    // Step 7: Apply random damage fluctuation.
    #ifdef DEBUG_DAMAGE_CALC
    // Debug mode: store all possible damage values as a buffer.
    // u32 damageValues[] = { 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100 };
    // for (int i = 0; i < 16; i++) {
    //     damageValues[i] = damage * damageValues[i] / 100;
    // }
    
    // Alternate debug mode: only take the maximum value, so do nothing here
    #else
    // Generate a random number from 85 to 100.
    int rand = 100 - (Battle_Random(battle) % 16);
    damage = damage * rand / 100;
    #endif

    // Step 8: 1.5x if the attacker shares a type with the move.
    // TODO: Handle Soak, Forest's Curse, Trick-or-Treat.
    u16 stabMod = UQ412__1_0;
    if ((server->moveType == attackerParams.type1) || (server->moveType == attackerParams.type2)) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] STAB: 1.5x\n");
        debugsyscall(buf);
        #endif

        stabMod = stabMod + UQ412__0_5;
    } else if ((attackerParams.ability == ABILITY_PROTEAN) || (attackerParams.ability == ABILITY_LIBERO)) {
        // This one is only here for the AI.
        stabMod = stabMod + UQ412__0_5;
    }

    if ((attackerParams.ability == ABILITY_ADAPTABILITY)
            && ((attackerParams.type1 == server->moveType) || (attackerParams.type2 == server->moveType))) {
        #ifdef DEBUG_DAMAGE_CALC
        sprintf(buf, "[PLAT-ENGINE] -- Adaptability: +0.5x\n");
        debugsyscall(buf);
        #endif

        stabMod = stabMod + UQ412__0_5;
    }

    // Step 9: Compute the modifier for type effectiveness.
    u16 typeMod = Calc_TypeModifier(server, &attackerParams, &defenderParams);

    // Step 10: Divide by 2 if the attacker is burned and does not have Guts nor is using Facade.
    u16 burnMod = UQ412__1_0;
    if (server->aiWork.moveTable[server->moveIDCurr].pss == PSS_PHYSICAL) {
        if ((attackerParams.condition & CONDITION_BURNED)
                && ((attackerParams.ability != ABILITY_GUTS) && (server->moveIDCurr != MOVE_FACADE))) {
            #ifdef DEBUG_DAMAGE_CALC
            sprintf(buf, "[PLAT-ENGINE] -- Burned Attacker: 0.5x\n");
            debugsyscall(buf);
            #endif

            burnMod = UQ412__0_5;
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
    u16 lastMod = Calc_ChainOtherModifiers(
        server,
        &attackerParams,
        &defenderParams,
        battleType,
        server->moveIDCurr,
        server->moveType,
        server->aiWork.moveTable[server->moveIDCurr].pss
    );

    // Step 11: Divide by 4 if the used move is a Z-move and the target is trying to Protect itself.
    // TODO: Z-moves

    // Apply all the modifiers.
    #ifdef DEBUG_DAMAGE_CALC
    // sprintf(buf, "[PLAT-ENGINE] Preliminary damage values: [ ");
    // int length = 43;
    // for (int i = 0; i < 16; i++) {
    //     length += sprintf(buf + length, "%ld ", damageValues[i]);
    // }
    // sprintf(buf + length, "]\n");
    // debugsyscall(buf);

    sprintf(buf, "[PLAT-ENGINE] Max Roll:       %ld\n", damage);

    damage = QMul_RoundDown(damage, stabMod);
    sprintf(buf, "[PLAT-ENGINE] With STAB:      %ld\n", damage);
    debugsyscall(buf);
    
    damage = QMul_RoundDown(damage, typeMod);
    sprintf(buf, "[PLAT-ENGINE] With Chart:     %ld\n", damage);
    debugsyscall(buf);

    damage = QMul_RoundDown(damage, burnMod);
    sprintf(buf, "[PLAT-ENGINE] With Burn:      %ld\n", damage);
    debugsyscall(buf);

    damage = QMul_RoundDown(damage, lastMod);
    sprintf(buf, "[PLAT-ENGINE] Final Damage:   %ld\n", damage);
    debugsyscall(buf);


    // If we're in debug mode, then we instead have a whole list of damage values that need to be
    // applied to and printed out.
    // sprintf(buf, "[PLAT-ENGINE] Damage results: [ ");
    // length = 32;
    // for (int i = 0; i < 16; i++) {
    //     damageValues[i] = Q412_Mul_IntByQ_RoundDown(damageValues[i], stabMod);
    //     damageValues[i] = Q412_Mul_IntByQ_RoundDown(damageValues[i], typeMod);
    //     damageValues[i] = Q412_Mul_IntByQ_RoundDown(damageValues[i], burnMod);
    //     damageValues[i] = Q412_Mul_IntByQ_RoundDown(damageValues[i], lastMod);
    //     length += sprintf(buf + length, "%ld ", damageValues[i]);
    // }
    // sprintf(buf + length, "]\n");
    // debugsyscall(buf);

    // Always use the max value in debug mode.
    // damage = damageValues[15];
    #else
    damage = QMul_RoundDown(damage, stabMod);
    damage = QMul_RoundDown(damage, typeMod);
    damage = QMul_RoundDown(damage, burnMod);
    damage = QMul_RoundDown(damage, lastMod);
    #endif

    #ifdef DEBUG_DAMAGE_CALC_1_DAMAGE
    // In this debug mode, always return 1 damage.
    server->damage = -1;
    #else
    // And we're done. Cut the top bit off, then multiply by -1.
    server->damage = ((s32) damage & 0x7FFF) * -1;
    #endif
}

BOOL Calc_Critical(struct Battle *battle, struct BattleServer *server)
{
#ifdef DEBUG_ALL_CRITS
    return TRUE;
#elif defined(DEBUG_NO_CRITS)
    return FALSE;
#else
    int ret = FALSE;

    u16 species            = server->activePokemon[server->attacker].species;
    u32 volatileConditions = server->activePokemon[server->attacker].condition2;
    u32 moveEffects        = server->activePokemon[server->defender].moveEffectsMask;
    u8  ability            = server->activePokemon[server->attacker].ability;
    u16 itemEffect         = Server_HeldItemEffect(server, server->attacker);

    u16 effectiveStages = (
        server->criticalCount
        + (itemEffect == HOLD_EFFECT_SCOPE_LENS)
        + (ability == ABILITY_SUPER_LUCK)
        + (((volatileConditions & CONDITION_V_PUMPED) != 0) * 2)
        + (((itemEffect == HOLD_EFFECT_LUCKY_PUNCH) && (species == SPECIES_CHANSEY)) * 2)
        + (((itemEffect == HOLD_EFFECT_LEEK) && (species == SPECIES_FARFETCHD)) * 2)   // TODO: Farfetch'd-G, Sirfetch'd
    );

    effectiveStages = (effectiveStages > 4) ? 4 : effectiveStages;  // crit stages max out at +4

    // TODO: Effect check here for auto-critical?
    // there's an argument to pass critStages == 4, but that might fuck with people
    // trying to change the crit ratios

    if (Battle_Random(battle) % gCriticalRateTable[effectiveStages] == 0) {
        if ((Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_BATTLE_ARMOR) == FALSE)
                && (Server_CheckDefenderAbility(server, server->attacker, server->defender, ABILITY_SHELL_ARMOR) == FALSE)
                && ((Server_Get(battle, server, SERVER_PARAM_SIDE_CONDITIONS, server->defender) & SIDE_CONDITION_LUCKY_CHANT) == FALSE)
                && ((moveEffects & MOVE_EFFECT_FLAG_NO_CRITICAL) == FALSE)) {
            ret = TRUE;
        }
    }

    return ret;
#endif
}

int Calc_TypeEffectivenessPower(u8 moveType, u8 pokeType1, u8 pokeType2)
{
    /*
     * Unlike the function above for the modifier, this function is ONLY used
     * by Stealth Rock checks; we'll just adhere to the standard that it expects.
     * 
     * This function does NOT check and should NEVER check for modified typings,
     * since it's only used for entry-hazard checks.
     */
    s8 matchup = sTypeEffectiveness[moveType][pokeType1];
    if (pokeType1 != pokeType2 && matchup != _IMMUN) {
        matchup = matchup + sTypeEffectiveness[moveType][pokeType2];
    }

    switch (matchup) {
        case      2:    return 160; // quad-effective
        case _SPEFF:    return 80;
        case __NORM:    return 40;
        case _NVEFF:    return 20;
        case     -2:    return 10;  // quad-resist
        default:        return 0;   // immune
    }
}
