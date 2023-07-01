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


.create "build/battle/scr/subscr/sub_seq_247.bin", 0

// SUBSCR_BURN_OR_FLINCH
subscr_247:
    CheckSecondaryEffectActivation      subscr_247_CheckFlinch
    CallSubscript                       SUBSCR_APPLY_BURN
subscr_247_CheckFlinch:
    CheckSecondaryEffectActivation      subscr_247_Exit
    CallSubscript                       SUBSCR_TRY_FLINCH
subscr_247_Exit:
    End                                 

.close