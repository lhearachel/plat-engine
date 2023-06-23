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


.create "build/battle/scr/subscr/sub_seq_056.bin", 0

// SUBSCR_UPROAR
subscr_056:
    SetVarFromVar                       OP_SET, VAR_MOVE_CONTINUATION, VAR_CURRENT_MOVE
    // Continue for a random number of turns (3-5)
    Random                              3, 3
    SetVar                              OP_LSH, VAR_CALC_WORK, 4
    SetMonDataFromVar                   OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    // Assign the field condition
    SetVarFromVar                       OP_TO_BIT, VAR_CALC_WORK, VAR_ATTACKER
    SetVar                              OP_LSH, VAR_CALC_WORK, 8
    SetVarFromVar                       OP_SET_FLAG, VAR_FIELD_CONDITIONS, VAR_CALC_WORK
    // "{0} caused an uproar!"
    Message                             308, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close