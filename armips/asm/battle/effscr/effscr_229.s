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


.create "build/battle/scr/effscr/be_seq_229.bin", 0

// Lower the user's Defense and SpDefense by 1 stage each (on-hit)
effscr_229:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_CLOSE_COMBAT
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close