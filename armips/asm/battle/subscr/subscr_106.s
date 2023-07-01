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


.create "build/battle/scr/subscr/sub_seq_106.bin", 0

// SUBSCR_APPLY_ATTRACT
subscr_106:
    // Oblivious blocks attraction
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECT_TARGET, ABILITY_OBLIVIOUS, subscr_106_Blocked
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_106_Failure
    TryAttract                          subscr_106_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Check if the effect came from Cute Charm or Destiny Knot
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_106_CuteCharm
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_106_DestinyKnot
    // "{0} fell in love!"
    Message                             162, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_106_AfterMessage

subscr_106_CuteCharm:
    // "{0}'s {1} infatuated {2}!"
    Message                             707, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN
    Branch                              subscr_106_AfterMessage

subscr_106_DestinyKnot:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0}'s {1} infatuated {2}!"
    Message                             1150, TAG_NICK_ITEM_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN

subscr_106_AfterMessage:
    Wait                                
    WaitTime                            30
    // Set the single-turn status flag, so that a defender moving after being attracted can be immobilized
    SetVar                              OP_SET_FLAG, VAR_EFFECT_TARGET_ONE_TURN_STATUS_FLAGS, SINGLE_TURN_STATUS_INFATUATED
    End                                 

subscr_106_Blocked:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_106_BlockedCuteCharm
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM, subscr_106_BlockedDestinyKnot
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s {1} prevents romance!"
    Message                             647, TAG_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

subscr_106_BlockedCuteCharm:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_106_Exit
    // Unreachable?
    // "{0}'s {1} suppressed {2}'s {3}!"
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_106_BlockedDestinyKnot:
    // "{0}'s {1} made the {2} ineffective!"
    Message                             1147, TAG_NICK_ABILITY_ITEM, BATTLER_EFFECT_TARGET, BATTLER_EFFECT_TARGET, BATTLER_CLIENT_WORK, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_106_Failure:
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY, subscr_106_Exit
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
subscr_106_Exit:
    End                                 

.close