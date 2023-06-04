.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_148.bin", 0

subscr_148:
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_ATK_STAGE, 0, 6
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_DEF_STAGE, 0, 39
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 29
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 22
    JumpToSubscript                     12
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2097152
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 23
    JumpToSubscript                     12
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 2
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             771, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close