.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_87.s", 0

effscr_087:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_LEVEL, VAR_DAMAGE
    SetVar                              OP_MUL, VAR_DAMAGE, 4294967295
    End                                 
