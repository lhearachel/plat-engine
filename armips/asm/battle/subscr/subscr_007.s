.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_7.s", 0

subscr_007:
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 131072, 3
    MessagePrepared                     
    Jump                                168
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 65536, 2
    Jump                                139
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 32768, 46
    If                                  EQUAL, VAR_CURRENT_MOVE, 173, 30
    If                                  EQUAL, VAR_CURRENT_MOVE, 171, 25
    If                                  EQUAL, VAR_CURRENT_MOVE, 374, 20
    If                                  EQUAL, VAR_CURRENT_MOVE, 387, 15
    If                                  EQUAL, VAR_CURRENT_MOVE, 375, 10
    If                                  EQUAL, VAR_CURRENT_MOVE, 252, 5
    If                                  NOT_EQUAL, VAR_CURRENT_MOVE, 363, 5
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 64, 34
    Message                             15, TAG_NICK, BATTLER_DEFENDER
    Jump                                110
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 2048, 7
    Message                             21, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER
    Jump                                98
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 1048576, 11
    SetVar                              OP_SET, VAR_MOVE_TEMP, 393
    Message                             1036, TAG_NICK_MOVE, BATTLER_DEFENDER, BATTLER_WORKING
    Jump                                82
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 64, 5
    Message                             796, TAG_NONE
    Jump                                72
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 262144, 7
    Message                             18, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER
    Jump                                60
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 8, 10
    IncGameStat                         BATTLER_ATTACKER, 0, 95
    Message                             27, TAG_NICK, BATTLER_DEFENDER
    Jump                                45
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 524288, 7
    Message                             625, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER
    Jump                                33
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 4096, 6
    Message                             342, TAG_NICK, BATTLER_DEFENDER
    Jump                                22
    GetCurrentMoveData                  MOVE_PARAM_RANGE
    If                                  EQUAL, VAR_CALC_WORK, 4, 11
    If                                  EQUAL, VAR_CALC_WORK, 8, 6
    Message                             12, TAG_NICK, BATTLER_ATTACKER
    Jump                                4
    Message                             24, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, 262144, 2
    JumpToSubscript                     57
    ClearContinuation                   BATTLER_ATTACKER
    JumpToSubscript                     61
    End                                 
