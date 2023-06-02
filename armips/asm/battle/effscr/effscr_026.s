.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_26.s", 0

effscr_026:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096, 10
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 512, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741887
    End                                 
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 1
    End                                 
