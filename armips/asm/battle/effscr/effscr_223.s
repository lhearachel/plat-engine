.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_223.s", 0

effscr_223:
    TryFeint                            7
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870991
    CriticalCalc                        
    DamageCalc                          
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
