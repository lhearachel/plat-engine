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


.create "build/battle/scr/effscr/be_seq_169.bin", 0

// Facade (double power if the user is Poisoned, Paralyzed, or Burned)
effscr_169:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_BOOST_FACADE, effscr_169_Damage
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
effscr_169_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close