.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_36.bin", 0

effscr_036:
    Random                              2, 3
    SetVar                              OP_ADD, VAR_CALC_WORK, 2147483648
    SetVarFromVar                       OP_SET, VAR_ADD_STATUS_INDIRECT, VAR_CALC_WORK
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close