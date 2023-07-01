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


.create "build/battle/scr/subscr/sub_seq_281.bin", 0

// SUBSCR_NO_TARGET
subscr_281:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "But there was no target..."
    Message                             1234, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    ClearContinuation                   BATTLER_ATTACKER
    // Don't clear the Rage flag if the current move is Rage
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_RAGE, subscr_281_Exit
    // Don't touch the Rage flag if it's not already set
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_RAGING, subscr_281_Exit
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_RAGING
subscr_281_Exit:
    End                                 

.close