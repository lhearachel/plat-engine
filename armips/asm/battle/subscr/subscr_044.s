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


.create "build/battle/scr/subscr/sub_seq_044.bin", 0

// SUBSCR_THRASHING
subscr_044:
    // Assign the number of turns we will continue thrashing
    Random                              1, 2
    SetVar                              OP_LSH, VAR_CALC_WORK, 10
    SetMonDataFromVar                   OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    SetVarFromVar                       OP_SET, VAR_MOVE_CONTINUATION, VAR_CURRENT_MOVE
    End                                 

.close