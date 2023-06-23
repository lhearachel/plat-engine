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


.create "build/battle/scr/subscr/sub_seq_071.bin", 0

// SUBSCR_MOVE_IS_DISABLED
subscr_071:
    // weird no-op check
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CHARGING, subscr_071_Continue
subscr_071_Continue:
    // "{0}'s {1} is disabled!"
    Message                             609, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    ClearContinuation                   BATTLER_ATTACKER
    End                                 

.close