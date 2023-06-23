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


.create "build/battle/scr/subscr/sub_seq_288.bin", 0

// SUBSCR_TAUNT_END
subscr_288:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_TAUNT
    // "{0}'s {1} wore off!"
    Message                             1257, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close