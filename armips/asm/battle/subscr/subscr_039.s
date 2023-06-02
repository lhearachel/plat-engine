.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_39.s", 0

subscr_039:
    Message                             150, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_ATTACKER, 6
    Wait                                
    Message                             797, TAG_NONE
    Wait                                
    WaitFrames                          30
    ClearContinuation                   BATTLER_ATTACKER
    CheckLeaveWith1HP                   BATTLER_ATTACKER
    JumpToSubscript                     2
    JumpToSubscript                     21
    End                                 
