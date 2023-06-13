.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/movscr/waza_seq_035.bin", 0

movscr_035:
    PrepareMessage                      248, TAG_NICK_NICK, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    JumpToMoveEffectScript              

.close