.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_129.s", 0

subscr_129:
    AttackMessage                       
    Wait                                
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 0, 6
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_SPA_STAGE, 0, 64
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    CheckSubstitute                     BATTLER_DEFENDER, 43
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 16385
    SetVarFromVar                       OP_SET, VAR_EFFECTSRC, VAR_DEFENDER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 0, 6
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 46
    JumpToSubscript                     12
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2097152
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 49
    JumpToSubscript                     12
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 2
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    End                                 
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             607, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
