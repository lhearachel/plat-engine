.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_99.s", 0

effscr_099:
    FlailDamageCalc                     
    CriticalCalc                        
    DamageCalc                          
    End                                 
