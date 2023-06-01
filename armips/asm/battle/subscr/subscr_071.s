.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_71.s", 0

subscr_071:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096, 0
    Message                             609, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    ClearContinuation                   BATTLER_ATTACKER
    End                                 
