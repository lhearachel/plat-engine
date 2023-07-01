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


.create "build/battle/scr/subscr/sub_seq_226.bin", 0

// SUBSCR_VOLT_TACKLE
subscr_226:
    CallSubscript                       SUBSCR_RECOIL_1_3
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_EFFECT, subscr_226_Exit
    CallSubscript                       SUBSCR_APPLY_PARALYSIS
subscr_226_Exit:
    End                                 

.close