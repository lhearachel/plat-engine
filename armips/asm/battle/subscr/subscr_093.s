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


.create "build/battle/scr/subscr/sub_seq_093.bin", 0

// SUBSCR_APPLY_NIGHTMARE
subscr_093:
    CheckSubstitute                     BATTLER_DEFENDER, subscr_093_Failure
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_NIGHTMARES, subscr_093_Failure
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, subscr_093_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_NIGHTMARES
    // "{0} began having a nightmare!"
    Message                             411, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_093_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close