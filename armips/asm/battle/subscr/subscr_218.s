.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_218.s", 0

subscr_218:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 53
    CheckSubstitute                     BATTLER_DEFENDER, 50
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 121, 44
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_EMBARGO_TURNS, 0, 38
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, 32
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, 26
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TEMP_SPE_MAX, 0, 20
    JumpToSubscript                     76
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 67108864
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_EMBARGO_TURNS, 5
    Message                             1135, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
