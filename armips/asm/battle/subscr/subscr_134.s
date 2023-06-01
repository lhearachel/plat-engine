.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_134.s", 0

subscr_134:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 114
    CheckSubstitute                     BATTLER_DEFENDER, 111
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 121, 105
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, 121, 99
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, 93
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, 87
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, 81
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TEMP_SPE_MAX, 0, 75
    TryTrick                            72, 58
    JumpToSubscript                     76
    Message                             510, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HELD_ITEM, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_HELD_ITEM, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 0, 8
    Message                             513, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 0, 8
    Message                             513, TAG_NICK_ITEM, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
