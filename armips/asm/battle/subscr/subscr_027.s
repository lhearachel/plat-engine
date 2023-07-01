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



.create "build/battle/scr/subscr/sub_seq_027.bin", 0

// SUBSCR_APPLY_FREEZE
subscr_027:
    // Check for Magma Armor
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_MAGMA_ARMOR, subscr_027_AbilityBlock
    // Check for Sun (no Leaf Guard check; Sun prevents freezing entirely)
    CheckCloudNine                      subscr_027_Resume
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_027_Failure
    // Check for Shield Dust blocking an indirect effect
subscr_027_Resume:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_027_SkipShieldDust
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_027_Failure
subscr_027_SkipShieldDust:
    // If the effect is not direct, skip the attack message
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_027_SkipAttackMessage
    AttackMessage                       
    Wait                                
subscr_027_SkipAttackMessage:
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_027_Failure
    // Check if the target is already frozen.
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_FROZEN, subscr_027_AlreadyFrozen
    // Ice-types cannot be frozen.
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_ICE, subscr_027_TypeBlock
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_ICE, subscr_027_TypeBlock
    // Ensure that the target is not already statused.
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_027_Failure
    // Check if the move actually hit.
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_027_Failure
    // Check for Safeguard.
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_027_SafeguardActive
    // If the effect is not direct, skip the move animation.
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_027_SkipAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_027_SkipAnimation:
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_FROZEN
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_FROZEN
    ClearContinuation                   BATTLER_EFFECT_TARGET
    // "{0} was frozen solid!"
    Message                             101, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_EFFECT_TARGET, STATUS_FROZEN
    WaitTime                            30
    End                                 

subscr_027_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_027_Exit
    WaitTime                            30
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_027_Exit

subscr_027_AlreadyFrozen:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_027_Exit
    WaitTime                            30
    Branch                              subscr_027_Cleanup

subscr_027_TypeBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_027_Exit
    WaitTime                            30
    // "It doesn't affect {0}..."
    Message                             27, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_027_Cleanup

subscr_027_AbilityBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_027_Exit
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Branch                              subscr_027_Cleanup

subscr_027_SafeguardActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_027_Exit
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_027_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_027_Exit:
    End                                 

.close