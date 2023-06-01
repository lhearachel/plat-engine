.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_82.s", 0

effscr_082:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536870983
    End                                 
