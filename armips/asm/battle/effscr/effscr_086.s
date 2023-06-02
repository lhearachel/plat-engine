.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_86.s", 0

effscr_086:
    SetVar                              OP_SET_FLAG, VAR_ADD_STATUS_DIRECT, 2684354633
    End                                 
