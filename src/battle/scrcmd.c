#include "config.h"

#include "battle/common.h"
#include "battle/moves.h"
#include "battle/scio.h"
#include "battle/scrcmd.h"

#include "constants/abilities.h"
#include "constants/item_hold_effects.h"
#include "constants/misc.h"

// Old script commands
BOOL BattleScrCmd_CheckLeaveWith1HP(struct Battle *battle, struct BattleServer *server);
BOOL BattleScrCmd_StatBoostChange(struct Battle *battle, struct BattleServer *server);

// New script commands
BOOL BattleScrCmd_CheckPowderImmunity(struct Battle *battle, struct BattleServer *server);

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

BOOL BattleScrCmd_CheckLeaveWith1HP(struct Battle *battle, struct BattleServer *server)
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

static inline BOOL CheckAbilityPreventsStatLoss(struct BattleServer *server, u16 ability, int blockedStat, int targetedStat)
{
    return Server_CheckDefenderAbility(server, server->attacker, server->addlEffectClient, ability)
            && (blockedStat == STAT_ATTACK + targetedStat);
}

BOOL BattleScrCmd_StatBoostChange(struct Battle *battle, struct BattleServer *server)
{
    IncScriptPtr(server, 1);

    /*
     * Args: jump distance if no change
     *       jump distance if change is blocked
     *       jump distance if change is blocked by Substitute
     */
    int jumpIfNoChange   = BattleScrCmd_ReadWord(server);
    int jumpIfBlocked    = BattleScrCmd_ReadWord(server);
    int jumpIfSubstitute = BattleScrCmd_ReadWord(server);

    struct BattlePokemon *mon = &server->activePokemon[server->addlEffectClient];
    server->serverStatusFlag &= ~SERVER_STATUS_FLAG_STAT_CHANGE_FAILED;

    int stat, change;
    if (server->addlEffectParam >= ADDL_EFFECT_ATK_DOWN_2) {
        stat = server->addlEffectParam - ADDL_EFFECT_ATK_DOWN_2;
        change = -2;
        server->tempWork = STATUS_STAT_DROP;
    } else if (server->addlEffectParam >= ADDL_EFFECT_ATK_UP_2) {
        stat = server->addlEffectParam - ADDL_EFFECT_ATK_UP_2;
        change = 2;
        server->tempWork = STATUS_STAT_BOOST;
    } else if (server->addlEffectParam >= ADDL_EFFECT_ATK_DOWN_1) {
        stat = server->addlEffectParam - ADDL_EFFECT_ATK_DOWN_1;
        change = -1;
        server->tempWork = STATUS_STAT_DROP;
    } else {
        stat = server->addlEffectParam - ADDL_EFFECT_ATK_UP_1;
        change = 1;
        server->tempWork = STATUS_STAT_BOOST;
    }

    // Start by checking some abilities upfront
    if (Server_CheckDefenderAbility(server, server->attacker, server->addlEffectClient, ABILITY_SIMPLE)) {
        change *= 2;
    } else if (Server_CheckDefenderAbility(server, server->attacker, server->addlEffectClient, ABILITY_CONTRARY)) {
        change *= -1;
        if (server->tempWork == STATUS_STAT_BOOST) {
            server->tempWork = STATUS_STAT_DROP;
        } else {
            server->tempWork = STATUS_STAT_BOOST;
        }
    }

    if (change > 0) {
        // Can't exceed +6
        if (mon->statBoosts[STAT_ATTACK + stat] == 12) {
            server->serverStatusFlag |= SERVER_STATUS_FLAG_STAT_CHANGE_FAILED;

            if (server->addlEffectType == ADDL_EFFECT_INDIRECT
                    || server->addlEffectType == ADDL_EFFECT_FROM_ABILITY) {
                IncScriptPtr(server, jumpIfBlocked);
            } else {
                server->messageParams.id = 142; // "{0}'s {1} won't go higher!"
                server->messageParams.tag = TAG_NICK_STAT;
                server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                server->messageParams.params[1] = STAT_ATTACK + stat;
                IncScriptPtr(server, jumpIfNoChange);
            }
        } else {
            if (server->addlEffectType == ADDL_EFFECT_FROM_ABILITY) {
                server->messageParams.id = 622; // "{0}'s {1} raised its {2}!"
                server->messageParams.tag = TAG_NICK_ABIL_STAT;
                server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                server->messageParams.params[1] = mon->ability;
                server->messageParams.params[2] = STAT_ATTACK + stat;
            } else if (server->addlEffectType == ADDL_EFFECT_FROM_ITEM) {
                server->messageParams.id = 622; // "{0}'s {1} raised its {2}!"
                server->messageParams.tag = TAG_NICK_ITEM_STAT;
                server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                server->messageParams.params[1] = server->itemWork;
                server->messageParams.params[2] = STAT_ATTACK + stat;
            } else {
                // "{0}'s {1} rose!" vs. "{0}'s {1} sharply rose!"
                server->messageParams.id = (change == 1 ? 750 : 753);
                server->messageParams.tag = TAG_NICK_STAT;
                server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                server->messageParams.params[1] = STAT_ATTACK + stat;
            }

            // Boost and normalize down to +6.
            mon->statBoosts[STAT_ATTACK + stat] += change;
            if (mon->statBoosts[STAT_ATTACK + stat] > 12) {
                mon->statBoosts[STAT_ATTACK + stat] = 12;
            }
        }
    } else {
        int blockType = 0;
        if ((server->addlEffectFlags & ADDL_EFFECT_NO_ABILITY) == FALSE) {
            // If the effect source and target are different, we need to consider a bunch
            // of extra stuff.
            if (server->attacker != server->addlEffectClient) {
                if (server->sideConditions.counts[server->addlEffectClient & 1].mistTurns) {
                    // "{0} is protected by Mist!"
                    server->messageParams.id = 273;
                    server->messageParams.tag = TAG_NICK;
                    server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);

                    blockType = 1;
                } else if (Server_CheckDefenderAbility(server, server->attacker, server->addlEffectClient, ABILITY_CLEAR_BODY)
                        || Server_CheckDefenderAbility(server, server->attacker, server->addlEffectClient, ABILITY_WHITE_SMOKE)) {
                    if (server->addlEffectType == ADDL_EFFECT_FROM_ABILITY) {
                        // "{0}'s {1} suppressed {2}'s {3}!"
                        server->messageParams.id = 727;
                        server->messageParams.tag = TAG_NICK_ABIL_NICK_ABIL;
                        server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                        server->messageParams.params[1] = mon->ability;
                        server->messageParams.params[2] = Server_NicknameParam(server, server->attacker);
                        server->messageParams.params[3] = server->activePokemon[server->attacker].ability;
                    } else {
                        // "{0}'s {1} prevents stat loss!"
                        server->messageParams.id = 669;
                        server->messageParams.tag = TAG_NICK_ABIL;
                        server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                        server->messageParams.params[1] = mon->ability;
                    }

                    blockType = 1;
                } else if (CheckAbilityPreventsStatLoss(server, ABILITY_KEEN_EYE, STAT_ACCURACY, stat)
                        || CheckAbilityPreventsStatLoss(server, ABILITY_HYPER_CUTTER, STAT_ATTACK, stat)
                        || CheckAbilityPreventsStatLoss(server, ABILITY_BIG_PECKS, STAT_DEFENSE, stat)) {
                    if (server->addlEffectType == ADDL_EFFECT_FROM_ABILITY) {
                        // "{0}'s {1} suppressed {2}'s {3}!"
                        server->messageParams.id = 727;
                        server->messageParams.tag = TAG_NICK_ABIL_NICK_ABIL;
                        server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                        server->messageParams.params[1] = mon->ability;
                        server->messageParams.params[2] = Server_NicknameParam(server, server->attacker);
                        server->messageParams.params[3] = server->activePokemon[server->attacker].ability;
                    } else {
                        // "{0}'s {1} prevents {2} loss!"
                        server->messageParams.id = 704;
                        server->messageParams.tag = TAG_NICK_ABIL;
                        server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                        server->messageParams.params[1] = mon->ability;
                        server->messageParams.params[2] = STAT_ATTACK + stat;
                    }

                    blockType = 1;
                // Do not go below -6.
                } else if (mon->statBoosts[STAT_ATTACK + stat] == 0) {
                    server->serverStatusFlag |= SERVER_STATUS_FLAG_STAT_CHANGE_FAILED;

                    if (server->addlEffectType == ADDL_EFFECT_INDIRECT
                            || server->addlEffectType == ADDL_EFFECT_FROM_ABILITY) {
                        IncScriptPtr(server, jumpIfBlocked);

                        return FALSE;
                    } else {
                        server->messageParams.id = 145; // "{0}'s {1} won't go lower!"
                        server->messageParams.tag = TAG_NICK_STAT;
                        server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                        server->messageParams.params[1] = STAT_ATTACK + stat;
                        IncScriptPtr(server, jumpIfNoChange);

                        return FALSE;
                    }
                } else if (Server_CheckDefenderAbility(server, server->attacker, server->addlEffectClient, ABILITY_SHIELD_DUST)
                        && server->addlEffectType == ADDL_EFFECT_INDIRECT) {
                    blockType = 1;
                } else if (mon->condition2 & CONDITION_V_SUBSTITUTED) {
                    blockType = 2;
                }
            // Don't go below -6.
            } else if (mon->statBoosts[STAT_ATTACK + stat] == 0) {
                server->serverStatusFlag |= SERVER_STATUS_FLAG_STAT_CHANGE_FAILED;

                if (server->addlEffectType == ADDL_EFFECT_INDIRECT
                        || server->addlEffectType == ADDL_EFFECT_FROM_ABILITY) {
                    IncScriptPtr(server, jumpIfBlocked);

                    return FALSE;
                } else {
                    server->messageParams.id = 145; // "{0}'s {1} won't go lower!"
                    server->messageParams.tag = TAG_NICK_STAT;
                    server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
                    server->messageParams.params[1] = STAT_ATTACK + stat;
                    IncScriptPtr(server, jumpIfNoChange);

                    return FALSE;
                }
            }

            if (blockType == 2 && server->addlEffectType == ADDL_EFFECT_DIRECT) {
                IncScriptPtr(server, jumpIfSubstitute);

                return FALSE;
            } else if (blockType) {
                if (server->addlEffectType == ADDL_EFFECT_INDIRECT) {
                    IncScriptPtr(server, jumpIfBlocked);
                } else {
                    IncScriptPtr(server, jumpIfNoChange);
                }

                return FALSE;
            }
        }

        if (server->addlEffectType == ADDL_EFFECT_FROM_ABILITY) {
            server->messageParams.id = 662; // "{0}'s {1} cuts {2}'s {3}!"
            server->messageParams.tag = TAG_NICK_ABIL_NICK_STAT;
            server->messageParams.params[0] = Server_NicknameParam(server, server->attacker);
            server->messageParams.params[1] = server->activePokemon[server->attacker].ability;
            server->messageParams.params[2] = Server_NicknameParam(server, server->addlEffectClient);
            server->messageParams.params[3] = STAT_ATTACK + stat;
        } else {
            // "{0}'s {1} fell!" vs "{0}'s {1} harshly fell!"
            server->messageParams.id = (change == -1 ? 762 : 765);
            server->messageParams.tag = TAG_NICK_STAT;
            server->messageParams.params[0] = Server_NicknameParam(server, server->addlEffectClient);
            server->messageParams.params[1] = STAT_ATTACK + stat;
        }

        mon->statBoosts[STAT_ATTACK + stat] += change;
        if (mon->statBoosts[STAT_ATTACK + stat] < 0) {
            mon->statBoosts[STAT_ATTACK + stat] = 0;
        }
    }

    return FALSE;
}

BOOL BattleScrCmd_CheckPowderImmunity(struct Battle *battle, struct BattleServer *server)
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
