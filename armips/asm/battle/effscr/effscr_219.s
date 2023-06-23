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


.create "build/battle/scr/effscr/be_seq_219.bin", 0

// Gyro Ball; power is proportional to the difference in speed between the user
// and the target
effscr_219:
    GyroBallDamageCalc                  
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close