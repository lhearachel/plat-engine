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


.create "build/battle/scr/effscr/be_seq_107.bin", 0

// Apply Nightmare status
effscr_107:
    // Do not apply if the target is behind a Substitute
    CheckSubstitute                     BATTLER_DEFENDER, effscr_107_Failure
    // Do not apply if the target is already suffering from the effect
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_NIGHTMARES, effscr_107_Failure
    // Do not apply if the target is not asleep
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, effscr_107_Failure
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_NIGHTMARE
    End                                 

effscr_107_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close