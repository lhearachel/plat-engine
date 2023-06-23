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


.create "build/battle/scr/effscr/be_seq_003.bin", 0

// Recover half of damage dealt
effscr_003:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DRAIN_HALF_DAMAGE | ADDL_EFFECT_FLAG_UPDATE
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close