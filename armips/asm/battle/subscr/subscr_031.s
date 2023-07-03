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


.create "build/battle/scr/subscr/sub_seq_031.bin", 0

// SUBSCR_APPLY_PARALYSIS
subscr_031:
    // Check for Limber
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LIMBER, subscr_031_AbilityBlock
    // Check for Sun + Leaf Guard
    CheckCloudNine                      subscr_031_Resume
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_031_Resume
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_031_AbilityBlock
subscr_031_Resume:
    // Check for Shield Dust on indirect effects
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_031_SkipShieldDust
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_031_Failure
subscr_031_SkipShieldDust:
    // Skip the attack message on indirect effects
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_031_SkipAttackMessage
    AttackMessage                       
    Wait                                
subscr_031_SkipAttackMessage:
    // Abilities bypass Substitute
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_031_SkipSubstitute
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_031_Failure
subscr_031_SkipSubstitute:
    // Check if the target is already paralyzed
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_PARALYZED, subscr_031_AlreadyParalyzed
    // Check if the target is immune to paralysis based on its typing
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_ELECTRIC, subscr_031_CannotBeParalyzed
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_ELECTRIC, subscr_031_CannotBeParalyzed
    // Ensure that the target has no other status
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_031_Failure
    // Abilities skip the attack animation
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_031_SkipAttackAnimation
    // Make sure the move actually hit
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_031_Failure
    // Check for Safeguard
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_031_SafeguardActive
    // Indirect effects skip the attack animation
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_031_SkipAttackAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_031_SkipAttackAnimation:
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_PARALYZED
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_PARALYZED
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_031_AbilityMessage
    // "{0} is paralyzed! It may be unable to move!"
    Message                             120, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_031_AfterMessage
subscr_031_AbilityMessage:
    // "{0}'s {1} paralyzed {2}! It may be unable to move!"
    Message                             123, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN
subscr_031_AfterMessage:
    Wait                                
    SetStatusIcon                       BATTLER_EFFECT_TARGET, STATUS_PARALYZED
    WaitTime                            30
    // Flip the Synchronize flag
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE, subscr_031_FlipSynchronize
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
    End                                 
subscr_031_FlipSynchronize:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
    End                                 

subscr_031_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_031_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_031_Exit
    WaitTime                            30
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_031_Exit

subscr_031_AlreadyParalyzed:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_031_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_031_Exit
    WaitTime                            30
    // "{0} is already paralyzed!"
    Message                             133, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_031_Cleanup

subscr_031_CannotBeParalyzed:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_031_Exit
    WaitTime                            30
    // "It doesn't affect {0}..."
    Message                             27, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_031_Cleanup

subscr_031_AbilityBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_031_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_031_Exit
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s {1} prevents paralysis!"
    Message                             644, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Branch                              subscr_031_Cleanup
// TODO: Unreachable
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN
    Branch                              subscr_031_Cleanup

subscr_031_SafeguardActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_031_Exit
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_031_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_031_Exit:
    End                                 

.close