.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_275.s", 0

effscr_275:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2684354701
    CriticalCalc                        
    DamageCalc                          
    End                                 
