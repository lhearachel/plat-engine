.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_121.bin", 0

subscr_121:
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    CheckHit                            BATTLER_ATTACKER_WORK, BATTLER_WORKING, MOVE_SPIT_UP, 109
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    PlayAnimationAtoD                   BATTLER_WORKING, 14, 255
    Wait                                
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 16777216, 31
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    JumpIfMonData                       LESSER, BATTLER_WORKING, BATTLE_MON_SUBSTITUTE_HP, VAR_HP_TEMP, 7
    SetMonDataFromVar                   OP_SUB, 255, BATTLE_MON_SUBSTITUTE_HP, VAR_HP_TEMP
    Branch                              10
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_SUBSTITUTE_HP, 0
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 16777216
    JumpToSubscript                     90
    Branch                              34
    CheckLeaveWith1HP                   BATTLER_WORKING
    JumpToSubscript                     2
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 8388608, 24
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_HP, 0, 18
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_ATK_STAGE, 12, 12
    SetMonData                          OP_ADD, BATTLER_WORKING, BATTLE_MON_ATK_STAGE, 1
    Message                             363, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 256, 19
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             912, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_WORKING, HOLD_EFFECT_FOCUS_SASH, 2
    RemoveItem                          BATTLER_WORKING
    End                                 
    WaitTime                            30
    Message                             796, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close