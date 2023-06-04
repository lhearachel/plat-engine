.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_55.bin", 0

subscr_055:
    AttackMessage                       
    Wait                                
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_INSOMNIA, 92
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_VITAL_SPIRIT, 87
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 7, 90
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_SOUNDPROOF, 5
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 3840, 88
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    JumpIfMonData                       EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_HP_TEMP, 99
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 4294967288, 6
    Message                             205, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              12
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NORMAL
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 4294967288
    Message                             208, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 3
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_ASLEEP
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 4294967288, 4294967257
    Message                             184, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              49
    WaitTime                            30
    Message                             329, TAG_NICK_ABILITY, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Branch                              36
    WaitTime                            30
    Message                             57, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              28
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 112, 8
    WaitTime                            30
    Message                             326, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              14
    WaitTime                            30
    Message                             323, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              6
    WaitTime                            30
    Message                             187, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    Wait                                
    WaitTime                            30
    End                                 

.close