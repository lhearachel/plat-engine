.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_283.bin", 0

subscr_283:
    SetBattleResult                     
    BattleResultMessage                 
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    End                                 

.close