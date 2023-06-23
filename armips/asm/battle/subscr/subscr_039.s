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


.create "build/battle/scr/subscr/sub_seq_039.bin", 0

// SUBSCR_CONFUSED_SELF_HIT
subscr_039:
    // "{0} is confused!"
    Message                             150, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_CONFUSED
    Wait                                
    // "It hurt itself in its confusion!"
    Message                             797, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    ClearContinuation                   BATTLER_ATTACKER
    CheckLeaveWith1HP                   BATTLER_ATTACKER
    CallSubscript                       SUBSCR_HP_CHANGE
    CallSubscript                       SUBSCR_MOVE_SUCCESS_MESSAGE
    End                                 

.close