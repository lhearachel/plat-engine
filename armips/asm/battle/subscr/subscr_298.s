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


.create "build/battle/scr/subscr/sub_seq_298.bin", 0

// SUBSCR_CHECK_TRIGGER_GEM
subscr_298:
    // Do not activate on OHKO moves
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ONE_HIT_KO, subscr_298_Exit
    // Modify the type of the move if the attacker has Normalize
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_NORMALIZE, subscr_298_NoAbilityTypeMod
    SetVar                              OP_SET, VAR_CALC_WORK, TYPE_NORMAL
    Branch                              subscr_298_Resume

subscr_298_NoAbilityTypeMod:
    If                                  EQUAL, VAR_MOVE_TYPE, 0, subscr_298_GetType
    SetVarFromVar                       OP_GET, VAR_MOVE_TYPE, VAR_CALC_WORK
    Branch                              subscr_298_Resume

subscr_298_GetType:
    GetCurrentMoveData                  MOVE_PARAM_TYPE
subscr_298_Resume:
    GetItemEffect                       BATTLER_ATTACKER, VAR_TEMP_WORK
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_NORMAL, subscr_298_CheckNormal
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_FIRE, subscr_298_CheckFire
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_WATER, subscr_298_CheckWater
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_ELECTRIC, subscr_298_CheckElectric
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_GRASS, subscr_298_CheckGrass
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_ICE, subscr_298_CheckIce
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_FIGHTING, subscr_298_CheckFighting
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_POISON, subscr_298_CheckPoison
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_GROUND, subscr_298_CheckGround
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_FLYING, subscr_298_CheckFlying
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_PSYCHIC, subscr_298_CheckPsychic
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_BUG, subscr_298_CheckBug
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_ROCK, subscr_298_CheckRock
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_GHOST, subscr_298_CheckGhost
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_DRAGON, subscr_298_CheckDragon
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_DARK, subscr_298_CheckDark
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_GEM_STEEL, subscr_298_CheckSteel
    Branch                              subscr_298_Exit

subscr_298_CheckNormal:
    // Struggle check; do not consume Normal Gems
    If                                  EQUAL, VAR_CURRENT_MOVE, 165, subscr_298_Exit
    If                                  EQUAL, VAR_CALC_WORK, TYPE_NORMAL, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckFire:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIRE, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckWater:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_WATER, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckElectric:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ELECTRIC, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckGrass:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GRASS, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckIce:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ICE, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckFighting:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIGHTING, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckPoison:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_POISON, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckGround:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GROUND, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckFlying:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FLYING, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckPsychic:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_PSYCHIC, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckBug:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_BUG, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckRock:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ROCK, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckGhost:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GHOST, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckDragon:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DRAGON, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckDark:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DARK, subscr_298_AnimateAndMessage
    Branch                              subscr_298_Exit

subscr_298_CheckSteel:
    If                                  NOT_EQUAL, VAR_CALC_WORK, TYPE_STEEL, subscr_298_Exit
subscr_298_AnimateAndMessage:
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_HELD_ITEM
    Wait                                
    // "The {1} strengthened {0}'s power!"
    Message                             1269, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_298_Exit:
    End                                 

.close