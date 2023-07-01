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


.create "build/battle/scr/effscr/be_seq_061.bin", 0

// Lower SpAttack by 2 stages (status)
//
// Vanilla does not actually implement this
effscr_061:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close