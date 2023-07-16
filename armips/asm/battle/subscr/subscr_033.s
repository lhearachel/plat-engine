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


.create "build/battle/scr/subscr/sub_seq_033.bin", 0

// SUBSCR_DREAM_EATER
subscr_033:
    // Check for Heal Block
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_HEAL_BLOCK_TURNS, 0, subscr_033_HealBlockActive
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_HIT_DAMAGE
    // Don't work out any healing if the damage was 0
    If                                  EQUAL, VAR_HP_TEMP, 0, subscr_033_ApplyHealing
    DamageDiv                           VAR_HP_TEMP, 2
    // Check for Big Root
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BIG_ROOT, subscr_033_ApplyHealing
    GetItemPower                        BATTLER_ATTACKER, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
subscr_033_ApplyHealing:
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0}'s dream was eaten!"
    Message                             139, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_033_HealBlockActive:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_HEAL_BLOCK
    // "{0} was prevented from healing due to {1}!"
    Message                             1054, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close