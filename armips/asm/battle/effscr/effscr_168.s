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


.create "build/battle/scr/effscr/be_seq_168.bin", 0

// Memento
effscr_168:
    SetVar                              OP_SET, VAR_CALC_WORK, SERVER_STATUS_FLAG_SELF_DESTRUCT
    SetVarFromVar                       OP_LSH, VAR_CALC_WORK, VAR_ATTACKER
    SetVarFromVar                       OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_HP, 0
    // 0x7FFF is the universal value for how much damage is applied to faint any Pokemon
    SetVar                              OP_SET, VAR_HP_TEMP, 0x7FFF
    UpdateHPGauge                       BATTLER_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_HIT_THROUGH_VANISH
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_MEMENTO
    End                                 

.close