.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_17.s", 0

subscr_017:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 65536, 7
    Message                             46, TAG_NUM, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
