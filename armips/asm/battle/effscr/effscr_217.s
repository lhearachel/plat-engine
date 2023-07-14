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


.create "build/battle/scr/effscr/be_seq_217.bin", 0

// Wake-Up Slap; double power if the target is asleep, cure the target's sleep
effscr_217:
    CheckSubstitute                     BATTLER_DEFENDER, effscr_217_Damage
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, effscr_217_TargetIsAsleep
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, Q412_1_0
    Branch                              effscr_217_Damage
effscr_217_TargetIsAsleep:
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, Q412_2_0
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_CURE_SLEEP
effscr_217_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close