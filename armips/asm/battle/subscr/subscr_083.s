.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_83.s", 0

subscr_083:
    IfMonData                           FLAG_NEQ, BATTLER_FAINTING, BATTLE_MON_CONDITION_2, 33554432, 61
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_FAINTING, 57
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, 51
    Message                             391, TAG_NICK_NICK, BATTLER_FAINTING, BATTLER_ATTACKER
    SetVarFromVar                       OP_GET, VAR_FAINTED_BATTLER, VAR_PUSH_CLIENT
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_HP, VAR_HP_TEMP
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    FaintAnimation                      
    Wait                                
    HPGaugeSlideOut                     BATTLER_FAINTING
    Message                             30, TAG_NICK, BATTLER_FAINTING
    Wait                                
    WaitFrames                          30
    IncGameStat                         BATTLER_FAINTING, 1, 41
    IncGameStat                         BATTLER_FAINTING, 0, 96
    SetVarFromVar                       OP_GET, VAR_PUSH_CLIENT, VAR_FAINTED_BATTLER
    TryGrudge                           8
    Message                             568, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 1
    JumpToSubscript                     6
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 1
    End                                 
