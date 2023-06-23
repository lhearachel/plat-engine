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


.create "build/battle/scr/subscr/sub_seq_129.bin", 0

// SUBSCR_MEMENTO
subscr_129:
    AttackMessage                       
    Wait                                
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 0, subscr_129_Success
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_SPA_STAGE, 0, subscr_129_Failure

subscr_129_Success:
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    CheckSubstitute                     BATTLER_DEFENDER, subscr_129_Substitute
    // Turn off future animations/attack messages
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF | SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE
    SetVarFromVar                       OP_SET, VAR_EFFECT_TARGET, VAR_DEFENDER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
subscr_129_ReduceAtk:
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 0, subscr_129_ReduceSpAtk
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_ATK_DOWN_2
    CallSubscript                       SUBSCR_BOOST_STATS
subscr_129_ReduceSpAtk:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_TURN_OFF_MESSAGES
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_SPA_DOWN_2
    CallSubscript                       SUBSCR_BOOST_STATS
    // Cleanup flags
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES
    End                                 

subscr_129_Substitute:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "But it had no effect!"
    Message                             607, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

subscr_129_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close