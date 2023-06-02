.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_62.s", 0

subscr_062:
    JumpToSubscript                     76
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION_2, 1048576
    Message                             276, TAG_NICK, BATTLER_EFFECTSRC
    Wait                                
    WaitFrames                          30
    End                                 
