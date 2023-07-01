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


.create "build/battle/scr/subscr/sub_seq_222.bin", 0

// SUBSCR_ITEM_ESCAPE
subscr_222:
    // "Used the {0}!"
    Message                             1206, TAG_ITEM, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusEffect                     BATTLER_ME, STATUS_ITEM_ESCAPE
    Wait                                
    PlaySound                           BATTLER_ATTACKER, 1791
    // "Got away safely!"
    Message                             781, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, BATTLE_RESULT_ESCAPE
    End                                 

.close