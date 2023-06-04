.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_140.bin", 0

subscr_140:
    TryBreakScreens                     14
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    JumpToSubscript                     76
    Message                             606, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              7
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2086985, 2
    JumpToSubscript                     76
    End                                 

.close