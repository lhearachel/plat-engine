.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_247.s", 0

effscr_247:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2684354688
    End                                 
