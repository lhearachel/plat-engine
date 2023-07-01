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


.create "build/battle/scr/subscr/sub_seq_167.bin", 0

// SUBSCR_WORRY_SEED
subscr_167:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_167_Failure
    CheckSubstitute                     BATTLER_DEFENDER, subscr_167_Failure
    // Cannot change out Truant or Multitype
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_TRUANT, subscr_167_Failure
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_167_Failure
    // Does not affect a mon holding a Griseous Orb
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, subscr_167_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Give the target Insomnia
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_INSOMNIA
    // "{0} acquired {1}!"
    Message                             1021, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_167_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close