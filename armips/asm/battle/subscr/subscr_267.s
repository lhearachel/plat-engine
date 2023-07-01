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


.create "build/battle/scr/subscr/sub_seq_267.bin", 0

// SUBSCR_BAG_HP_RESTORE
subscr_267:
    WaitTime                            15
    PlaySound                           BATTLER_ATTACKER, 1516
    // "{0} {1} used one {2}!"
    Message                             858, TAG_TRTYPE_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RecoverStatus                       BATTLER_ATTACKER
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ITEM_HP_RESTORED, 0, subscr_267_Exit
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_ITEM_HP_RESTORED, VAR_HP_TEMP
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_ITEM_HP_RESTORED, 0
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
subscr_267_Exit:
    End                                 

.close