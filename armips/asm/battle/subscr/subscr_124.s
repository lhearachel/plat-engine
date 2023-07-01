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


.create "build/battle/scr/subscr/sub_seq_124.bin", 0

// SUBSCR_STOCKPILE
subscr_124:
    AttackMessage                       
    Wait                                
    // Can only stockpile up to 3
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 3, subscr_124_Stockpiled3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    // Don't play the attack animation again
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    // Increment the stockpile counter
    SetMonData                          OP_ADD, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 1
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, VAR_PREPARED_MESSAGE
    // "{0} stockpiled {1}!"
    Message                             317, TAG_NICK_NUM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
subscr_124_BoostDef:
    // Boost Defense by 1
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_DEF_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_NO_MESSAGE_BETWEEN, subscr_124_BoostSpDef
    SetMonData                          OP_ADD, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, 1
subscr_124_BoostSpDef:
    // Boost SpDefense by 1
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_SPD_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_NO_MESSAGE_BETWEEN, subscr_124_Cleanup
    SetMonData                          OP_ADD, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, 1
subscr_124_Cleanup:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    End                                 

subscr_124_Stockpiled3:
    WaitTime                            30
    // "{0} can't stockpile any more!"
    Message                             320, TAG_NICK_NUM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close