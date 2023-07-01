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


.create "build/battle/scr/subscr/sub_seq_079.bin", 0

// SUBSCR_LOCKON
subscr_079:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_079_Failure
    CheckSubstitute                     BATTLER_DEFENDER, subscr_079_Failure
    SetMonData                          OP_CLEAR_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_LOCKED_ON
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 0x10
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_LOCKED_ON_BY, VAR_ATTACKER
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // "{0} took aim at {1}!"
    Message                             378, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_079_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close