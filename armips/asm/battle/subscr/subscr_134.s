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


.create "build/battle/scr/subscr/sub_seq_134.bin", 0

// SUBSCR_TRICK
subscr_134:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_134_Failure
    CheckSubstitute                     BATTLER_DEFENDER, subscr_134_Failure
    // Don't try to Trick off of Arceus
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_134_Failure
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_134_Failure
    // Don't try to Trick a Griseous Orb
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, subscr_134_Failure
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, subscr_134_Failure
    // Don't try to Trick an activated Quick Claw
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, subscr_134_Failure
    // Don't try to Trick an activated Custap Berry
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TEMP_SPE_MAX, 0, subscr_134_Failure
    TryTrick                            subscr_134_Failure, subscr_134_AbilityBlock
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // "{0} switched items with its target!"
    Message                             510, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Swap the items
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 0, subscr_134_AfterAttackerMessage
    // "{0} obtained one {1}."
    Message                             513, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_134_AfterAttackerMessage:
    // "{0} obtained one {1}."
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 0, subscr_134_Exit
    Message                             513, TAG_NICK_ITEM, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_134_Exit:
    End                                 

subscr_134_AbilityBlock:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s {1} made {2} ineffective!"
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_134_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close