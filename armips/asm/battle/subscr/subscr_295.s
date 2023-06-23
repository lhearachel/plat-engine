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


.create "build/battle/scr/subscr/sub_seq_295.bin", 0

// SUBSCR_OVERWORLD_TRICK_ROOM
subscr_295:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_TRICK_ROOM
    PlayAnimation                       BATTLER_WORKING
    Wait                                
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 0
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    // "The dimensions became distorted!"
    Message                             1267, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Initialize 5 turns of Trick Room
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 0x50000
    End                                 

.close