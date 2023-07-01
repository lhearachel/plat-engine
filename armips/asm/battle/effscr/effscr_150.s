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


.create "build/battle/scr/effscr/be_seq_150.bin", 0

// Double damage to Minimized target; chance to flinch on hit
effscr_150:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLINCH
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 10
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MINIMIZED, effscr_150_Damage
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
effscr_150_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close