.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_211.s", 0

subscr_211:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             905, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    JumpToSubscript                     290
    End                                 
