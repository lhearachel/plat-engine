.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_188.s", 0

effscr_188:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870966
    CriticalCalc                        
    DamageCalc                          
    End                                 
