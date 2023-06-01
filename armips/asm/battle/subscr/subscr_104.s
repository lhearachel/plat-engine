.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_104.s", 0

subscr_104:
    JumpToSubscript                     57
    SetStatusEffectFromVar              BATTLER_ME, VAR_TEMP_WORK
    Wait                                
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
    GetBattlerBySpeedOrder              VAR_BATTLER_WORK
    WeatherDamageCalc                   BATTLER_WORKING
    If                                  EQUAL, VAR_TEMP_WORK, 1, 80
    If                                  EQUAL, VAR_HP_TEMP, 0, 67
    If                                  GREATER, VAR_HP_TEMP, 0, 48
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, 57
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 48, 7
    Message                             285, TAG_MOVE_NICK, BATTLER_WORKING, BATTLER_WORKING
    Jump                                17
    If                                  EQUAL, VAR_TEMP_WORK, 2, 7
    Message                             1090, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Jump                                5
    Message                             1096, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    JumpToSubscript                     2
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, 251658240, 18
    JumpToSubscript                     6
    Jump                                14
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    Message                             635, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, 4294967208
    End                                 
    JumpToSubscript                     190
    Jump                                4294967284
