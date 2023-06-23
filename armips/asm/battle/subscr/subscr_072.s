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


.create "build/battle/scr/subscr/sub_seq_072.bin", 0

// SUBSCR_DISABLE_END
subscr_072:
    // "{0} is no longer disabled!"
    Message                             369, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close