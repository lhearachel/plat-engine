.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_212.s", 0

subscr_212:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             893, TAG_NICK_ITEM_COND, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 983040
    JumpToSubscript                     290
    End                                 
