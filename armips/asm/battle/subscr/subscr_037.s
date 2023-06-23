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


.create "build/battle/scr/subscr/sub_seq_037.bin", 0

// SUBSCR_APPLY_CONFUSION
subscr_037:
    // Handle confusion berries first
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_037_NormalConfusion
    // Own Tempo blocks confusion
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_OWN_TEMPO, subscr_037_End
    // Check if the target is already confused
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED, subscr_037_End
    // Check for Safeguard
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_037_End
    Branch                              subscr_037_SkipMoveAnimation

subscr_037_NormalConfusion:
    // Own Tempo blocks confusion
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_OWN_TEMPO, subscr_037_AbilityBlock
    // If the effect comes from a move, skip the animation (which has already played)
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_037_SkipMoveAnimation
    // Check for Shield Dust on indirect effects
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_037_SkipShieldDust
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_037_Failure
subscr_037_SkipShieldDust:
    // Indirect effects should not (re-)print the attack message
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_037_SkipAttackMessage
    AttackMessage                       
    Wait                                
subscr_037_SkipAttackMessage:
    // Check for Substitute
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_037_Failure
    IfMonData                           FLAG_EQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED, subscr_037_AlreadyConfused
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_037_Failure
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_037_SafeguardActive
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_037_SkipMoveAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_037_SkipMoveAnimation:
    SetStatusEffect                     BATTLER_EFFECT_TARGET, STATUS_CONFUSED
    Wait                                
    // Generate the number of turns
    Random                              3, 2
    SetMonDataFromVar                   OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_037_Exit
    // "{0} became confused!"
    Message                             156, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_037_End:
    End                                 

subscr_037_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_037_Exit
    WaitTime                            30
    GetCurrentMoveData                  MOVE_PARAM_RANGE
    // Check for moves with spread range
    If                                  EQUAL, VAR_CALC_WORK, RANGE_DOUBLE, subscr_037_RangeCheck
    If                                  EQUAL, VAR_CALC_WORK, RANGE_TRIPLE, subscr_037_RangeCheck
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_037_Exit
    
subscr_037_RangeCheck:
    CallSubscript                       SUBSCR_MOVE_FAIL_MISSED
    Branch                              subscr_037_Exit

subscr_037_AlreadyConfused:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_037_Exit
    WaitTime                            30
    // "{0} is already confused!"
    Message                             159, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_037_Cleanup

subscr_037_AbilityBlock:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_037_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_037_Exit
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE, subscr_037_Exit
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s {1} prevents confusion!"
    Message                             653, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Branch                              subscr_037_Cleanup

subscr_037_SafeguardActive:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_037_Exit
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_037_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_037_Exit:
    End                                 

.close