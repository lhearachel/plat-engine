.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_27.s", 0

effscr_027:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 3072, 4
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870965
    CriticalCalc                        
    DamageCalc                          
    End                                 
