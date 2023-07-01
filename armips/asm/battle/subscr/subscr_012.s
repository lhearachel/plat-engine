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


.create "build/battle/scr/subscr/sub_seq_012.bin", 0

// SUBSCR_BOOST_STATS
subscr_012:
    StatBoostChange                     subscr_012_NoChange, subscr_012_End, subscr_012_ChangeFailed
    // Skip the attack message for indirect effects (e.g. damaging moves with secondary effects)
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_012_SkipAttackMessage
    AttackMessage                       
    Wait                                
subscr_012_SkipAttackMessage:
    // Also skip the attack animation for indirect effects; TODO: optimize this a bit
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_012_SkipEffectAnimation
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_012_SkipEffectAnimation:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES, subscr_012_NoFlagUpdate
    SetStatusEffectFromVar              BATTLER_EFFECT_TARGET, VAR_TEMP_WORK
    Wait                                
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_CHECK_STAT_STAGES, subscr_012_NoFlagUpdate
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES
subscr_012_NoFlagUpdate:
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    End                                 

subscr_012_NoChange:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_012_NoChangeNoMessage
    AttackMessage                       
    Wait                                
subscr_012_NoChangeNoMessage:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_TURN_OFF_MESSAGES, subscr_012_End
    WaitTime                            30
    MessagePrepared                     
    Wait                                
    WaitTime                            30
subscr_012_End:
    End                                 

subscr_012_ChangeFailed:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close