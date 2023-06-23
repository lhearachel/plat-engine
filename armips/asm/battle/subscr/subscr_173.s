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


.create "build/battle/scr/subscr/sub_seq_173.bin", 0

// SUBSCR_APPLY_HEAL_BLOCK
subscr_173:
    CheckSubstitute                     BATTLER_DEFENDER, subscr_173_Failure
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HEAL_BLOCK_TURNS, 0, subscr_173_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_HEAL_BLOCK
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_HEAL_BLOCK_TURNS, 5
    // "{0} was prevented from healing!"
    Message                             1051, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_173_Failure:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    // "It failed to affect {0}!"
    Message                             1235, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close