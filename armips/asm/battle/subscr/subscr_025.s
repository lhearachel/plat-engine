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


.create "build/battle/scr/subscr/sub_seq_025.bin", 0

// SUBSCR_APPLY_BURN
subscr_025:
    // If the burn effect does not come from Flame Orb, skip ahead.
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_025_NormalBurn
subscr_025_FlameOrb:
    // Check for Water Veil
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_WATER_VEIL, subscr_025_End
    // Check for Sun + Leaf Guard
    CheckCloudNine                      subscr_025_FlameOrbResume
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_025_FlameOrbResume
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_025_End
subscr_025_FlameOrbResume:
    // If the target is already burned, do nothing.
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_BURNED, subscr_025_End
    // Fire-types cannot be burned.
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_FIRE, subscr_025_End
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_FIRE, subscr_025_End
    // Do nothing if the target is already statused.
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_025_End
    // Do nothing if the target is behind Safeguard.
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_025_End
    // Skip any move animations.
    Branch                              subscr_025_SkipAnimation

subscr_025_NormalBurn:
    // Check for Water Veil
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_WATER_VEIL, subscr_025_AbilityBlock
    // Check for Sun + Leaf Guard
    CheckCloudNine                      subscr_025_Resume
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_025_Resume
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_025_AbilityBlock
subscr_025_Resume:
    // Check for Shield Dust on indirect effects
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_025_SkipShieldDust
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_025_Failure
subscr_025_SkipShieldDust:
    // Skip the attack message for indirect effects
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_025_SkipAttackMessage
    AttackMessage                       
    Wait                                
subscr_025_SkipAttackMessage:
    // Ability-sourced burns (e.g. Flame Body) ignore Substitute
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_025_SkipSubstitute
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_025_Failure
subscr_025_SkipSubstitute:
    // Check if the target is already burned.
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_BURNED, subscr_025_AlreadyBurned
    // Fire-types cannot be burned.
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_FIRE, subscr_025_CannotBeBurned
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_FIRE, subscr_025_CannotBeBurned
    // Ensure the target is not already statused.
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_025_Failure
    // Don't play a move animation if the effect is from an ability.
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_025_SkipAnimation
    // Failure message if we miss
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_025_Failure
    // Special Safeguard message
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_025_SafeguardActive
    // If the effect is not direct, skip the move animation
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_025_SkipAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_025_SkipAnimation:
    // Special animation for getting burned by Flame Orb
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_025_SkipItemAnimation
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_HELD_ITEM
    Wait                                
    WaitTime                            15
subscr_025_SkipItemAnimation:
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_BURNED
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_BURNED
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_025_AbilityMessage
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_025_FlameOrbMessage
subscr_025_NormalMessage:
    // "{0} was burned!"
    Message                             85, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_025_AfterMessage

subscr_025_AbilityMessage:
    // "{0}'s {1} burned {2}!"
    Message                             88, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN
    Branch                              subscr_025_AfterMessage

subscr_025_FlameOrbMessage:
    // "{0} gor a burn from the {1}!"
    Message                             1171, TAG_NICK_ITEM, BATTLER_EFFECT_TARGET, BATTLER_WORKING, NaN, NaN, NaN, NaN

subscr_025_AfterMessage:
    Wait                                
    SetStatusIcon                       BATTLER_EFFECT_TARGET, STATUS_BURNED
    WaitTime                            30
    // Flip the Synchronize flag as appropriate.
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE, subscr_025_FlipSynchronize
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
    Branch                              subscr_025_End
subscr_025_FlipSynchronize:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
subscr_025_End:
    End                                 

subscr_025_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_025_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_025_Exit
    WaitTime                            30
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_025_Exit

subscr_025_AlreadyBurned:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_025_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_025_Exit
    WaitTime                            30
    // "{0} already has a burn."
    Message                             98, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_025_Cleanup

subscr_025_CannotBeBurned:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_025_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_025_Exit
    WaitTime                            30
    // "It doesn't affect {0}..."
    Message                             27, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_025_Cleanup

subscr_025_AbilityBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_025_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_025_Exit
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s {1} prevents burns!"
    Message                             686, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Branch                              subscr_025_Cleanup
// TODO: Unreachable instructions
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN
    Branch                              subscr_025_Cleanup

subscr_025_SafeguardActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, subscr_025_Exit
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_025_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_025_Exit:
    End                                 

.close