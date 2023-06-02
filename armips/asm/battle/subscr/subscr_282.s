.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_282.s", 0

subscr_282:
    Message                             335, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096
    Message                             1234, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
