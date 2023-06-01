.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_209.s", 0

effscr_209:
    SetVar                              OP_ADD, VAR_CRITICAL_CHANCE, 1
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2147483650
    CriticalCalc                        
    DamageCalc                          
    End                                 
