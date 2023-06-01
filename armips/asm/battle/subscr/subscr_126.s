.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_126.s", 0

subscr_126:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 5
    AttackMessage                       
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    MessagePrepared                     
    Wait                                
    WaitFrames                          30
    End                                 
