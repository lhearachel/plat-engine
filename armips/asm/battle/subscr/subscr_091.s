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


.create "build/battle/scr/subscr/sub_seq_091.bin", 0

// SUBSCR_FORCE_OUT
subscr_091:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_DURING_FLY, subscr_091_Failure
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_DEFENDER, ABILITY_SUCTION_CUPS, subscr_091_SuctionCups
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_INGRAINED, subscr_091_Ingrained
    // Whirlwind effects do not work in wild double battles
    If                                  EQUAL, VAR_BATTLE_TYPE, BATTLE_TYPE_AI | BATTLE_TYPE_2vs2 | BATTLE_TYPE_DOUBLES, subscr_091_Failure
    TryWhirlwind                        subscr_091_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    TryNaturalCure                      BATTLER_DEFENDER, subscr_091_SkipNaturalCure
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_CONDITION, 0
subscr_091_SkipNaturalCure:
    PokemonDelete                       BATTLER_DEFENDER
    Wait                                
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TRAINER, subscr_091_EndBattle
    HPGaugeSlideOut                     BATTLER_DEFENDER
    Wait                                
    SwitchInAndUpdate                   BATTLER_FORCED_OUT
    Wait                                
    PokemonAppear                       BATTLER_DEFENDER
    WaitFrames                          72
    HPGaugeSlideIn                      BATTLER_DEFENDER
    Wait                                
    // "{0} was dragged out!"
    Message                             603, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER, VAR_DEFENDER
    CallSubscript                       SUBSCR_HAZARDS_CHECK
    End                                 

subscr_091_EndBattle:
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, BATTLE_RESULT_ESCAPE
    End                                 

subscr_091_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

subscr_091_SuctionCups:
    // "{0} anchors itself with {1}!"
    PrepareMessage                      659, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              subscr_091_ShowMessage

subscr_091_Ingrained:
    // "{0} anchored itself with its roots!"
    PrepareMessage                      542, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
subscr_091_ShowMessage:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close