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


.create "build/battle/scr/effscr/be_seq_263.bin", 0

// Bounce; charge turn, chance to paralyze on-hit
effscr_263:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CHARGING, effscr_263_Damage
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_SKIP_CHARGE_TURN, effscr_263_PowerHerb
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_AIRBORNE
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_CHARGE_TURN
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_CHARGING_TURN
    End                                 

effscr_263_PowerHerb:
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_AIRBORNE
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS_TEMP, MOVE_EFFECT_AIRBORNE
    CallSubscript                       SUBSCR_ITEM_POWER_HERB
    ToggleVanish                        BATTLER_ATTACKER, 1
    If                                  EQUAL, VAR_DEFENDER, 0xFF, effscr_263_Cleanup
effscr_263_Damage:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_PARALYZE
    CriticalCalc                        
    DamageCalc                          
effscr_263_Cleanup:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MULTI_TURN_VANISHING
    CallSubscript                       SUBSCR_CHARGE_MOVE_CLEANUP
    End                                 

.close