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


.create "build/battle/scr/subscr/sub_seq_069.bin", 0

// SUBSCR_LEECH_SEED_DAMAGE
subscr_069:
    SetStatusEffectMulti                BATTLER_ATTACKER_WORK, BATTLER_DEFENDER_WORK, STATUS_DAMAGE_LEECH_SEED
    Wait                                
    // Compute damage dealt to the defender
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER_WORK, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 8
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER_WORK
    CallSubscript                       SUBSCR_HP_CHANGE
    // Compute damage healed by the attacker
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_HIT_DAMAGE
    // Check for Big Root
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER_WORK, HOLD_EFFECT_BOOST_LEECHING, subscr_069_HealSapper
    GetItemPower                        BATTLER_ATTACKER_WORK, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
subscr_069_HealSapper:
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER_WORK
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    // Check for Liquid Ooze
    CheckAbility                        MODE_HAVE, BATTLER_DEFENDER_WORK, ABILITY_LIQUID_OOZE, subscr_069_LiquidOoze
    // Check for Heal Block
    IfMonData                           NOT_EQUAL, BATTLER_WORKING, BATTLE_MON_HEAL_BLOCK_TURNS, 0, subscr_069_HealBlockActive
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0}'s health is sapped by Leech Seed!"
    Message                             296, TAG_NICK, BATTLER_DEFENDER_WORK, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_069_HealBlockActive:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_HEAL_BLOCK
    // "{0} was prevented from healing due to {1}!"
    Message                             1054, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_069_LiquidOoze:
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER_WORK, ABILITY_MAGIC_GUARD, subscr_069_LiquidOoze_MagicGuard
    CallSubscript                       SUBSCR_HP_CHANGE
    // "It sucked up the liquid ooze!"
    Message                             720, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_069_LiquidOoze_MagicGuard:
    // "It sucked up the liquid ooze!"
    Message                             720, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // "{0}'s {1} suppressed {2}'s {3}!"
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_ATTACKER_WORK, BATTLER_ATTACKER_WORK, BATTLER_DEFENDER_WORK, BATTLER_DEFENDER_WORK, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close