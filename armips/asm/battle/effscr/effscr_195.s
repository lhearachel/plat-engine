.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_195.s", 0

effscr_195:
    TrySnatch                           9
    PrepareMessage                      577, TAG_NICK, BATTLER_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    End                                 
    SetVar                              OP_SET, VAR_MOVE_STATUS_FLAG, 64
    End                                 
