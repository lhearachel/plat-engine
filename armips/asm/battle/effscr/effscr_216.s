.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_216.s", 0

effscr_216:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871031
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 32768
    End                                 
