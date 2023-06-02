.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_112.s", 0

subscr_112:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2086985, 10
    AttackMessage                       
    Wait                                
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HEAL_BLOCK_TURNS, 0, 3
    JumpToSubscript                     111
    End                                 
    SetVar                              OP_SET, VAR_MOVE_TEMP, 377
    Message                             1054, TAG_NICK_MOVE, BATTLER_DEFENDER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
