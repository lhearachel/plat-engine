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


.create "build/battle/scr/effscr/be_seq_262.bin", 0

// User takes recoil = 1/3 of damage dealt; chance to paralyze on hit
//
// Reckless damage multiplier is handled in the battle calc
effscr_262:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_HAS_PROBABILITY | ADDL_EFFECT_VOLT_TACKLE
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close