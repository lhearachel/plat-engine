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


.create "build/battle/scr/effscr/be_seq_180.bin", 0

// Assist
effscr_180:
    TryAssist                           effscr_180_NoPartyMembers
    AttackMessage                       
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    JumpToMoveScript                    

effscr_180_NoPartyMembers:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close