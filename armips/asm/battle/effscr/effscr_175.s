.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_175.s", 0

effscr_175:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2684354669
    End                                 
