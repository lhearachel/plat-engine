#include "battle/client.h"
#include "battle/scio.h"

static const ClientFunc *sClientFunctionTable_Old; // 0x0226F068

static const ClientFunc sClientFunctionTable_New[] = {
    Client_PopupResourceFree,
    Client_PopupResourceLoad,
    Client_PopupShow,
    Client_PopupHide,
};

void ClientCommand_Main(void *battle, struct BattleClient *client)
{
    if (client->commandBuffer[0]) {
        client->clientBufferFlag = 0;
        
        int commandCode = client->commandBuffer[0];
        if (commandCode < CLIENT_NUM_VANILLA_MESSAGES) {
            sClientFunctionTable_Old[commandCode](battle, client);
        } else {
            sClientFunctionTable_New[commandCode - CLIENT_NUM_VANILLA_MESSAGES](battle, client);
        }
    }
}
