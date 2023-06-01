.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_89.s", 0

subscr_089:
    AttackMessage                       
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 16777216, 36
    TrySubstitute                       27
    SetStatusEffect                     BATTLER_ATTACKER, 25
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 16777216
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    JumpToSubscript                     2
    Message                             348, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
    WaitFrames                          30
    Message                             819, TAG_NONE
    Jump                                6
    WaitFrames                          30
    Message                             351, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
