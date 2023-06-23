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


.create "build/battle/scr/effscr/be_seq_125.bin", 0

// Thaw the user; chance to burn the target on hit
//
// This one is identical to effscr_004; the user-thawing functionality is
// deeper in the server code.
effscr_125:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_BURN
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close