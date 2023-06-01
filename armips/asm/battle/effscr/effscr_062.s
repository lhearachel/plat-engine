.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_62.s", 0

effscr_062:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2147483698
    End                                 
