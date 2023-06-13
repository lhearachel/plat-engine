.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_018.bin", 0

subscr_018:
    If                                  EQUAL, VAR_EFFECT_TYPE, 7, 143
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 4, 46
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_INSOMNIA, 188
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_VITAL_SPIRIT, 183
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 171
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 7, 237
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SOUNDPROOF, 5
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 3840, 245
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 184
    Branch                              92
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_INSOMNIA, 142
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_VITAL_SPIRIT, 137
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 125
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 2, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SHIELD_DUST, 150
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 3
    CheckSubstitute                     BATTLER_EFFECTSRC, 135
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 7, 166
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SOUNDPROOF, 5
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 3840, 174
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 113
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 18
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 103
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 180
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetStatusEffect                     BATTLER_EFFECTSRC, 1
    Wait                                
    Random                              3, 2
    SetMonDataFromVar                   OP_SET_FLAG, 7, BATTLE_MON_CONDITION, VAR_CALC_WORK
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 6
    Message                             47, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Branch                              6
    Message                             50, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECTSRC, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetStatusIcon                       BATTLER_EFFECTSRC, STATUS_ASLEEP
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_MOVE_EFFECTS, 537133248, 4
    ClearContinuation                   BATTLER_EFFECTSRC
    Branch                              8
    ClearContinuation                   BATTLER_EFFECTSRC
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_EFFECTSRC
    JumpToSubscript                     287
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 130
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 125
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 4
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             329, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN
    Branch                              102
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN
    Branch                              93
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 95
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 90
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 85
    WaitTime                            30
    GetCurrentMoveData                  MOVE_PARAM_RANGE
    If                                  EQUAL, VAR_CALC_WORK, 4, 9
    If                                  EQUAL, VAR_CALC_WORK, 8, 4
    JumpToSubscript                     75
    Branch                              67
    JumpToSubscript                     176
    Branch                              63
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 58
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 53
    WaitTime                            30
    Message                             57, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Branch                              38
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 40
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION_2, 112, 8
    WaitTime                            30
    Message                             326, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Branch                              19
    WaitTime                            30
    Message                             323, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Branch                              11
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 13
    WaitTime                            30
    Message                             200, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close