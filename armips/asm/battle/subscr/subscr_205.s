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


.create "build/battle/scr/subscr/sub_seq_205.bin", 0

// SUBSCR_ITEM_RECOVER_CNF
subscr_205:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0}'s {1} snapped it out of confusion!"
    Message                             890, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close