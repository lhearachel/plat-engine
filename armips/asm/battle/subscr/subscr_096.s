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


.create "build/battle/scr/subscr/sub_seq_096.bin", 0

// SUBSCR_CURSE_BOOST
subscr_096:
    // Speed -1
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_SPE_DOWN_1
    CallSubscript                       SUBSCR_BOOST_STATS
    // Turn off the attack message and animation for the other boosts (so it doesn't play again)
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF | SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    // Attack +1
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_ATK_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    // Defense +1
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_DEF_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    // Clear flags
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    End                                 

.close