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


.create "build/battle/scr/subscr/sub_seq_094.bin", 0

// SUBSCR_NIGHTMARE_DAMAGE
subscr_094:
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, subscr_094_Exit
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_NIGHTMARE
    Wait                                
    // Compute the damage (1/4 of max HP)
    SetMonDataFromVar                   OP_GET, BATTLER_WORKING, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 4
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    // "{0} is locked in a nightmare!"
    Message                             414, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    JumpTo                              SUBSCR_HP_CHANGE
subscr_094_Exit:
    End                                 

.close