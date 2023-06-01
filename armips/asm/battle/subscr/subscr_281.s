.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_281.s", 0

subscr_281:
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             1234, TAG_NONE
    Wait                                
    WaitFrames                          30
    ClearContinuation                   BATTLER_ATTACKER
    If                                  EQUAL, VAR_CURRENT_MOVE, 99, 11
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 8388608, 5
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 8388608
    End                                 
