.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_80.s", 0

effscr_080:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870941
    CriticalCalc                        
    DamageCalc                          
    End                                 
