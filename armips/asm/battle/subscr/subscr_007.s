.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_007.bin", 0

subscr_007:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 131072, 3
    MessagePrepared                     
    Branch                              168
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 65536, 2
    Branch                              139
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 32768, 46
    If                                  EQUAL, VAR_CURRENT_MOVE, 173, 30
    If                                  EQUAL, VAR_CURRENT_MOVE, 171, 25
    If                                  EQUAL, VAR_CURRENT_MOVE, 374, 20
    If                                  EQUAL, VAR_CURRENT_MOVE, 387, 15
    If                                  EQUAL, VAR_CURRENT_MOVE, 375, 10
    If                                  EQUAL, VAR_CURRENT_MOVE, 252, 5
    If                                  NOT_EQUAL, VAR_CURRENT_MOVE, 363, 5
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 64, 34
    Message                             15, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              110
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 2048, 7
    Message                             21, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              98
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 1048576, 11
    SetVar                              OP_SET, VAR_MOVE_TEMP, 393
    Message                             1036, TAG_NICK_MOVE, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              82
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 64, 5
    Message                             796, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              72
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 262144, 7
    Message                             18, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              60
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 8, 10
    IncGameStat                         BATTLER_ATTACKER, 0, 95
    Message                             27, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              45
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 524288, 7
    Message                             625, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              33
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 4096, 6
    Message                             342, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              22
    GetCurrentMoveData                  MOVE_PARAM_RANGE
    If                                  EQUAL, VAR_CALC_WORK, 4, 11
    If                                  EQUAL, VAR_CALC_WORK, 8, 6
    Message                             12, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              4
    Message                             24, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, 262144, 2
    JumpToSubscript                     57
    ClearContinuation                   BATTLER_ATTACKER
    JumpToSubscript                     61
    End                                 

.close