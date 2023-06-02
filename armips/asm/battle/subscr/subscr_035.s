.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_35.s", 0

subscr_035:
    JumpToSubscript                     76
    SetContinuation                     BATTLER_ATTACKER
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 512
    SetVar                              OP_SET, VAR_BIDE_DAMAGE, 0
    End                                 
