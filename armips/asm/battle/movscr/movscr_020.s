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


.create "build/battle/scr/movscr/waza_seq_020.bin", 0

movscr_020:
    // "{0} was squeezed by {1}!"
    PrepareMessage                      235, TAG_NICK_NICK, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    JumpToMoveEffectScript              

.close