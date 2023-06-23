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


.create "build/battle/scr/subscr/sub_seq_135.bin", 0

// SUBSCR_ROLE_PLAY
subscr_135:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_135_Failure
    // Cannot copy Wonder Guard
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_WONDER_GUARD, subscr_135_Failure
    // Cannot copy nor overwrite Multitype
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_135_Failure
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_135_Failure
    // Don't try to copy a nil ability
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_NONE, subscr_135_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Force Truant to be active
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_AND, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_TRUANT_ACTIVE, VAR_TEMP_WORK
    // Copy the ability
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_ABILITY, VAR_TEMP_WORK
    // Set the Slow Start counter, if applicable
    If                                  NOT_EQUAL, VAR_TEMP_WORK, ABILITY_SLOW_START, subscr_135_Message
    SetVarFromVar                       OP_SET, VAR_TEMP_WORK, VAR_TURNS
    SetVar                              OP_ADD, VAR_TEMP_WORK, 1
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_TURNS, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ACTIVE, 0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_SLOW_START_ENDED, 0
subscr_135_Message:
    // "{0} copied {1}'s {2}!"
    Message                             523, TAG_NICK_NICK_ABILITY, BATTLER_ATTACKER, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_135_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close