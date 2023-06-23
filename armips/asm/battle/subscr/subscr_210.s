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


.create "build/battle/scr/subscr/sub_seq_210.bin", 0

// SUBSCR_ITEM_STAT_BOOST_2
subscr_210:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    WaitTime                            15
    SetStatusEffect                     BATTLER_WORKING, STATUS_STAT_BOOST
    Wait                                
    // "The {1} sharply raised {0}'s {2}!"
    Message                             759, TAG_NICK_ITEM_STAT, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Pick the stat to boost (0x12 + Prepared)
    SetVar                              OP_SET, VAR_TEMP_WORK, 0x12
    SetVarFromVar                       OP_ADD, VAR_TEMP_WORK, VAR_PREPARED_MESSAGE
    // Cap out at +6
    SetMonData                          OP_ADD, BATTLER_WORKING, BATTLE_MON_TEMP_WORK, 2
    IfMonData                           LESSER, BATTLER_WORKING, BATTLE_MON_TEMP_WORK, 12, subscr_210_Cleanup
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_TEMP_WORK, 12
subscr_210_Cleanup:
    CallSubscript                       SUBSCR_PLUCK_CHECK
    End                                 

.close