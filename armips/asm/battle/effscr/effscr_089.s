.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_89.s", 0

effscr_089:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    Counter                             
    End                                 
