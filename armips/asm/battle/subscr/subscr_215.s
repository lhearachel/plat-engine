.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_215.s", 0

subscr_215:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    Message                             1132, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    End                                 
