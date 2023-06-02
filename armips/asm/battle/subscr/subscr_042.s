.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_42.s", 0

subscr_042:
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             824, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
