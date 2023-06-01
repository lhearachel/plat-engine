.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_258.s", 0

subscr_258:
    Message                             829, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    Message                             797, TAG_NONE
    Wait                                
    WaitFrames                          30
    ClearContinuation                   BATTLER_ATTACKER
    JumpToSubscript                     2
