.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_237.s", 0

subscr_237:
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 64
    Message                             812, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
