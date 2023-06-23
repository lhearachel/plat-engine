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


.create "build/battle/scr/subscr/sub_seq_153.bin", 0

// SUBSCR_PURSUIT
subscr_153:
    CallSubscript                       SUBSCR_PUSH_ATTACKER_DEFENDER
subscr_153_Loop:
    // If no Pursuit damage, bail out
    TryPursuit                          subscr_153_Exit
    // Double damage on a switch
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
    CriticalCalc                        
    DamageCalc                          
    ApplyTypeMultipliers                
    // Make sure the animation and attack message show
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    AttackMessage                       
    Wait                                
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_COMPOSITE_MISSED, subscr_153_Failed
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    CheckSubstitute                     BATTLER_DEFENDER, subscr_153_Substitute

// Check for Shell Bell first before proceeding
subscr_153_ShellBellCalc:
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_DAMAGE
    SetVar                              OP_MUL, VAR_TEMP_WORK, -1
    JumpIfMonData                       LESSER, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_TEMP_WORK, subscr_153_ShellBellSetHP
    SetVarFromVar                       OP_SET, VAR_ATTACKER_SHELL_BELL_DAMAGE, VAR_DAMAGE
    Branch                              subscr_153_NormalPursuit
subscr_153_ShellBellSetHP:
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_ATTACKER_SHELL_BELL_DAMAGE
    SetVar                              OP_MUL, VAR_ATTACKER_SHELL_BELL_DAMAGE, -1

// Proceed
subscr_153_NormalPursuit:
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_DAMAGE
    SetVarFromVar                       OP_SET, VAR_DEFENDER_ONE_TURN_PHYSICAL_DAMAGE, VAR_DAMAGE
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    CheckLeaveWith1HP                   BATTLER_WORKING
    CallSubscript                       SUBSCR_HP_CHANGE
    CallSubscript                       SUBSCR_CRITICAL_HIT
    CallSubscript                       SUBSCR_MOVE_SUCCESS_MESSAGE
    // Check for a faint
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, subscr_153_Killed
    // Check for any ability effects; jump to item effects if there are none
    CheckAbilityEffectOnHit             subscr_153_CheckItemEffect
    CallSubscriptFromVar                VAR_TEMP_WORK

subscr_153_CheckItemEffect:
    // Check for any item effects; jump to U-turn item effects if there are none
    CheckItemEffectOnHit                subscr_153_CheckUturnItemEffect
    CallSubscriptFromVar                VAR_TEMP_WORK

subscr_153_CheckUturnItemEffect:
    // Check for any item effects on U-turn
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_SUCCESSFUL
    CheckUturnItemEffect                subscr_153_Jump
    CallSubscriptFromVar                VAR_TEMP_WORK

subscr_153_Jump:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_SUCCESSFUL
    Branch                              subscr_153_Resume

subscr_153_Substitute:
    // Apply damage to substitute; not possible to kill
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_DAMAGE
    SetVar                              OP_MUL, VAR_TEMP_WORK, -1
    JumpIfMonData                       LESSER, BATTLER_DEFENDER, BATTLE_MON_SUBSTITUTE_HP, VAR_TEMP_WORK, subscr_153_ShellBellCalcOnSubstitute
    SetVarFromVar                       OP_SET, VAR_ATTACKER_SHELL_BELL_DAMAGE, VAR_DAMAGE
    Branch                              subscr_153_ResumeSubstitute

subscr_153_ShellBellCalcOnSubstitute:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_SUBSTITUTE_HP, VAR_ATTACKER_SHELL_BELL_DAMAGE
    SetVar                              OP_MUL, VAR_ATTACKER_SHELL_BELL_DAMAGE, -1
subscr_153_ResumeSubstitute:
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    CallSubscript                       SUBSCR_HIT_SUBSTITUTE
    CallSubscript                       SUBSCR_CRITICAL_HIT
    CallSubscript                       SUBSCR_MOVE_SUCCESS_MESSAGE
    Branch                              subscr_153_Resume

subscr_153_Failed:
    WaitTime                            15
    CallSubscript                       SUBSCR_MOVE_FAIL

subscr_153_Resume:
    // Pop the attacker and defender off the stack, then loop upwards
    CallSubscript                       SUBSCR_POP_ATTACKER_DEFENDER
    SetVarFromVar                       OP_GET, VAR_MOVE_NUM_WORK, VAR_CURRENT_MOVE
    Branch                              subscr_153_Loop

subscr_153_Killed:
    CallSubscript                       SUBSCR_TRIGGER_ON_FAINTING

// This stuff is all unreachable, not bothering to document it
subscr_153_CheckAbilityEffect_Unreachable:
    CheckAbilityEffectOnHit             subscr_153_CheckItemEffect_Unreachable
    CallSubscriptFromVar                VAR_TEMP_WORK
subscr_153_CheckItemEffect_Unreachable:
    CheckItemEffectOnHit                subscr_153_CheckUturnItemEffect_Unreachable
    CallSubscriptFromVar                VAR_TEMP_WORK
subscr_153_CheckUturnItemEffect_Unreachable:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_SUCCESSFUL
    CheckUturnItemEffect                subscr_153_Cleanup_Unreachable
    CallSubscriptFromVar                VAR_TEMP_WORK
subscr_153_Cleanup_Unreachable:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_SUCCESSFUL
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_FAINTED_BATTLER
    SetVar                              OP_SET, VAR_FAINTED_BATTLER, 0
    SetVarFromVar                       OP_SET, VAR_CALC_WORK, VAR_SERVER_STATUS_FLAG2
    SetVar                              OP_RSH, VAR_CALC_WORK, 28
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 4026531840
subscr_153_LoopUnreachable:
    If                                  FLAG_NEQ, VAR_CALC_WORK, 1, subscr_153_NextUnreachable
    CallSubscript                       SUBSCR_GET_EXP
subscr_153_NextUnreachable:
    SetVar                              OP_ADD, VAR_FAINTED_BATTLER, 1
    SetVar                              OP_RSH, VAR_CALC_WORK, 1
    If                                  NOT_EQUAL, VAR_CALC_WORK, 0, subscr_153_LoopUnreachable
    SetVarFromVar                       OP_SUB_TO_ZERO, VAR_FIELD_CONDITIONS, VAR_TEMP_WORK
    CallSubscript                       SUBSCR_POP_ATTACKER_DEFENDER
    SetVarFromVar                       OP_GET, VAR_MOVE_NUM_WORK, VAR_CURRENT_MOVE

subscr_153_Exit:
    End                                 

.close