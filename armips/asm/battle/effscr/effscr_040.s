.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_40.bin", 0

effscr_040:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HP, VAR_DAMAGE
    SetVar                              OP_MUL, VAR_DAMAGE, 4294967295
    DamageDiv                           VAR_DAMAGE, 2
    End                                 

.close