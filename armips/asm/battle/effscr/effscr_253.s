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


.create "build/battle/scr/effscr/be_seq_253.bin", 0

// User takes recoil = 1/3 of damage dealt; chance to burn on hit
effscr_253:
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_RECKLESS, effscr_253_Damage
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 12
effscr_253_Damage:
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_HAS_PROBABILITY | ADDL_EFFECT_FLARE_BLITZ
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close