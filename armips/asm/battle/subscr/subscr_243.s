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


.create "build/battle/scr/subscr/sub_seq_243.bin", 0

// SUBSCR_HEAL_BLOCK_END
subscr_243:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_HEAL_BLOCK
    // "{0}'s {1} wore off!"
    Message                             1060, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_HEAL_BLOCK
    End                                 

.close