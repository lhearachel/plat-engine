.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_20.s", 0

movscr_020:
    PrepareMessage                      235, TAG_NICK_NICK, BATTLER_DEFENDER, BATTLER_ATTACKER
    JumpToMoveEffectScript              
