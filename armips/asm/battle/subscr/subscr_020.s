.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_20.s", 0

subscr_020:
    Message                             299, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_ATTACKER, 1
    Wait                                
    End                                 
