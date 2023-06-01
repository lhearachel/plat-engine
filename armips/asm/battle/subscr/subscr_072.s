.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_72.s", 0

subscr_072:
    Message                             369, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
