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


.create "build/battle/scr/subscr/sub_seq_077.bin", 0

// SUBSCR_PAIN_SPLIT
subscr_077:
    CheckSubstitute                     BATTLER_DEFENDER, subscr_073_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Compute the average of the current HP values of the attacker and defender
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_ADD, VAR_CALC_WORK, VAR_HP_TEMP
    SetVar                              OP_DIV, VAR_CALC_WORK, 2
    // Set the attacker's HP
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_SUB, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    CallSubscript                       SUBSCR_HP_CHANGE
    // Set the defender's HP
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_SUB, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    CallSubscript                       SUBSCR_HP_CHANGE
    // "The battlers shared their pain!"
    Message                             820, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_073_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close