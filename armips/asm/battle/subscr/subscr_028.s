.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_28.s", 0

subscr_028:
    Message                             111, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_ATTACKER, 4
    Wait                                
    End                                 
