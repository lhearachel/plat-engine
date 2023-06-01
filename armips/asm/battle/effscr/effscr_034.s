.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_34.s", 0

effscr_034:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2164260875
    CriticalCalc                        
    DamageCalc                          
    End                                 
