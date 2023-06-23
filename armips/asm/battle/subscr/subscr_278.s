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


.create "build/battle/scr/subscr/sub_seq_278.bin", 0

// SUBSCR_CHECK_QUICK_CLAW
subscr_278:
    // Check if a Custap Berry is active
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TEMP_SPE_MAX, 1, subscr_278_CustapBerry
    // Check that Quick Claw activated
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, subscr_278_Exit
    If                                  EQUAL, VAR_CLIENT_WORKING_COUNT, 1, subscr_278_Cleanup
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_HELD_ITEM
    Wait                                
    Branch                              subscr_278_Cleanup

subscr_278_CustapBerry:
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_HELD_ITEM
    Wait                                
    If                                  EQUAL, VAR_CLIENT_WORKING_COUNT, 1, subscr_278_Cleanup
    // "{0}'s {1} let it move first!"
    Message                             1254, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_278_Cleanup:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, subscr_278_CleanupCustap
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0
subscr_278_CleanupCustap:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TEMP_SPE_MAX, 0, subscr_278_Exit
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_TEMP_SPE_MAX, 0
    RemoveItem                          BATTLER_ATTACKER
subscr_278_Exit:
    End                                 

.close