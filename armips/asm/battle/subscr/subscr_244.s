.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_244.s", 0

subscr_244:
    Message                             1138, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, 67108864
    End                                 
