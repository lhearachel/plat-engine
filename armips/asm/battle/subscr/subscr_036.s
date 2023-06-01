.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_36.s", 0

subscr_036:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 768, 33
    Message                             335, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 512
    If                                  EQUAL, VAR_DAMAGE, 0, 1
    End                                 
    JumpToSubscript                     75
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
    Message                             332, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
