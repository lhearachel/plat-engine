.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_178.s", 0

effscr_178:
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_MULTITYPE, 11
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2415919215
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
