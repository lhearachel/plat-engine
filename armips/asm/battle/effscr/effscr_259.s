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


.create "build/battle/scr/effscr/be_seq_259.bin", 0

// Trick Room
effscr_259:
    // If Trick Room is already in effect, immediately end it
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_TRICK_ROOM, effscr_259_EndTrickRoom
    // Set the normal duration of Trick Room (5 turns)
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 0x00050000
    PrepareMessage                      1070, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              effscr_259_Message
effscr_259_EndTrickRoom:
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, FIELD_CONDITION_TRICK_ROOM
    PrepareMessage                      1073, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
effscr_259_Message:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    TrickRoom                           
    End                                 

// No, this is never actually reached.
effscr_259_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close