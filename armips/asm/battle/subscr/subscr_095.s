.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_095.bin", 0

subscr_095:
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECTSRC, BATTLE_MON_MOVE_EFFECTS, 256
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 21
    JumpTo                              12

.close