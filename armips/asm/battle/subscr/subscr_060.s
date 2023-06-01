.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_60.s", 0

subscr_060:
    Message                             265, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
