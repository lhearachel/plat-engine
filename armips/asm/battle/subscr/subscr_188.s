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


.create "build/battle/scr/subscr/sub_seq_188.bin", 0

// SUBSCR_COLOR_CHANGE
subscr_188:
    // "{0}'s {1} made it the {2} type!"
    Message                             641, TAG_NICK_ABILITY_TYPE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_TYPE_1, VAR_PREPARED_MESSAGE
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_TYPE_2, VAR_PREPARED_MESSAGE
    End                                 

.close