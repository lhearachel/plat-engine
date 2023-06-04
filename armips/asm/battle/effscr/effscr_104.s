.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_104.bin", 0

effscr_104:
    SetMultiHit                         3, TRIPLE_KICK_FLAGS
    SetVar                              OP_SET, VAR_SWOAM_TYPE, 1
    SetVar                              OP_ADD, VAR_DAMAGE_POWER, 10
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close