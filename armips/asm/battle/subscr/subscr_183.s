.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_183.s", 0

subscr_183:
    SetStatusEffect                     BATTLER_ME, 19
    Wait                                
    Message                             619, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 33023
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 2
    End                                 
