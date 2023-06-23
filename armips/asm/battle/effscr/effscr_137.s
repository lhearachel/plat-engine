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


.create "build/battle/scr/effscr/be_seq_137.bin", 0

// Set weather: Sun
effscr_137:
    // Don't try to set the weather if Sun is already in effect
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, effscr_137_SunAlreadySet
    PrepareMessage                      807, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_WEATHER
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY_TEMP
    SetVar                              OP_SET, VAR_WEATHER_COUNT, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_SET_WEATHER
    // If the user is holding a Heat Rock, extend the duration of the weather
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_EXTEND_SUN, effscr_137_End
    GetItemPower                        BATTLER_ATTACKER, VAR_CALC_WORK
    SetVarFromVar                       OP_ADD, VAR_WEATHER_COUNT, VAR_CALC_WORK
effscr_137_End:
    End                                 

effscr_137_SunAlreadySet:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close