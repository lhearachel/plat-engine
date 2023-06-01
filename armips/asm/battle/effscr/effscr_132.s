.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_132.s", 0

effscr_132:
    WeatherHPRecovery                   
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871009
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 256
    End                                 
