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


.create "build/battle/scr/effscr/be_seq_047.bin", 0

// Increase critical hit rate by 2 stages
effscr_047:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_PUMPED, effscr_047_Failure
    SetVar                              OP_SET_FLAG, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_CRIT_UP_2
    End                                 

effscr_047_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close