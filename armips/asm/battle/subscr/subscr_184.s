.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_184.s", 0

subscr_184:
    SetStatusEffect                     BATTLER_ME, 21
    Wait                                
    Message                             695, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 33023
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 8
    End                                 
