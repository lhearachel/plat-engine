.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_121.bin", 0

effscr_121:
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_FRIENDSHIP, VAR_DAMAGE_POWER
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 10
    SetVar                              OP_DIV, VAR_DAMAGE_POWER, 25
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close