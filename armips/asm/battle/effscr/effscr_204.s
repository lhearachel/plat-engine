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


.create "build/battle/scr/effscr/be_seq_204.bin", 0

// Lower the user's SpAttack by 2 stages on-hit
effscr_204:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_SPA_DOWN_2
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close