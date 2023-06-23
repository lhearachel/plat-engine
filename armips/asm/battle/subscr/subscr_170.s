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


.create "build/battle/scr/subscr/sub_seq_170.bin", 0

// SUBSCR_FLARE_BLITZ
subscr_170:
    CallSubscript                       SUBSCR_RECOIL_1_3
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_EFFECT, subscr_170_Exit
    CallSubscript                       SUBSCR_APPLY_BURN
subscr_170_Exit:
    End                                 

.close