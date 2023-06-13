.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_041.bin", 0

effscr_041:
    If                                  FLAG_EQ, VAR_RULESET, 1, 9
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    SetVar                              OP_SET, VAR_DAMAGE, 4294967256
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close