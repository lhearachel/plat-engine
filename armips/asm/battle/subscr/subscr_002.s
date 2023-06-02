.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_2.s", 0

subscr_002:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 64, 12
    PlayMoveSoundEffect                 BATTLER_WORKING
    FlickerMon                          BATTLER_WORKING
    Wait                                
    If                                  EQUAL, VAR_CLIENT_WORKING_COUNT, 0, 2
    JumpToSubscript                     264
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 64
    UpdateHPGauge                       BATTLER_WORKING
    Wait                                
    UpdateHP                            BATTLER_WORKING
    TryFaintMon                         BATTLER_WORKING
    If                                  GREATER, VAR_HP_TEMP, 0, 4
    SetVarFromVar                       OP_SET, VAR_ATTACKER_ASSURANCE_DAMAGE, VAR_HP_TEMP
    End                                 
