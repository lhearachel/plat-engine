.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_127.s", 0

subscr_127:
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 2147483648, 20
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 15
    JumpToSubscript                     76
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 2147483648
    Message                             494, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
