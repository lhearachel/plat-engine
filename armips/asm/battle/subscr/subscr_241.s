.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_241.s", 0

subscr_241:
    Message                             314, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
