#include "global.h"
#include "q412.h"

#include "constants/misc.h"

#include "battle/common.h"
#include "battle/server.h"

void __attribute__((long_call)) Server_InitState(struct BattleServer *server)
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
