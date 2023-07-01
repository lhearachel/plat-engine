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


.create "build/battle/scr/subscr/sub_seq_005.bin", 0

// SUBSCR_BATTLE_LOST
subscr_005:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TOWER, subscr_005_TowerLoss
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_LINK, subscr_005_LinkLoss
    Message                             36, TAG_TRNAME, BATTLER_ME, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TOWER, subscr_005_Cleanup
    CalcMoney                           
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, subscr_005_Cleanup
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TRAINER, subscr_005_TrainerLoss
    Message                             34, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              subscr_005_Cleanup

subscr_005_TrainerLoss:
    Message                             35, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30

subscr_005_Cleanup:
    Message                             38, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Message                             37, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    End                                 

subscr_005_LinkLoss:
    CallSubscript                       SUBSCR_LINK_WIN_LOSE
    End                                 

subscr_005_TowerLoss:
    IfMonData                           EQUAL, BATTLER_ENEMY_SLOT_1, BATTLE_MON_HP, 0, subscr_005_Enemy2Recall
    PokemonReturn                       BATTLER_ENEMY_SLOT_1
subscr_005_Enemy2Recall:
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, BATTLE_TYPE_DOUBLES, subscr_005_WaitToRecall
    IfMonData                           EQUAL, BATTLER_ENEMY_SLOT_2, BATTLE_MON_HP, 0, subscr_005_WaitToRecall
    PokemonReturn                       BATTLER_ENEMY_SLOT_2
subscr_005_WaitToRecall:
    Wait                                
    HPGaugeSlideOut                     BATTLER_ENEMY
    Wait                                
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_1, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_WIN
    Wait                                
    WaitTime                            30
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, 8, subscr_005_TowerLossContinue
    TrainerSlideOut                     BATTLER_ENEMY_SLOT_1
    Wait                                
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_2, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_2, TRAINER_MESSAGE_WIN
    Wait                                
    WaitTime                            60
    Branch                              subscr_005_TowerLossNoWait
subscr_005_TowerLossContinue:
    WaitTime                            30
subscr_005_TowerLossNoWait:
    SetBattleResult                     
    FadeOut                             
    Wait                                
    End                                 

.close