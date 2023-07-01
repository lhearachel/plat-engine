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


.create "build/battle/scr/subscr/sub_seq_051.bin", 0

// SUBSCR_THRASH_END
subscr_051:
    SetVar                              OP_SET, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_MOVE
    CallSubscript                       SUBSCR_APPLY_CONFUSION
    IfMonData                           FLAG_NEQ, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED, subscr_051_NoConfusion
    // "{0} became confused due to fatigue!"
    Message                             338, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_051_NoConfusion:
    End                                 

.close