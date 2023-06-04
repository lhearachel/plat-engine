.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_290.bin", 0

subscr_290:
    If                                  FLAG_EQ, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, 2, 2
    RemoveItem                          BATTLER_WORKING
    SetVar                              OP_CLEAR_FLAG, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, 2
    End                                 

.close