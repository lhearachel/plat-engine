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


.create "build/battle/scr/subscr/sub_seq_120.bin", 0

// SUBSCR_BELLY_DRUM
subscr_120:
    // Quit out if attack is already maxed
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ATK_STAGE, 12, subscr_120_Failure
    // Ensure we have enough HP to use Belly Drum (over half of maximum)
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 2
    JumpIfMonData                       LESSER, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_HP_TEMP, subscr_120_Failure
    // Execute
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_ATK_STAGE, 12
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_STAT_BOOST
    Wait                                
    // "{0} cut its own HP and maximized its attack!"
    Message                             449, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_120_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close