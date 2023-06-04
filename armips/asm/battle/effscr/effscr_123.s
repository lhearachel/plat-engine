.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_123.bin", 0

effscr_123:
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_FRIENDSHIP, VAR_DAMAGE_POWER
    SetVar                              OP_SUB, VAR_DAMAGE_POWER, 255
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 4294967286
    SetVar                              OP_DIV, VAR_DAMAGE_POWER, 25
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close