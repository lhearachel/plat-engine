.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_085.bin", 0

effscr_085:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 8192
    End                                 

.close