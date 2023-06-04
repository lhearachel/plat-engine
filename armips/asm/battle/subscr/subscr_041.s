.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_41.bin", 0

subscr_041:
    TrainerSlideIn                      BATTLER_ENEMY, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessagePrepared              BATTLER_ENEMY
    Wait                                
    WaitTime                            60
    TrainerSlideOut                     4
    Wait                                
    End                                 

.close