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


.create "build/battle/scr/movscr/waza_seq_353.bin", 0

movscr_353:
    // "{0} chose {1} as its destiny!"
    PrepareMessage                      478, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    JumpToMoveEffectScript              

.close