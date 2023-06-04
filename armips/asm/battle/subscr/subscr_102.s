.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_102.bin", 0

subscr_102:
    Message                             439, TAG_NICK_NUM, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, 32, 2
    JumpToSubscript                     2
    End                                 

.close