.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_169.s", 0

effscr_169:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 216, 4
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
    CriticalCalc                        
    DamageCalc                          
    End                                 
