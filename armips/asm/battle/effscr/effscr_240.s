.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_240.s", 0

effscr_240:
    If                                  FLAG_EQ, VAR_ATTACKER_SIDE_CONDITIONS, 28672, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871037
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
