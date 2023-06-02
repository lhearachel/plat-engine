.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_280.s", 0

subscr_280:
    SetVarFromVar                       OP_GET, VAR_ATTACKER_TEMP, VAR_ATTACKER
    SetVarFromVar                       OP_GET, VAR_DEFENDER_TEMP, VAR_DEFENDER
    End                                 
