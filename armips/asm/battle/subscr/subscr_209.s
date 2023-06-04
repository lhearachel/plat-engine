.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_209.bin", 0

subscr_209:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             597, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_SET_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 1048576
    JumpToSubscript                     290
    End                                 

.close