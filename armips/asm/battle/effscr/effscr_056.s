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


.create "build/battle/scr/effscr/be_seq_056.bin", 0

// Raise Evasion by 2 stages (status)
//
// Vanilla does not implement this at all, nor is it used by any move in Vanilla
effscr_056:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close