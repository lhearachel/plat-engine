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


.create "build/battle/scr/movscr/waza_seq_076.bin", 0

movscr_076:
    // "{0} absorbed light!"
    PrepareMessage                      214, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    JumpToMoveEffectScript              

.close