#include "battle/common.h"
#include "battle/scio.h"
#include "battle/skillseq.h"

static int __attribute__((long_call)) ReadWord(struct BattleServer *server);
static int __attribute__((long_call)) BattlerClient(void *battle, struct BattleServer *server, int battler);

static BOOL __attribute__((long_call)) SkillSeq_LoadPopupGraphics(void *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) SkillSeq_FreePopupGraphics(void *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) SkillSeq_ShowPopup(void *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) SkillSeq_HidePopup(void *battle, struct BattleServer *server);

static const u8 sOriginalTableSize = 223;

static const SkillSeqCmd *sBattleScriptCommandTable_Old;  // SkillIntpTable

static const SkillSeqCmd sBattleScriptCommandTable_New[] = {
    SkillSeq_LoadPopupGraphics,
    SkillSeq_FreePopupGraphics,
    SkillSeq_ShowPopup,
    SkillSeq_HidePopup,
};

BOOL SkillSeq_Exec(void *battle, struct BattleServer *server)
{
    BOOL ret;
    while ((server->battleProgressFlag == 0) && (Battle_FightType(battle) & BATTLE_TYPE_LINK == 0)) {
        u32 word = server->moveSeqWork[server->moveSeqNum];
        if (word < sOriginalTableSize) {
            ret = sBattleScriptCommandTable_Old[word](battle, server);
        } else {
            ret = sBattleScriptCommandTable_New[sOriginalTableSize - word](battle, server);
        }
    }

    server->battleProgressFlag = 0;
    return ret;
}

#if 0   // old ability popup stuff

inline void IncScriptPtr(struct BattleServer *server, int incBy)
{
    server->moveSeqNum += incBy;
}

inline void SCIO_MessageClientCommandOnly(void *battle, struct BattleServer *server, int sendingClient, int command)
{
    IncScriptPtr(server, 1);

    SCIO_Message(battle, SCIO_CLIENT, sendingClient, &command, 4);
}

BOOL SkillSeq_LoadPopupGraphics(void *battle, struct BattleServer *server)
{
    SCIO_MessageClientCommandOnly(battle, server, 0, CLIENT_POPUP_RESOURCE_LOAD);

    return 0;
}

BOOL SkillSeq_FreePopupGraphics(void *battle, struct BattleServer *server)
{
    SCIO_MessageClientCommandOnly(battle, server, 0, CLIENT_POPUP_RESOURCE_FREE);

    return 0;
}

BOOL SkillSeq_ShowPopup(void *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    int side   = ReadWord(server);
    int client = BattlerClient(battle, server, side);
    SCIO_MessageClientCommandOnly(battle, server, client, CLIENT_POPUP_IN);
    
    return 0;
}

BOOL SkillSeq_HidePopup(void *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    int side   = ReadWord(server);
    int client = BattlerClient(battle, server, side);
    SCIO_MessageClientCommandOnly(battle, server, client, CLIENT_POPUP_OUT);
    
    return 0;
}

#endif
