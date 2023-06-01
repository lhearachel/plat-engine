.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_117.s", 0

effscr_117:
    RolloutDamageCalc                   
    CriticalCalc                        
    DamageCalc                          
    End                                 
