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


.create "build/battle/scr/subscr/sub_seq_266.bin", 0

// SUBSCR_ITEM_DAMAGE_BACK
subscr_266:
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, subscr_266_AfterAnimation
    SetStatusEffect                     BATTLER_DEFENDER, STATUS_HELD_ITEM
    Wait                                
subscr_266_AfterAnimation:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} is hurt by {1}'s {2}!"
    Message                             1160, TAG_NICK_NICK_ITEM, BATTLER_ATTACKER, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RemoveItem                          BATTLER_DEFENDER
    End                                 

.close