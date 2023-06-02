.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_53.s", 0

subscr_053:
    JumpToSubscript                     76
    MessagePrepared                     
    Wait                                
    WaitFrames                          30
    End                                 
