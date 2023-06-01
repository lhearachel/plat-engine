.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_110.s", 0

effscr_110:
    CriticalCalc                        
    DamageCalc                          
    End                                 
