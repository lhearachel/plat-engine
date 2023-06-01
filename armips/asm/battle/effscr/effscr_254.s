.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_254.s", 0

effscr_254:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870976
    CriticalCalc                        
    DamageCalc                          
    End                                 
