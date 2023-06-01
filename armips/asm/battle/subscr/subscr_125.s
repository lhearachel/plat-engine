.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_125.s", 0

subscr_125:
    AttackMessage                       
    Wait                                
    JumpToSubscript                     111
    Message                             994, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
