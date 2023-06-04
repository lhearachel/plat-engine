.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_254.bin", 0

effscr_254:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870976
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close