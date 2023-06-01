.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_273.s", 0

subscr_273:
    SetStatusEffect                     BATTLER_ME, 21
    Wait                                
    Message                             804, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 8
    End                                 
