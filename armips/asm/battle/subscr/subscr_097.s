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


.create "build/battle/scr/subscr/sub_seq_097.bin", 0

// SUBSCR_CURSE_GHOST
subscr_097:
    // Check for failure conditions (Fly, Substitute, already cursed)
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_DURING_FLY, subscr_097_Failure
    CheckSubstitute                     BATTLER_DEFENDER, subscr_097_Failure
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_CURSED, subscr_097_Failure
    // Play the animation
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Apply the Cursed status to the target
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_CURSED
    // Cut the attacker's HP by half of its maximum HP
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    DamageDiv                           VAR_HP_TEMP, 2
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} cut its own HP and laid a curse on {1}!"
    Message                             417, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_097_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close