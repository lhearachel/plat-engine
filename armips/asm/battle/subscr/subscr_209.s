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


.create "build/battle/scr/subscr/sub_seq_209.bin", 0

// SUBSCR_ITEM_RAISE_CRIT
subscr_209:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0} used the {1} to get pumped!"
    Message                             597, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_SET_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_PUMPED
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close