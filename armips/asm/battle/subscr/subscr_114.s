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


.create "build/battle/scr/subscr/sub_seq_114.bin", 0

// SUBSCR_BATON_PASS
subscr_114:
    // Try to make the switch (opening the party menu)
    TrySwitchInMon                      BATTLER_ATTACKER, 1, subscr_114_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    TryNaturalCure                      BATTLER_ATTACKER, subscr_114_DoSwitch
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
subscr_114_DoSwitch:
    PokemonDelete                       BATTLER_ATTACKER
    Wait                                
    HPGaugeSlideOut                     BATTLER_ATTACKER
    Wait                                
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_BATON_PASS
    JumpTo                              SUBSCR_PARTY_LIST

subscr_114_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close