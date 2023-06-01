.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_29.s", 0

subscr_029:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION, 32
    Message                             114, TAG_NICK, BATTLER_WORKING
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NORMAL
    WaitFrames                          30
    End                                 
