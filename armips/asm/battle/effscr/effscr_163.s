.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_163.s", 0

effscr_163:
    CriticalCalc                        
    DamageCalc                          
    End                                 
