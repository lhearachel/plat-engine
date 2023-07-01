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


.create "build/battle/scr/subscr/sub_seq_104.bin", 0

// SUBSCR_WEATHER_EOT_EFFECT
subscr_104:
    CallSubscript                       SUBSCR_SHOW_PREPARED_MESSAGE
    SetStatusEffectFromVar              BATTLER_ME, VAR_TEMP_WORK
    Wait                                
    // Start with the fastest battler
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
// Loop over the battlers in speed order
subscr_104_WeatherDamageLoop:
    GetBattlerBySpeedOrder              VAR_BATTLER_WORK
    // Calculate any weather damage for this battler
    WeatherDamageCalc                   BATTLER_WORKING
    // Hydration check
    If                                  EQUAL, VAR_TEMP_WORK, 1, subscr_104_Hydration
    // If there is no damage to deal, skip ahead
    If                                  EQUAL, VAR_HP_TEMP, 0, subscr_104_NextBattler
    // If the computed value is positive, do healing instead (Rain Dish, Ice Body)
    If                                  GREATER, VAR_HP_TEMP, 0, subscr_104_WeatherHealing
    // Check for Magic Guard immunity
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, subscr_104_NextBattler
    // Check for Sun (extra Solar Power / Dry Skin check)
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, subscr_104_SolarPower
    // "{0} is buffeted by the {1}!"
    Message                             285, TAG_MOVE_NICK, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_104_AfterMessage

subscr_104_SolarPower:
    // Solar Power check
    If                                  EQUAL, VAR_TEMP_WORK, 2, subscr_104_SolarPowerMessage
    // "{0} is hurt by its {1}!"
    Message                             1090, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Branch                              subscr_104_AfterMessage

subscr_104_SolarPowerMessage:
    // "{0} lost some HP because of its {1}!"
    Message                             1096, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN

subscr_104_AfterMessage:
    Wait                                
    WaitTime                            30
    CallSubscript                       SUBSCR_HP_CHANGE
    // Check for any battlers that are fainting (and faint them in the midst of the loop after they take their assigned damage)
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_FAINTED_MON, subscr_104_NextBattler
    CallSubscript                       SUBSCR_FAINT
    Branch                              subscr_104_NextBattler

subscr_104_WeatherHealing:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} restored HP using its {1}!"
    Message                             635, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30

// Get the next battler and loop back up to the top
subscr_104_NextBattler:
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, subscr_104_WeatherDamageLoop
    End                                 

subscr_104_Hydration:
    CallSubscript                       SUBSCR_SHED_SKIN
    Branch                              subscr_104_NextBattler

.close