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


.create "build/battle/scr/subscr/sub_seq_269.bin", 0

// SUBSCR_BAG_STAT_BOOST
subscr_269:
    WaitTime                            15
    PlaySound                           BATTLER_ATTACKER, 1516
    // "{0} {1} used one {2}!"
    Message                             858, TAG_TRTYPE_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RecoverStatus                       BATTLER_ATTACKER
    // "The {1} raised {0}'s {2}!"
    Message                             756, TAG_NICK_ITEM_STAT, BATTLER_ATTACKER, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close