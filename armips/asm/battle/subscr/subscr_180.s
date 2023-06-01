.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_180.s", 0

subscr_180:
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    Message                             724, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
