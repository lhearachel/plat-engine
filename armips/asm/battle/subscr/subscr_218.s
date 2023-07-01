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


.create "build/battle/scr/subscr/sub_seq_218.bin", 0

// SUBSCR_EMBARGO
subscr_218:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_218_Failure
    CheckSubstitute                     BATTLER_DEFENDER, subscr_218_Failure
    // Can't Embargo a pokemon with Multitype
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_218_Failure
    // Can't Embargo a pokemon that is already Embargo'd
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_EMBARGO_TURNS, 0, subscr_218_Failure
    // Can't Embargo a pokemon with Griseous Orb
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, subscr_218_Failure
    // Can't embargo on turns when items activate
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, subscr_218_Failure
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TEMP_SPE_MAX, 0, subscr_218_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_EMBARGO
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_EMBARGO_TURNS, 5
    // "{0} can't use items anymore!"
    Message                             1135, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_218_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close