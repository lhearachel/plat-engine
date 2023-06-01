.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_234.s", 0

effscr_234:
    TryPsychoShift                      5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2147483792
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
