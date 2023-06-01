.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_193.s", 0

subscr_193:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    Message                             1099, TAG_NICK_ABILITY_NICK, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
