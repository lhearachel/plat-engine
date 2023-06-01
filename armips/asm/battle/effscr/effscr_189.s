.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_189.s", 0

effscr_189:
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HP, VAR_DAMAGE
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_HP, VAR_CALC_WORK
    JumpIf                              LESSER, VAR_DAMAGE, VAR_CALC_WORK, 13
    SetVarFromVar                       OP_SUB, VAR_DAMAGE, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_DAMAGE, 4294967295
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2048
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
