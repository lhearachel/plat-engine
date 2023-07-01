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


.create "build/battle/scr/effscr/be_seq_268.bin", 0

// Judgment
effscr_268:
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FIGHTING_PLATE, effscr_268_SetFightingType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FLYING_PLATE, effscr_268_SetFlyingType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_POISON_PLATE, effscr_268_SetPoisonType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GROUND_PLATE, effscr_268_SetGroundType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ROCK_PLATE, effscr_268_SetRockType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_BUG_PLATE, effscr_268_SetBugType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GHOST_PLATE, effscr_268_SetGhostType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_STEEL_PLATE, effscr_268_SetSteelType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FIRE_PLATE, effscr_268_SetFireType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_WATER_PLATE, effscr_268_SetWaterType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GRASS_PLATE, effscr_268_SetGrassType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ELECTRIC_PLATE, effscr_268_SetElectricType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_PSYCHIC_PLATE, effscr_268_SetPsychicType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ICE_PLATE, effscr_268_SetIceType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_DRAGON_PLATE, effscr_268_SetDragonType
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_DARK_PLATE, effscr_268_SetDarkType
    Branch                              effscr_268_Damage

effscr_268_SetFightingType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_FIGHTING
    Branch                              effscr_268_Damage
effscr_268_SetFlyingType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_FLYING
    Branch                              effscr_268_Damage
effscr_268_SetPoisonType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_POISON
    Branch                              effscr_268_Damage
effscr_268_SetGroundType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_GROUND
    Branch                              effscr_268_Damage
effscr_268_SetRockType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_ROCK
    Branch                              effscr_268_Damage
effscr_268_SetBugType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_BUG
    Branch                              effscr_268_Damage
effscr_268_SetGhostType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_GHOST
    Branch                              effscr_268_Damage
effscr_268_SetSteelType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_STEEL
    Branch                              effscr_268_Damage
// TODO: Add Pixie Plate here
effscr_268_SetFireType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_FIRE
    Branch                              effscr_268_Damage
effscr_268_SetWaterType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_WATER
    Branch                              effscr_268_Damage
effscr_268_SetGrassType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_GRASS
    Branch                              effscr_268_Damage
effscr_268_SetElectricType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_ELECTRIC
    Branch                              effscr_268_Damage
effscr_268_SetPsychicType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_PSYCHIC
    Branch                              effscr_268_Damage
effscr_268_SetIceType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_ICE
    Branch                              effscr_268_Damage
effscr_268_SetDragonType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_DRAGON
    Branch                              effscr_268_Damage
effscr_268_SetDarkType:
    SetVar                              OP_SET, VAR_MOVE_TYPE, TYPE_DARK
effscr_268_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close