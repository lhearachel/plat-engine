.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_24.s", 0

effscr_024:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2147483676
    End                                 
