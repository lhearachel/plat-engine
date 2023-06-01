.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_139.s", 0

subscr_139:
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    Message                             574, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    MagicCoat                           
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    End                                 
