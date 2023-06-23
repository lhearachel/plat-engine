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


.create "build/battle/scr/subscr/sub_seq_030.bin", 0

// SUBSCR_THAW_OUT_FROM_MOVE
subscr_030:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_FROZEN
    // "{0} was defrosted by {1}!"
    Message                             117, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    WaitTime                            30
    End                                 

.close