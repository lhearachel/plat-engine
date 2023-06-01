.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_162.s", 0

effscr_162:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0, 73
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_STOCKPILE_COUNT, VAR_HP_TEMP
    SetVar                              OP_SUB, VAR_HP_TEMP, 3
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    SetVar                              OP_SET, VAR_CALC_WORK, 1
    SetVarFromVar                       OP_LSH, VAR_CALC_WORK, VAR_HP_TEMP
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDivByVar                      VAR_HP_TEMP, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_STOCKPILE_DEF_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, 1, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_STOCKPILE_SPD_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, 1, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, 0
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871016
    End                                 
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             815, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
