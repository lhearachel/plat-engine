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


.create "build/battle/scr/subscr/sub_seq_132.bin", 0

// SUBSCR_APPLY_TAUNT
subscr_132:
    // Fail if Taunt is already active
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TAUNTED_TURNS, 0, subscr_132_Failure
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_132_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Generate the duration (random, 3-5)
    Random                              2, 3
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_TAUNTED_TURNS, VAR_CALC_WORK
    // "{0} fell for the taunt!"
    Message                             500, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_132_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close