.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_266.s", 0

subscr_266:
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, 4
    SetStatusEffect                     BATTLER_DEFENDER, 10
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    JumpToSubscript                     2
    Message                             1160, TAG_NICK_NICK_ITEM, BATTLER_ATTACKER, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    RemoveItem                          BATTLER_DEFENDER
    End                                 
