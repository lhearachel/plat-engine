.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_108.s", 0

effscr_108:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741911
    End                                 
