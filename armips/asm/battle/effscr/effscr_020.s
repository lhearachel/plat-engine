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


.create "build/battle/scr/effscr/be_seq_020.bin", 0

// Lower Speed by 1 stage (status)
effscr_020:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_SPE_DOWN_1
    End                                 

.close