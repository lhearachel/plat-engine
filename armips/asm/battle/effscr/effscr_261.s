.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_261.s", 0

effscr_261:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 16
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 10
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 262144, 4
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2181038093
    CriticalCalc                        
    DamageCalc                          
    End                                 
