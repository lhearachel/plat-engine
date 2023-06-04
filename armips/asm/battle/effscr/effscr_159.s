.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_159.bin", 0

effscr_159:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 112, 4
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870922
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close