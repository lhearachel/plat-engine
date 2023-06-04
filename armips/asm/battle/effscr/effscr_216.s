.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_216.bin", 0

effscr_216:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871031
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 32768
    End                                 

.close