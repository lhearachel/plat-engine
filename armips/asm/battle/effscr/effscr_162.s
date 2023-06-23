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


.create "build/battle/scr/effscr/be_seq_162.bin", 0

// Swallow
effscr_162:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0, effscr_162_NoEffect
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, VAR_HP_TEMP
    SetVar                              OP_SUB, VAR_HP_TEMP, 3
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    SetVar                              OP_SET, VAR_CALC_WORK, 1
    SetVarFromVar                       OP_LSH, VAR_CALC_WORK, VAR_HP_TEMP
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDivByVar                      VAR_HP_TEMP, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 0
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, BATTLER_ATTACKER, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SUB_TO_ZERO, BATTLER_ATTACKER, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, 0
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_SWALLOW
    End                                 

effscr_162_NoEffect:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             815, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close