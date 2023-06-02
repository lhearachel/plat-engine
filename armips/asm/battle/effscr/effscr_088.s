.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_88.s", 0

effscr_088:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    Random                              10, 5
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_LEVEL, VAR_DAMAGE
    SetVarFromVar                       OP_MUL, VAR_DAMAGE, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_DAMAGE, 10
    If                                  NOT_EQUAL, VAR_DAMAGE, 0, 4
    SetVar                              OP_SET, VAR_DAMAGE, 1
    SetVar                              OP_MUL, VAR_DAMAGE, 4294967295
    End                                 
