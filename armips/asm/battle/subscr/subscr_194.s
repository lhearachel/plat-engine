.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_194.s", 0

subscr_194:
    Message                             1106, TAG_ABILITY_NICK, BATTLER_CLIENT_WORK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
