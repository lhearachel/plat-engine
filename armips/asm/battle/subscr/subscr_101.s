.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_101.bin", 0

subscr_101:
    TryPerishSong                       44
    JumpToSubscript                     76
    Message                             822, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET, VAR_MOVE_TEMP, 195
    SetVar                              OP_SET, VAR_ABILITY_TEMP, 43
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
    GetBattlerBySpeedOrder              VAR_BATTLER_WORK
    MoldBreakerAbilityCheck             MODE_NOT_HAVE, BATTLER_WORKING, ABILITY_SOUNDPROOF, 9
    Message                             689, TAG_NICK_ABILITY_MOVE, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, 4294967273
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close