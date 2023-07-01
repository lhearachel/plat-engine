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


.create "build/battle/scr/subscr/sub_seq_140.bin", 0

// SUBSCR_BREAK_SCREENS
subscr_140:
    TryBreakScreens                     subscr_140_NoScreens
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // "It shattered the barrier!"
    Message                             606, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              subscr_140_Exit

subscr_140_NoScreens:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_COMPOSITE_MISSED, subscr_140_Exit
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
subscr_140_Exit:
    End                                 

.close