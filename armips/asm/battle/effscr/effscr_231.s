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


.create "build/battle/scr/effscr/be_seq_231.bin", 0

// Assurance; double power if the target has been hit
effscr_231:
    GetCurrentMoveData                  MOVE_PARAM_POWER
    SetVarFromVar                       OP_SET, VAR_DAMAGE_POWER, VAR_CALC_WORK
    If                                  EQUAL, VAR_DEFENDER_ASSURANCE_DAMAGE, 0, effscr_231_Damage
    SetVarFromVar                       OP_SET, VAR_DAMAGE_POWER, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 2
effscr_231_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close