.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_173.s", 0

subscr_173:
    CheckSubstitute                     BATTLER_DEFENDER, 26
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HEAL_BLOCK_TURNS, 0, 20
    JumpToSubscript                     76
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 33554432
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_HEAL_BLOCK_TURNS, 5
    Message                             1051, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    Message                             1235, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
