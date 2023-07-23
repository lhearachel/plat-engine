#include "global.h"
#include "q412.h"
#include "archive.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/misc.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/server.h"

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
                // The move's type does not match either of the user's current types
                && BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_1, NULL) != server->moveType
                && BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_2, NULL) != server->moveType) {
            server->messageWork = server->moveType;
            *seqNum = SUBSCR_COLOR_CHANGE;
            result  = TRUE;
        }
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
