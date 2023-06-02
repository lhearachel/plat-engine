.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_174.s", 0

subscr_174:
    SetVar                              OP_SET, VAR_MOVE_TEMP, 377
    Message                             1057, TAG_NICK_MOVE_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
