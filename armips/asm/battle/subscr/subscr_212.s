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


.create "build/battle/scr/subscr/sub_seq_212.bin", 0

// SUBSCR_ITEM_RECOVER_INF
subscr_212:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0} cured its {2} status using its {1}!"
    Message                             893, TAG_NICK_ITEM_COND, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_INFATUATED
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close