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


.create "build/battle/scr/subscr/sub_seq_282.bin", 0

// SUBSCR_BIDE_END_NO_TARGET
subscr_282:
    // "{0} unleashed energy!"
    Message                             335, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CHARGING
    // "But there was no target...""
    Message                             1234, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close