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


.create "build/battle/scr/subscr/sub_seq_138.bin", 0

// SUBSCR_SUPERPOWER_DEBUFF
subscr_138:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_ATK_DOWN_1
    CallSubscript                       SUBSCR_BOOST_STATS
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_DEF_DOWN_1
    CallSubscript                       SUBSCR_BOOST_STATS
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    End                                 

.close