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


.create "build/battle/scr/subscr/sub_seq_101.bin", 0

// SUBSCR_START_PERISH_SONG
subscr_101:
    TryPerishSong                       subscr_101_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // "All Pokemon hearing the song will faint in three turns!"
    Message                             822, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_PERISH_SONG
    SetVar                              OP_SET, VAR_ABILITY_TEMP, ABILITY_SOUNDPROOF
    // Get the fastest battler in play
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
// Loop through the battlers by their speed values
subscr_101_SoundproofLoop:
    GetBattlerBySpeedOrder              VAR_BATTLER_WORK
    MoldBreakerAbilityCheck             MODE_NOT_HAVE, BATTLER_WORKING, ABILITY_SOUNDPROOF, subscr_101_AfterSoundproof
    // "{0}'s {1} blocks {2}!"
    Message                             689, TAG_NICK_ABILITY_MOVE, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_101_AfterSoundproof:
    // Get the next battler
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    // Jump backwards if that battler is valid
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, subscr_101_SoundproofLoop
    End                                 

subscr_101_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close