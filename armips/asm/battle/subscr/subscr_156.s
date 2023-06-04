.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_156.bin", 0

subscr_156:
    Message                             997, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
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
    Branch                              20
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_MAGNET_RISE_TURNS, 0
    Branch                              6
    ClearContinuation                   BATTLER_WORKING
    ToggleVanish                        255, 0
    Wait                                
    Message                             998, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, 4294967217
    End                                 

.close