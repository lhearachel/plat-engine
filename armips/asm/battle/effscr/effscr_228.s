.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_228.s", 0

effscr_228:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871045
    CriticalCalc                        
    DamageCalc                          
    End                                 
