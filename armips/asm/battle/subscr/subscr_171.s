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


.create "build/battle/scr/subscr/sub_seq_171.bin", 0

// SUBSCR_DEFOG
subscr_171:
    // Clear all of the following from the target's side: Reflect, Light Screen, Mist, Safeguard, Spikes, Toxic Spikes, Stealth Rock
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_REFLECT_COUNT, subscr_171_Resume
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_LIGHT_SCREEN_COUNT, subscr_171_Resume
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_MIST_COUNT, subscr_171_Resume
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_SAFEGUARD_COUNT, subscr_171_Resume
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_SPIKES_COUNT, subscr_171_Resume
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_ON, SIDE_CONDITION_TOXIC_SPIKES_COUNT, subscr_171_Resume
    If                                  FLAG_EQ, VAR_DEFENDER_SIDE_CONDITIONS, SIDE_CONDITION_STEALTH_ROCK, subscr_171_Resume
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_DEEP_FOG, subscr_171_Resume
    // If there is nothing to clear, then skip the attack animation (?)
    Branch                              subscr_171_SkipAnimation

subscr_171_Resume:
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
subscr_171_SkipAnimation:
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_EVA_DOWN_1
    CallSubscript                       SUBSCR_BOOST_STATS

subscr_171_ClearReflect:
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_REFLECT_COUNT, subscr_171_ClearLightScreen
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_REFLECT_COUNT, subscr_171_ClearLightScreen
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_REFLECT
    CallSubscript                       SUBSCR_DEFOG_MESSAGE

subscr_171_ClearLightScreen:
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_LIGHT_SCREEN_COUNT, subscr_171_ClearMist
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_LIGHT_SCREEN_COUNT, subscr_171_ClearMist
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_LIGHT_SCREEN
    CallSubscript                       SUBSCR_DEFOG_MESSAGE

subscr_171_ClearMist:
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_MIST_COUNT, subscr_171_ClearSafeguard
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_MIST_COUNT, subscr_171_ClearSafeguard
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_MIST
    CallSubscript                       SUBSCR_DEFOG_MESSAGE

subscr_171_ClearSafeguard:
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_SAFEGUARD_COUNT, subscr_171_ClearSpikes
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_SAFEGUARD_COUNT, subscr_171_ClearSpikes
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_SAFEGUARD
    CallSubscript                       SUBSCR_DEFOG_MESSAGE

subscr_171_ClearSpikes:
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_SPIKES_COUNT, subscr_171_ClearToxicSpikes
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_SPIKES_COUNT, subscr_171_ClearToxicSpikes
    SetVar                              OP_CLEAR_FLAG, VAR_DEFENDER_SIDE_CONDITIONS, SIDE_CONDITION_SPIKES
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_SPIKES
    CallSubscript                       SUBSCR_DEFOG_MESSAGE

subscr_171_ClearToxicSpikes:
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CHECK_OFF, SIDE_CONDITION_TOXIC_SPIKES_COUNT, subscr_171_ClearStealthRock
    CheckSideCondition                  BATTLER_DEFENDER, SIDE_CONDITION_MODE_CLEAR, SIDE_CONDITION_TOXIC_SPIKES_COUNT, subscr_171_ClearStealthRock
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_TOXIC_SPIKES
    CallSubscript                       SUBSCR_DEFOG_MESSAGE

subscr_171_ClearStealthRock:
    If                                  FLAG_NEQ, VAR_DEFENDER_SIDE_CONDITIONS, SIDE_CONDITION_STEALTH_ROCK, subscr_171_ClearDeepFog
    SetVar                              OP_CLEAR_FLAG, VAR_DEFENDER_SIDE_CONDITIONS, SIDE_CONDITION_STEALTH_ROCK
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_STEALTH_ROCK
    CallSubscript                       SUBSCR_DEFOG_MESSAGE

subscr_171_ClearDeepFog:
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_DEEP_FOG, subscr_171_Exit
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_DEEP_FOG
    // "{0} blew away the deep fog with {1}!"
    Message                             1045, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    
subscr_171_Exit:
    End                                 

.close