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


.create "build/battle/scr/subscr/sub_seq_137.bin", 0

// SUBSCR_INGRAIN_HEAL
subscr_137:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_INGRAIN
    Wait                                
    // "{0} absorbed nutrients with its roots!"
    Message                             539, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Compute the restored HP (1/16 of max HP)
    SetMonDataFromVar                   OP_GET, BATTLER_WORKING, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 16
    // Check for Big Root
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_WORKING, HOLD_EFFECT_BOOST_LEECHING, subscr_137_ApplyHeal
    GetItemPower                        BATTLER_WORKING, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
subscr_137_ApplyHeal:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    End                                 

.close