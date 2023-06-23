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


.create "build/battle/scr/subscr/sub_seq_142.bin", 0

// SUBSCR_KNOCK_OFF
subscr_142:
    CheckSubstitute                     BATTLER_DEFENDER, subscr_142_Exit
    // Do not try to knock off a target with Multitype
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, subscr_142_Exit
    // Do not try to knock off a Griseous Orb
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, subscr_142_Exit
    // Do not try to knock off an active Quick Claw or Custap Berry
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, subscr_142_Exit
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TEMP_SPE_MAX, 0, subscr_142_Exit
    // This should also play the Knock Off animation?
    TryKnockOff                         subscr_142_Exit
    MessagePrepared                     
    Wait                                
    WaitTime                            30
subscr_142_Exit:
    End                                 

.close