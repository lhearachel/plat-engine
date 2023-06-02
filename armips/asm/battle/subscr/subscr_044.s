.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_44.s", 0

subscr_044:
    Random                              1, 2
    SetVar                              OP_LSH, VAR_CALC_WORK, 10
    SetMonDataFromVar                   OP_SET_FLAG, 1, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    SetVarFromVar                       OP_SET, VAR_MOVE_CONTINUATION, VAR_CURRENT_MOVE
    End                                 
