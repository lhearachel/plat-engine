.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_121.s", 0

effscr_121:
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_FRIENDSHIP, VAR_DAMAGE_POWER
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 10
    SetVar                              OP_DIV, VAR_DAMAGE_POWER, 25
    CriticalCalc                        
    DamageCalc                          
    End                                 
