.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_129.s", 0

effscr_129:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870947
    CriticalCalc                        
    DamageCalc                          
    End                                 
