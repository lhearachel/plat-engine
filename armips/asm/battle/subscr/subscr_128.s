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


.create "build/battle/scr/subscr/sub_seq_128.bin", 0

// SUBSCR_FLATTER
subscr_128:
    CheckSubstitute                     BATTLER_DEFENDER, subscr_128_Failure
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_SPA_STAGE, 12, subscr_128_Boost
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED, subscr_128_Confuse
    Branch                              subscr_128_Failure

subscr_128_Boost:
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_SPA_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED, subscr_128_Exit
subscr_128_Confuse:
    CallSubscript                       SUBSCR_APPLY_CONFUSION
subscr_128_Exit:
    End                                 

subscr_128_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close