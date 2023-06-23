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


.create "build/battle/scr/subscr/sub_seq_152.bin", 0

// SUBSCR_DRAGON_DANCE
subscr_152:
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_ATK_STAGE, 12, subscr_152_Resume
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_SPE_STAGE, 12, subscr_152_NoBoost
subscr_152_Resume:
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_TURN_OFF_MESSAGES
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF | SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_ATK_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_SPE_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    End                                 

subscr_152_NoBoost:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s stats won't go any higher!"
    Message                             768, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close