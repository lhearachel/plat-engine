.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_56.s", 0

subscr_056:
    SetVarFromVar                       OP_SET, VAR_MOVE_CONTINUATION, VAR_CURRENT_MOVE
    Random                              3, 3
    SetVar                              OP_LSH, VAR_CALC_WORK, 4
    SetMonDataFromVar                   OP_SET_FLAG, 1, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    SetVarFromVar                       OP_TO_BIT, VAR_CALC_WORK, VAR_ATTACKER
    SetVar                              OP_LSH, VAR_CALC_WORK, 8
    SetVarFromVar                       OP_SET_FLAG, VAR_FIELD_CONDITIONS, VAR_CALC_WORK
    Message                             308, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
