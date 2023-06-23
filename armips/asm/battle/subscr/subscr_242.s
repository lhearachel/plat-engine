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


.create "build/battle/scr/subscr/sub_seq_242.bin", 0

// SUBSCR_MAGNET_RISE_END
subscr_242:
    // "{0}'s electromagnetism wore off!"
    Message                             1039, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MAGNET_RISE
    End                                 

.close