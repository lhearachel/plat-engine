.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_154.s", 0

effscr_154:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 32768
    CriticalCalc                        
    BeatUpDamageCalc                    
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871014
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 65536
    End                                 
