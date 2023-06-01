.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_68.s", 0

effscr_068:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2147483670
    CriticalCalc                        
    DamageCalc                          
    End                                 
