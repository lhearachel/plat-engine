.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_107.s", 0

effscr_107:
    CheckSubstitute                     BATTLER_DEFENDER, 17
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 134217728, 11
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, 7, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536870945
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
