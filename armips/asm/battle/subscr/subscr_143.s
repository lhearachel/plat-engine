.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_143.bin", 0

subscr_143:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 152
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, 25, 146
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 25, 140
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, 121, 134
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 121, 128
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, 122
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, 116
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, 0, 6
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 0, 104
    JumpToSubscript                     76
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_AND, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_TRUANT_ACTIVE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_TRUANT_ACTIVE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ABILITY, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_ABILITY, VAR_CALC_WORK
    If                                  NOT_EQUAL, VAR_TEMP_WORK, 112, 23
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_ADD, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_SLOW_START_TURNS, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ACTIVE, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ENDED, 0
    If                                  NOT_EQUAL, VAR_CALC_WORK, 112, 23
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_ADD, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_SLOW_START_TURNS, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_SLOW_START_ACTIVE, 0
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_SLOW_START_ENDED, 0
    Message                             559, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close