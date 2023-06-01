.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_85.s", 0

effscr_085:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 8192
    End                                 
