.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_250.s", 0

subscr_250:
    Message                             1085, TAG_NONE_DIR, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
