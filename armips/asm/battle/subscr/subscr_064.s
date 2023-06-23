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


.create "build/battle/scr/subscr/sub_seq_064.bin", 0

// SUBSCR_RECHARGE_MOVE
subscr_064:
    // Set the recharging flag
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_RECHARGING
    SetVarFromVar                       OP_SET, VAR_MOVE_CONTINUATION, VAR_CURRENT_MOVE
    // Me First needs to look at the most recently used move
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_ME_FIRST_ACTIVE, VAR_TURNS
    End                                 

.close