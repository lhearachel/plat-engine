.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_103.s", 0

effscr_103:
    CriticalCalc                        
    DamageCalc                          
    End                                 
