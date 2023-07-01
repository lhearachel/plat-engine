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


.create "build/battle/scr/subscr/sub_seq_204.bin", 0

// SUBSCR_ITEM_PP_RESTORE
subscr_204:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0} restored {2}'s PP using its {1}!"
    Message                             902, TAG_NICK_ITEM_MOVE, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close