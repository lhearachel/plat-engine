.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_106.s", 0

subscr_106:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_OBLIVIOUS, 51
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 99
    TryAttract                          97
    JumpToSubscript                     76
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 11
    If                                  EQUAL, VAR_EFFECT_TYPE, 5, 14
    Message                             162, TAG_NICK, BATTLER_EFFECTSRC
    Jump                                18
    Message                             707, TAG_NICK_ABILITY_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECTSRC
    Jump                                10
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             1150, TAG_NICK_ITEM_NICK, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_EFFECTSRC_ONE_TURN_STATUS_FLAGS, 4
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 22
    If                                  EQUAL, VAR_EFFECT_TYPE, 5, 33
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             647, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 30
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    End                                 
    Message                             1147, TAG_NICK_ABILITY_ITEM, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    End                                 
    If                                  EQUAL, VAR_EFFECT_TYPE, 3, 4
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
