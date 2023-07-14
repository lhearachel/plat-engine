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


.create "build/battle/scr/subscr/sub_seq_299.bin", 0

// SUBSCR_CHECK_REMOVE_GEM
subscr_299:
    // Do not activate on OHKO moves
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ONE_HIT_KO, subscr_299_Exit
    // Modify the type of the move if the attacker has Normalize
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_NORMALIZE, subscr_299_NoAbilityTypeMod
    SetVar                              OP_SET, VAR_CALC_WORK, TYPE_NORMAL
    Branch                              subscr_299_Resume

subscr_299_NoAbilityTypeMod:
    If                                  EQUAL, VAR_MOVE_TYPE, 0, subscr_299_GetType
    SetVarFromVar                       OP_GET, VAR_MOVE_TYPE, VAR_CALC_WORK
    Branch                              subscr_299_Resume

subscr_299_GetType:
    GetCurrentMoveData                  MOVE_PARAM_TYPE
subscr_299_Resume:
    GetItemEffect                       BATTLER_ATTACKER, VAR_TEMP_WORK
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_NORMAL, subscr_299_CheckNormal
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_FIRE, subscr_299_CheckFire
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_WATER, subscr_299_CheckWater
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_ELECTRIC, subscr_299_CheckElectric
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_GRASS, subscr_299_CheckGrass
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_ICE, subscr_299_CheckIce
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_FIGHTING, subscr_299_CheckFighting
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_POISON, subscr_299_CheckPoison
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_GROUND, subscr_299_CheckGround
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_FLYING, subscr_299_CheckFlying
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_PSYCHIC, subscr_299_CheckPsychic
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_BUG, subscr_299_CheckBug
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_ROCK, subscr_299_CheckRock
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_GHOST, subscr_299_CheckGhost
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_DRAGON, subscr_299_CheckDragon
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_DARK, subscr_299_CheckDark
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_STEEL, subscr_299_CheckSteel
    Branch                              subscr_299_Exit

subscr_299_CheckNormal:
    // Struggle check; do not consume Normal Gems
    If                                  EQUAL, VAR_CURRENT_MOVE, 165, subscr_299_Exit
    If                                  EQUAL, VAR_CALC_WORK, TYPE_NORMAL, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckFire:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIRE, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckWater:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_WATER, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckElectric:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ELECTRIC, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckGrass:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GRASS, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckIce:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ICE, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckFighting:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIGHTING, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckPoison:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_POISON, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckGround:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GROUND, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckFlying:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FLYING, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckPsychic:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_PSYCHIC, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckBug:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_BUG, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckRock:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ROCK, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckGhost:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GHOST, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckDragon:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DRAGON, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckDark:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DARK, subscr_299_RemoveItem
    Branch                              subscr_299_Exit

subscr_299_CheckSteel:
    If                                  NOT_EQUAL, VAR_CALC_WORK, TYPE_STEEL, subscr_299_Exit
subscr_299_RemoveItem:
    RemoveItem                          BATTLER_ATTACKER
subscr_299_Exit:
    End                                 

.close