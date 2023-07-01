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


.create "build/battle/scr/subscr/sub_seq_290.bin", 0

// SUBSCR_PLUCK_CHECK
subscr_290:
    If                                  FLAG_EQ, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, SINGLE_TURN_STATUS_FLAG_PLUCK_BERRY, subscr_290_ClearFlag
    RemoveItem                          BATTLER_WORKING
subscr_290_ClearFlag:
    SetVar                              OP_CLEAR_FLAG, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, SINGLE_TURN_STATUS_FLAG_PLUCK_BERRY
    End                                 

.close