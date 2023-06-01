.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_253.s", 0

subscr_253:
    WaitFrames                          15
    Message                             1118, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
