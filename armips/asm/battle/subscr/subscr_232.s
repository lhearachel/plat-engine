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


.create "build/battle/scr/subscr/sub_seq_232.bin", 0

// SUBSCR_FOCUS_PUNCH_START
subscr_232:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_FOCUS_PUNCH
    PlayAnimationAtoD                   BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    // "{0} is tightening its focus!"
    Message                             497, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    End                                 

.close