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


.create "build/battle/scr/subscr/sub_seq_000.bin", 0

// SUBSCR_START_BATTLE
//
// This is the generic battle-start sequence. It determines what sort of battle
// to load based on the input parameters, then delegates to an appropriate
// routine.
subscr_000:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TRAINER, subscr_000_TrainerEncounter
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_SAFARI, subscr_000_SafariEncounter
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_PAL_PARK, subscr_000_PalParkEncounter
subscr_000_WildEncounter:
    SetPokemonForEncounter              BATTLER_ENEMY
    SetTrainersForEncounter             BATTLER_ME
    SetEncounterEffects                 
    WaitFrames                          122
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, BATTLE_STATUS_DISTORTION, subscr_000_DistortionEncounter
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, BATTLE_STATUS_LEGENDARY, subscr_000_LegendaryEncounter
    // this line below is a hold-over from Diamond/Pearl
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, BATTLE_STATUS_FIRST_BATTLE, subscr_000_FirstEncounter
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, BATTLE_STATUS_HONEY_TREE, subscr_000_HoneyTreeEncounter
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_DOUBLES, subscr_000_DoubleWildEncounter
subscr_000_GenericWildEncounter:
    MessageNoBattler                    965, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_000_ShowStartMessage
subscr_000_FirstEncounter:
    MessageNoBattler                    1167, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_000_ShowStartMessage
subscr_000_HoneyTreeEncounter:
    MessageNoBattler                    968, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_000_ShowStartMessage
subscr_000_LegendaryEncounter:
    MessageNoBattler                    1246, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_000_ShowStartMessage
subscr_000_DistortionEncounter:
    MessageNoBattler                    1268, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_000_ShowStartMessage
subscr_000_DoubleWildEncounter:
    MessageNoBattler                    967, TAG_NICK_NICK, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_2, NaN, NaN, NaN, NaN
subscr_000_ShowStartMessage:
    Wait                                
    WaitTime                            30
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_2vs2, subscr_000_ShowTagStartMessage
    Message                             979, TAG_NICK, BATTLER_ME, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_000_StartWildBattle
subscr_000_ShowTagStartMessage:
    EncounterSendOutMessage             BATTLER_ME
subscr_000_StartWildBattle:
    SpriteToOAM                         BATTLER_ENEMY
    Wait                                
    Throw                               BATTLER_ME, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ME
    WaitFrames                          96
    HPGaugeSlideWait                    BATTLER_ME
    Wait                                
    OAMToSprite                         BATTLER_ENEMY
    Wait                                
    Branch                              subscr_000_Cleanup

subscr_000_TrainerEncounter:
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, BATTLE_STATUS_RECORDED_CHILD, subscr_000_TrainerReverse
    SetEncounterEffects                 
    SetTrainersForEncounter             BATTLER_ALL
    WaitFrames                          96
    LoadBallGaugeGraphics               
    ShowStartBallGauge                  BATTLER_ENEMY
    ShowStartBallGauge                  BATTLER_ME
    EncounterStartMessage               BATTLER_ENEMY
    Wait                                
    WaitTime                            30
// enemy trainer sends out their Pokemon
    EncounterSendOutMessage             BATTLER_ENEMY
    HideStartBallGauge                  BATTLER_ENEMY
    Throw                               BATTLER_ENEMY, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ENEMY
    WaitFrames                          112
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
// player trainer sends out their Pokemon
    EncounterSendOutMessage             BATTLER_ME
    HideStartBallGauge                  BATTLER_ME
    Throw                               BATTLER_ME, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ME
    WaitFrames                          96
    HPGaugeSlideWait                    BATTLER_ME
    Wait                                
    FreeBallGaugeGraphics               
    Branch                              subscr_000_Cleanup

subscr_000_TrainerReverse:
    SetEncounterEffects                 
    SetTrainersForEncounter             BATTLER_ALL
    WaitFrames                          96
    LoadBallGaugeGraphics               
    ShowStartBallGauge                  BATTLER_ENEMY
    ShowStartBallGauge                  BATTLER_ME
    EncounterStartMessage               BATTLER_ENEMY
    Wait                                
    WaitTime                            30
// player trainer sends out their Pokemon
    EncounterSendOutMessage             BATTLER_ME
    HideStartBallGauge                  BATTLER_ME
    Throw                               BATTLER_ME, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ME
    WaitFrames                          96
    HPGaugeSlideWait                    BATTLER_ME
    Wait                                
// enemy trainer sends out their Pokemon
    EncounterSendOutMessage             BATTLER_ENEMY
    HideStartBallGauge                  BATTLER_ENEMY
    Throw                               BATTLER_ENEMY, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ENEMY
    WaitFrames                          112
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    FreeBallGaugeGraphics               
    Branch                              subscr_000_Cleanup

subscr_000_SafariEncounter:
    SetPokemonForEncounter              BATTLER_ENEMY
    SetTrainersForEncounter             BATTLER_ME
    SetEncounterEffects                 
    WaitFrames                          122
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    MessageNoBattler                    965, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Wait                                
    HPGaugeSlideIn                      BATTLER_ME
    WaitTime                            7
    Wait                                
    Branch                              subscr_000_Cleanup

subscr_000_PalParkEncounter:
    SetPokemonForEncounter              BATTLER_ENEMY
    SetTrainersForEncounter             BATTLER_ME
    SetEncounterEffects                 
    WaitFrames                          122
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    MessageNoBattler                    1219, TAG_TRNAME_NICK, BATTLER_ENEMY, BATTLER_ENEMY, NaN, NaN, NaN, NaN
    Wait                                
    HPGaugeSlideIn                      BATTLER_ME
    WaitTime                            7
    Wait                                

subscr_000_Cleanup:
    ChangeBackground                    
    End                                 

.close