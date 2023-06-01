.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_29.s", 0

effscr_029:
    SetMultiHit                         0, MULTI_HIT_FLAGS
    SetVar                              OP_SET, VAR_SWOAM_TYPE, 1
    CriticalCalc                        
    DamageCalc                          
    End                                 
