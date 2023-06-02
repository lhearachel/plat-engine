.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_116.s", 0

effscr_116:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1342177362
    End                                 
