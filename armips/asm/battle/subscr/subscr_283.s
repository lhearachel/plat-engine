.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_283.s", 0

subscr_283:
    SetBattleResult                     
    BattleResultMessage                 
    Wait                                
    WaitFrames                          30
    FadeOut                             
    Wait                                
    End                                 
