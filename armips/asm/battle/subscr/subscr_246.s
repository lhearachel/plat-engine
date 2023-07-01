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


.create "build/battle/scr/subscr/sub_seq_246.bin", 0

// SUBSCR_RECOIL_1_2
subscr_246:
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_ROCK_HEAD, subscr_246_Exit
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_MAGIC_GUARD, subscr_246_Exit
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_HIT_DAMAGE
    If                                  EQUAL, VAR_HP_TEMP, 0, subscr_246_Damage
    DamageDiv                           VAR_HP_TEMP, 2
subscr_246_Damage:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} is hit with recoil!"
    Message                             279, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_246_Exit:
    End                                 

.close