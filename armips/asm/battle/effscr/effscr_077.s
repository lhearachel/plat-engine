.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_077.bin", 0

effscr_077:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2147483650
    SetMultiHit                         2, MULTI_HIT_FLAGS
    SetVar                              OP_SET, VAR_SWOAM_TYPE, 1
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close