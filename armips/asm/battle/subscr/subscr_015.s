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


.create "build/battle/scr/subscr/sub_seq_015.bin", 0

// SUBSCR_MOVE_FAIL_FLINCHED
subscr_015:
    // "{0} flinched!"
    Message                             181, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Turn off the continuation flag for moves like Thrash, etc.
    ClearContinuation                   BATTLER_ATTACKER
    // Apply Steadfast boost, if necessary.
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_STEADFAST, subscr_015_End
    SetVar                              OP_SET, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_SPE_UP_1
    SetVarFromVar                       OP_SET, VAR_EFFECT_TARGET, VAR_ATTACKER
    CallSubscript                       SUBSCR_BOOST_STATS
    
subscr_015_End:
    End                                 

.close