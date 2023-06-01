.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_80.s", 0

subscr_080:
    CheckSubstitute                     BATTLER_DEFENDER, 13
    TrySketch                           11
    JumpToSubscript                     76
    Message                             385, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
