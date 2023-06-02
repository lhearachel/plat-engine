.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_86.s", 0

subscr_086:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 32768, 40
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2086985, 29
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 67108864, 33
    CheckSubstitute                     BATTLER_DEFENDER, 30
    JumpToSubscript                     76
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 67108864
    SetMonDataFromVar                   OP_SET_FLAG, 2, BATTLE_MON_MEAN_LOOK_TARGET, VAR_ATTACKER
    Message                             408, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_CLEAR_FLAG, VAR_MOVE_STATUS_FLAG, 65536
    Jump                                4
    SetVar                              OP_CLEAR_FLAG, VAR_MOVE_STATUS_FLAG, 32768
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
