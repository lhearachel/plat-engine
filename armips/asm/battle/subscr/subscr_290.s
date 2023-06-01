.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_290.s", 0

subscr_290:
    If                                  FLAG_EQ, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, 2, 2
    RemoveItem                          BATTLER_WORKING
    SetVar                              OP_CLEAR_FLAG, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, 2
    End                                 
