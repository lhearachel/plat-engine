.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_128.s", 0

subscr_128:
    CheckSubstitute                     BATTLER_DEFENDER, 29
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_SPA_STAGE, 12, 8
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 7, 14
    Jump                                15
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 18
    JumpToSubscript                     12
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 7, 2
    JumpToSubscript                     37
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
