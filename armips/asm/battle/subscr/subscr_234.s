.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_234.s", 0

subscr_234:
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 1
    Message                             803, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
