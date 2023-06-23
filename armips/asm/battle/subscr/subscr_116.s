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


.create "build/battle/scr/subscr/sub_seq_116.bin", 0

// SUBSCR_BREAK_CLAMP
subscr_116:
    // "{0} got free of {1}'s {2}!"
    Message                             459, TAG_NICK_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close