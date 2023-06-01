.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_163.s", 0

subscr_163:
    CheckSubstitute                     BATTLER_DEFENDER, 32
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 2097152, 26
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 21
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 121, 15
    JumpToSubscript                     76
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 2097152
    Message                             1012, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
