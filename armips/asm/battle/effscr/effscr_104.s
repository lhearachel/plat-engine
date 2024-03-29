.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/effscr/be_seq_104.bin", 0

// Triple Kick (hit 3 times, increase power by 10 with each hit)
effscr_104:
    SetMultiHit                         3, TRIPLE_KICK_FLAGS
    SetVar                              OP_SET, VAR_SWOAM_TYPE, 1
    SetVar                              OP_ADD, VAR_DAMAGE_POWER, 10
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close