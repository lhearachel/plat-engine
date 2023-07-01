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


.create "build/battle/scr/subscr/sub_seq_118.bin", 0

// SUBSCR_SYNCHRONIZE
subscr_118:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, subscr_118_Poison
    CallSubscript                       SUBSCR_APPLY_SLEEP
    Branch                              subscr_118_AfterSynchronize

subscr_118_Poison:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_POISONED, subscr_118_Burn
    CallSubscript                       SUBSCR_APPLY_POISON
    Branch                              subscr_118_AfterSynchronize

subscr_118_Burn:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_BURNED, subscr_118_Paralysis
    CallSubscript                       SUBSCR_APPLY_BURN
    Branch                              subscr_118_AfterSynchronize

subscr_118_Paralysis:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_PARALYZED, subscr_118_Toxic
    CallSubscript                       SUBSCR_APPLY_PARALYSIS
    Branch                              subscr_118_AfterSynchronize

subscr_118_Toxic:
    CallSubscript                       SUBSCR_BADLY_POISON

subscr_118_AfterSynchronize:
    // If the defender is no longer statused for whatever reason, bail out
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, CONDITION_STATUSED, subscr_118_Exit
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
subscr_118_Exit:
    End                                 

.close