.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_125.s", 0

effscr_125:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2147483651
    CriticalCalc                        
    DamageCalc                          
    End                                 
