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


.create "build/battle/scr/subscr/sub_seq_047.bin", 0

// SUBSCR_BADLY_POISON
subscr_047:
    // Check if this was applied by Toxic Spikes
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_047_CheckToxicOrb
    // Check for Immunity
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_IMMUNITY, subscr_047_AbilityBlock
    // Check for Sun + Leaf Guard
    CheckCloudNine                      subscr_047_Resume
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_047_Resume
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_047_AbilityBlock
    Branch                              subscr_047_Resume

subscr_047_CheckToxicOrb:
    // Check if this is being applied by Toxic Orb
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_047_CheckFromMove
    // Check for Immunity
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_IMMUNITY, subscr_047_End
    // Check for Sun + Leaf Guard
    CheckCloudNine                      subscr_047_ToxicOrbResume
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_047_ToxicOrbResume
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_047_End
subscr_047_ToxicOrbResume:
    // Check if the target is already poisoned
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_POISONED, subscr_047_End
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_BADLY_POISONED, subscr_047_End
    // Check if the target cannot be poisoned by its typing
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_POISON, subscr_047_End
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_POISON, subscr_047_End
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_STEEL, subscr_047_End
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_STEEL, subscr_047_End
    // Check if the target has any other status
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_047_End
    // Check for Safeguard
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_047_End
    Branch                              subscr_047_SkipMoveAnimation

subscr_047_CheckFromMove:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_IMMUNITY, subscr_047_AbilityBlock
    CheckCloudNine                      subscr_047_SkipLeafGuard
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_047_SkipLeafGuard
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_047_AbilityBlock
subscr_047_SkipLeafGuard:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_047_Resume
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_047_Failure
subscr_047_Resume:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_047_SkipAttackMessage
    AttackMessage                       
    Wait                                
subscr_047_SkipAttackMessage:
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_047_Failure
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_POISONED, subscr_047_AlreadyPoisoned
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_BADLY_POISONED, subscr_047_AlreadyPoisoned
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_POISON, subscr_047_TypeBlock
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_POISON, subscr_047_TypeBlock
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_1, TYPE_STEEL, subscr_047_TypeBlock
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_TYPE_2, TYPE_STEEL, subscr_047_TypeBlock
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_047_Failure
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_047_Failure
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_047_SafeguardActive
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_047_SkipMoveAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_047_SkipMoveAnimation:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_047_SkipItemAnimation
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_HELD_ITEM
    Wait                                
    WaitTime                            15
subscr_047_SkipItemAnimation:
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_POISONED
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, CONDITION_BADLY_POISONED
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_047_ToxicOrbMessage
    // "{0} was badly poisoned!"
    Message                             79, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_047_AfterMessage
subscr_047_ToxicOrbMessage:
    // "{0} was badly poisoned by the {1}!"
    Message                             1168, TAG_NICK_ITEM, BATTLER_EFFECT_TARGET, BATTLER_WORKING, NaN, NaN, NaN, NaN
subscr_047_AfterMessage:
    Wait                                
    SetStatusIcon                       BATTLER_EFFECT_TARGET, STATUS_POISONED
    WaitTime                            30
    // Flip the Synchronize flag
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE, subscr_047_FlipSynchronize
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
    Branch                              subscr_047_End
subscr_047_FlipSynchronize:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
subscr_047_End:
    End                                 // 249

subscr_047_AbilityBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_047_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_047_AbilityBlockSkipAttackMessage
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_047_AbilityBlockSkipAttackMessage
    AttackMessage                       
    Wait                                
subscr_047_AbilityBlockSkipAttackMessage:
    WaitTime                            30
    // "{0}'s {1} prevents poisoning!"
    Message                             650, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Branch                              subscr_047_Cleanup

subscr_047_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_047_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_047_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_047_Exit
    WaitTime                            30
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_047_Exit

subscr_047_AlreadyPoisoned:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_047_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_047_Exit
    WaitTime                            30
    // "{0} is already poisoned!"
    Message                             76, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_047_Cleanup

subscr_047_TypeBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_047_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_047_Exit
    WaitTime                            30
    // "It doesn't affect {0}..."
    Message                             27, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_047_Cleanup

subscr_047_SafeguardActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_047_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_TOXIC_SPIKES, subscr_047_Exit
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_047_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_047_Exit:
    End                                 

.close