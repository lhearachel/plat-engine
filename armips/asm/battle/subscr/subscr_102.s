.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_102.s", 0

subscr_102:
    Message                             439, TAG_NICK_NUM, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, 32, 2
    JumpToSubscript                     2
    End                                 
