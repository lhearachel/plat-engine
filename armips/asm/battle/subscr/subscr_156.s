.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_156.s", 0

subscr_156:
    Message                             997, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 20480
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
    GetBattlerBySpeedOrder              VAR_BATTLER_WORK
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_HP, 0, 64
    IfMonData                           NOT_EQUAL, BATTLER_WORKING, BATTLE_MON_MAGNET_RISE_TURNS, 0, 38
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, 64, 39
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, 2097152, 46
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, 1024, 40
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_ABILITY, 26, 27
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_TYPE_1, 2, 21
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_TYPE_2, 2, 15
    Jump                                20
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_MAGNET_RISE_TURNS, 0
    Jump                                6
    ClearContinuation                   BATTLER_WORKING
    ToggleVanish                        255, 0
    Wait                                
    Message                             998, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, 4294967217
    End                                 
