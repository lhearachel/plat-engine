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


.create "build/battle/scr/subscr/sub_seq_024.bin", 0

// SUBSCR_DRAIN_HALF
subscr_024:
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_HIT_DAMAGE
    If                                  EQUAL, VAR_HP_TEMP, 0, subscr_023_SkipDivide
    DamageDiv                           VAR_HP_TEMP, 2
subscr_023_SkipDivide:
    // Check for Big Root; increase leeching effect, if so
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BIG_ROOT, subscr_023_NoBigRoot
    GetItemPower                        BATTLER_ATTACKER, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
subscr_023_NoBigRoot:
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    // Handle Liquid Ooze separately
    CheckAbility                        MODE_HAVE, BATTLER_DEFENDER, ABILITY_LIQUID_OOZE, subscr_023_HandleLiquidOoze
    // Ensure Heal Block is not active
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_HEAL_BLOCK_TURNS, 0, subscr_023_HealBlockActive
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} had its energy drained!"
    Message                             82, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_023_HealBlockActive:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_HEAL_BLOCK
    // "{0} was prevented from healing due to {1}!"
    Message                             1054, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End

subscr_023_HandleLiquidOoze:          
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_MAGIC_GUARD, subscr_023_Exit
    CallSubscript                       SUBSCR_HP_CHANGE
    // "It sucked up the liquid ooze!"
    Message                             720, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_023_Exit:
    End                                 

.close