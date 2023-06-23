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


.create "build/battle/scr/subscr/sub_seq_075.bin", 0

// SUBSCR_BUT_IT_FAILED
subscr_075:
    // "But it failed!"
    Message                             796, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close