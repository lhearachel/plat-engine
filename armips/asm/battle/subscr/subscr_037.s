.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_37.s", 0

subscr_037:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 5, 18
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_OWN_TEMPO, 91
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION_2, 7, 85
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 80
    Jump                                54
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_OWN_TEMPO, 114
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 44
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 2, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SHIELD_DUST, 59
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    CheckSubstitute                     BATTLER_EFFECTSRC, 49
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION_2, 7, 70
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 38
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 99
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetStatusEffect                     BATTLER_EFFECTSRC, 6
    Wait                                
    Random                              3, 2
    SetMonDataFromVar                   OP_SET_FLAG, 7, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 92
    Message                             156, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 79
    WaitFrames                          30
    GetCurrentMoveData                  MOVE_PARAM_RANGE
    If                                  EQUAL, VAR_CALC_WORK, 4, 9
    If                                  EQUAL, VAR_CALC_WORK, 8, 4
    JumpToSubscript                     75
    Jump                                61
    JumpToSubscript                     176
    Jump                                57
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 52
    WaitFrames                          30
    Message                             159, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                37
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 39
    If                                  EQUAL, VAR_EFFECT_TYPE, 5, 34
    If                                  EQUAL, VAR_EFFECT_TYPE, 4, 29
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             653, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC
    Jump                                11
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 13
    WaitFrames                          30
    Message                             200, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
