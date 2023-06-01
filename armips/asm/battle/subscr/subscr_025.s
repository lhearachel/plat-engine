.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_25.s", 0

subscr_025:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 5, 48
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_WATER_VEIL, 202
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 190
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 16, 184
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 10, 178
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 10, 172
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 166
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 161
    Jump                                89
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_WATER_VEIL, 207
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 195
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 2, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SHIELD_DUST, 133
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 3
    CheckSubstitute                     BATTLER_EFFECTSRC, 118
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 16, 128
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 10, 140
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 10, 134
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 94
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 18
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 84
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 161
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 5, 6
    SetStatusEffect                     BATTLER_EFFECTSRC, 10
    Wait                                
    WaitFrames                          15
    SetStatusEffect                     BATTLER_EFFECTSRC, 3
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 16
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 11
    If                                  EQUAL, VAR_EFFECT_TYPE, 5, 14
    Message                             85, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                13
    Message                             88, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECTSRC
    Jump                                5
    Message                             1171, TAG_NICK_ITEM, BATTLER_EFFECTSRC, BATTLER_WORKING
    Wait                                
    SetStatusIcon                       BATTLER_EFFECTSRC, STATUS_BURNED
    WaitFrames                          30
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 128, 6
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 128
    Jump                                4
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 128
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 95
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 90
    WaitFrames                          30
    JumpToSubscript                     75
    Jump                                84
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 79
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 74
    WaitFrames                          30
    Message                             98, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                59
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 61
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 56
    WaitFrames                          30
    Message                             27, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                41
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 43
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 38
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             686, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC
    Jump                                20
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Jump                                11
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 13
    WaitFrames                          30
    Message                             200, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
