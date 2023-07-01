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


.create "build/battle/scr/effscr/be_seq_128.bin", 0

// Pursuit
//
// The effect script here is just a damage calc; all the heavy lifting is
// done elsewhere.
effscr_128:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close