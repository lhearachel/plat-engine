.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_161.s", 0

subscr_161:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 23
    JumpToSubscript                     12
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 26
    JumpToSubscript                     12
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 2
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    End                                 
