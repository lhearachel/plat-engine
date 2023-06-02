.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_235.s", 0

subscr_235:
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 4
    Message                             806, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
