.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_168.bin", 0

effscr_168:
    SetVar                              OP_SET, VAR_CALC_WORK, 268435456
    SetVarFromVar                       OP_LSH, VAR_CALC_WORK, VAR_ATTACKER
    SetVarFromVar                       OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_HP, 0
    SetVar                              OP_SET, VAR_HP_TEMP, 32767
    UpdateHPGauge                       BATTLER_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 524316
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2684354667
    End                                 

.close