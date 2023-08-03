#include "archive.h"
#include "config.h"
#include "debug.h"
#include "global.h"
#include "pokemon.h"
#include "q412.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/items.h"
#include "constants/misc.h"
#include "constants/move_effects.h"
#include "constants/species.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/server.h"

#ifdef DEBUG_ABILTIIES
static const u8 *sDebugAbilityNames[] = {
    "None",
    "Stench",
    "Drizzle",
    "Speed Boost",
    "Battle Armor",
    "Sturdy",
    "Damp",
    "Limber",
    "Sand Veil",
    "Static",
    "Volt Absorb",
    "Water Absorb",
    "Oblivious",
    "Cloud Nine",
    "Compound Eyes",
    "Insomnia",
    "Color Change",
    "Immunity",
    "Flash Fire",
    "Shield Dust",
    "Own Tempo",
    "Suction Cups",
    "Intimidate",
    "Shadow Tag",
    "Rough Skin",
    "Wonder Guard",
    "Levitate",
    "Effect Spore",
    "Synchronize",
    "Clear Body",
    "Natural Cure",
    "Lightning Rod",
    "Serene Grace",
    "Swift Swim",
    "Chlorophyll",
    "Illuminate",
    "Trace",
    "Huge Power",
    "Poison Point",
    "Inner Focus",
    "Magma Armor",
    "Water Veil",
    "Magnet Pull",
    "Soundproof",
    "Rain Dish",
    "Sand Stream",
    "Pressure",
    "Thick Fat",
    "Early Bird",
    "Flame Body",
    "Run Away",
    "Keen Eye",
    "Hyper Cutter",
    "Pickup",
    "Truant",
    "Hustle",
    "Cute Charm",
    "Plus",
    "Minus",
    "Forecast",
    "Sticky Hold",
    "Shed Skin",
    "Guts",
    "Marvel Scale",
    "Liquid Ooze",
    "Overgrow",
    "Blaze",
    "Torrent",
    "Swarm",
    "Rock Head",
    "Drought",
    "Arena Trap",
    "Vital Spirit",
    "White Smoke",
    "Pure Power",
    "Shell Armor",
    "Air Lock",
    "Tangled Feet",
    "Motor Drive",
    "Rivalry",
    "Steadfast",
    "Snow Cloak",
    "Gluttony",
    "Anger Point",
    "Unburden",
    "Heatproof",
    "Simple",
    "Dry Skin",
    "Download",
    "Iron Fist",
    "Poison Heal",
    "Adaptability",
    "Skill Link",
    "Hydration",
    "Solar Power",
    "Quick Feet",
    "Normalize",
    "Sniper",
    "Magic Guard",
    "No Guard",
    "Stall",
    "Technician",
    "Leaf Guard",
    "Klutz",
    "Mold Breaker",
    "Super Luck",
    "Aftermath",
    "Anticipation",
    "Forewarn",
    "Unaware",
    "Tinted Lens",
    "Filter",
    "Slow Start",
    "Scrappy",
    "Storm Drain",
    "Ice Body",
    "Solid Rock",
    "Snow Warning",
    "Honey Gather",
    "Frisk",
    "Reckless",
    "Multitype",
    "Flower Gift",
    "Bad Dreams",
};
#endif

static inline BOOL DamageWasDealt(struct BattleServer *server)
{
    return server->stSelfFX[server->defender].physicalDamage
        || server->stSelfFX[server->defender].specialDamage;
}

BOOL Server_CheckAbilityOnHit(struct Battle *battle, struct BattleServer *server, int *seqNum)
{
    if (server->defender == 0xFF) {
        return FALSE;
    }

    if (Server_CheckSubstitute(server, server->defender)) {
        return FALSE;
    }

    if (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) {
        return FALSE;
    }

    if (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) {
        return FALSE;
    }

    if (!DamageWasDealt(server)) {
        return FALSE;
    }

    BOOL result = FALSE;
    switch (Server_Ability(server, server->defender)) {
    case ABILITY_STATIC:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Attacker has no present status condition
                && server->activePokemon[server->attacker].condition == 0
                // Move makes contact
                && server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_MAKES_CONTACT
                // Activate 30% of the time
                && Battle_Random(battle) % 10 < 3) {
            server->addlEffectType   = ADDL_EFFECT_FROM_ABILITY;
            server->addlEffectClient = server->attacker;
            server->clientWork       = server->defender;
            *seqNum = SUBSCR_APPLY_PARALYSIS;
            result  = TRUE;
        }
        break;

    case ABILITY_COLOR_CHANGE:
        // Defender is still alive after the attack
        if (server->activePokemon[server->defender].curHP
                // The move is not Struggle
                && server->moveIDCurr != MOVE_STRUGGLE
                // Move actually has a base power
                && server->aiWork.moveTable[server->moveIDCurr].power
                // Don't activate until the final hit of a move
                && server->multiHitCounter <= 1
                // The move's type does not match either of the user's current types
                && BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_1, NULL) != server->moveType
                && BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_2, NULL) != server->moveType) {
            server->messageWork = server->moveType;
            *seqNum = SUBSCR_COLOR_CHANGE;
            result  = TRUE;
        }
        break;

    case ABILITY_ROUGH_SKIN:
    case ABILITY_IRON_BARBS:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Attacker does not have Magic Guard
                && Server_Ability(server, server->attacker) != ABILITY_MAGIC_GUARD
                // Move makes contact
                && server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_MAKES_CONTACT) {
            server->hpCalcWork = Server_DivideBy(server->activePokemon[server->attacker].maxHP * -1, 8);
            server->clientWork = server->attacker;
            *seqNum = SUBSCR_ROUGH_SKIN;
            result  = TRUE;
        }
        break;

    case ABILITY_EFFECT_SPORE:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Attacker does not have Overcoat
                && Server_Ability(server, server->attacker) != ABILITY_OVERCOAT
                // Attacker has no present status condition
                && server->activePokemon[server->attacker].condition == 0
                // Move makes contact
                && server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_MAKES_CONTACT
                // Activate 30% of the time
                && Battle_Random(battle) % 10 < 3) {
            // Determine the effect to apply
            switch (Battle_Random(battle) % 3) {
                case 0:     *seqNum = SUBSCR_APPLY_POISON;      break;
                case 1:     *seqNum = SUBSCR_APPLY_PARALYSIS;   break;
                case 2:     *seqNum = SUBSCR_APPLY_SLEEP;       break;
            }

            server->addlEffectType   = ADDL_EFFECT_FROM_ABILITY;
            server->addlEffectClient = server->attacker;
            server->clientWork       = server->defender;
            result = TRUE;
        }
        break;

    case ABILITY_POISON_POINT:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Attacker has no present status condition
                && server->activePokemon[server->attacker].condition == 0
                // Move makes contact
                && server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_MAKES_CONTACT
                // Activate 30% of the time
                && Battle_Random(battle) % 10 < 3) {
            server->addlEffectType   = ADDL_EFFECT_FROM_ABILITY;
            server->addlEffectClient = server->attacker;
            server->clientWork       = server->defender;
            *seqNum = SUBSCR_APPLY_POISON;
            result  = TRUE;
        }
        break;

    case ABILITY_FLAME_BODY:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Attacker has no present status condition
                && server->activePokemon[server->attacker].condition == 0
                // Move makes contact
                && server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_MAKES_CONTACT
                // Activate 30% of the time
                && Battle_Random(battle) % 10 < 3) {
            server->addlEffectType   = ADDL_EFFECT_FROM_ABILITY;
            server->addlEffectClient = server->attacker;
            server->clientWork       = server->defender;
            *seqNum = SUBSCR_APPLY_BURN;
            result  = TRUE;
        }
        break;

    case ABILITY_CUTE_CHARM:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Defender is still alive after the attack
                && server->activePokemon[server->defender].curHP
                // Attacker is not currently infatuated
                && (server->activePokemon[server->attacker].condition2 & CONDITION_V_INFATUATED) == 0
                // Move makes contact
                && server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_MAKES_CONTACT
                // Activate 30% of the time
                && Battle_Random(battle) % 10 < 3) {
            server->addlEffectType   = ADDL_EFFECT_FROM_ABILITY;
            server->addlEffectClient = server->attacker;
            server->clientWork       = server->defender;
            *seqNum = SUBSCR_APPLY_ATTRACT;
            result  = TRUE;
        }
        break;

    case ABILITY_AFTERMATH:
        // Defender is fainting
        if (server->defender == server->faintingClient
                // Attacker is still alive after the attack
                && server->activePokemon[server->attacker].curHP
                // Attacker does not have Magic Guard
                && Server_Ability(server, server->attacker) != ABILITY_MAGIC_GUARD
                // Damp is not active
                && Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_DAMP) == FALSE
                // Move makes contact
                && server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_MAKES_CONTACT) {
            server->hpCalcWork = Server_DivideBy(server->activePokemon[server->attacker].maxHP * -1, 4);
            server->clientWork = server->attacker;
            *seqNum = SUBSCR_AFTERMATH_DAMAGE;
            result  = TRUE;
        }       
        break;

    default:
        break;
    }

    return result;
}

BOOL Server_CheckExtraFlinch(struct Battle *battle, struct BattleServer *server)
{
    if (server->defender == 0xFF) {
        return FALSE;
    }

    if (server->activePokemon[server->defender].curHP) {
        return FALSE;
    }

    if (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) {
        return FALSE;
    }

    BOOL result        = FALSE;
    int heldItemEffect = Server_HeldItemEffect(server, server->attacker);
    int heldItemPower  = Server_HeldItemPower(server, server->attacker, 0);
    if (heldItemEffect == HOLD_EFFECT_KINGS_ROCK
            && DamageWasDealt(server)
            && (Battle_Random(battle) % 100) < heldItemPower
            && (server->aiWork.moveTable[server->moveIDCurr].flag & MOVE_FLAG_TRIGGERS_KINGS_ROCK)) {
        server->addlEffectClient = server->defender;
        server->addlEffectType   = ADDL_EFFECT_INDIRECT;
        
        Server_LoadSequence(server, ARCHIVE_SUBSCR, SUBSCR_TRY_FLINCH);

        server->serverSeqNext = server->serverSeqNum;
        server->serverSeqNext = 21; // todo: enum
        result = FALSE;
    }

    return result;
}

int Server_CheckAbilityDamageOverride(struct BattleServer *server, int attacker, int defender)
{
    int nextScript = 0;
    int moveType;
    if (Server_Ability(server, attacker) == ABILITY_NORMALIZE && Moves_CanNormalize(server->moveIDCurr)) {
        moveType = TYPE_NORMAL;
    } else if (server->moveType) {
        moveType = server->moveType;
    } else {
        moveType = server->aiWork.moveTable[server->moveIDCurr].type;
    }

    #ifdef DEBUG_ABILTIIES
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | Defender Ability: %s\n", sDebugAbilityNames[Server_Ability(server, defender)]);
    debugsyscall(buf);
    #endif

    if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_VOLT_ABSORB)) {
        if (moveType == TYPE_ELECTRIC
                && (server->serverStatusCheckSeq & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == FALSE
                && attacker != defender) {
            server->hpCalcWork = Server_DivideBy(server->activePokemon[defender].maxHP, 4);
            nextScript = SUBSCR_ABILITY_HP_RESTORE;
        }
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_WATER_ABSORB)
            || Server_CheckDefenderAbility(server, attacker, defender, ABILITY_DRY_SKIN)) {
        if (moveType == TYPE_WATER
                && (server->serverStatusCheckSeq & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == FALSE
                && attacker != defender) {
            server->hpCalcWork = Server_DivideBy(server->activePokemon[defender].maxHP, 4);
            nextScript = SUBSCR_ABILITY_HP_RESTORE;
        }
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_FLASH_FIRE)) {
        if (moveType == TYPE_FIRE
                && server->activePokemon[defender].condition & CONDITION_FROZEN == FALSE
                && (server->serverStatusCheckSeq & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == FALSE
                && attacker != defender) {
            nextScript = SUBSCR_FLASH_FIRE;
        }
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_SOUNDPROOF)) {
        if (Moves_IsSound(server->moveIDCurr)) {
            nextScript = SUBSCR_SOUNDPROOF;
        }
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_MOTOR_DRIVE)) {
        if (moveType == TYPE_ELECTRIC
                && (server->serverStatusCheckSeq & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == FALSE
                && attacker != defender) {
            nextScript = SUBSCR_MOTOR_DRIVE;
        }
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_LIGHTNING_ROD)) {
        if (moveType == TYPE_ELECTRIC
                && (server->serverStatusCheckSeq & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == FALSE
                && attacker != defender) {
            nextScript = SUBSCR_LIGHTNING_ROD_STORM_DRAIN;
        }
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_STORM_DRAIN)) {
        if (moveType == TYPE_WATER
                && (server->serverStatusCheckSeq & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == FALSE
                && attacker != defender) {
            nextScript = SUBSCR_LIGHTNING_ROD_STORM_DRAIN;
        }
    } else if (Server_CheckDefenderAbility(server, attacker, defender, ABILITY_SAP_SIPPER)) {
        if (moveType == TYPE_GRASS
                && (server->serverStatusCheckSeq & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == FALSE
                && attacker != defender) {
            nextScript = SUBSCR_SAP_SIPPER;
        }
    }

    return nextScript;
}

BOOL Server_CheckEndOfTurnAbility(struct Battle *battle, struct BattleServer *server, int battler)
{
    if (server->activePokemon[battler].curHP == 0) {
        return FALSE;
    }

    BOOL result = FALSE;
    int nextScript = 0;

    u16 ability = Server_Ability(server, battler);
    if (ability == ABILITY_SPEED_BOOST) {
        // Don't activate on the first turn that we switch in
        if (server->activePokemon[battler].moveEffects.fakeOutTurnCount != server->totalTurns + 1
                // Don't activate if we're already at +6
                && server->activePokemon[battler].statBoosts[STAT_SPEED] < 12) {
            server->addlEffectParam  = ADDL_EFFECT_SPE_UP_1;
            server->addlEffectType   = ADDL_EFFECT_FROM_ABILITY;
            server->addlEffectClient = battler;
            nextScript = SUBSCR_BOOST_STATS;
            result     = TRUE;
        }
    } else if (ability == ABILITY_SHED_SKIN) {
        if (server->activePokemon[battler].condition & CONDITION_STATUSED
                && Battle_Random(battle) % 10 < 3) {
            if (server->activePokemon[battler].condition & CONDITION_ASLEEP) {
                server->messageWork = MSG_COND_ASLEEP;
            } else if (server->activePokemon[battler].condition & CONDITION_POISON_ALL) {
                server->messageWork = MSG_COND_POISONED;
            } else if (server->activePokemon[battler].condition & CONDITION_BURNED) {
                server->messageWork = MSG_COND_BURNED;
            } else if (server->activePokemon[battler].condition & CONDITION_PARALYZED) {
                server->messageWork = MSG_COND_PARALYZED;
            } else {
                server->messageWork = MSG_COND_FROZEN;
            }

            server->clientWork = battler;
            nextScript = SUBSCR_SHED_SKIN;
            result     = TRUE;
        }
    }

    if (result) {
        Server_LoadSequence(server, ARCHIVE_SUBSCR, nextScript);
        server->serverSeqNext = server->serverSeqNum;
        server->serverSeqNum = 21;
    }

    return result;
}

// tl;dr: any ability that involves a form change or copies
// another ability, as well as comatose for some reason
static const u16 sAbilities_CannotBeTraced[] = {
    ABILITY_BATTLE_BOND,
    ABILITY_COMATOSE,
    ABILITY_COMMANDER,
    ABILITY_DISGUISE,
    ABILITY_FLOWER_GIFT,
    ABILITY_FORECAST,
    ABILITY_GULP_MISSILE,
    ABILITY_HUNGER_SWITCH,
    ABILITY_ICE_FACE,
    ABILITY_ILLUSION,
    ABILITY_IMPOSTER,
    ABILITY_MULTITYPE,
    ABILITY_NEUTRALIZING_GAS,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_POWER_OF_ALCHEMY,
    ABILITY_RECEIVER,
    ABILITY_RKS_SYSTEM,
    ABILITY_SCHOOLING,
    ABILITY_SHIELDS_DOWN,
    ABILITY_STANCE_CHANGE,
    ABILITY_TRACE,
    ABILITY_ZEN_MODE,
    ABILITY_ZERO_TO_HERO,
};

static int PickTraceOpponent(struct Battle *battle, struct BattleServer *server, int opp1, int opp2)
{
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | ---- Opp 1 ability: %s\n", sDebugAbilityNames[server->activePokemon[opp1].ability]);
    debugsyscall(buf);
    sprintf(buf, "PLAT-ENGINE | ---- Opp 2 ability: %s\n", sDebugAbilityNames[server->activePokemon[opp2].ability]);
    debugsyscall(buf);
    #endif

    // Check the validity of either opponent.
    BOOL opp1Valid = TRUE, opp2Valid = TRUE;
    for (unsigned int i = 0; i < NELEMS(sAbilities_CannotBeTraced); i++) {
        opp1Valid &= server->activePokemon[opp1].ability != sAbilities_CannotBeTraced[i];
        opp2Valid &= server->activePokemon[opp2].ability != sAbilities_CannotBeTraced[i];
    }

    #ifdef DEBUG_SWITCHIN_EFFECTS
    sprintf(buf, "PLAT-ENGINE | ---- Opp 1 valid? %s\n", opp1Valid ? "YES" : "NO");
    debugsyscall(buf);
    sprintf(buf, "PLAT-ENGINE | ---- Opp 2 valid? %s\n", opp2Valid ? "YES" : "NO");
    debugsyscall(buf);
    #endif

    // If opp1 and opp2 are both valid, pick randomly.
    if (opp1Valid && opp2Valid) {
        return (Battle_Random(battle) & 1) ? opp2 : opp1;
    }

    // If only one opp is valid, pick that one; if neither are valid,
    // return 0xFF.
    return opp1Valid ? opp1 : (opp2Valid ? opp2: 0xFF);
}

static void ProcessTrace(struct Battle *battle, struct BattleServer *server, int numBattlers, int *nextScript, BOOL *processing)
{
    int i;
    
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    #endif

    for (i = 0; i < numBattlers; i++) {
        int battler = server->pokemonSpeedWork[i];   // iterate by speed order
        u16 ability = Server_Ability(server, battler);

        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | -- %dth battler by speed: %d\n", i, battler);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | ---- Ability: %s\n", sDebugAbilityNames[ability]);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | ---- Already Traced? %s\n", server->activePokemon[battler].traceDone ? "YES" : "NO");
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | ---- Current HP: %d\n", server->activePokemon[battler].curHP);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | ---- Held Item: %d\n", server->activePokemon[battler].heldItem);
        debugsyscall(buf);
        #endif

        // Verify that this battler is actually able to do Trace things.
        if (ability != ABILITY_TRACE
                || server->activePokemon[battler].traceDone
                || server->activePokemon[battler].curHP == 0
                || server->activePokemon[battler].heldItem == ITEM_GRISEOUS_ORB) {
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | -- Skipping Trace activation\n");
            debugsyscall(buf);
            #endif

            continue;
        }

        // Pick an opponent.
        // 
        // This has a chance, in Doubles against only 1 remaining opponent, to choose
        // the empty slot on th eopposite side of the field. This is intentional to
        // replicate behavior in vanilla Pokemon.
        int opp1 = Battle_Opponent(battle, battler, 0);
        int opp2 = Battle_Opponent(battle, battler, 2);
        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | ---- Opponent 1: %d\n", opp1);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | ---- Opponent 2: %d\n", opp2);
        debugsyscall(buf);
        #endif

        server->defenderWork = PickTraceOpponent(battle, server, opp1, opp2);
        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | -- Tracing battler: %d\n", server->defenderWork);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | ---- Current HP: %d\n", server->activePokemon[server->defenderWork].curHP);
        debugsyscall(buf);
        #endif

        // If the opponent is alive, break execution on the processing loop and
        // pass the break upstream.
        if (server->defenderWork != 0xFF
                && server->activePokemon[server->defenderWork].curHP) {
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | -- Setting up Trace script\n");
            debugsyscall(buf);
            #endif

            server->activePokemon[battler].traceDone = TRUE;
            server->clientWork = battler;
            *nextScript = SUBSCR_TRACE;
            *processing = FALSE;
            break;
        }
    }

    // If we got through all of the battlers, tell the upstream processor to proceed
    // in the state machine.
    if (i == numBattlers) {
        server->serverSwitchInEffectsSeq++;
    }
}

typedef void (*AbilityHandler)(struct Battle*, struct BattleServer*, int, int, int*, BOOL*);

static void ProcessIntimidate(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    // All Intimidate logic for things like Own Tempo and Oblivious is handled in the subscript.
    // Effects like Defiant and Competitive will trigger automatically.
    // 
    // TODO: Investigate how the fuck this will work in doubles with Defiant/Competitive oh god.
    // It might be fine, actually. I think the way scripts work are on a queueing system. Defiant
    // would just activate after all Intimidate instances resolve. Kinda quirky, but functionally
    // equivalent.
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | -- Setting up Intimidate script from battler %d\n", battler);
    debugsyscall(buf);
    #endif

    server->clientWork = battler;
    *nextScript = SUBSCR_INTIMIDATE;
    *processing = FALSE;
}

extern const u8 gStatModifierTable[][2];    // 0x0226EBE0

static void ProcessDownload(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    int oppDef = 0, oppSpdef = 0;
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | -- Processing Download from battler %d\n", battler);
    debugsyscall(buf);
    #endif

    for (int i = 0; i < numBattlers; i++) {
        if ((i & 1) == (battler & 1)    // If these have the same parity, they're allies
                || server->activePokemon[i].curHP == 0) {
            continue;
        }

        oppDef   += server->activePokemon[i].defense
                  * gStatModifierTable[STAT_DEFENSE][0]
                  / gStatModifierTable[STAT_DEFENSE][1];
        oppSpdef += server->activePokemon[i].spDefense
                  * gStatModifierTable[STAT_SPDEFENSE][0]
                  / gStatModifierTable[STAT_SPDEFENSE][1];

        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | ---- DEF for opponent %d: %d\n", i, oppDef);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | ---- SPD for opponent %d: %d\n", i, oppSpdef);
        debugsyscall(buf);
        #endif
    }

    if (oppDef + oppSpdef == 0) {
        // No opponents were evaluated; just break out cleanly
        // and go to the next battler.
        return;
    }

    if (oppDef >= oppSpdef) {
        server->addlEffectParam = ADDL_EFFECT_SPA_UP_1;
    } else {
        server->addlEffectParam = ADDL_EFFECT_ATK_UP_1;
    }

    #ifdef DEBUG_SWITCHIN_EFFECTS
    sprintf(buf, "PLAT-ENGINE | ---- Setting up Download script from battler %d: +1 %s\n",
            battler, server->addlEffectParam == ADDL_EFFECT_ATK_UP_1 ? "ATK" : "SPA");
    debugsyscall(buf);
    #endif
    server->addlEffectType   = ADDL_EFFECT_FROM_ABILITY;
    server->addlEffectClient = battler;
    *nextScript = SUBSCR_BOOST_STATS;
    *processing = FALSE;
}

static inline BOOL IsPossibleOHKO(struct BattleServer *server, u16 moveID, int attacker, int defender)
{
    return server->aiWork.moveTable[moveID].effect == MOVE_EFFECT_ONE_HIT_KO
            && server->activePokemon[attacker].level >= server->activePokemon[defender].level;
}

BOOL __attribute__((long_call)) CheckLegalForAnticipation(struct BattleServer *server, u16 moveID);

static void ProcessAnticipation(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | -- Processing Anticipation from battler %d\n", battler);
    debugsyscall(buf);
    #endif

    for (int i = 0; i < numBattlers; i++) {
        if ((i & 1) == (battler & 1)    // If these have the same parity, they're allies
                || server->activePokemon[i].curHP == 0) {
            continue;
        }

        for (int j = 0; j < 4; j++) {
            u16 moveID = server->activePokemon[i].moves[j];
            if (moveID == 0) {
                continue;
            }

            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | ---- Considering move ID: %d\n", moveID);
            debugsyscall(buf);
            #endif

            u8 moveType = server->aiWork.moveTable[moveID].type;    // TODO: Use dynamic type for Hidden Power
            if (server->aiWork.moveTable[moveID].effect == MOVE_EFFECT_HIDDEN_POWER) {  // Hidden Power is treated as its effective type
                moveType = server->moveType;
            }

            u8 effectiveness = Calc_TypeEffectivenessPower(         // TODO: consider Levitate
                moveType,
                server->activePokemon[i].type1,
                server->activePokemon[i].type2
            );

            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | ------ Move Type: %d\n", moveType);
            debugsyscall(buf);
            sprintf(buf, "PLAT-ENGINE | ------ Matchup:   %d\n", effectiveness);
            debugsyscall(buf);
            #endif

            if (CheckLegalForAnticipation(server, moveID) == FALSE
                    && (effectiveness > 40 || IsPossibleOHKO(server, moveID, i, battler))) {
                server->clientWork = battler;
                *nextScript = SUBSCR_ANTICIPATION;
                *processing = FALSE;
                break;
            }
        }

        if (!*processing) {
            break;
        }
    }
}

static void ProcessForewarn(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | -- Processing Forewarn from battler %d\n", battler);
    debugsyscall(buf);
    #endif

    u8 maxPower = 0;
    for (int i = 0; i < numBattlers; i++) {
        if ((i & 1) == (battler & 1)    // If these have the same parity, they're allies
                || server->activePokemon[i].curHP == 0) {
            continue;
        }

        for (int j = 0; j < 4; j++) {
            u16 moveID = server->activePokemon[i].moves[j];
            u8 movePower = server->aiWork.moveTable[moveID].power;

            if (movePower == 1) {   // account for variable power
                switch (server->aiWork.moveTable[moveID].effect) {
                case MOVE_EFFECT_ONE_HIT_KO:
                    movePower = 150;
                    break;

                case MOVE_EFFECT_COUNTER:
                case MOVE_MIRROR_COAT:
                case MOVE_METAL_BURST:
                    movePower = 120;
                    break;

                default:
                    movePower = 80;
                    break;
                }
            }

            if (maxPower < movePower
                    || (maxPower == movePower && (Battle_Random(battle) & 1))) {
                maxPower = movePower;
                server->moveWork = moveID;
            }
        }
    }

    if (maxPower) {
        server->clientWork = battler;
        *nextScript = SUBSCR_FOREWARN;
        *processing = FALSE;
    }
}

static void ProcessFrisk(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    // Gen6 Frisk reveals the items of all foes.
    // This will be handled entirely within the script.
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | -- Setting up Frisk script from battler %d\n", battler);
    debugsyscall(buf);
    #endif

    server->clientWork = Battle_Opponent(battle, battler, 2);   // pass the client on the left first
    *nextScript = SUBSCR_FRISK;
    *processing = FALSE;
}

static void ProcessSlowStart(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | -- Processing Slow Start from battler %d\n", battler);
    debugsyscall(buf);
    #endif

    if (server->totalTurns <= server->activePokemon[battler].moveEffects.slowStartInitTurn) {
        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | ---- Setting up Slow Start init script\n", battler);
        debugsyscall(buf);
        #endif

        server->clientWork = battler;
        *nextScript = SUBSCR_APPLY_SLOW_START;
        *processing = FALSE;

        return;
    }

    if (server->activePokemon[battler].slowStartFinished == FALSE
            && server->totalTurns - server->activePokemon[battler].moveEffects.slowStartInitTurn == 5) {
        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | ---- Setting up Slow Start end script\n", battler);
        debugsyscall(buf);
        #endif

        server->activePokemon[battler].slowStartFinished = TRUE;
        server->clientWork = battler;
        *nextScript = SUBSCR_SLOW_START_END;
        *processing = FALSE;
    }
}

static void ProcessMoldBreaker(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    server->clientWork = battler;
    *nextScript = SUBSCR_MOLD_BREAKER;
    *processing = FALSE;
}

static void ProcessPressure(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    server->clientWork = battler;
    *nextScript = SUBSCR_PRESSURE;
    *processing = FALSE;
}

static void ProcessDrizzle(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    server->clientWork = battler;
    *nextScript = SUBSCR_DRIZZLE;
    *processing = FALSE;
}

static void ProcessDrought(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    server->clientWork = battler;
    *nextScript = SUBSCR_DROUGHT;
    *processing = FALSE;
}

static void ProcessSandStream(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    server->clientWork = battler;
    *nextScript = SUBSCR_SAND_STREAM;
    *processing = FALSE;
}

static void ProcessSnowWarning(struct Battle *battle, struct BattleServer *server, int numBattlers, int battler, int *nextScript, BOOL *processing)
{
    server->clientWork = battler;
    *nextScript = SUBSCR_SNOW_WARNING;
    *processing = FALSE;
}

static void ProcessAbilities(struct Battle *battle, struct BattleServer *server, int numBattlers, int *nextScript, BOOL *processing)
{
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    #endif

    int i;
    for (i = 0; i < numBattlers; i++) {
        int battler = server->pokemonSpeedWork[i];   // iterate by speed order
        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | -- %dth battler by speed: %d\n", i, battler);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | -- Battler's current HP: %d\n", server->activePokemon[battler].curHP);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | -- Ability already announced? %s\n", server->activePokemon[battler].abilityAnnounced ? "YES" : "NO");
        debugsyscall(buf);
        #endif

        // Verify that this battler should even be checked.
        if (server->activePokemon[battler].curHP == 0
                || server->activePokemon[battler].abilityAnnounced) {
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | ---- Skipping battler; no check\n");
            debugsyscall(buf);
            #endif

            continue;
        }

        server->activePokemon[battler].abilityAnnounced = TRUE;
        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | -- Ability newly announced? %s\n", server->activePokemon[battler].abilityAnnounced ? "YES" : "NO");
        debugsyscall(buf);
        #endif

        // Call the handler for this battler's ability. This is an if-tree instead of a
        // switch because Abilities handled by this routine are not uniformly-distributed.
        AbilityHandler handler;
        u16 ability = Server_Ability(server, battler);
        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | -- Ability: %s\n", sDebugAbilityNames[ability]);
        debugsyscall(buf);
        #endif

        switch (ability) {
            case ABILITY_INTIMIDATE:    handler = &ProcessIntimidate; break;
            case ABILITY_DOWNLOAD:      handler = &ProcessDownload; break;
            case ABILITY_ANTICIPATION:  handler = &ProcessAnticipation; break;
            case ABILITY_FOREWARN:      handler = &ProcessForewarn; break;
            case ABILITY_FRISK:         handler = &ProcessFrisk; break;
            case ABILITY_SLOW_START:    handler = &ProcessSlowStart; break;
            case ABILITY_MOLD_BREAKER:  handler = &ProcessMoldBreaker; break;
            case ABILITY_PRESSURE:      handler = &ProcessPressure; break;
            case ABILITY_DRIZZLE:       handler = &ProcessDrizzle; break;
            case ABILITY_DROUGHT:       handler = &ProcessDrought; break;
            case ABILITY_SAND_STREAM:   handler = &ProcessSandStream; break;
            case ABILITY_SNOW_WARNING:  handler = &ProcessSnowWarning; break;

            default:                    continue;
        }

        handler(battle, server, numBattlers, battler, nextScript, processing);

        #ifdef DEBUG_SWITCHIN_EFFECTS
        sprintf(buf, "PLAT-ENGINE | -- Next Script ID: %d\n", *nextScript);
        debugsyscall(buf);
        sprintf(buf, "PLAT-ENGINE | -- Continue Processing? %s\n", *processing ? "YES" : "NO");
        debugsyscall(buf);
        #endif

        // Check if we need to break through the machine's present iteration to invoke
        // the child subscript.
        if (*processing == FALSE) {
            break;
        }
    }

    // If we got through all of the battlers, tell the upstream processor to proceed
    // in the state machine.
    if (i == numBattlers) {
        server->serverSwitchInEffectsSeq++;
    }
}

static void ProcessFormChanges(struct Battle *battle, struct BattleServer *server, int numBattlers, int *nextScript, BOOL *processing)
{
    int i;
    for (i = 0; i < numBattlers; i++) {
        server->clientWork = server->pokemonSpeedWork[i];    // iterate by speed order
        if (server->activePokemon[server->clientWork].curHP == 0) {
            continue;
        }
        
        switch (server->activePokemon[server->clientWork].species) {
            case SPECIES_CASTFORM:
                // Castform's transformation is tied to Forecast
                if (Server_Ability(server, server->clientWork) != ABILITY_FORECAST) {
                    // Force Castform back to Normal form if it loses Forecast for whatever reason
                    if (server->activePokemon[server->clientWork].type1 != TYPE_NORMAL) {
                        goto CastformNormal;
                    }
                    break;
                }

                // No weather suppression in effect
                if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE)
                        || Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK)) {
                    // Force Castform back to Normal form if weather is suppressed
                    if (server->activePokemon[server->clientWork].type1 != TYPE_NORMAL) {
                        goto CastformNormal;
                    }
                    break;
                }

                // No Forecast-related weather; back to Normal type
                if ((server->fieldConditions.raw & FIELD_CONDITION_FORECAST) == 0
                        && server->activePokemon[server->clientWork].type1 != TYPE_NORMAL) {
                CastformNormal:
                    server->activePokemon[server->clientWork].type1 = TYPE_NORMAL;
                    server->activePokemon[server->clientWork].type2 = TYPE_NORMAL;
                    server->activePokemon[server->clientWork].formNum = 0;
                    *nextScript = SUBSCR_CHANGE_FORM;
                    *processing = FALSE;
                    return;
                } else if ((server->fieldConditions.raw & FIELD_CONDITION_SUNNY)
                        && server->activePokemon[server->clientWork].type1 != TYPE_FIRE) {
                    server->activePokemon[server->clientWork].type1 = TYPE_FIRE;
                    server->activePokemon[server->clientWork].type2 = TYPE_FIRE;
                    server->activePokemon[server->clientWork].formNum = 1;
                    *nextScript = SUBSCR_CHANGE_FORM;
                    *processing = FALSE;
                    return;
                } else if ((server->fieldConditions.raw & FIELD_CONDITION_RAINING)
                        && server->activePokemon[server->clientWork].type1 != TYPE_WATER) {
                    server->activePokemon[server->clientWork].type1 = TYPE_WATER;
                    server->activePokemon[server->clientWork].type2 = TYPE_WATER;
                    server->activePokemon[server->clientWork].formNum = 2;
                    *nextScript = SUBSCR_CHANGE_FORM;
                    *processing = FALSE;
                    return;
                } else if ((server->fieldConditions.raw & FIELD_CONDITION_HAILING)
                        && server->activePokemon[server->clientWork].type1 != TYPE_ICE) {
                    server->activePokemon[server->clientWork].type1 = TYPE_ICE;
                    server->activePokemon[server->clientWork].type2 = TYPE_ICE;
                    server->activePokemon[server->clientWork].formNum = 3;
                    *nextScript = SUBSCR_CHANGE_FORM;
                    *processing = FALSE;
                    return;
                }

                break;

            case SPECIES_CHERRIM:
                if (Server_Ability(server, server->clientWork) != ABILITY_FLOWER_GIFT) {
                    goto CherrimOvercastForm;
                }

                if (Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_CLOUD_NINE)
                        || Server_CheckAbility(battle, server, CHECK_ABILITY_ACTIVE, 0, ABILITY_AIR_LOCK)) {
                    goto CherrimOvercastForm;
                }

                if ((server->fieldConditions.raw & FIELD_CONDITION_SUNNY) == 0) {
                    goto CherrimOvercastForm;
                } else if (server->activePokemon[server->clientWork].formNum == 0) {
                    // Change to Sunshine Form
                    server->activePokemon[server->clientWork].formNum = 1;
                    *nextScript = SUBSCR_CHANGE_FORM;
                    *processing = FALSE;

                    return;
                }

            CherrimOvercastForm:
                if (server->activePokemon[server->clientWork].formNum == 1) {
                    // Change to Overcast Form
                    server->activePokemon[server->clientWork].formNum = 0;
                    *nextScript = SUBSCR_CHANGE_FORM;
                    *processing = FALSE;
                }

                break;

            case SPECIES_GIRATINA:
                if (server->activePokemon[server->clientWork].formNum == 1) {
                    /*
                     * Mons that transformed into Giratina-Origin should not try to transform
                     * back to Giratina-Altered.
                     */
                    if (server->activePokemon[server->clientWork].condition2 & CONDITION_V_TRANSFORMED) {
                        break;
                    }

                    // Giratina-Origin can only exist in the Distortion World or if it is
                    // holding the Griseous Orb.
                    if (server->activePokemon[server->clientWork].heldItem != ITEM_GRISEOUS_ORB
                            || (Battle_StatusFlag(battle) & BATTLE_STATUS_DISTORTION) == 0) {
                        *nextScript = SUBSCR_GIRATINA_FORM_CHECK;
                        *processing = FALSE;
                        return;
                    }
                // Change to Origin Form if we are given a Griseous Orb
                } else if (server->activePokemon[server->clientWork].heldItem == ITEM_GRISEOUS_ORB) {
                    *nextScript = SUBSCR_GIRATINA_FORM_CHECK;
                    *processing = FALSE;
                    return;
                }

                break;

            // vanilla gen4 used to check for arceus here to handle cases where
            // a mon would transform into it but was holding a different plate
            // those cases are irrelevant with gen5+ logic

            default:
                break;
        }
    }

    if (i == numBattlers) {
        server->serverSwitchInEffectsSeq++;
    }
}

static void ProcessStatusRecovery(struct Battle *battle, struct BattleServer *server, int numBattlers, int *nextScript, BOOL *processing)
{
    int i;
    for (i = 0; i < numBattlers; i++) {
        int battler = server->pokemonSpeedWork[i];    // iterate by speed order
        if (server->activePokemon[battler].curHP == 0) {
            continue;
        }
        
        // Check for items, then for abilities (updated for gen5+ logic)
        int itemEffect = Server_HeldItemEffect(server, battler);
        int itemPower  = Server_HeldItemPower(server, battler, 0);

        // TODO: Can we extract this into a separate function? Other items
        // will probably get added, and this logic is replicated in vanilla.
        switch (itemEffect) {
            case HOLD_EFFECT_RESTORE_HP:
                // Oran Berry, Berry Juice
                if (server->activePokemon[battler].curHP <= (server->activePokemon[battler].maxHP / 2)) {
                    server->hpCalcWork = itemPower;
                    *nextScript = SUBSCR_ITEM_HP_RESTORE;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_RESTORE_PERCENT_HP:
                // Sitrus Berry
                if (server->activePokemon[battler].curHP <= (server->activePokemon[battler].maxHP / 2)) {
                    server->hpCalcWork = Server_DivideBy(server->activePokemon[battler].maxHP * itemPower, 100);
                    *nextScript = SUBSCR_ITEM_HP_RESTORE;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_CURE_ALL:
                if ((server->activePokemon[battler].condition & CONDITION_STATUSED)
                        || (server->activePokemon[battler].condition2 & CONDITION_V_CONFUSED)) {
                    if (server->activePokemon[battler].condition & CONDITION_BURNED) {
                        *nextScript = SUBSCR_ITEM_RECOVER_BRN;
                    }
                    if (server->activePokemon[battler].condition & CONDITION_ASLEEP) {
                        *nextScript = SUBSCR_ITEM_RECOVER_SLP;
                    }
                    if (server->activePokemon[battler].condition & CONDITION_PARALYZED) {
                        *nextScript = SUBSCR_ITEM_RECOVER_PRZ;
                    }
                    if (server->activePokemon[battler].condition & CONDITION_FROZEN) {
                        *nextScript = SUBSCR_ITEM_RECOVER_FRZ;
                    }
                    if (server->activePokemon[battler].condition & CONDITION_POISON_ALL) {
                        *nextScript = SUBSCR_ITEM_RECOVER_PSN;
                    }
                    if (server->activePokemon[battler].condition2 & CONDITION_V_CONFUSED) {
                        *nextScript = SUBSCR_ITEM_RECOVER_CNF;
                    }
                    if ((server->activePokemon[battler].condition & CONDITION_STATUSED)
                            && (server->activePokemon[battler].condition2 & CONDITION_V_CONFUSED)) {
                        *nextScript = SUBSCR_ITEM_RECOVER_ALL;
                    }

                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_CURE_BRN:
                if (server->activePokemon[battler].condition & CONDITION_BURNED) {
                    *nextScript = SUBSCR_ITEM_RECOVER_BRN;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_CURE_CNF:
                if (server->activePokemon[battler].condition2 & CONDITION_V_CONFUSED) {
                    *nextScript = SUBSCR_ITEM_RECOVER_CNF;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_CURE_FRZ:
                if (server->activePokemon[battler].condition & CONDITION_FROZEN) {
                    *nextScript = SUBSCR_ITEM_RECOVER_FRZ;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_CURE_PRZ:
                if (server->activePokemon[battler].condition & CONDITION_PARALYZED) {
                    *nextScript = SUBSCR_ITEM_RECOVER_PRZ;
                    *processing = FALSE;
                }
                break;
            
            case HOLD_EFFECT_CURE_PSN:
                if (server->activePokemon[battler].condition & CONDITION_POISON_ALL) {
                    *nextScript = SUBSCR_ITEM_RECOVER_PSN;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_CURE_SLP:
                if (server->activePokemon[battler].condition & CONDITION_ASLEEP) {
                    *nextScript = SUBSCR_ITEM_RECOVER_SLP;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_MENTAL_HERB:
                if (server->activePokemon[battler].condition2 & CONDITION_V_INFATUATED) {
                    server->messageWork = MSG_COND_INFATUATED;
                    *nextScript = SUBSCR_ITEM_RECOVER_INF;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_RESTORE_PP:
                int j;
                for (j = 0; j < 4; j++) {
                    if (server->activePokemon[battler].moves[j]
                            && server->activePokemon[battler].curPP[j] == 0) {
                        break;
                    }
                }

                if (j != 4) {
                    BattlePokemon_Add(&server->activePokemon[battler], BATTLE_MON_PARAM_PP_1 + j, itemPower);
                    Server_CopyBattleMonData(battle, server, battler);

                    server->moveWork = server->activePokemon[battler].moves[j];
                    *nextScript = SUBSCR_ITEM_PP_RESTORE;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_PINCH_WIDE_LENS_ON_NEXT:
                if (Server_Ability(server, battler) == ABILITY_GLUTTONY) {
                    itemPower /= 2;
                }

                if (server->activePokemon[battler].curHP <= (server->activePokemon[battler].maxHP / itemPower)) {
                    *nextScript = SUBSCR_ITEM_ACC_UP_ONCE;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_WHITE_HERB:
                for (int j = 0; j < 8; j++) {
                    if (server->activePokemon[battler].statBoosts[j] < 6) {
                        server->activePokemon[battler].statBoosts[j] = 6;
                        *processing = FALSE;
                    }
                }

                if (!*processing) {
                    *nextScript = SUBSCR_ITEM_RECOVER_STAT_DROP;
                }
                break;

            case HOLD_EFFECT_RESTORE_PERCENT_HP_BITTER:
                server->messageWork = FLAVOR_BITTER;
                goto FlavorBerryCheck;

            case HOLD_EFFECT_RESTORE_PERCENT_HP_DRY:
                server->messageWork = FLAVOR_DRY;
                goto FlavorBerryCheck;

            case HOLD_EFFECT_RESTORE_PERCENT_HP_SOUR:
                server->messageWork = FLAVOR_SOUR;
                goto FlavorBerryCheck;

            case HOLD_EFFECT_RESTORE_PERCENT_HP_SPICY:
                server->messageWork = FLAVOR_SPICY;
                goto FlavorBerryCheck;

            case HOLD_EFFECT_RESTORE_PERCENT_HP_SWEET:
                server->messageWork = FLAVOR_SWEET;
            
            FlavorBerryCheck:
                // TODO: Update with configurable options + Gluttony support
                if (server->activePokemon[battler].curHP <= (server->activePokemon[battler].maxHP / 2)) {
                    server->hpCalcWork = Server_DivideBy(server->activePokemon[battler].maxHP, itemPower);
                    if (Pokemon_CheckTaste(server->activePokemon[battler].pid, server->messageWork) == -1) {
                        *nextScript = SUBSCR_ITEM_HP_RESTORE_CNF;
                    } else {
                        *nextScript = SUBSCR_ITEM_HP_RESTORE;
                    }

                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_PINCH_BOOST_ATTACK:
                server->messageWork = STAT_ATTACK;
                goto PinchBoostBerry;

            case HOLD_EFFECT_PINCH_BOOST_DEFENSE:
                server->messageWork = STAT_DEFENSE;
                goto PinchBoostBerry;

            case HOLD_EFFECT_PINCH_BOOST_SPEED:
                server->messageWork = STAT_SPEED;
                goto PinchBoostBerry;

            case HOLD_EFFECT_PINCH_BOOST_SPATK:
                server->messageWork = STAT_SPATTACK;
                goto PinchBoostBerry;

            case HOLD_EFFECT_PINCH_BOOST_SPDEF:
                server->messageWork = STAT_SPDEFENSE;
                
            PinchBoostBerry:
                if (Server_Ability(server, battler) == ABILITY_GLUTTONY) {
                    itemPower /= 2;
                }

                if (server->activePokemon[battler].curHP <= (server->activePokemon[battler].maxHP / itemPower)
                        && server->activePokemon[battler].statBoosts[server->messageWork] < 12) {
                    *nextScript = SUBSCR_ITEM_STAT_BOOST;
                    *processing = FALSE;
                }
                break;
                
            case HOLD_EFFECT_PINCH_BOOST_CRIT:
                if (Server_Ability(server, battler) == ABILITY_GLUTTONY) {
                    itemPower /= 2;
                }

                if (server->activePokemon[battler].curHP <= (server->activePokemon[battler].maxHP / itemPower)
                        && (server->activePokemon[battler].condition2 & CONDITION_V_PUMPED) == FALSE) {
                    *nextScript = SUBSCR_ITEM_RAISE_CRIT;
                    *processing = FALSE;
                }
                break;

            case HOLD_EFFECT_PINCH_DOUBLE_BOOST_RANDOM:
                if (Server_Ability(server, battler) == ABILITY_GLUTTONY) {
                    itemPower /= 2;
                }

                if (server->activePokemon[battler].curHP <= (server->activePokemon[battler].maxHP / itemPower)) {
                    int j;
                    for (j = 0; j < 5; j++) {
                        if (server->activePokemon[battler].statBoosts[STAT_ATTACK + j] < 12) {
                            break;
                        }
                    }

                    if (j != 5) {
                        do {
                            j = Battle_Random(battle) % 5;
                        } while (server->activePokemon[battler].statBoosts[STAT_ATTACK + j] == 12);
                        server->messageWork = STAT_ATTACK + j;
                        *nextScript = SUBSCR_ITEM_STAT_BOOST_2;
                        *processing = FALSE;
                    }
                }
                break;
        }

        // if an item activates, break out
        if (!*processing) {
            server->clientWork = battler;
            server->itemWork = server->activePokemon[battler].heldItem;

            return;
        }

        // Now check abilities
        switch (Server_Ability(server, battler)) {
            case ABILITY_IMMUNITY:
                if (server->activePokemon[battler].condition & CONDITION_POISON_ALL) {
                    server->messageWork = MSG_COND_POISONED;
                    *processing = FALSE;
                }
                break;

            case ABILITY_LIMBER:
                if (server->activePokemon[battler].condition & CONDITION_PARALYZED) {
                    server->messageWork = MSG_COND_PARALYZED;
                    *processing = FALSE;
                }
                break;

            case ABILITY_INSOMNIA:
                // fallthrough
            case ABILITY_VITAL_SPIRIT:
                if (server->activePokemon[battler].condition & CONDITION_ASLEEP) {
                    server->messageWork = MSG_COND_ASLEEP;
                    *processing = FALSE;
                }
                break;

            case ABILITY_WATER_VEIL:
                if (server->activePokemon[battler].condition & CONDITION_BURNED) {
                    server->messageWork = MSG_COND_BURNED;
                    *processing = FALSE;
                }
                break;

            case ABILITY_MAGMA_ARMOR:
                if (server->activePokemon[battler].condition & CONDITION_FROZEN) {
                    server->messageWork = MSG_COND_FROZEN;
                    *processing = FALSE;
                }
                break;

            case ABILITY_OWN_TEMPO:
                if (server->activePokemon[battler].condition2 & CONDITION_V_CONFUSED) {
                    server->messageWork = MSG_COND_CONFUSED;
                    *processing = FALSE;
                }
                break;

            case ABILITY_OBLIVIOUS:
                if (server->activePokemon[battler].condition2 & CONDITION_V_INFATUATED) {
                    server->messageWork = MSG_COND_INFATUATED;
                    *processing = FALSE;
                }
                break;

            case ABILITY_UNBURDEN:
                if (server->activePokemon[battler].heldItem) {
                    server->activePokemon[battler].moveEffects.canUnburden = 1;
                }
                break;
        }

        if (!*processing) {
            server->clientWork = battler;
            server->abilityWork = Server_Ability(server, battler);
        }
    }

    if (i == numBattlers) {
        server->serverSwitchInEffectsSeq++;
    }
}

enum {
    SWITCHFX_WEATHER = 0,
    SWITCHFX_TRACE,
    SWITCHFX_ABILITIES,
    SWITCHFX_FORM_CHANGES,
    SWITCHFX_AMULET_COIN,
    SWITCHFX_STATUS_RECOVERY,
    SWITCHFX_END
};

int Server_CheckSwitchInEffects(struct Battle *battle, struct BattleServer *server)
{
    int numBattlers = Battle_NumBattlers(battle);
    int nextScript  = 0;    // child subscript to execute
    BOOL processing = TRUE; // checks if we need to break out of the loop to execute a child subscript
    #ifdef DEBUG_SWITCHIN_EFFECTS
    u8 buf[128];
    #endif

    while (processing) {
        switch (server->serverSwitchInEffectsSeq) {
        case SWITCHFX_WEATHER:
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | STATE: Field Weather Check\n");
            debugsyscall(buf);
            #endif

            if (server->fieldWeatherChecked) {
                #ifdef DEBUG_SWITCHIN_EFFECTS
                sprintf(buf, "[PLAT-ENGINE] Field weather already checked; skipping");
                debugsyscall(buf);
                #endif

                break;
            }

            switch (Battle_FieldWeather(battle)) {
                case WEATHER_RAINING:
                case WEATHER_HEAVY_RAIN:
                case WEATHER_THUNDERSTORM:
                    #ifdef DEBUG_SWITCHIN_EFFECTS
                    sprintf(buf, "[PLAT-ENGINE] Field weather is Rain");
                    debugsyscall(buf);
                    #endif

                    nextScript = SUBSCR_OVERWORLD_RAIN;
                    processing = FALSE;
                    break;
                
                case WEATHER_SNOWING:
                case WEATHER_HEAVY_SNOW:
                case WEATHER_BLIZZARD:
                    #ifdef DEBUG_SWITCHIN_EFFECTS
                    sprintf(buf, "[PLAT-ENGINE] Field weather is Hail");
                    debugsyscall(buf);
                    #endif

                    nextScript = SUBSCR_OVERWORLD_HAIL;
                    processing = FALSE;
                    break;
                
                case WEATHER_SANDSTORM:
                    #ifdef DEBUG_SWITCHIN_EFFECTS
                    sprintf(buf, "[PLAT-ENGINE] Field weather is Sand");
                    debugsyscall(buf);
                    #endif

                    nextScript = SUBSCR_OVERWORLD_SAND;
                    processing = FALSE;
                    break;
                
                case WEATHER_FOG:
                case WEATHER_DEEP_FOG:
                    #ifdef DEBUG_SWITCHIN_EFFECTS
                    sprintf(buf, "[PLAT-ENGINE] Field weather is Fog");
                    debugsyscall(buf);
                    #endif

                    nextScript = SUBSCR_OVERWORLD_FOG;
                    processing = FALSE;
                    break;
                
                case WEATHER_HARSH_SUN:
                    #ifdef DEBUG_SWITCHIN_EFFECTS
                    sprintf(buf, "[PLAT-ENGINE] Field weather is Sun");
                    debugsyscall(buf);
                    #endif

                    nextScript = SUBSCR_OVERWORLD_SUN;
                    processing = FALSE;
                    break;
                
                case WEATHER_TRICK_ROOM:
                    #ifdef DEBUG_SWITCHIN_EFFECTS
                    sprintf(buf, "[PLAT-ENGINE] Field weather is Trick Room");
                    debugsyscall(buf);
                    #endif

                    nextScript = SUBSCR_OVERWORLD_TRICK_ROOM;
                    processing = FALSE;
                    break;
                
                default:
                    break;
            }

            if (!processing) {
                server->fieldWeatherChecked = TRUE;
            }

            server->serverSwitchInEffectsSeq++;
            break;

        case SWITCHFX_TRACE:
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | STATE: Trace Check\n");
            debugsyscall(buf);
            #endif

            ProcessTrace(battle, server, numBattlers, &nextScript, &processing);
            break;

        case SWITCHFX_ABILITIES:
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | STATE: Abilities Check\n");
            debugsyscall(buf);
            #endif

            ProcessAbilities(battle, server, numBattlers, &nextScript, &processing);
            break;
        
        case SWITCHFX_FORM_CHANGES:
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | STATE: Form Change Check\n");
            debugsyscall(buf);
            #endif

            // Forecast, Flower Gift, Giratina
            ProcessFormChanges(battle, server, numBattlers, &nextScript, &processing);
            break;

        case SWITCHFX_AMULET_COIN:
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | STATE: Amulet Coin Check\n");
            debugsyscall(buf);
            #endif

            for (int battler = 0; battler < numBattlers; battler++) {
                if (Server_HeldItemEffect(server, battler) == HOLD_EFFECT_DOUBLE_PRIZE_MONEY) {
                    server->moneyMultiplier = 2;
                }
            }

            server->serverSwitchInEffectsSeq++;
            break;

        case SWITCHFX_STATUS_RECOVERY:
            #ifdef DEBUG_SWITCHIN_EFFECTS
            sprintf(buf, "PLAT-ENGINE | STATE: Status Recovery Check\n");
            debugsyscall(buf);
            #endif

            ProcessStatusRecovery(battle, server, numBattlers, &nextScript, &processing);
            break;

        case SWITCHFX_END:
            server->serverSwitchInEffectsSeq = 0;
            processing = FALSE;
            break;
        }
    }

    return nextScript;
}
