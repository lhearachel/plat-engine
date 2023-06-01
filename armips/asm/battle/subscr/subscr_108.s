.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_108.s", 0

subscr_108:
    JumpToSubscript                     107
    Message                             172, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    ClearContinuation                   BATTLER_ATTACKER
    End                                 
