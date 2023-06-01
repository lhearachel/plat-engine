.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_270.s", 0

effscr_270:
    TrySwitchInMon                      BATTLER_ATTACKER, 1, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871055
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
