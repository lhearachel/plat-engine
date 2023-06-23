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


.create "build/battle/scr/subscr/sub_seq_194.bin", 0

// SUBSCR_ANTICIPATION
subscr_194:
    // "{0}'s {1} made it shudder!"
    Message                             1106, TAG_ABILITY_NICK, BATTLER_CLIENT_WORK, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close