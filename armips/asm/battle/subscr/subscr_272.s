.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_272.s", 0

subscr_272:
    SetStatusEffect                     BATTLER_ME, 20
    Wait                                
    Message                             810, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 128
    End                                 
