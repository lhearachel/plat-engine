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


.create "build/battle/scr/subscr/sub_seq_180.bin", 0

// SUBSCR_LIGHTNING_ROD (+ Storm Drain)
subscr_180:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    // "{0}'s {1} took the attack!"
    Message                             724, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close