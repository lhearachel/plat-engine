.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_264.s", 0

subscr_264:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 34816, 258
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 32, 253
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_NORMALIZE, 6
    SetVar                              OP_SET, VAR_CALC_WORK, 0
    Jump                                13
    If                                  EQUAL, VAR_MOVE_TYPE, 0, 6
    SetVarFromVar                       OP_GET, VAR_MOVE_TYPE, VAR_CALC_WORK
    Jump                                2
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
    Jump                                134
    If                                  EQUAL, VAR_CALC_WORK, 0, 112
    Jump                                127
    If                                  EQUAL, VAR_CALC_WORK, 10, 105
    Jump                                120
    If                                  EQUAL, VAR_CALC_WORK, 11, 98
    Jump                                113
    If                                  EQUAL, VAR_CALC_WORK, 13, 91
    Jump                                106
    If                                  EQUAL, VAR_CALC_WORK, 12, 84
    Jump                                99
    If                                  EQUAL, VAR_CALC_WORK, 15, 77
    Jump                                92
    If                                  EQUAL, VAR_CALC_WORK, 1, 70
    Jump                                85
    If                                  EQUAL, VAR_CALC_WORK, 3, 63
    Jump                                78
    If                                  EQUAL, VAR_CALC_WORK, 4, 56
    Jump                                71
    If                                  EQUAL, VAR_CALC_WORK, 2, 49
    Jump                                64
    If                                  EQUAL, VAR_CALC_WORK, 14, 42
    Jump                                57
    If                                  EQUAL, VAR_CALC_WORK, 6, 35
    Jump                                50
    If                                  EQUAL, VAR_CALC_WORK, 5, 28
    Jump                                43
    If                                  EQUAL, VAR_CALC_WORK, 7, 21
    Jump                                36
    If                                  EQUAL, VAR_CALC_WORK, 16, 14
    Jump                                29
    If                                  EQUAL, VAR_CALC_WORK, 17, 7
    Jump                                22
    If                                  NOT_EQUAL, VAR_CALC_WORK, 8, 17
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    DamageDiv                           VAR_HP_TEMP, 2
    Message                             1131, TAG_ITEM_MOVE, BATTLER_CLIENT_WORK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    RemoveItem                          BATTLER_WORKING
    End                                 
