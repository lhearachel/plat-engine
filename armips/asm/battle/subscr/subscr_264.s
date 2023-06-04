.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_264.bin", 0

subscr_264:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 34816, 258
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 32, 253
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_NORMALIZE, 6
    SetVar                              OP_SET, VAR_CALC_WORK, 0
    Branch                              13
    If                                  EQUAL, VAR_MOVE_TYPE, 0, 6
    SetVarFromVar                       OP_GET, VAR_MOVE_TYPE, VAR_CALC_WORK
    Branch                              2
    GetCurrentMoveData                  MOVE_PARAM_TYPE
    GetItemEffect                       BATTLER_WORKING, VAR_TEMP_WORK
    If                                  EQUAL, VAR_TEMP_WORK, 35, 87
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 2, 216
    If                                  EQUAL, VAR_TEMP_WORK, 19, 84
    If                                  EQUAL, VAR_TEMP_WORK, 20, 86
    If                                  EQUAL, VAR_TEMP_WORK, 21, 88
    If                                  EQUAL, VAR_TEMP_WORK, 22, 90
    If                                  EQUAL, VAR_TEMP_WORK, 23, 92
    If                                  EQUAL, VAR_TEMP_WORK, 24, 94
    If                                  EQUAL, VAR_TEMP_WORK, 25, 96
    If                                  EQUAL, VAR_TEMP_WORK, 26, 98
    If                                  EQUAL, VAR_TEMP_WORK, 27, 100
    If                                  EQUAL, VAR_TEMP_WORK, 28, 102
    If                                  EQUAL, VAR_TEMP_WORK, 29, 104
    If                                  EQUAL, VAR_TEMP_WORK, 30, 106
    If                                  EQUAL, VAR_TEMP_WORK, 31, 108
    If                                  EQUAL, VAR_TEMP_WORK, 32, 110
    If                                  EQUAL, VAR_TEMP_WORK, 33, 112
    If                                  EQUAL, VAR_TEMP_WORK, 34, 114
    Branch                              134
    If                                  EQUAL, VAR_CALC_WORK, 0, 112
    Branch                              127
    If                                  EQUAL, VAR_CALC_WORK, 10, 105
    Branch                              120
    If                                  EQUAL, VAR_CALC_WORK, 11, 98
    Branch                              113
    If                                  EQUAL, VAR_CALC_WORK, 13, 91
    Branch                              106
    If                                  EQUAL, VAR_CALC_WORK, 12, 84
    Branch                              99
    If                                  EQUAL, VAR_CALC_WORK, 15, 77
    Branch                              92
    If                                  EQUAL, VAR_CALC_WORK, 1, 70
    Branch                              85
    If                                  EQUAL, VAR_CALC_WORK, 3, 63
    Branch                              78
    If                                  EQUAL, VAR_CALC_WORK, 4, 56
    Branch                              71
    If                                  EQUAL, VAR_CALC_WORK, 2, 49
    Branch                              64
    If                                  EQUAL, VAR_CALC_WORK, 14, 42
    Branch                              57
    If                                  EQUAL, VAR_CALC_WORK, 6, 35
    Branch                              50
    If                                  EQUAL, VAR_CALC_WORK, 5, 28
    Branch                              43
    If                                  EQUAL, VAR_CALC_WORK, 7, 21
    Branch                              36
    If                                  EQUAL, VAR_CALC_WORK, 16, 14
    Branch                              29
    If                                  EQUAL, VAR_CALC_WORK, 17, 7
    Branch                              22
    If                                  NOT_EQUAL, VAR_CALC_WORK, 8, 17
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    DamageDiv                           VAR_HP_TEMP, 2
    Message                             1131, TAG_ITEM_MOVE, BATTLER_CLIENT_WORK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RemoveItem                          BATTLER_WORKING
    End                                 

.close