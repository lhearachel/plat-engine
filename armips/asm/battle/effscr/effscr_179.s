.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_179.s", 0

effscr_179:
    TryWish                             1
    End                                 
    SetVar                              OP_SET, VAR_MOVE_STATUS_FLAG, 64
    End                                 
