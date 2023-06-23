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


.create "build/battle/scr/subscr/sub_seq_088.bin", 0

// SUBSCR_HEAL_BELL
subscr_088:
    HealBell                            
    // MOVE_AROMATHERAPY
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_AROMATHERAPY, subscr_088_AromatherapyMessage
    // "A bell chimed!"
    Message                             821, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_088_AfterMessage

subscr_088_AromatherapyMessage:
    // "A soothing aroma wafted through the area!"
    Message                             592, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
subscr_088_AfterMessage:
    Wait                                
    WaitTime                            30
    // Check for Soundproof on active Pokemon listening to Heal Bell
    // TODO: remove the check for Soundproof on attacker (gen8)
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_AROMATHERAPY, subscr_088_Cleanup
    If                                  FLAG_NEQ, VAR_CALC_WORK, 1, subscr_088_CheckPartner
    // "{0}'s {1} blocked {2}!"
    Message                             689, TAG_NICK_ABILITY_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_088_CheckPartner:
    If                                  FLAG_NEQ, VAR_CALC_WORK, 2, subscr_088_Cleanup
    // "{0}'s {1} blocked {2}!"
    Message                             689, TAG_NICK_ABILITY_MOVE, BATTLER_ATTACKER_PARTNER, BATTLER_ATTACKER_PARTNER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_088_Cleanup:
    If                                  FLAG_EQ, VAR_CALC_WORK, 4, subscr_088_NoSlot1
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
subscr_088_NoSlot1:
    If                                  FLAG_EQ, VAR_CALC_WORK, 8, subscr_088_NoSlot2
    SetStatusIcon                       BATTLER_ATTACKER_PARTNER, STATUS_NONE
subscr_088_NoSlot2:
    End                                 

.close