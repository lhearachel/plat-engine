.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_132.bin", 0

effscr_132:
    WeatherHPRecovery                   
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871009
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 256
    End                                 

.close