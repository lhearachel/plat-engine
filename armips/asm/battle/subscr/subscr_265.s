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


.create "build/battle/scr/subscr/sub_seq_265.bin", 0

// SUBSCR_ITEM_ACC_UP_ONCE
subscr_265:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0} boosted the accuracy of its next move using its {1}!"
    Message                             1157, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_TEMP_ACC_MAX, 1
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close