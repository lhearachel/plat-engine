.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_48.bin", 0

subscr_048:
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_LEVEL, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_CALC_WORK, 5
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_ENEMY, 4
    SetVarFromVar                       OP_ADD, VAR_MONEY, VAR_CALC_WORK
    Message                             818, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close