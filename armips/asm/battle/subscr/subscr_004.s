.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_4.s", 0

subscr_004:
    TryNaturalCure                      BATTLER_ME_SLOT_1, 5
    SetMonData                          OP_SET, BATTLER_ME_SLOT_1, BATTLE_MON_CONDITION, 0
    TryNaturalCure                      BATTLER_ME_SLOT_2, 5
    SetMonData                          OP_SET, BATTLER_ME_SLOT_2, BATTLE_MON_CONDITION, 0
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, 1, 115
    If                                  EQUAL, VAR_BATTLE_TYPE, 143, 59
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 4, 123
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 8, 52
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 16, 47
    Message                             839, TAG_TRTYPE_TRNAME, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_1
    Wait                                
    WaitFrames                          15
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_1, POS_SINGLES_ENEMY
    Wait                                
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 2, 8
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE
    Wait                                
    WaitFrames                          60
    Jump                                56
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE_1
    Wait                                
    WaitFrames                          60
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 128, 45
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE_2
    Wait                                
    WaitFrames                          60
    Jump                                37
    PlayMusic                           BATTLER_ME_SLOT_1, 1128
    Message                             953, TAG_TRTYPE_TRNAME_TRTYPE_TRNAME, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_2, BATTLER_ENEMY_SLOT_2
    Wait                                
    WaitFrames                          15
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_1, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_LOSE
    Wait                                
    WaitFrames                          30
    TrainerSlideOut                     10
    Wait                                
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_2, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_2, TRAINER_MESSAGE_LOSE
    Wait                                
    WaitFrames                          60
    SetBattleResult                     
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 128, 24
    CalcMoney                           
    Message                             33, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING
    Wait                                
    WaitFrames                          60
    PickupItem                          
    AddPayDayMoney                      
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, 8
    Message                             341, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING
    Wait                                
    WaitFrames                          60
    FadeOut                             
    Wait                                
    End                                 
    JumpToSubscript                     283
    End                                 
