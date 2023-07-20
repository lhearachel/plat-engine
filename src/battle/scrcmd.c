#include "config.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/scio.h"
#include "battle/scrcmd.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/misc.h"

static BOOL __attribute__((long_call)) BattleScrCmd_CheckPowderImmunity(struct Battle *battle, struct BattleServer *server);

#define START_OF_NEW_BATTLE_SCRIPT_COMMANDS 0xDF

typedef BOOL (*BattleScrCmd)(struct Battle *battle, struct BattleServer *server);

extern const BattleScrCmd gBattleScriptCommandTable_Old[];

const BattleScrCmd gBattleScriptCommandTable_New[] = {
    BattleScrCmd_CheckPowderImmunity,
};

BOOL BattleScrCmd_Exec(struct Battle *battle, struct BattleServer *server)
{
    BOOL ret;
    u32 word;
#ifdef DEBUG_MODE
    u8 buf[64];
    sprintf(buf, "[PLAT-ENGINE] moveSeqNum: %ld\n", OFFSET_OF(struct BattleServer, moveSeqNum));
    debugsyscall(buf);
    sprintf(buf, "[PLAT-ENGINE] moveSeqWork: %ld\n", OFFSET_OF(struct BattleServer, moveSeqWork));
    debugsyscall(buf);
#endif
    
    do {
        word = server->moveSeqWork[server->moveSeqNum];
#ifdef DEBUG_MODE
        sprintf(buf, "[PLAT-ENGINE] Got word: %ld\n", word);
        debugsyscall(buf);
#endif // DEBUG_BATTLE_SCRIPTS

        if (word < START_OF_NEW_BATTLE_SCRIPT_COMMANDS) {
            ret = gBattleScriptCommandTable_Old[word](battle, server);
        } else {
            ret = gBattleScriptCommandTable_New[word - START_OF_NEW_BATTLE_SCRIPT_COMMANDS](battle, server);
        }
    } while ((server->battleProgressFlag == 0) && ((Battle_Type(battle) & BATTLE_TYPE_LINK) == 0));

    server->battleProgressFlag = 0;
    return ret;
}

inline void IncScriptPtr(struct BattleServer *server, int incBy)
{
    server->moveSeqNum += incBy;
}

static BOOL BattleScrCmd_CheckPowderImmunity(struct Battle *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    int battler              = BattleScrCmd_ReadWord(server);
    int jumpIfTypeBlocked    = BattleScrCmd_ReadWord(server);
    int jumpIfAbilityBlocked = BattleScrCmd_ReadWord(server);
    int jumpIfItemBlocked    = BattleScrCmd_ReadWord(server);

    if (Moves_IsPowder(server->moveWork)) {
        if ((server->activePokemon[battler].type1 == TYPE_GRASS)
                || (server->activePokemon[battler].type2 == TYPE_GRASS)) {
            IncScriptPtr(server, jumpIfTypeBlocked);
        } else if (server->activePokemon[battler].ability == ABILITY_OVERCOAT) {
            IncScriptPtr(server, jumpIfAbilityBlocked);
        } else if (Server_HeldItemEffect(server, battler) == HOLD_EFFECT_SAFETY_GOGGLES) {
            IncScriptPtr(server, jumpIfItemBlocked);
        }
    }

    return FALSE;
}
