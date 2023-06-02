.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_107.s", 0

subscr_107:
    Message                             165, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_ATTACKER, 7
    Wait                                
    End                                 
