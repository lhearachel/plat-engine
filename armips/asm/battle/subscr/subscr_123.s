.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_123.s", 0

subscr_123:
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    MessagePrepared                     
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    End                                 
