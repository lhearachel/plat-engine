.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_157.s", 0

subscr_157:
    Message                             1001, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
