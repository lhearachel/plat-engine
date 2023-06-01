.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_50.s", 0

subscr_050:
    MessageWithBattler                  BATTLER_WORKING, 288, TAG_MOVE, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
