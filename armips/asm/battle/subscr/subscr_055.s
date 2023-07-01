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


.create "build/battle/scr/subscr/sub_seq_055.bin", 0

// SUBSCR_REST
subscr_055:
    AttackMessage                       
    Wait                                
    // Check if the Pokemon can fall asleep
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_INSOMNIA, subscr_055_AbilityBlock
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_VITAL_SPIRIT, subscr_055_AbilityBlock
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, subscr_055_AlreadyAsleep
    // Soundproof skips the Uproar check
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_SOUNDPROOF, subscr_055_IgnoreUproar
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_UPROAR, subscr_055_UproarActive
subscr_055_IgnoreUproar:
    // Check if there is healing to do at all
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    JumpIfMonData                       EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_HP_TEMP, subscr_055_AlreadyFullHP
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_NOT_ASLEEP, subscr_055_StatusHealed
    // "{0} went to sleep!"
    Message                             205, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_055_AfterMessage
subscr_055_StatusHealed:
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_NOT_ASLEEP
    // "{0} slept and became healthy!"
    Message                             208, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
subscr_055_AfterMessage:
    Wait                                
    WaitTime                            30
    // Forcibly set 2 sleep turns
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 3
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_ASLEEP
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_NOT_ASLEEP, subscr_055_StatusHealed
    // "{0} regained health!"
    Message                             184, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_055_Exit

subscr_055_AbilityBlock:
    WaitTime                            30
    // "{0} stayed awake because of its {1}!"
    Message                             329, TAG_NICK_ABILITY, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Branch                              subscr_055_Cleanup

subscr_055_AlreadyAsleep:
    WaitTime                            30
    // "{0} is already asleep!"
    Message                             57, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_055_Cleanup

subscr_055_UproarActive:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_UPROARING, subscr_055_UproarOurs
    WaitTime                            30
    // "But the uproar kept {0} awake!"
    Message                             326, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_055_Cleanup
subscr_055_UproarOurs:
    WaitTime                            30
    // "But {0} can't sleep in an uproar!"
    Message                             323, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_055_Cleanup

subscr_055_AlreadyFullHP:
    WaitTime                            30
    // "{0}'s HP is full!"
    Message                             187, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN

subscr_055_Cleanup:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
subscr_055_Exit:
    Wait                                
    WaitTime                            30
    End                                 

.close