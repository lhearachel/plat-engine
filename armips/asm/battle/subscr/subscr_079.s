.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_79.s", 0

subscr_079:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 29
    CheckSubstitute                     BATTLER_DEFENDER, 26
    SetMonData                          OP_CLEAR_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 24
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 16
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_LOCK_ON_TARGET, VAR_ATTACKER
    JumpToSubscript                     76
    Message                             378, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
