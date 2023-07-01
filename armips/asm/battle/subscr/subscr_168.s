.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/subscr/sub_seq_168.bin", 0

// SUBSCR_HEART_SWAP
subscr_168:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_168_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Swap Attack stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    // Swap Defense stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_DEF_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_DEF_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    // Swap SpAttack stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    // Swap SpDefense stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_SPD_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_SPD_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    // Swap Speed stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_SPE_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_SPE_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_SPE_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_SPE_STAGE, VAR_CALC_WORK
    // Swap Accuracy stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_ACC_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_ACC_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_ACC_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_ACC_STAGE, VAR_CALC_WORK
    // Swap Evasion stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_EVA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_EVA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_EVA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_EVA_STAGE, VAR_CALC_WORK
    // Swap Focus Energy states
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, VAR_TEMP_WORK
subscr_168_CheckDefenderFocusEnergy:
    If                                  FLAG_EQ, VAR_CALC_WORK, CONDITION_V_PUMPED, subscr_168_DefenderOn
subscr_168_DefenderOff:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_PUMPED
    Branch                              subscr_168_CheckAttackerFocusEnergy
subscr_168_DefenderOn:
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_PUMPED
subscr_168_CheckAttackerFocusEnergy:
    If                                  FLAG_EQ, VAR_TEMP_WORK, CONDITION_V_PUMPED, subscr_168_AttackerOn
subscr_168_AttackerOff:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_PUMPED
    Branch                              subscr_168_ShowMessage
subscr_168_AttackerOn:
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_PUMPED
subscr_168_ShowMessage:
    // "{0} switched stat changes with the target!"
    Message                             1024, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_168_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close