.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_82.s", 0

subscr_082:
    Message                             388, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 33554432
    End                                 
