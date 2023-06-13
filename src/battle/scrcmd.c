#include "battle/common.h"
#include "battle/scio.h"
#include "battle/scrcmd.h"

#if 0
static BOOL __attribute__((long_call)) SkillSeq_LoadPopupGraphics(void *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) SkillSeq_FreePopupGraphics(void *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) SkillSeq_ShowPopup(void *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) SkillSeq_HidePopup(void *battle, struct BattleServer *server);
#endif

static BOOL __attribute__((long_call)) BattleScrCmd_ShowAbility(void *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) BattleScrCmd_HideAbility(void *battle, struct BattleServer *server);

#define START_OF_NEW_BATTLE_SCRIPT_COMMANDS 0xDF

extern const BattleScrCmd gBattleScriptCommandTable_Old[];

const BattleScrCmd gBattleScriptCommandTable_New[] = {
    BattleScrCmd_ShowAbility,
    BattleScrCmd_HideAbility,
};

BOOL BattleScrCmd_Exec(void *battle, struct BattleServer *server)
{
    BOOL ret = FALSE;
    u8 buf[32];
    
    while ((server->battleProgressFlag == 0) && ((Battle_FightType(battle) & BATTLE_TYPE_LINK) == 0)) {
        u32 word = server->moveSeqWork[server->moveSeqNum];

        sprintf(buf, "Starting cmd %ld\n", word);
        debugsyscall(buf);
        if (word < START_OF_NEW_BATTLE_SCRIPT_COMMANDS) {
            ret = gBattleScriptCommandTable_Old[word](battle, server);
        } else {
            ret = gBattleScriptCommandTable_New[word - START_OF_NEW_BATTLE_SCRIPT_COMMANDS](battle, server);
        }
    }

    server->battleProgressFlag = 0;
    return ret;
}

inline void IncScriptPtr(struct BattleServer *server, int incBy)
{
    server->moveSeqNum += incBy;
}

// ========================================================================= //
//                           ABILITY POPUPS                                  //
// ========================================================================= //

#define ABILITY_POPUP_MESSAGE_ID 1269   // TODO: move this to a better place

static BOOL BattleScrCmd_ShowAbility(void *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    // Parameters:
    //      - client number
    int abilityClient = BattleScrCmd_ReadWord(server);
    
    struct MessageParams msgParams = {
        .commandCode = CLIENT_SHOW_ABILITY,
        .id          = ABILITY_POPUP_MESSAGE_ID,
        .tag         = 11,  // TAG_NICK_ABILITY
    };
    msgParams.params[0] = abilityClient;
    msgParams.params[1] = server->activePokemon[abilityClient].ability;

    SCIO_Message(battle, SCIO_CLIENT, server->attacker, &msgParams, sizeof(struct MessageParams));

    return FALSE;
}

static BOOL BattleScrCmd_HideAbility(void *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    int command = CLIENT_HIDE_ABILITY;
    SCIO_Message(battle, SCIO_CLIENT, server->attacker, &command, 4);

    return FALSE;
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
