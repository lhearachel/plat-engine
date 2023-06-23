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


.create "build/battle/scr/subscr/sub_seq_252.bin", 0

// SUBSCR_SNOW_WARNING
subscr_252:
    SetStatusEffect                     BATTLER_ME, STATUS_WEATHER_HAIL
    Wait                                
    WaitTime                            15
    // "{0}'s {1} whipped up a hailstorm!"
    Message                             701, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_WEATHER
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_HAILING_PERM
    End                                 

.close