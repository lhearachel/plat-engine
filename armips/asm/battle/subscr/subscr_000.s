.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_0.s", 0

subscr_000:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 1, 114
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 32, 206
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 512, 223
    SetPokemonForEncounter              BATTLER_ENEMY
    SetTrainersForEncounter             BATTLER_ME
    SetEncounterEffects                 
    WaitFrames                          122
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, 128, 44
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, 8, 33
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, 1, 16
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, 2, 17
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 2, 30
    MessageNoBattler                    965, TAG_NICK, BATTLER_ENEMY
    Jump                                29
    MessageNoBattler                    1167, TAG_NICK, BATTLER_ENEMY
    Jump                                23
    MessageNoBattler                    968, TAG_NICK, BATTLER_ENEMY
    Jump                                17
    MessageNoBattler                    1246, TAG_NICK, BATTLER_ENEMY
    Jump                                11
    MessageNoBattler                    1268, TAG_NICK, BATTLER_ENEMY
    Jump                                5
    MessageNoBattler                    967, TAG_NICK_NICK, BATTLER_ENEMY_SLOT_1, BATTLER_ENEMY_SLOT_2
    Wait                                
    WaitFrames                          30
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 8, 6
    Message                             979, TAG_NICK, BATTLER_ME
    Jump                                2
    EncounterSendOutMessage             BATTLER_ME
    SpriteToOAM                         BATTLER_ENEMY
    Wait                                
    Throw                               BATTLER_ME, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ME
    WaitFrames                          96
    HPGaugeSlideWait                    BATTLER_ME
    Wait                                
    OAMToSprite                         BATTLER_ENEMY
    Wait                                
    Jump                                140
    If                                  FLAG_EQ, VAR_BATTLE_STATUS_FLAG, 32, 46
    SetEncounterEffects                 
    SetTrainersForEncounter             BATTLER_ALL
    WaitFrames                          96
    LoadBallGaugeGraphics               
    ShowStartBallGauge                  BATTLER_ENEMY
    ShowStartBallGauge                  BATTLER_ME
    EncounterStartMessage               BATTLER_ENEMY
    Wait                                
    WaitFrames                          30
    EncounterSendOutMessage             BATTLER_ENEMY
    HideStartBallGauge                  BATTLER_ENEMY
    Throw                               BATTLER_ENEMY, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ENEMY
    WaitFrames                          112
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    EncounterSendOutMessage             BATTLER_ME
    HideStartBallGauge                  BATTLER_ME
    Throw                               BATTLER_ME, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ME
    WaitFrames                          96
    HPGaugeSlideWait                    BATTLER_ME
    Wait                                
    FreeBallGaugeGraphics               
    Jump                                89
    SetEncounterEffects                 
    SetTrainersForEncounter             BATTLER_ALL
    WaitFrames                          96
    LoadBallGaugeGraphics               
    ShowStartBallGauge                  BATTLER_ENEMY
    ShowStartBallGauge                  BATTLER_ME
    EncounterStartMessage               BATTLER_ENEMY
    Wait                                
    WaitFrames                          30
    EncounterSendOutMessage             BATTLER_ME
    HideStartBallGauge                  BATTLER_ME
    Throw                               BATTLER_ME, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ME
    WaitFrames                          96
    HPGaugeSlideWait                    BATTLER_ME
    Wait                                
    EncounterSendOutMessage             BATTLER_ENEMY
    HideStartBallGauge                  BATTLER_ENEMY
    Throw                               BATTLER_ENEMY, THROW_POKE_BALL
    PokemonSlideIn                      BATTLER_ENEMY
    WaitFrames                          112
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    FreeBallGaugeGraphics               
    Jump                                43
    SetPokemonForEncounter              BATTLER_ENEMY
    SetTrainersForEncounter             BATTLER_ME
    SetEncounterEffects                 
    WaitFrames                          122
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    MessageNoBattler                    965, TAG_NICK, BATTLER_ENEMY
    Wait                                
    HPGaugeSlideIn                      BATTLER_ME
    WaitFrames                          7
    Wait                                
    Jump                                21
    SetPokemonForEncounter              BATTLER_ENEMY
    SetTrainersForEncounter             BATTLER_ME
    SetEncounterEffects                 
    WaitFrames                          122
    HPGaugeSlideWait                    BATTLER_ENEMY
    Wait                                
    MessageNoBattler                    1219, TAG_TRNAME_NICK, BATTLER_ENEMY, BATTLER_ENEMY
    Wait                                
    HPGaugeSlideIn                      BATTLER_ME
    WaitFrames                          7
    Wait                                
    ChangeBackground                    
    End                                 
