.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_68.s", 0

subscr_068:
    CheckSubstitute                     BATTLER_DEFENDER, 58
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_TYPE_1, 12, 57
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_TYPE_2, 12, 51
    AttackMessage                       
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 4, 24
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 19
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetMonDataFromVar                   OP_SET_FLAG, 2, BATTLE_MON_MOVE_EFFECTS, VAR_ATTACKER
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 4
    Message                             290, TAG_NICK, BATTLER_DEFENDER
    Jump                                10
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    WaitFrames                          30
    Message                             293, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 8
    End                                 
