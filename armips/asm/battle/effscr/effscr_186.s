.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_186.s", 0

effscr_186:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2155872368
    CriticalCalc                        
    DamageCalc                          
    End                                 
