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


.create "build/battle/scr/subscr/sub_seq_303.bin", 0

// SUBSCR_TURBOBLAZE
subscr_303:
    // "{0} is radiating a blazing aura!"
    Message                             1273, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close
