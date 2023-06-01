.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_168.s", 0

subscr_168:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 194
    JumpToSubscript                     76
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_DEF_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_DEF_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_SPD_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_SPD_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_SPE_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_SPE_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_SPE_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_SPE_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ACC_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_ACC_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ACC_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_ACC_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_EVA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_EVA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_EVA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_EVA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_CONDITION_2, VAR_TEMP_WORK
    If                                  FLAG_EQ, VAR_CALC_WORK, 1048576, 7
    SetMonData                          OP_CLEAR_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 1048576
    Jump                                5
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 1048576
    If                                  FLAG_EQ, VAR_TEMP_WORK, 1048576, 7
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 1048576
    Jump                                5
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 1048576
    Message                             1024, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
