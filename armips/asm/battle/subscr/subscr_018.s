.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/subscr/sub_seq_018.bin", 0

// SUBSCR_APPLY_SLEEP
subscr_018:
    // Check for disobedience.
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DISOBEY, subscr_018_SkipAnimation
    // Ensure that the effect comes from a move.
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_018_NormalChecks
    // Check for abilities that would break sleep: Insomnia, Vital Spirit, Leaf Guard (in the sun)
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_INSOMNIA, subscr_018_AbilityBlock
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_VITAL_SPIRIT, subscr_018_AbilityBlock
    // Skip Leaf Guard check if Cloud Nine is active.
    CheckCloudNine                      subscr_018_CheckMoveEffect
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_018_CheckMoveEffect
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_018_AbilityBlock
subscr_018_CheckMoveEffect:
    // Check if the target is already asleep.
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_ASLEEP, subscr_018_AlreadyAsleep
    // Check for Uproar preventing sleep (and for Soundproof, which ignores Uproar).
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SOUNDPROOF, subscr_018_MoveEffectSkipUproar
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_UPROAR, subscr_018_UproarActive
subscr_018_MoveEffectSkipUproar:
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_018_Failure
    Branch                              subscr_018_SkipAnimation

subscr_018_NormalChecks:
    // Check for abilities that would break sleep: Insomnia, Vital Spirit, Leaf Guard (in the sun)
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_INSOMNIA, subscr_018_AbilityBlock
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_VITAL_SPIRIT, subscr_018_AbilityBlock
    CheckCloudNine                      subscr_018_Resume
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_018_Resume
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_018_AbilityBlock
subscr_018_Resume:
    // Check for Shield Dust on indirect effects.
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, susbcr_018_SkipShieldDust
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_018_Failure
susbcr_018_SkipShieldDust:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_018_NoAttackMessage
    AttackMessage                       
    Wait                                
subscr_018_NoAttackMessage:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_018_SkipSubstitute
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_018_Failure
subscr_018_SkipSubstitute:
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_ASLEEP, subscr_018_AlreadyAsleep
    // Check for Soundproof and Uproar
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SOUNDPROOF, subscr_018_SkipUproar
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_UPROAR, subscr_018_UproarActive
subscr_018_SkipUproar:
    // Verify that the target has no other non-volatile status
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_018_Failure
    // Check if the sleep is from an ability (e.g. Effect Spore)
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_018_SkipAnimation
    // Check for a miss
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_018_Failure
    // Check for Safeguard
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_018_SafeguardActive
    // Indirect sleep effects should skip the attack animation (since it already played)
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_018_SkipAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_018_SkipAnimation:
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_ASLEEP
    Wait                                
    // Generation 5: Sleep now lasts a total of 1-3 turns
    // Generate 0-2, then offset by 1
    Random                              2, 1
    SetMonDataFromVar                   OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, VAR_CALC_WORK
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_018_AbilityMessage
    // "{0} fell asleep!"
    Message                             47, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_018_AfterMessage

subscr_018_AbilityMessage:
    // "{0}'s {1} made {2} fall asleep!"
    Message                             50, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN
subscr_018_AfterMessage:
    Wait                                
    WaitTime                            30
    SetStatusIcon                       BATTLER_EFFECT_TARGET, STATUS_ASLEEP
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MULTI_TURN_VANISHING, subscr_018_StopMultiTurn
    ClearContinuation                   BATTLER_EFFECT_TARGET
    Branch                              subscr_018_End
    
subscr_018_StopMultiTurn:
    ClearContinuation                   BATTLER_EFFECT_TARGET
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_EFFECT_TARGET
    CallSubscript                       SUBSCR_VANISH_OFF
subscr_018_End:
    End                                 

subscr_018_AbilityBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_018_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_018_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_018_SkipAttackMessage
    AttackMessage                       
    Wait                                
    WaitTime                            30
subscr_018_SkipAttackMessage:
    // "{0} stayed awake because of its {1}!"
    Message                             329, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Branch                              subscr_018_Cleanup

subscr_018_AbilityBlockResume:
    // "{0}'s {1} suppressed {2}'s {3}!"
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN
    Branch                              subscr_018_Cleanup

subscr_018_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_018_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_018_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_018_Exit
    WaitTime                            30
    GetCurrentMoveData                  MOVE_PARAM_RANGE
    // Check for double range
    If                                  EQUAL, VAR_CALC_WORK, RANGE_DOUBLE, subscr_018_CheckPartialSuccess
    // Check for triple range
    If                                  EQUAL, VAR_CALC_WORK, RANGE_TRIPLE, subscr_018_CheckPartialSuccess
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_018_Exit
    
subscr_018_CheckPartialSuccess:
    CallSubscript                       SUBSCR_MOVE_FAIL_MISSED
    Branch                              subscr_018_Exit

subscr_018_AlreadyAsleep:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_018_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_018_Exit
    WaitTime                            30
    // "{0} is already asleep!"
    Message                             57, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_018_Cleanup

subscr_018_UproarActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_018_Exit
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION_2, CONDITION_V_UPROARING, subscr_018_UproarMine
    WaitTime                            30
    // "But the uproar kept {0} awake!"
    Message                             326, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_018_Cleanup

subscr_018_UproarMine:
    WaitTime                            30
    // "But {0} can't sleep in an uproar!"
    Message                             323, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_018_Cleanup

subscr_018_SafeguardActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_018_Exit
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_018_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_018_Exit:
    End                                 

.close