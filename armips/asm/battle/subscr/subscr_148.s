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


.create "build/battle/scr/subscr/sub_seq_148.bin", 0

// SUBSCR_TICKLE
subscr_148:
    IfMonData                           NOT_EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_ATK_STAGE, 0, subscr_148_AttackDown
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_DEF_STAGE, 0, subscr_148_NoStatChange
subscr_148_AttackDown:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_148_Failure
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_ATK_DOWN_1
    CallSubscript                       SUBSCR_BOOST_STATS
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_TURN_OFF_MESSAGES
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_DEF_DOWN_1
    CallSubscript                       SUBSCR_BOOST_STATS
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    End                                 

subscr_148_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

subscr_148_NoStatChange:
    // Both target's attack and defense are already at -6
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s stats won't go any lower!"
    Message                             771, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close