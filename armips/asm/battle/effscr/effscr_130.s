.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_130.s", 0

effscr_130:
    If                                  FLAG_EQ, VAR_RULESET, 1, 9
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    SetVar                              OP_SET, VAR_DAMAGE, 4294967276
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
