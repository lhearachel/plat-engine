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


.create "build/battle/scr/subscr/sub_seq_102.bin", 0

// SUBSCR_COUNT_PERISH_SONG
subscr_102:
    // "{0}'s perish count fell to {1}!"
    Message                             439, TAG_NICK_NUM, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Faint the mon if the count is 0
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_PERISH_SONG, subscr_102_Exit
    CallSubscript                       SUBSCR_HP_CHANGE
subscr_102_Exit:
    End                                 

.close