.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_175.bin", 0

subscr_175:
    CheckWhiteOut                       BATTLER_DEFENDER, 170
    TrySwitchInMon                      BATTLER_ATTACKER, 1, 166
    CheckAbilityEffectOnHit             2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    CheckUturnItemEffect                2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, 59
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 33554432, 53
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_DEFENDER, 49
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, 43
    Message                             391, TAG_NICK_NICK, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_HP, VAR_HP_TEMP
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    FaintAnimation                      
    Wait                                
    HPGaugeSlideOut                     BATTLER_FAINTING
    Message                             30, TAG_NICK, BATTLER_FAINTING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    IncGameStat                         BATTLER_FAINTING, 1, 41
    IncGameStat                         BATTLER_FAINTING, 0, 96
    SetVarFromVar                       OP_GET, VAR_FAINTED_BATTLER, VAR_PUSH_CLIENT
    SetVarFromVar                       OP_SET, VAR_FAINTED_BATTLER, VAR_DEFENDER
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, 10
    TryGrudge                           8
    Message                             568, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVarFromVar                       OP_SET, VAR_FAINTED_BATTLER, VAR_PUSH_CLIENT
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, 59
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER, VAR_ATTACKER
    Message                             1067, TAG_NICK_TRNAME, BATTLER_SWITCHING, BATTLER_SWITCHING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    JumpToSubscript                     153
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, 39
    TryNaturalCure                      BATTLER_ATTACKER, 5
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    PokemonDelete                       BATTLER_ATTACKER
    Wait                                
    HPGaugeSlideOut                     BATTLER_ATTACKER
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 16
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 128
    SetVar                              OP_SET, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, 0
    JumpTo                              10
    End                                 

.close