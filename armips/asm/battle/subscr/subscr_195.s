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


.create "build/battle/scr/subscr/sub_seq_195.bin", 0

// SUBSCR_FOREWARN
subscr_195:
    // "{0}'s {1} alerted it to {2}!"
    Message                             1109, TAG_NICK_ABILITY_MOVE, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close