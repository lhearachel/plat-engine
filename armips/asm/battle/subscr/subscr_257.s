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


.create "build/battle/scr/subscr/sub_seq_257.bin", 0

// SUBSCR_DISOBEY_NAP
subscr_257:
    WaitTime                            15
    // "{0} began to nap!"
    Message                             827, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVarFromVar                       OP_SET, VAR_EFFECT_TARGET, VAR_ATTACKER
    SetVar                              OP_SET, VAR_EFFECT_TYPE, ADDL_EFFECT_DISOBEY
    CallSubscript                       SUBSCR_APPLY_SLEEP
    End                                 

.close