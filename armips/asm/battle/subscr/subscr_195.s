.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_195.s", 0

subscr_195:
    Message                             1109, TAG_NICK_ABILITY_MOVE, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
