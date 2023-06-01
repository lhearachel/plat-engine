.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_259.s", 0

subscr_259:
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 512
    End                                 
