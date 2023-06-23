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


.create "build/battle/scr/subscr/sub_seq_187.bin", 0

// SUBSCR_TRACE
subscr_187:
    WaitTime                            15
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER_WORK, BATTLE_MON_ABILITY, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_WORKING, BATTLE_MON_ABILITY, VAR_CALC_WORK
    // "{0} traced {1}'s {2}!"
    Message                             679, TAG_NICK_NICK_ABILITY, BATTLER_WORKING, BATTLER_DEFENDER_WORK, BATTLER_DEFENDER_WORK, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close