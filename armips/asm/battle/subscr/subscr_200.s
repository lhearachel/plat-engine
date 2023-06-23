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


.create "build/battle/scr/subscr/sub_seq_200.bin", 0

// SUBSCR_ITEM_RECOVER_SLP
subscr_200:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0}'s {1} woke it up!"
    Message                             887, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NONE
    WaitTime                            30
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_NIGHTMARES
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close