.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_220.s", 0

subscr_220:
    If                                  EQUAL, VAR_FLING_SUBSCRIPT, 0, 15
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, 9
    CheckSubstitute                     BATTLER_DEFENDER, 6
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_FLING_TEMP
    JumpToSubscriptFromVar              VAR_FLING_SUBSCRIPT
    End                                 
