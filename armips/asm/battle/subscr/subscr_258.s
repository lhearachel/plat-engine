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


.create "build/battle/scr/subscr/sub_seq_258.bin", 0

// SUBSCR_DISOBEY_SELF_HIT
subscr_258:
    // "{0} won't obey!"
    Message                             829, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // "It hurt itself in its confusion!"
    Message                             797, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    ClearContinuation                   BATTLER_ATTACKER
    JumpTo                              SUBSCR_HP_CHANGE

.close