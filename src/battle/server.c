#include "global.h"
#include "q412.h"

#include "constants/abilities.h"
#include "constants/misc.h"

#include "battle/common.h"
#include "battle/server.h"

#include "moves.h"

void Server_InitState(struct BattleServer *server)
{
    server->damage            = 0;
    server->critical          = FALSE;
    server->criticalCount     = 0;
    server->movePower         = 0;
    server->powerModifier     = UQ412__1_0;
    server->magnitude         = 0;
    server->moveType          = TYPE_NORMAL;
    server->moveEffectCounter = 0;
    server->moveStatusFlag    = 0;
    server->faintingClient    = 0xFF;

    server->addlDirectStatus   = 0;
    server->addlIndirectStatus = 0;
    server->addlAbilityStatus  = 0;
    server->addlEffectType     = ADDL_EFFECT_NONE;
    server->addlEffectParam    = 0;
    server->addlEffectClient   = 0xFF;

    server->continuationCounter      = 0;
    server->continuationCounterTemp  = 0;
    server->multiHitLoopCounter      = 0;
    server->loopingFlag              = FALSE;
    server->afterMoveFailMessageType = 0;
    server->moveFailedCheck          = FALSE;
    server->loopingHitCheck          = FALSE;

    server->fieldConditionCheck.seqNum  = 0;
    server->pokeConditionCheck.seqNum   = 0;
    server->sideConditionCheck.seqNum   = 0;
    server->beforeActions.seqNum        = 0;
    server->afterMoveHitCheck.seqNum    = 0;
    server->afterMoveFailMessageSeqNum  = 0;
    server->afterMoveFailEffects.seqNum = 0;
    server->beforeMoveSeq               = 0;
    server->moveFailCheckSeq            = 0;
    server->serverStatusCheckSeq        = 0;
    server->serverAbilityCheckSeq       = 0;

    server->serverStatusFlag  &= SERVER_STATUS_FLAG_START_OF_TURN;
    server->serverStatusFlag2 &= SERVER_STATUS_FLAG2_START_OF_TURN;

    for (int client = 0; client < 4; client++) {
        MemFill(0, &server->stSelfFX[client], sizeof(struct SelfSingleTurnEffects));
        server->aiSwitchSelectedMonNum[client] = 6;
    }
}

static inline DamageWasDealt(struct BattleServer *server)
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

    BOOL result = FALSE;
    switch (Server_Ability(server, server->defender)) {
    case ABILITY_STATIC:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Attacker has no present status condition
                && server->activePokemon[server->attacker].condition == 0
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // It is not turn one of a two-turn move (does this matter?)
                && (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
                // Damage was actually dealt
                && DamageWasDealt(server)
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
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
                // The move is not Struggle
                && server->moveIDCurr != MOVE_STRUGGLE
                // Damage was actually dealt
                && DamageWasDealt(server)
                // Move actually has a base power (seems superfluous with the above?)
                && server->aiWork.moveTable[server->moveIDCurr].power
                // The move's type does not match either of the user's current types
                && BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_1, NULL) != server->moveType
                && BattlePokemon_Get(server, server->defender, BATTLE_MON_PARAM_TYPE_2, NULL) != server->moveType) {
            server->messageWork = server->moveType;
            *seqNum = SUBSCR_COLOR_CHANGE;
            result  = TRUE;
        }
        break;
    case ABILITY_ROUGH_SKIN:
        // Attacker is still alive after the attack
        if (server->activePokemon[server->attacker].curHP
                // Attacker does not have Magic Guard
                && Server_Ability(server, server->attacker) != ABILITY_MAGIC_GUARD
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // It is not turn one of a two-turn move
                && (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
                // Damage was actually dealt
                && DamageWasDealt(server)
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
                // Attacker has no present status condition
                && server->activePokemon[server->attacker].condition == 0
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // It is not turn one of a two-turn move
                && (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
                // Damage was actually dealt
                && DamageWasDealt(server)
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
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // It is not turn one of a two-turn move
                && (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
                // Damage was actually dealt
                && DamageWasDealt(server)
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
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // It is not turn one of a two-turn move
                && (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
                // Damage was actually dealt
                && DamageWasDealt(server)
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
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // It is not turn one of a two-turn move
                && (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
                // Damage was actually dealt
                && DamageWasDealt(server)
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
                // The move should activate any effects after hitting
                && (server->moveStatusFlag & MOVE_STATUS_FLAG_NO_HIT_EFFECTS) == 0
                // The move is not a pivoting move (there is a separate checker for that)
                && (server->serverStatusFlag2 & SERVER_STATUS_FLAG2_PIVOT_MOVE) == 0
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
