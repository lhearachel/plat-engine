.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_32.s", 0

subscr_032:
    Message                             130, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_ATTACKER, 5
    Wait                                
    ClearContinuation                   BATTLER_ATTACKER
    End                                 
