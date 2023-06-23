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


.create "build/battle/scr/subscr/sub_seq_174.bin", 0

// SUBSCR_MOVE_FAILED_HEAL_BLOCK
subscr_174:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_HEAL_BLOCK
    // "{0} can't use {1} due to {2}!"
    Message                             1057, TAG_NICK_MOVE_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close