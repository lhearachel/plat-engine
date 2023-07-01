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


.create "build/battle/scr/effscr/be_seq_151.bin", 0

// Charge turn unless Sun is active
effscr_151:
    CheckCloudNine                      effscr_151_SkipWeatherCheck
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_SUNNY, effscr_152_SunIsActive
effscr_151_SkipWeatherCheck:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CHARGING, effscr_152_Damage
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_SKIP_CHARGE_TURN, effscr_152_PowerHerb
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_CHARGE_TURN
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_CHARGING_TURN
    End

effscr_152_PowerHerb:                                 
    CallSubscript                       SUBSCR_ITEM_POWER_HERB
effscr_152_SunIsActive:
    If                                  EQUAL, VAR_DEFENDER, 0xFF, effscr_152_Cleanup
effscr_152_Damage:
    CriticalCalc                        
    DamageCalc                          
effscr_152_Cleanup:
    CallSubscript                       SUBSCR_CHARGE_MOVE_CLEANUP
    End                                 

.close