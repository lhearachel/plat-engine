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


.create "build/battle/scr/effscr/be_seq_036.bin", 0

// Tri-Attack (random Burn, Paralyze, or Freeze on hit)
effscr_036:
    Random                              2, 3
    SetVar                              OP_ADD, VAR_CALC_WORK, ADDL_EFFECT_DEFENDER
    SetVarFromVar                       OP_SET, VAR_ADD_STATUS_INDIRECT, VAR_CALC_WORK
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close