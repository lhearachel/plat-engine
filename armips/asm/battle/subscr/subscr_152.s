.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_152.bin", 0

subscr_152:
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_ATK_STAGE, 12, 6
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_SPE_STAGE, 12, 35
    JumpToSubscript                     76
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2097152
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 16385
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 15
    JumpToSubscript                     12
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 17
    JumpToSubscript                     12
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 2
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    End                                 
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             768, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close