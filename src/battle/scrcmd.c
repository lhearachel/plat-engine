#include "battle/common.h"
#include "battle/scio.h"
#include "battle/scrcmd.h"

//#define DEBUG_BATTLE_SCRIPTS
#define START_OF_NEW_BATTLE_SCRIPT_COMMANDS 0xDF

typedef BOOL (*BattleScrCmd)(void *battle, struct BattleServer *server);

extern const BattleScrCmd gBattleScriptCommandTable_Old[];

const BattleScrCmd gBattleScriptCommandTable_New[] = {
};

BOOL BattleScrCmd_Exec(void *battle, struct BattleServer *server)
{
    BOOL ret;
    u32 word;
#ifdef DEBUG_BATTLE_SCRIPTS
    u8 buf[64];
#endif
    
    do {
        word = server->moveSeqWork[server->moveSeqNum];
#ifdef DEBUG_BATTLE_SCRIPTS
        sprintf(buf, "Got word: %ld\n", word);
        debugsyscall(buf);
#endif // DEBUG_BATTLE_SCRIPTS

        if (word < START_OF_NEW_BATTLE_SCRIPT_COMMANDS) {
            ret = gBattleScriptCommandTable_Old[word](battle, server);
        } else {
            ret = gBattleScriptCommandTable_New[word - START_OF_NEW_BATTLE_SCRIPT_COMMANDS](battle, server);
        }
    } while ((server->battleProgressFlag == 0) && ((Battle_FightType(battle) & BATTLE_TYPE_LINK) == 0));

    server->battleProgressFlag = 0;
    return ret;
}

inline void IncScriptPtr(struct BattleServer *server, int incBy)
{
    server->moveSeqNum += incBy;
}
