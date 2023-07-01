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


.create "build/battle/scr/subscr/sub_seq_004.bin", 0

// SUBSCR_BATTLE_WON
subscr_004:
    // Leaving a battle triggers Natural Cure
    TryNaturalCure                      BATTLER_ME_SLOT_1, subscr_004_CheckSlot2
    SetMonData                          OP_SET, BATTLER_ME_SLOT_1, BATTLE_MON_CONDITION, 0
subscr_004_CheckSlot2:
    TryNaturalCure                      BATTLER_ME_SLOT_2, subscr_004_Start
    SetMonData                          OP_SET, BATTLER_ME_SLOT_2, BATTLE_MON_CONDITION, 0

subscr_004_Start:
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TRAINER, subscr_004_CheckPickupAndPayDay
    If                                  EQUAL, VAR_BATTLE_TYPE, BATTLE_TYPE_TOWER_LINK_2vs2, subscr_004_TrainerMultiMessageLink
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_LINK, subscr_004_LinkWin
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_2vs2, subscr_004_TrainerMultiMessage
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TAG, subscr_004_TrainerMultiMessage

subscr_004_TrainerMessage1vs1:
    // "Player defeated {0} {1}!"
    Message                             839, TAG_TRTYPE_TRNAME, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_1, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            15
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_1, POS_SINGLES_ENEMY
    Wait                                
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_DOUBLES, subscr_004_TrainerMessage2vs2
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE
    Wait                                
    WaitTime                            60
    Branch                              subscr_004_Continue

subscr_004_TrainerMessage2vs2:
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE_1
    Wait                                
    WaitTime                            60
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TOWER, subscr_004_Continue
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE_2
    Wait                                
    WaitTime                            60
    Branch                              subscr_004_Continue

subscr_004_TrainerMultiMessageLink:
    PlayMusic                           BATTLER_ME_SLOT_1, 1128
subscr_004_TrainerMultiMessage:
    // "Player beat {0} {1} and {2} {3}!"
    Message                             953, TAG_TRTYPE_TRNAME_TRTYPE_TRNAME, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_2, BATTLER_ENEMY_SLOT_2, NaN, NaN
    Wait                                
    WaitTime                            15
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_1, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE
    Wait                                
    WaitTime                            30
    TrainerSlideOut                     BATTLER_ENEMY_SLOT_1
    Wait                                
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_2, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_2, TRAINER_MESSAGE_LOSE
    Wait                                
    WaitTime                            60
    SetBattleResult                     

subscr_004_Continue:
    // Battle Tower fights have no money payout
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TOWER, subscr_004_Cleanup
    CalcMoney                           
    Message                             33, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            60

subscr_004_CheckPickupAndPayDay:
    PickupItem                          
    AddPayDayMoney                      
    // If there is no Pay Day money to display, proceed to cleanup
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, subscr_004_Cleanup
    Message                             341, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            60

subscr_004_Cleanup:
    FadeOut                             
    Wait                                
    End                                 

subscr_004_LinkWin:
    CallSubscript                       SUBSCR_LINK_WIN_LOSE
    End                                 

.close