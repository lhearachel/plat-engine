.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_47.s", 0

subscr_047:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 6, 19
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_IMMUNITY, 240
    CheckCloudNine                      110
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 105
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 228
    Jump                                98
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 5, 66
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_IMMUNITY, 215
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 203
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 8, 197
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 128, 191
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 3, 185
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 3, 179
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 8, 173
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 8, 167
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 161
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 156
    Jump                                97
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_IMMUNITY, 150
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 138
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 2, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SHIELD_DUST, 154
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    CheckSubstitute                     BATTLER_EFFECTSRC, 144
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 8, 159
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 128, 153
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 3, 165
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 3, 159
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 8, 153
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 8, 147
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 102
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 97
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 149
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 5, 6
    SetStatusEffect                     BATTLER_EFFECTSRC, 10
    Wait                                
    WaitFrames                          15
    SetStatusEffect                     BATTLER_EFFECTSRC, 2
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 128
    If                                  EQUAL, VAR_EFFECT_TYPE, 5, 6
    Message                             79, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                5
    Message                             1168, TAG_NICK_ITEM, BATTLER_EFFECTSRC, BATTLER_WORKING
    Wait                                
    SetStatusIcon                       BATTLER_EFFECTSRC, STATUS_POISONED
    WaitFrames                          30
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 128, 6
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 128
    Jump                                4
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 128
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 101
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 7
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 2
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             650, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC
    Jump                                73
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 75
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 70
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 65
    WaitFrames                          30
    JumpToSubscript                     75
    Jump                                59
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 54
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 49
    WaitFrames                          30
    Message                             76, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                34
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 36
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 31
    WaitFrames                          30
    Message                             27, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                16
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 18
    If                                  EQUAL, VAR_EFFECT_TYPE, 6, 13
    WaitFrames                          30
    Message                             200, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
