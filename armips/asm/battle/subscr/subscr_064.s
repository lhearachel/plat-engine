.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_64.s", 0

subscr_064:
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4194304
    SetVarFromVar                       OP_SET, VAR_MOVE_CONTINUATION, VAR_CURRENT_MOVE
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ME_FIRST_ACTIVE, VAR_TURNS
    End                                 
