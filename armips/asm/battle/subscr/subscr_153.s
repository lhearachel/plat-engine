.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_153.bin", 0

subscr_153:
    JumpToSubscript                     279
    TryPursuit                          235
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
    CriticalCalc                        
    DamageCalc                          
    ApplyTypeMultipliers                
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 1
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    AttackMessage                       
    Wait                                
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2086985, 129
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    CheckSubstitute                     BATTLER_DEFENDER, 77
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_DAMAGE
    SetVar                              OP_MUL, VAR_TEMP_WORK, 4294967295
    JumpIfMonData                       LESSER, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_TEMP_WORK, 6
    SetVarFromVar                       OP_SET, VAR_ATTACKER_SHELL_BELL_DAMAGE, VAR_DAMAGE
    Branch                              9
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HP, VAR_ATTACKER_SHELL_BELL_DAMAGE
    SetVar                              OP_MUL, VAR_ATTACKER_SHELL_BELL_DAMAGE, 4294967295
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_DAMAGE
    SetVarFromVar                       OP_SET, VAR_DEFENDER_ONE_TURN_PHYSICAL_DAMAGE, VAR_DAMAGE
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    CheckLeaveWith1HP                   BATTLER_WORKING
    JumpToSubscript                     2
    JumpToSubscript                     16
    JumpToSubscript                     21
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, 80
    CheckAbilityEffectOnHit             2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    CheckItemEffectOnHit                2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 8192
    CheckUturnItemEffect                2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 8192
    Branch                              50
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_DAMAGE
    SetVar                              OP_MUL, VAR_TEMP_WORK, 4294967295
    JumpIfMonData                       LESSER, BATTLER_DEFENDER, BATTLE_MON_SUBSTITUTE_HP, VAR_TEMP_WORK, 6
    SetVarFromVar                       OP_SET, VAR_ATTACKER_SHELL_BELL_DAMAGE, VAR_DAMAGE
    Branch                              14
    SetMonData                          OP_CLEAR_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 16777216
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_SUBSTITUTE_HP, VAR_ATTACKER_SHELL_BELL_DAMAGE
    SetVar                              OP_MUL, VAR_ATTACKER_SHELL_BELL_DAMAGE, 4294967295
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    JumpToSubscript                     90
    JumpToSubscript                     16
    JumpToSubscript                     21
    Branch                              4
    WaitTime                            15
    JumpToSubscript                     7
    JumpToSubscript                     280
    SetVarFromVar                       OP_GET, VAR_MOVE_NUM_WORK, VAR_CURRENT_MOVE
    Branch                              4294967131
    JumpToSubscript                     83
    CheckAbilityEffectOnHit             2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    CheckItemEffectOnHit                2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 8192
    CheckUturnItemEffect                2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 8192
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_FAINTED_BATTLER
    SetVar                              OP_SET, VAR_FAINTED_BATTLER, 0
    SetVarFromVar                       OP_SET, VAR_CALC_WORK, VAR_SERVER_STATUS_FLAG2
    SetVar                              OP_RSH, VAR_CALC_WORK, 28
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 4026531840
    If                                  FLAG_NEQ, VAR_CALC_WORK, 1, 2
    JumpToSubscript                     276
    SetVar                              OP_ADD, VAR_FAINTED_BATTLER, 1
    SetVar                              OP_RSH, VAR_CALC_WORK, 1
    If                                  NOT_EQUAL, VAR_CALC_WORK, 0, 4294967276
    SetVarFromVar                       OP_SUB_TO_ZERO, VAR_FIELD_CONDITIONS, VAR_TEMP_WORK
    JumpToSubscript                     280
    SetVarFromVar                       OP_GET, VAR_MOVE_NUM_WORK, VAR_CURRENT_MOVE
    End                                 

.close