.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_231.s", 0

effscr_231:
    GetCurrentMoveData                  MOVE_PARAM_POWER
    SetVarFromVar                       OP_SET, VAR_DAMAGE_POWER, VAR_CALC_WORK
    If                                  EQUAL, VAR_DEFENDER_ASSURANCE_DAMAGE, 0, 8
    SetVarFromVar                       OP_SET, VAR_DAMAGE_POWER, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 2
    CriticalCalc                        
    DamageCalc                          
    End                                 
