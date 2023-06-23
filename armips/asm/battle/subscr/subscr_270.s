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


.create "build/battle/scr/subscr/sub_seq_270.bin", 0

// SUBSCR_BAG_GUARD_SPEC
subscr_270:
    WaitTime                            15
    PlaySound                           BATTLER_ATTACKER, 1516
    // "{0} {1} used one {2}!"
    Message                             858, TAG_TRTYPE_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RecoverStatus                       BATTLER_ATTACKER
    // "{Your team/The foe} became shrouded in mist!"
    Message                             271, TAG_NONE_DIR, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close