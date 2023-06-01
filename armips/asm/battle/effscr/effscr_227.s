.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_227.s", 0

effscr_227:
    MetalBurstDamageCalc                5
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
