#include "heap.h"

#include "battle/client.h"
#include "battle/scio.h"
#include "battle/server.h"

#include "ui/battle.h"

extern const ClientFunc gClientFunctionTable_Old[]; // 0x0226F068

const ClientFunc gClientFunctionTable_New[] = {
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
