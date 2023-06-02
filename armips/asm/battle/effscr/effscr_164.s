.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_164.s", 0

effscr_164:
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 64, 32
    PrepareMessage                      810, TAG_NONE
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 33023
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 64
    SetVar                              OP_SET, VAR_WEATHER_COUNT, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871005
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_EXTEND_HAIL, 7
    GetItemPower                        BATTLER_ATTACKER, VAR_CALC_WORK
    SetVarFromVar                       OP_ADD, VAR_WEATHER_COUNT, VAR_CALC_WORK
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
