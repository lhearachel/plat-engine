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


.create "build/battle/scr/effscr/be_seq_252.bin", 0

// Magnet Rise
effscr_252:
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_MAGNET_RISE_TURNS, 0, effscr_252_Failure
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_LEVITATE, effscr_252_Failure
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_INGRAINED, effscr_252_Failure
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_MAGNET_RISE
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_MAGNET_RISE_TURNS, 5
    PrepareMessage                      1033, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    End                                 

effscr_252_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close