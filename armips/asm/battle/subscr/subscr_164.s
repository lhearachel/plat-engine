.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_164.bin", 0

subscr_164:
    SetVar                              OP_SET, VAR_CALC_WORK, 20480
    SetVarFromVar                       OP_SET_FLAG, VAR_ATTACKER_SIDE_CONDITIONS, VAR_CALC_WORK
    Message                             1241, TAG_NONE_DIR, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close