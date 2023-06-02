.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_135.s", 0

subscr_135:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 87
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 25, 81
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 121, 75
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, 121, 69
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 0, 63
    JumpToSubscript                     76
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_AND, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_TRUANT_ACTIVE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    If                                  NOT_EQUAL, VAR_TEMP_WORK, 112, 23
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_ADD, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_SLOW_START_TURNS, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ACTIVE, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ENDED, 0
    Message                             523, TAG_NICK_NICK_ABILITY, BATTLER_ATTACKER, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
