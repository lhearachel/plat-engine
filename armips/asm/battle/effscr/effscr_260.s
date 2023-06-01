.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_260.s", 0

effscr_260:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2147483652
    CriticalCalc                        
    DamageCalc                          
    End                                 
