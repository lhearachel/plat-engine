.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_128.s", 0

movscr_128:
    PrepareMessage                      255, TAG_NICK_NICK, BATTLER_DEFENDER, BATTLER_ATTACKER
    JumpToMoveEffectScript              
