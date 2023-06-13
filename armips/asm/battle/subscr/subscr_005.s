.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_005.bin", 0

subscr_005:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 128, 64
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 4, 56
    Message                             36, TAG_TRNAME, BATTLER_ME, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 128, 29
    CalcMoney                           
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, 23
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 1, 10
    Message                             34, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              8
    Message                             35, TAG_TRNAME_NUM, BATTLER_ME, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Message                             38, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Message                             37, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    End                                 
    JumpToSubscript                     283
    End                                 
    IfMonData                           EQUAL, BATTLER_ENEMY_SLOT_1, BATTLE_MON_HP, 0, 2
    PokemonReturn                       BATTLER_ENEMY_SLOT_1
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, 2, 8
    IfMonData                           EQUAL, BATTLER_ENEMY_SLOT_2, BATTLE_MON_HP, 0, 2
    PokemonReturn                       BATTLER_ENEMY_SLOT_2
    Wait                                
    HPGaugeSlideOut                     BATTLER_ENEMY
    Wait                                
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_1, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_1, TRAINER_MESSAGE_WIN
    Wait                                
    WaitTime                            30
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, 8, 15
    TrainerSlideOut                     10
    Wait                                
    TrainerSlideIn                      BATTLER_ENEMY_SLOT_2, POS_SINGLES_ENEMY
    Wait                                
    TrainerMessage                      BATTLER_ENEMY_SLOT_2, TRAINER_MESSAGE_WIN
    Wait                                
    WaitTime                            60
    Branch                              2
    WaitTime                            30
    SetBattleResult                     
    FadeOut                             
    Wait                                
    End                                 

.close