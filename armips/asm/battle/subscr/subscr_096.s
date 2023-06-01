.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_96.s", 0

subscr_096:
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 24
    JumpToSubscript                     12
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 16385
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 15
    JumpToSubscript                     12
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 16
    JumpToSubscript                     12
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 2
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    End                                 
