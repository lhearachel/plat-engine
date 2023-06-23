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


.create "build/battle/scr/subscr/sub_seq_154.bin", 0

// SUBSCR_ROOST
subscr_154:
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 2
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    AttackMessage                       
    Wait                                
    CallSubscript                       SUBSCR_RECOVER_HP
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE, subscr_154_Exit
    SetOneTurnFlag                      BATTLER_ATTACKER, ONE_TURN_FLAG_ROOSTING, 1
subscr_154_Exit:
    End                                 

.close