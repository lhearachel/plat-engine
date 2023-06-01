.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_12.s", 0

effscr_012:
    CriticalCalc                        
    DamageCalc                          
    End                                 
