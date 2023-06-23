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


.create "build/battle/scr/subscr/sub_seq_028.bin", 0

// SUBSCR_FROZEN
subscr_028:
    // "{0} is frozen solid!"
    Message                             111, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_FROZEN
    Wait                                
    End                                 

.close