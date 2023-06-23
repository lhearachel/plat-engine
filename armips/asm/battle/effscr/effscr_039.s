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


.create "build/battle/scr/effscr/be_seq_039.bin", 0

// Charge on first turn; high critical-hit rate
effscr_039:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CHARGING, effscr_039_Damage
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_TURN_TWO_OF_TWO, effscr_039_Damage
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_SKIP_CHARGE_TURN, effscr_039_PowerHerb
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_CHARGE_TURN
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_CHARGING_TURN
    End                                 

effscr_039_PowerHerb:
    CallSubscript                       SUBSCR_ITEM_POWER_HERB
    // Check if the target client still has a living Pokemon
    If                                  EQUAL, VAR_DEFENDER, 0xFF, effscr_039_Cleanup
effscr_039_Damage:
    SetVar                              OP_ADD, VAR_CRITICAL_CHANCE, 1
    CriticalCalc                        
    DamageCalc                          
effscr_039_Cleanup:
    CallSubscript                       SUBSCR_CHARGE_MOVE_CLEANUP
    End                                 

.close