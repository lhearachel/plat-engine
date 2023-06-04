.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_154.bin", 0

effscr_154:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 32768
    CriticalCalc                        
    BeatUpDamageCalc                    
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871014
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 65536
    End                                 

.close