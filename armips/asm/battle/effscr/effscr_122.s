.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_122.s", 0

effscr_122:
    TryPresent                          3
    CriticalCalc                        
    DamageCalc                          
    End                                 
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871009
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 32768
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    End                                 
