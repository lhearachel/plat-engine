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


.create "build/battle/scr/effscr/be_seq_218.bin", 0

// Lower target's Speed by 1 stage (on-hit)
effscr_218:
    // I'm not sure why it does it this way; kinda weird
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_SPE_DOWN_1
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close