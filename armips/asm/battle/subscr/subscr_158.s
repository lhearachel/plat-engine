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


.create "build/battle/scr/subscr/sub_seq_158.bin", 0

// SUBSCR_MIRACLE_EYE
subscr_158:
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MIRACLE_EYE
    // "{0} identified {1}!"
    Message                             432, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close