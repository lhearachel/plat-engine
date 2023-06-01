.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_21.s", 0

effscr_021:
    CriticalCalc                        
    DamageCalc                          
    End                                 
