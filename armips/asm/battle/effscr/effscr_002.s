.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_2.s", 0

effscr_002:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2147483650
    CriticalCalc                        
    DamageCalc                          
    End                                 
