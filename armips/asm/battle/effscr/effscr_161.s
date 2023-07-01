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


.create "build/battle/scr/effscr/be_seq_161.bin", 0

// Spit Up
effscr_161:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0, effscr_161_NoEffect
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, VAR_DAMAGE_POWER
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 100
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, BATTLER_ATTACKER, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, BATTLER_ATTACKER, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, 0
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MESSAGE_AFTER_MISS
    PrepareMessage                      994, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    CriticalCalc                        
    DamageCalcMaximum                   
    End

effscr_161_NoEffect:                                 
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             814, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close