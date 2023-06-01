.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_274.s", 0

subscr_274:
    SetStatusEffect                     BATTLER_ME, 18
    Wait                                
    Message                             813, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 32768
    End                                 
