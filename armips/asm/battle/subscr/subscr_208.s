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


.create "build/battle/scr/subscr/sub_seq_208.bin", 0

// SUBSCR_ITEM_STAT_BOOST
subscr_208:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // Pick the stat to boost (0xE + Prepared)
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 0xE
    SetVarFromVar                       OP_ADD, VAR_EFFECT_PARAMS, VAR_PREPARED_MESSAGE
    SetVar                              OP_SET, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM
    SetVarFromVar                       OP_SET, VAR_EFFECT_TARGET, VAR_BATTLER_WORK
    CallSubscript                       SUBSCR_BOOST_STATS
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close