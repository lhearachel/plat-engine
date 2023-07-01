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


.create "build/battle/scr/subscr/sub_seq_249.bin", 0

subscr_249:
    CheckSecondaryEffectActivation      subscr_249_CheckFlinch
    CallSubscript                       SUBSCR_APPLY_PARALYSIS
subscr_249_CheckFlinch:
    CheckSecondaryEffectActivation      subscr_249_Exit
    CallSubscript                       SUBSCR_TRY_FLINCH
subscr_249_Exit:
    End                                 

.close