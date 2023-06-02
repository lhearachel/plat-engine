.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_279.s", 0

subscr_279:
    SetVarFromVar                       OP_GET, VAR_ATTACKER, VAR_ATTACKER_TEMP
    SetVarFromVar                       OP_GET, VAR_DEFENDER, VAR_DEFENDER_TEMP
    End                                 
