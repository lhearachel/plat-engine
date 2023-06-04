.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_252.bin", 0

effscr_252:
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_MAGNET_RISE_TURNS, 0, 30
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_LEVITATE, 25
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 1024, 19
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 134217728
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_MAGNET_RISE_TURNS, 5
    PrepareMessage                      1033, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871002
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close