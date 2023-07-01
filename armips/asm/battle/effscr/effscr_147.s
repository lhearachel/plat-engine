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


.create "build/battle/scr/effscr/be_seq_147.bin", 0

// Double damage to an underground target
effscr_147:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_HIT_DIGGING_MON
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 10
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_UNDERGROUND, effscr_147_Damage
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
effscr_147_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close