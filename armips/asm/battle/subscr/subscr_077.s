.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_77.s", 0

subscr_077:
    CheckSubstitute                     BATTLER_DEFENDER, 73
    JumpToSubscript                     76
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_HP, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_ADD, VAR_CALC_WORK, VAR_HP_TEMP
    SetVar                              OP_DIV, VAR_CALC_WORK, 2
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_SUB, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    JumpToSubscript                     2
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_SUB, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    JumpToSubscript                     2
    Message                             820, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
