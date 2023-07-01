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


.create "build/battle/scr/effscr/be_seq_146.bin", 0

// Twister: chance to flinch + double damage to a target in the air
effscr_146:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLINCH
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_HIT_FLYING_MON
    // This line is technically a no-op; should probably remove it during the revamp
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 10
    // If the target is airborne, add a multiplication factor of 2x to the damage output
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_AIRBORNE, effscr_146_Damage
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
effscr_146_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close