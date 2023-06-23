.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/subscr/sub_seq_041.bin", 0

// SUBSCR_TRAINER_MESSAGE
subscr_041:
    TrainerSlideIn                      BATTLER_ENEMY, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessagePrepared              BATTLER_ENEMY
    Wait                                
    WaitTime                            60
    TrainerSlideOut                     BATTLER_ENEMY
    Wait                                
    End                                 

.close