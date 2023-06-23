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


.create "build/battle/scr/subscr/sub_seq_190.bin", 0

// SUBSCR_SHED_SKIN
subscr_190:
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    // Also clear nightmares, since we are no longer sleeping
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_NIGHTMARES
    // "{0}'s {1} cured its {2} status!"
    Message                             717, TAG_NICK_ABILITY_COND, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NONE
    WaitTime                            30
    End                                 

.close