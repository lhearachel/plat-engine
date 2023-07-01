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


.create "build/battle/scr/effscr/be_seq_029.bin", 0

// Multi-strike (2-5 hits)
effscr_029:
    SetMultiHit                         0, MULTI_HIT_FLAGS
    // This line just tells the attack to loop
    SetVar                              OP_SET, VAR_SWOAM_TYPE, 1
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close