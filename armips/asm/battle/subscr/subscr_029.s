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


.create "build/battle/scr/subscr/sub_seq_029.bin", 0

// SUBSCR_THAW_OUT
subscr_029:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION, CONDITION_FROZEN
    // "{0} thawed out!"
    Message                             114, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NONE
    WaitTime                            30
    End                                 

.close