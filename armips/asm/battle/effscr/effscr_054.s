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


.create "build/battle/scr/effscr/be_seq_054.bin", 0

// Raise SpDefense by 2 stages (status)
effscr_054:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_SPD_UP_2
    End                                 

.close