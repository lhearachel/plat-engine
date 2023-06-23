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


.create "build/battle/scr/effscr/be_seq_193.bin", 0

// Refresh; cures the user of Burn, Poison, and Paralysis
effscr_193:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_REFRESH
    End                                 

.close