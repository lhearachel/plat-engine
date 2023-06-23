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


.create "build/battle/scr/effscr/be_seq_007.bin", 0

// Self-Destruct
effscr_007:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_ALL, ABILITY_DAMP, effscr_007_Failure
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_SELF_DESTRUCTING, effscr_007_Damage
    SetVar                              OP_SET, VAR_CALC_WORK, SERVER_STATUS_FLAG_SELF_DESTRUCT
    SetVarFromVar                       OP_LSH, VAR_CALC_WORK, VAR_ATTACKER
    SetVarFromVar                       OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_HP, 0
    SetVar                              OP_SET, VAR_HP_TEMP, 0x7FFF
    UpdateHPGauge                       BATTLER_ATTACKER
    Wait                                
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION

effscr_007_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

// Failure handler due to, e.g., Damp switching mid-turn
effscr_007_Failure:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "{0}'s {1} prevents {2} from using {3}!"
    Message                             628, TAG_NICK_ABILITY_NICK_MOVE, BATTLER_ABILITYSRC, BATTLER_ABILITYSRC, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_NO_DOUBLE_CHECK
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close