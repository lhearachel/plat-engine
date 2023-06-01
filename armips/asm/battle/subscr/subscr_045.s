.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_45.s", 0

subscr_045:
    TryConversion                       11
    JumpToSubscript                     76
    Message                             178, TAG_NICK_TYPE, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
