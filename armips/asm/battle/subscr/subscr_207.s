.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_207.s", 0

subscr_207:
    JumpToSubscript                     198
    Message                             594, TAG_ITEM_NICK_TASTE, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 16385
    SetVarFromVar                       OP_SET, VAR_EFFECTSRC, VAR_BATTLER_WORK
    SetVar                              OP_SET, VAR_EFFECT_TYPE, 5
    JumpToSubscript                     37
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16385
    End                                 
