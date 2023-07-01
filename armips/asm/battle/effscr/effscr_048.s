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


.create "build/battle/scr/effscr/be_seq_048.bin", 0

// User takes recoil = 1/4 of damage dealt
effscr_048:
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_RECKLESS, effscr_048_Damage
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 12
effscr_048_Damage:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_TAKE_RECOIL_1_4
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close