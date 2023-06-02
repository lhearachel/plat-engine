.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_167.s", 0

subscr_167:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 37
    CheckSubstitute                     BATTLER_DEFENDER, 34
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 54, 28
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 121, 22
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, 16
    JumpToSubscript                     76
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 15
    Message                             1021, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
