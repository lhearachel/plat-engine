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


.create "build/battle/scr/subscr/sub_seq_022.bin", 0

// SUBSCR_APPLY_POISON
subscr_022:
    // Check if the poison is applied by Toxic Spikes.
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_022_GeneralChecks
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_IMMUNITY, subscr_022_AbilityBlock
    CheckCloudNine                      subscr_022_CheckDirect
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_022_CheckDirect
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_022_AbilityBlock
    Branch                              subscr_022_CheckDirect

subscr_022_GeneralChecks:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_IMMUNITY, subscr_022_AbilityBlock
    CheckCloudNine                      subscr_022_CheckIndirect
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_022_CheckIndirect
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_022_AbilityBlock
subscr_022_CheckIndirect:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_022_CheckDirect
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_022_Failure
subscr_022_CheckDirect:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_022_CheckFromAbility
    AttackMessage                       
    Wait                                
subscr_022_CheckFromAbility:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_022_SkipSubstituteCheck
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_022_Failure
subscr_022_SkipSubstituteCheck:
    // Check if the target is already poisoned
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_POISONED, subscr_022_AlreadyPoisoned
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_BADLY_POISONED, subscr_022_AlreadyPoisoned
    // Check if the target is immune to poison based on its typing
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_POISON, subscr_022_CannotBePoisoned
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_POISON, subscr_022_CannotBePoisoned
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_STEEL, subscr_022_CannotBePoisoned
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_STEEL, subscr_022_CannotBePoisoned
    // Check if the target is already statused
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_022_Failure
    // Skip the animation if the poison comes from an ability
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_022_SkipAnimation
    // Show the failure message if the move missed
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_022_Failure
    // Show a special failure message if the target is protected by Safeguard
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_022_SafeguardActive
    // If the effect is not direct for any other reason, skip the move animation
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_022_SkipAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait

subscr_022_SkipAnimation:
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_POISONED
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_POISONED
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_022_AbilityMessage
    // "{0} was poisoned!"
    Message                             63, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_022_AfterMessage
subscr_022_AbilityMessage:
    // "{0}'s {1} poisoned {2}!"
    Message                             66, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN
subscr_022_AfterMessage:
    Wait                                
    SetStatusIcon                       BATTLER_EFFECT_TARGET, STATUS_POISONED
    WaitTime                            30
    // Check for and set the Synchronize flag
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE, subscr_022_FlipSynchronize
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
    End                                 

subscr_022_FlipSynchronize:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
    End                                 

subscr_022_AbilityBlock:
    // Exit if the effect is indirect
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_022_Exit
    // Exit if the effect comes from an ability
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_022_Exit
    // Check for if the effect comes from a move or Toxic Spikes (and skip the attack animation, if so)
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_022_SkipAttackMessage
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_022_SkipAttackMessage
    AttackMessage                       
    Wait                                
    WaitTime                            30
subscr_022_SkipAttackMessage:
    // "{0}'s {1} prevents poisoning!"
    Message                             650, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Branch                              subscr_022_Cleanup
// TODO: This branch is unreachable
subscr_022_AbilityBlock2:
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN
    Branch                              subscr_022_Cleanup

subscr_022_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_022_Exit
    WaitTime                            30
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_022_Exit

subscr_022_AlreadyPoisoned:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_022_Exit
    WaitTime                            30
    // "{0} is already poisoned."
    Message                             76, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_022_Cleanup

subscr_022_CannotBePoisoned:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_022_Exit
    WaitTime                            30
    // "It doesn't affect {0}..."
    Message                             27, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_022_Cleanup

subscr_022_SafeguardActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_022_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_022_Exit
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_022_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE

subscr_022_Exit:
    End                                 

.close