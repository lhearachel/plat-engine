.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_58.s", 0

subscr_058:
    CheckSubstitute                     BATTLER_EFFECTSRC, 41
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 57344, 35
    MessagePrepared                     
    Wait                                
    WaitFrames                          30
    Random                              3, 3
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_EXTEND_TRAPPING, 4
    SetVar                              OP_SET, VAR_CALC_WORK, 6
    SetVar                              OP_LSH, VAR_CALC_WORK, 13
    SetMonDataFromVar                   OP_SET_FLAG, 2, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_BOUND_TARGET, VAR_ATTACKER
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_BINDING_MOVE, VAR_CURRENT_MOVE
    End                                 
