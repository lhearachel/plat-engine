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


.create "build/battle/scr/subscr/sub_seq_260.bin", 0

// SUBSCR_CHATTER
subscr_260:
    CheckChatterActivation              subscr_260_Exit
    CallSubscript                       SUBSCR_APPLY_CONFUSION
subscr_260_Exit:
    End                                 

.close