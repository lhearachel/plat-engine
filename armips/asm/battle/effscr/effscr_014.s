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


.create "build/battle/scr/effscr/be_seq_014.bin", 0

// Raise SpDefense by 1 stage (status)
//
// Vanilla does not implement this at all, nor is it used by any move in Vanilla
effscr_014:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close