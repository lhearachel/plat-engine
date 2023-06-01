.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_110.s", 0

subscr_110:
    Message                             203, TAG_NONE_DIR, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
