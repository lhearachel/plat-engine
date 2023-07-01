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


.create "build/battle/scr/subscr/sub_seq_086.bin", 0

// SUBSCR_MEAN_LOOK
subscr_086:
    // Check for failure conditions
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_PROTECTED, subscr_086_Protected
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_COMPOSITE_MISSED, subscr_086_Missed
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_MEAN_LOOKED, subscr_086_Failure
    CheckSubstitute                     BATTLER_DEFENDER, subscr_086_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Set the condition
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_MEAN_LOOKED
    SetMonDataFromVar                   OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MEAN_LOOKED_BY, VAR_ATTACKER
    // "{0} can no longer escape!"
    Message                             408, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_086_Missed:
    // We can only miss during Fly/Dive/Dig/Shadow Force
    SetVar                              OP_CLEAR_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_DURING_FLY
    Branch                              subscr_086_Failure
subscr_086_Protected:
    SetVar                              OP_CLEAR_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_PROTECTED
subscr_086_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close