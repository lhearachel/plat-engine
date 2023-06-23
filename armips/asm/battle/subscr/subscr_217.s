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


.create "build/battle/scr/subscr/sub_seq_217.bin", 0

// SUBSCR_ITEM_POWER_HERB
subscr_217:
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MULTI_TURN_VANISHING, subscr_217_AfterToggle
    ToggleVanish                        BATTLER_ATTACKER, 1
subscr_217_AfterToggle:
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_HELD_ITEM
    Wait                                
    // "{0} became fully charged due to its {1}!"
    Message                             1251, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RemoveItem                          BATTLER_ATTACKER
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    End                                 

.close