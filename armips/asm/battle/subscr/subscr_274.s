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


.create "build/battle/scr/subscr/sub_seq_274.bin", 0

// SUBSCR_OVERWORLD_FOG
subscr_274:
    SetStatusEffect                     BATTLER_ME, STATUS_WEATHER_FOG
    Wait                                
    // "The fog is deep..."
    Message                             813, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_DEEP_FOG
    End                                 

.close