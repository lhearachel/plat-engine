.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_232.s", 0

effscr_232:
    CheckSubstitute                     BATTLER_DEFENDER, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2684354694
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
