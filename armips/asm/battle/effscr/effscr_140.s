.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_140.s", 0

effscr_140:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 1073741858
    CriticalCalc                        
    DamageCalc                          
    End                                 
