.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_288.s", 0

subscr_288:
    SetVar                              OP_SET, VAR_MOVE_TEMP, 269
    Message                             1257, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
