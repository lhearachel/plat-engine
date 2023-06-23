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


.create "build/battle/scr/subscr/sub_seq_219.bin", 0

// SUBSCR_PLUCK
subscr_219:
    TryPluck                            subscr_219_StickyHold, subscr_219_Exit
    // "{0} stole and ate its foe's {1}!"
    Message                             1141, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RemoveItem                          BATTLER_DEFENDER
    // Call the Plucked berry's subscript
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    If                                  EQUAL, VAR_TEMP_WORK, 0, subscr_219_Exit
    CallSubscriptFromVar                VAR_TEMP_WORK
subscr_219_Exit:
    End                                 

subscr_219_StickyHold:
    // "{0}'s {1} made {2} ineffective!"
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close