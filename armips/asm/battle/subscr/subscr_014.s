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


.create "build/battle/scr/subscr/sub_seq_014.bin", 0

// SUBSCR_TRY_FLINCH
subscr_014:
    // If the move missed, then there's no point trying to flinch; quit out.
    CheckMoveMissed                     BATTLER_EFFECT_TARGET, subscr_014_End
    // Substitutes are immune to flinching.
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_014_NoFlinchingAllowed
    // Check for Inner Focus.
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_INNER_FOCUS, subscr_014_InnerFocus
    // Check for Shield Dust. No special output handling.
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_INDIRECT, subscr_014_ApplyFlinch
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_SHIELD_DUST, subscr_014_End
subscr_014_ApplyFlinch:
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION_2, CONDITION_V_FLINCHED
subscr_014_End:
    End                                 

subscr_014_InnerFocus:
    // Indirect flinches don't have a special message for Inner Focus (e.g., Stomp).
    // The exception is Fake Out, which is an indirect Flinch, but prints a message anyways.
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_FAKE_OUT, subscr_014_InnerFocusMessage
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_014_InnerFocusEnd
subscr_014_InnerFocusMessage:
    // "{0} won't flinch because of its Inner Focus!"
    Message                             737, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_014_InnerFocusEnd:
    End                                 

subscr_014_NoFlinchingAllowed:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_014_NoFlinchingAllowedEnd
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
subscr_014_NoFlinchingAllowedEnd:
    End                                 

.close