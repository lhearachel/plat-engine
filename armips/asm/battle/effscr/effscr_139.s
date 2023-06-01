.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_139.s", 0

effscr_139:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 1073741839
    CriticalCalc                        
    DamageCalc                          
    End                                 
