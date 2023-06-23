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


.create "build/battle/scr/subscr/sub_seq_036.bin", 0

// SUBSCR_END_BIDE
subscr_036:
    // If the condition is 0x300, then we have another turn remaining
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_BIDING, subscr_036_StoringEnergy
    // "{0} unleashed energy!"
    Message                             335, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    // We are done with a charging move
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CHARGING
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_TURN_TWO_OF_TWO
    // No damage stored, use "But it failed!"
    If                                  EQUAL, VAR_DAMAGE, 0, subscr_036_Failure
    End                                 

subscr_036_Failure:
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

subscr_036_StoringEnergy:
    // "{0} is storing energy!"
    Message                             332, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close