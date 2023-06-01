.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_22.s", 0

subscr_022:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 6, 19
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_IMMUNITY, 168
    CheckCloudNine                      39
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 34
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 156
    Jump                                27
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_IMMUNITY, 149
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 137
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 2, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SHIELD_DUST, 167
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 3
    CheckSubstitute                     BATTLER_EFFECTSRC, 152
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 8, 172
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 128, 166
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 3, 183
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 3, 177
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 8, 171
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 8, 165
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 110
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 18
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 100
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 172
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetStatusEffect                     BATTLER_EFFECTSRC, 2
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 8
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 6
    Message                             63, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                6
    Message                             66, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECTSRC
    Wait                                
    SetStatusIcon                       BATTLER_EFFECTSRC, STATUS_POISONED
    WaitFrames                          30
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 128, 5
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 128
    End                                 
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 128
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 140
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 135
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 9
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 4
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             650, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC
    Jump                                107
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Jump                                98
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 100
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 95
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 90
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 85
    WaitFrames                          30
    JumpToSubscript                     75
    Jump                                79
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 74
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 69
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 64
    WaitFrames                          30
    Message                             76, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                49
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 51
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 46
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 41
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 36
    WaitFrames                          30
    Message                             27, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                21
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 23
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 18
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 13
    WaitFrames                          30
    Message                             200, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
