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


.create "build/battle/scr/effscr/be_seq_077.bin", 0

// Hit twice; chance to poison on-hit
effscr_077:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_POISON
    SetMultiHit                         2, MULTI_HIT_FLAGS
    SetVar                              OP_SET, VAR_SWOAM_TYPE, 1
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close