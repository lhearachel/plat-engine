.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_171.bin", 0

subscr_171:
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_LIGHT_SCREEN_COUNT, 37
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_REFLECT_COUNT, 32
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_MIST_COUNT, 27
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_SAFEGUARD_COUNT, 22
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_SPIKES_COUNT, 17
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_TOXIC_SPIKES_COUNT, 12
    If                                  FLAG_EQ, VAR_DEFENDER_SIDE_CONDITIONS, 128, 7
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 32768, 2
    Branch                              2
    JumpToSubscript                     76
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 28
    JumpToSubscript                     12
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_LIGHT_SCREEN_COUNT, 11
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_LIGHT_SCREEN_COUNT, 6
    SetVar                              OP_SET, VAR_MOVE_TEMP, 115
    JumpToSubscript                     172
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_REFLECT_COUNT, 11
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_REFLECT_COUNT, 6
    SetVar                              OP_SET, VAR_MOVE_TEMP, 113
    JumpToSubscript                     172
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_MIST_COUNT, 11
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_MIST_COUNT, 6
    SetVar                              OP_SET, VAR_MOVE_TEMP, 54
    JumpToSubscript                     172
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_SAFEGUARD_COUNT, 11
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_SAFEGUARD_COUNT, 6
    SetVar                              OP_SET, VAR_MOVE_TEMP, 219
    JumpToSubscript                     172
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_SPIKES_COUNT, 15
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_SPIKES_COUNT, 10
    SetVar                              OP_CLEAR_FLAG, VAR_DEFENDER_SIDE_CONDITIONS, 4
    SetVar                              OP_SET, VAR_MOVE_TEMP, 191
    JumpToSubscript                     172
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_TOXIC_SPIKES_COUNT, 11
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_TOXIC_SPIKES_COUNT, 6
    SetVar                              OP_SET, VAR_MOVE_TEMP, 390
    JumpToSubscript                     172
    If                                  FLAG_NEQ, VAR_DEFENDER_SIDE_CONDITIONS, 128, 10
    SetVar                              OP_CLEAR_FLAG, VAR_DEFENDER_SIDE_CONDITIONS, 128
    SetVar                              OP_SET, VAR_MOVE_TEMP, 446
    JumpToSubscript                     172
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 32768, 12
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 32768
    Message                             1045, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close