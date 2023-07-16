.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/subscr/sub_seq_007.bin", 0

// SUBSCR_MOVE_FAIL
subscr_007:
    AttackMessage                       
    Wait                                
    WaitTime                            30
subscr_007_CheckFocusPunch:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_LOST_FOCUS, subscr_007_CheckFly
    MessagePrepared                     
    Branch                              subscr_007_MessageAfterMiss

subscr_007_CheckFly:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_DURING_FLY, subscr_007_CheckProtect
    Branch                              subscr_007_GeneralMiss

subscr_007_CheckProtect:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_PROTECTED, subscr_007_CheckLevitate
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_SNORE, subscr_007_CheckFailure
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_NIGHTMARE, subscr_007_CheckFailure
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_FLING, subscr_007_CheckFailure
    If                                  EQUAL, VAR_CURRENT_MOVE, LAGGING_TAIL_RESORT, subscr_007_CheckFailure
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_PSYCHO_SHIFT, subscr_007_CheckFailure
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_FAKE_OUT, subscr_007_CheckFailure
    If                                  NOT_EQUAL, VAR_CURRENT_MOVE, MOVE_NATURAL_GIFT, subscr_007_EnemeyProtectedItself
subscr_007_CheckFailure:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED, subscr_007_ButItFailed
subscr_007_EnemeyProtectedItself:
    Message                             15, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_CheckLevitate:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BY_ABILITY, subscr_007_CheckMagnetRise
    Message                             21, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_CheckMagnetRise:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BY_MAGNET_RISE, subscr_007_ButItFailed
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_MAGNET_RISE
    Message                             1036, TAG_NICK_MOVE, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_ButItFailed:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED, subscr_007_CheckWonderGuard
    Message                             796, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_CheckWonderGuard:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_PROTECTED_BY_WONDER_GUARD, subscr_007_CheckIneffective
    Message                             18, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_CheckIneffective:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_DOES_NOT_AFFECT, subscr_007_CheckSturdy
    IncGameStat                         BATTLER_ATTACKER, 0, 95
    Message                             27, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_CheckSturdy:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ENDURED_BY_STURDY, subscr_007_CheckOHKOMissed
    Message                             625, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_CheckOHKOMissed:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ONE_HIT_KO_FAILED, subscr_007_GeneralMiss
    Message                             342, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_GeneralMiss:
    GetCurrentMoveData                  MOVE_PARAM_RANGE
    // Check double and triple range
    If                                  EQUAL, VAR_CALC_WORK, 4, subscr_007_MissedATarget
    If                                  EQUAL, VAR_CALC_WORK, 8, subscr_007_MissedATarget
    Message                             12, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_007_MessageAfterMiss

subscr_007_MissedATarget:
    Message                             24, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
subscr_007_MessageAfterMiss:
    Wait                                
    WaitTime                            30
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MESSAGE_AFTER_MISS, subscr_007_Continue
    CallSubscript                       SUBSCR_SHOW_PREPARED_MESSAGE
    
subscr_007_Continue:
    ClearContinuation                   BATTLER_ATTACKER
    CallSubscript                       SUBSCR_CRASH_ON_MISS
    End                                 

.close