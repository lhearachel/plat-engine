.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_152.s", 0

effscr_152:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2147483653
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 4
    CriticalCalc                        
    DamageCalc                          
    End                                 
