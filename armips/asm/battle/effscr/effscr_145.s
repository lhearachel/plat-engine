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


.create "build/battle/scr/effscr/be_seq_145.bin", 0

// Charge turn; raise Defense by 1 stage
effscr_145:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CHARGING, effscr_145_Damage
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_SKIP_CHARGE_TURN, effscr_145_PowerHerb
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_CHARGE_TURN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_DEF_UP_1
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_CHARGING_TURN
    End

effscr_145_PowerHerb:                                 
    CallSubscript                       SUBSCR_POWER_HERB_SKULL_BASH
    // Check if the target client still has a living Pokemon
    If                                  EQUAL, VAR_DEFENDER, 0xFF, effscr_145_Cleanup
effscr_145_Damage:
    CriticalCalc                        
    DamageCalc                          
effscr_145_Cleanup:
    CallSubscript                       SUBSCR_CHARGE_MOVE_CLEANUP
    End                                 

.close