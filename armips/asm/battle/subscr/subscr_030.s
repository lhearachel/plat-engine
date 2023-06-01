.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_30.s", 0

subscr_030:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 32
    Message                             117, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER
    Wait                                
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NORMAL
    WaitFrames                          30
    End                                 
