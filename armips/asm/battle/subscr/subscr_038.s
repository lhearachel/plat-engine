.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_38.s", 0

subscr_038:
    Message                             150, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_ATTACKER, 6
    Wait                                
    End                                 
