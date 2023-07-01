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


.create "build/battle/scr/subscr/sub_seq_026.bin", 0

// SUBSCR_BURN_DAMAGE
subscr_026:
    // Check for Magic Guard.
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, subscr_026_Exit
    SetMonDataFromVar                   OP_GET, BATTLER_WORKING, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 8
    // Heatproof reduces burn damage by half.
    CheckAbility                        MODE_NOT_HAVE, BATTLER_WORKING, ABILITY_HEATPROOF, subscr_026_ApplyBurnDamage
    DamageDiv                           VAR_HP_TEMP, 2
subscr_026_ApplyBurnDamage:
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    // "{0} is hurt by its burn!"
    Message                             95, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetStatusEffect                     BATTLER_WORKING, STATUS_BURNED
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    JumpTo                              SUBSCR_HP_CHANGE
subscr_026_Exit:
    End                                 

.close