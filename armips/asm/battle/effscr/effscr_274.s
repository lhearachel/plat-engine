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


.create "build/battle/scr/effscr/be_seq_274.bin", 0

// Chance to flinch and/or freeze on-hit
effscr_274:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_FREEZE_AND_FLINCH
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close