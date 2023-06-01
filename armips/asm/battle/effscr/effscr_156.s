.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_156.s", 0

effscr_156:
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 1073741824
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741840
    End                                 
