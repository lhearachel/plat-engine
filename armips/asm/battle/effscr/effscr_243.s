.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_243.s", 0

effscr_243:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871038
    End                                 
