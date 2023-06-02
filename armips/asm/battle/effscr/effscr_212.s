.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_212.s", 0

effscr_212:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741883
    End                                 
