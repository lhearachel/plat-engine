.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_70.bin", 0

subscr_070:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 13
    TryDisable                          11
    JumpToSubscript                     76
    Message                             366, TAG_NICK_MOVE, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close