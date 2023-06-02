.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_251.s", 0

subscr_251:
    MessageNoBattler                    1076, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
