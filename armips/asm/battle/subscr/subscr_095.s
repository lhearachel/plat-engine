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


.create "build/battle/scr/subscr/sub_seq_095.bin", 0

// SUBSCR_MINIMIZE
subscr_095:
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECT_TARGET, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MINIMIZED
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_EVA_UP_1
    JumpTo                              SUBSCR_BOOST_STATS

.close