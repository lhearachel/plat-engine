.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_161.bin", 0

effscr_161:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0, 59
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_STOCKPILE_COUNT, VAR_DAMAGE_POWER
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 100
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_STOCKPILE_DEF_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, 1, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_STOCKPILE_SPD_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, 1, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, 0
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 262144
    PrepareMessage                      994, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    CriticalCalc                        
    DamageCalcMaximum                   
    End                                 
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             814, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close