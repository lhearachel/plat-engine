.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_8.s", 0

subscr_008:
    Message                             42, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
