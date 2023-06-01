.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_214.s", 0

effscr_214:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1610612852
    End                                 
