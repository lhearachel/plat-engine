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


.create "build/battle/scr/subscr/sub_seq_105.bin", 0

// SUBSCR_SWAGGER
subscr_105:
    CheckSubstitute                     BATTLER_DEFENDER, subscr_105_Failure
    // Do not boost if the target has already maximized their Attack stat
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12, subscr_105_Boost
    // Do not try to confuse a target that is already confused
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED, subscr_105_Confuse
    // Fail if the target is both max-Attack and already confused
    Branch                              subscr_105_Failure

subscr_105_Boost:
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_ATK_UP_2
    CallSubscript                       SUBSCR_BOOST_STATS
    // Do not try to confuse a target that is already confused
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED, subscr_105_End
subscr_105_Confuse:
    CallSubscript                       SUBSCR_APPLY_CONFUSION
subscr_105_End:
    End                                 

subscr_105_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close