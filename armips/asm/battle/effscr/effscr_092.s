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


.create "build/battle/scr/effscr/be_seq_092.bin", 0

// Snore
effscr_092:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, effscr_092_Failure
    // Check if Sleep Talk invoked Snore; if it did, skip the subscript jump
    If                                  EQUAL, VAR_MOVE_NUM_WORK, 214, effscr_092_AfterSleeping
    CallSubscript                       SUBSCR_SLEEPING
effscr_092_AfterSleeping:
    SetVar                              OP_SET_FLAG, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLINCH
    CriticalCalc                        
    DamageCalc                          
    End                                 

effscr_092_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close