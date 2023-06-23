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


.create "build/battle/scr/effscr/be_seq_156.bin", 0

// Defense Curl (raise Defense by 1 stage, increase Rollout power)
effscr_156:
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_DEFENSE_CURLED
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_DEF_UP_1
    End                                 

.close