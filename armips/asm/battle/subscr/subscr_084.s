.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_84.s", 0

subscr_084:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 14
    TrySpite                            12
    JumpToSubscript                     76
    Message                             398, TAG_NICK_MOVE_NUM, BATTLER_DEFENDER, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
