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


.create "build/battle/scr/subscr/sub_seq_013.bin", 0

// SUBSCR_VANISH_ON_CHARGE_TURN
subscr_013:
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    SetContinuation                     BATTLER_EFFECT_TARGET
    IfMonData                           FLAG_NEQ, BATTLER_EFFECT_TARGET, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MULTI_TURN_VANISHING, subscr_013_End
    ToggleVanish                        BATTLER_EFFECT_TARGET, 1
subscr_013_End:
    End                                 

.close