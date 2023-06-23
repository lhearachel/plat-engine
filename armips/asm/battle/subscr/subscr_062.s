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


.create "build/battle/scr/subscr/sub_seq_062.bin", 0

// SUBSCR_FOCUS_ENERGY
subscr_062:
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_CONDITION_2, CONDITION_V_PUMPED
    // "{0} is getting pumped!"
    Message                             276, TAG_NICK, BATTLER_EFFECT_TARGET, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close