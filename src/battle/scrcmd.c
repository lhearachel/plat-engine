#include "config.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/scio.h"
#include "battle/scrcmd.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/misc.h"

static BOOL __attribute__((long_call)) BattleScrCmd_CheckLeaveWith1HP(struct Battle *battle, struct BattleServer *server);
static BOOL __attribute__((long_call)) BattleScrCmd_CheckPowderImmunity(struct Battle *battle, struct BattleServer *server);

#define START_OF_NEW_BATTLE_SCRIPT_COMMANDS 0xDF

typedef BOOL (*BattleScrCmd)(struct Battle *battle, struct BattleServer *server);

extern const BattleScrCmd gBattleScriptCommandTable_Old[];  // Do NOT EVER change this to a pointer from an array or everything breaks

const BattleScrCmd gBattleScriptCommandTable_New[] = {
    BattleScrCmd_CheckPowderImmunity,
};

BOOL BattleScrCmd_Exec(struct Battle *battle, struct BattleServer *server)
{
    BOOL result;
    do {
        u32 word = server->moveSeqWork[server->moveSeqNum];
        if (word < START_OF_NEW_BATTLE_SCRIPT_COMMANDS) {
            result = gBattleScriptCommandTable_Old[word](battle, server);
        } else {
            result = gBattleScriptCommandTable_New[word - START_OF_NEW_BATTLE_SCRIPT_COMMANDS](battle, server);
        }
    } while ((server->battleProgressFlag == 0) && ((Battle_Type(battle) & BATTLE_TYPE_LINK) == 0));

    server->battleProgressFlag = 0;
    return result;
}

inline void IncScriptPtr(struct BattleServer *server, int incBy)
{
    server->moveSeqNum += incBy;
}

static BOOL BattleScrCmd_CheckLeaveWith1HP(struct Battle *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    /*
     * Args: battler
     */
    int battler = BattleScrCmd_ReadWord(server);
    battler     = BattleScrCmd_TrueBattler(battle, server, battler);

    int heldItemEffect = Server_HeldItemEffect(server, battler);
    int heldItemPower  = Server_HeldItemPower(server, battler, 0);

    BOOL triggered = FALSE;
    if (heldItemEffect == HOLD_EFFECT_FOCUS_BAND && (Battle_Random(battle) % 100) < heldItemPower) {
        triggered = TRUE;
    }

    if (heldItemEffect == HOLD_EFFECT_FOCUS_SASH
            && server->activePokemon[battler].curHP == server->activePokemon[battler].maxHP) {
        triggered = TRUE;
    }

    if (triggered) {
        if (server->activePokemon[battler].curHP + server->hpCalcWork <= 0) {
            server->hpCalcWork      = (server->activePokemon[battler].curHP - 1) * -1;
            server->moveStatusFlag |= MOVE_STATUS_FLAG_HELD_ON_WITH_ITEM;
        }
    }

    return FALSE;
}

static BOOL BattleScrCmd_CheckPowderImmunity(struct Battle *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    /*
     * Args: battler
     *       jump distance if blocked by type
     *       jump distance if blocked by ability
     *       jump distance if blocked by item
     */
    int battler              = BattleScrCmd_ReadWord(server);
    int jumpIfTypeBlocked    = BattleScrCmd_ReadWord(server);
    int jumpIfAbilityBlocked = BattleScrCmd_ReadWord(server);
    int jumpIfItemBlocked    = BattleScrCmd_ReadWord(server);

    battler = BattleScrCmd_TrueBattler(battle, server, battler);
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
