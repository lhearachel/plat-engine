.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_92.s", 0

subscr_092:
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 537133248, 18
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 2097152, 12
    JumpToSubscript                     76
    Transform                           
    Message                             345, TAG_NICK_POKE, BATTLER_ATTACKER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
