.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_295.s", 0

subscr_295:
    SetVar                              OP_SET, VAR_MOVE_TEMP, 433
    PlayAnimation                       BATTLER_WORKING
    Wait                                
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 0
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    Message                             1267, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 327680
    End                                 
