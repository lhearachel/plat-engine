#include "heap.h"

#include "battle/client.h"
#include "battle/scio.h"
#include "battle/server.h"

#include "ui/battle.h"

static void __attribute__((long_call)) Client_ShowAbility(struct Battle *battle, struct BattleClient *client);
static void __attribute__((long_call)) Client_HideAbility(struct Battle *battle, struct BattleClient *client);

extern const ClientFunc gClientFunctionTable_Old[]; // 0x0226F068

const ClientFunc gClientFunctionTable_New[] = {
    Client_ShowAbility,
    Client_HideAbility,
};

void ClientCommand_Main(struct Battle *battle, struct BattleClient *client)
{
    if (client->commandBuffer[0]) {
        client->clientBufferFlag = 0;
        
        int commandCode = client->commandBuffer[0];
        if (commandCode < CLIENT_NUM_VANILLA_MESSAGES) {
            gClientFunctionTable_Old[commandCode](battle, client);
        } else {
            gClientFunctionTable_New[commandCode - CLIENT_NUM_VANILLA_MESSAGES](battle, client);
        }
    }
}

// ========================================================================= //
//                           ABILITY POPUPS                                  //
// ========================================================================= //

struct WaitMessageTask {
    void *battle;

    u8   commandCode;
    u8   clientNum;
    u8   msgIndex;
    u8   _dummyPadding;
};

static BOOL __attribute__((long_call)) CheckStillPrinting(u8 msgIndex); // 0x0201D6F8

static void TaskControl_WaitMessage(void *taskControl, void *taskData)
{
    struct WaitMessageTask *wait = taskData;

    if (CheckStillPrinting(wait->msgIndex) == FALSE) {
        SCIO_ClearQueue(wait->battle, wait->clientNum, wait->commandCode);
        Free(taskData);
        TaskControl_Delete(taskControl);
    }
}

static void Client_ShowAbility(struct Battle *battle, struct BattleClient *client)
{
    struct MessageParams *msgParams = (struct MessageParams*) &(client->commandBuffer[0]);
    struct WaitMessageTask *wait    = Malloc(HEAP_ID_BATTLE, sizeof(struct WaitMessageTask));
    wait->battle      = battle;
    wait->commandCode = msgParams->commandCode;
    wait->clientNum   = client->clientNum;
    wait->msgIndex    = BattleUI_PrintPopupMessage(battle, msgParams);

    TaskControl_Add(TaskControl_WaitMessage, wait, 0);
    ClientCommand_Reset(client);
}

static void Client_HideAbility(struct Battle *battle, struct BattleClient *client)
{
    BattleUI_ClosePopupMessage();
    
    ClientCommand_Reset(client);
}
