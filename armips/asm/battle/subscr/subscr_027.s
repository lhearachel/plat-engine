.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_27.s", 0

subscr_027:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_MAGMA_ARMOR, 124
    CheckCloudNine                      5
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 48, 84
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 2, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SHIELD_DUST, 74
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    CheckSubstitute                     BATTLER_EFFECTSRC, 64
    IfMonData                           FLAG_EQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 32, 69
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_1, 15, 72
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_TYPE_2, 15, 66
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 40
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 35
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 74
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetStatusEffect                     BATTLER_EFFECTSRC, 4
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 32
    ClearContinuation                   BATTLER_EFFECTSRC
    Message                             101, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    SetStatusIcon                       BATTLER_EFFECTSRC, STATUS_FROZEN
    WaitFrames                          30
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 57
    WaitFrames                          30
    JumpToSubscript                     75
    Jump                                51
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 46
    WaitFrames                          30
    Jump                                35
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 37
    WaitFrames                          30
    Message                             27, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                22
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 24
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Jump                                11
    If                                  EQUAL, VAR_EFFECT_TYPE, 2, 13
    WaitFrames                          30
    Message                             200, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
