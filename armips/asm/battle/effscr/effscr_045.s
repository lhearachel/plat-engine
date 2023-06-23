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


.create "build/battle/scr/effscr/be_seq_045.bin", 0

// Crash damage on miss
effscr_045:
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_RECKLESS, effscr_045_Damage
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 12
effscr_045_Damage:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_CRASH_DAMAGE
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close