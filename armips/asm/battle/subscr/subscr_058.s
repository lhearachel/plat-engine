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


.create "build/battle/scr/subscr/sub_seq_058.bin", 0

// SUBSCR_CLAMP_START
subscr_058:
    // Substitutes are immune to trapping
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_058_End
    // If the target is already trapped, do nothing
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_CLAMPED, subscr_058_End
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    // Generate the trapping duration
    Random                              3, 3
    // Check for Grip Claw (always 6 turns of trapping)
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_EXTEND_TRAPPING, subscr_058_SetTrapping
    SetVar                              OP_SET, VAR_CALC_WORK, 6
subscr_058_SetTrapping:
    SetVar                              OP_LSH, VAR_CALC_WORK, 13
    SetMonDataFromVar                   OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_BOUND_TARGET, VAR_ATTACKER
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_BINDING_MOVE, VAR_CURRENT_MOVE
subscr_058_End:
    End                                 

.close