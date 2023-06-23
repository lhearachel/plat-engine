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


.create "build/battle/scr/subscr/sub_seq_141.bin", 0

// SUBSCR_YAWN
subscr_141:
    // Insomnia and Vital Spirit prevent sleep
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_INSOMNIA, subscr_141_AbilityBlock
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_VITAL_SPIRIT, subscr_141_AbilityBlock
    // Sun + Leaf Guard prevents Sleep
    CheckCloudNine                      subscr_141_Resume
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_141_Resume
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_LEAF_GUARD, subscr_141_AbilityBlock
subscr_141_Resume:
    AttackMessage                       
    Wait                                
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_141_Failure
    CheckAbility                        MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SOUNDPROOF, subscr_141_AfterUproar
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_UPROAR, subscr_141_Failure
subscr_141_AfterUproar:
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION, 0, subscr_141_Failure
    If                                  FLAG_EQ, VAR_EFFECT_TARGET_SIDECOND, SIDE_CONDITION_SAFEGUARD, subscr_141_SafeguardActive
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_141_Failure
    TryYawn                             subscr_141_Failure
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    // "{0} made {1} drowsy!"
    Message                             545, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_141_AbilityBlock:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s {1} made it ineffective!"
    Message                             734, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Branch                              subscr_141_Cleanup

subscr_141_Failure:
    WaitTime                            30
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    Branch                              subscr_141_Exit

subscr_141_SafeguardActive:
    WaitTime                            30
    // "{0} is protected by Safeguard!"
    Message                             200, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
subscr_141_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_141_Exit:
    End                                 

.close