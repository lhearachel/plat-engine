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


.create "build/battle/scr/subscr/sub_seq_049.bin", 0

// SUBSCR_LIGHT_SCREEN
subscr_049:
    SetLightScreen                      subscr_049_Failure
    CallSubscript                       SUBSCR_ANIMATION_WITH_PREPARED_MESSAGE
subscr_049_Failure:
    End                                 

.close