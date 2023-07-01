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


.create "build/battle/scr/subscr/sub_seq_248.bin", 0

subscr_248:
    CheckSecondaryEffectActivation      subscr_248_CheckFlinch
    CallSubscript                       SUBSCR_APPLY_FREEZE
subscr_248_CheckFlinch:
    CheckSecondaryEffectActivation      subscr_248_Exit
    CallSubscript                       SUBSCR_TRY_FLINCH
subscr_248_Exit:
    End                                 

.close