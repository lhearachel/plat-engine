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


.create "build/battle/scr/subscr/sub_seq_143.bin", 0

// SUBSCR_SKILL_SWAP
subscr_143:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_143_Failure
    // Don't swap Wonder Guard
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, ABILITY_WONDER_GUARD, subscr_143_Failure
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_WONDER_GUARD, subscr_143_Failure
    // Don't swap Multitype
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_143_Failure
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_143_Failure
    // Don't swap with a target holding a Griseous Orb
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, subscr_143_Failure
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, subscr_143_Failure
    // Don't swap a nil ability to the defender
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, 0, subscr_143_DoSwap
    // Don't swap with a defender with no ability
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 0, subscr_143_Failure
subscr_143_DoSwap:
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Force Truant to be active
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_AND, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_TRUANT_ACTIVE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_TRUANT_ACTIVE, VAR_TEMP_WORK
    // Actually swap the abilities
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_ABILITY, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_ABILITY, VAR_CALC_WORK
subscr_143_CheckAttackerSlowStart:
    // Check for Slow Start
    If                                  NOT_EQUAL, VAR_TEMP_WORK, ABILITY_SLOW_START, subscr_143_CheckDefenderSlowStart
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_ADD, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_TURNS, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ACTIVE, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ENDED, 0
subscr_143_CheckDefenderSlowStart:
    If                                  NOT_EQUAL, VAR_CALC_WORK, ABILITY_SLOW_START, subscr_143_ShowMessage
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_ADD, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_SLOW_START_TURNS, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_SLOW_START_ACTIVE, 0
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_SLOW_START_ENDED, 0
subscr_143_ShowMessage:
    // "{0} swapped abilities with its target!"
    Message                             559, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_143_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close