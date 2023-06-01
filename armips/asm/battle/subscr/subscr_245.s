.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_245.s", 0

subscr_245:
    Message                             363, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
