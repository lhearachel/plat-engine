.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_232.s", 0

subscr_232:
    SetVar                              OP_SET, VAR_MOVE_TEMP, 264
    PlayAnimationAtoD                   BATTLER_WORKING, 255, 255
    Wait                                
    Message                             497, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    End                                 
