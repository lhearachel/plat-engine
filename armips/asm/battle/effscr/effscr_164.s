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


.create "build/battle/scr/effscr/be_seq_164.bin", 0

// Set Hail
effscr_164:
    // This is not by mistake. Yes, it only checks the temporary hailing flag in vanilla.
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_HAILING_TEMP, effscr_164_Failure
    // "It started to hail!"
    PrepareMessage                      810, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_WEATHER
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_HAILING_TEMP
    SetVar                              OP_SET, VAR_WEATHER_COUNT, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_SET_WEATHER
    // Account for Icy Rock
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_EXTEND_HAIL, subscr_164_Exit
    GetItemPower                        BATTLER_ATTACKER, VAR_CALC_WORK
    SetVarFromVar                       OP_ADD, VAR_WEATHER_COUNT, VAR_CALC_WORK
subscr_164_Exit:
    End                                 

effscr_164_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close