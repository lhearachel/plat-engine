.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_229.s", 0

effscr_229:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 1610612858
    CriticalCalc                        
    DamageCalc                          
    End                                 
