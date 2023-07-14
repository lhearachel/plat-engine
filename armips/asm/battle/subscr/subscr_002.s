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


.create "build/battle/scr/subscr/sub_seq_002.bin", 0

// SUBSCR_HP_CHANGE
subscr_002:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK, subscr_002_NoBlink
    PlayMoveSoundEffect                 BATTLER_WORKING
    FlickerMon                          BATTLER_WORKING
    Wait                                
subscr_002_NoBlink:
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    UpdateHPGauge                       BATTLER_WORKING
    Wait                                
    UpdateHP                            BATTLER_WORKING
    TryFaintMon                         BATTLER_WORKING
    If                                  GREATER, VAR_HP_TEMP, 0, subscr_002_End
    SetVarFromVar                       OP_SET, VAR_ATTACKER_ASSURANCE_DAMAGE, VAR_HP_TEMP
subscr_002_End:
    End                                 

.close