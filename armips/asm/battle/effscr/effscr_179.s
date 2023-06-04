.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_179.bin", 0

effscr_179:
    TryWish                             1
    End                                 
    SetVar                              OP_SET, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close