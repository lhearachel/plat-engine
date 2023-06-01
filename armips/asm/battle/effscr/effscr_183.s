.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_183.s", 0

effscr_183:
    TrySetMagicCoat                     9
    PrepareMessage                      571, TAG_NICK, BATTLER_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    End                                 
    SetVar                              OP_SET, VAR_MOVE_STATUS_FLAG, 64
    End                                 
