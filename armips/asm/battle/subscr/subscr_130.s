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


.create "build/battle/scr/subscr/sub_seq_130.bin", 0

// SUBSCR_HEAL_PARALYSIS
subscr_130:
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, subscr_130_Exit
    SetMonData                          OP_CLEAR_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION, CONDITION_PARALYZED
    // "{0} was healed of paralysis!"
    Message                             136, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_DEFENDER, STATUS_NONE
    WaitTime                            30
subscr_130_Exit:
    End                                 

.close