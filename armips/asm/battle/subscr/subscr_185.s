.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_185.s", 0

subscr_185:
    SetStatusEffect                     BATTLER_ME, 22
    Wait                                
    Message                             698, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 33023
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 32
    End                                 
