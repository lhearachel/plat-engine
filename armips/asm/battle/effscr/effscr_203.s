.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_203.s", 0

effscr_203:
    WeatherBallDamageCalc               
    CriticalCalc                        
    DamageCalc                          
    End                                 
