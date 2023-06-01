.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_209.s", 0

subscr_209:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             597, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_SET_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 1048576
    JumpToSubscript                     290
    End                                 
