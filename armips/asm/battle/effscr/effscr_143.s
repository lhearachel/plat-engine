.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_143.s", 0

effscr_143:
    PsychUp                             
    PrepareMessage                      452, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    End                                 
