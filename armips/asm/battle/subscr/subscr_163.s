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


.create "build/battle/scr/subscr/sub_seq_163.bin", 0

// SUBSCR_GASTRO_ACID
subscr_163:
    CheckSubstitute                     BATTLER_DEFENDER, subscr_163_Failure
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_ABILITY_SUPPRESSED, subscr_163_Failure
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_163_Failure
    // Cannot suppress Multitype
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_163_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_ABILITY_SUPPRESSED
    // "{0}'s ability was suppressed!"
    Message                             1012, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_163_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close