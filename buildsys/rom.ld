/* global.h */
GF_RAND = 0x0201D2E8 | 1;
Free = 0x020181C4 | 1;
Malloc = 0x02018144 | 1;

/* archive.h */
LoadFromNARC = 0x02006AA4 | 1;
LoadFromNARC_Malloc = 0x02006AC0 | 1;
LoadFromNARC_Offset = 0x02006AFC | 1;
LoadFromNARC_OffsetAndMalloc = 0x02006B18 | 1;

/* overlay.h */
FS_SetDefaultDMA = 0x020C84E0 | 1;
Overlay_MemoryRegion = 0x02006544 | 1;
Overlay_Free = 0x020064F0 | 1;
Overlay_CanLoad = 0x02006644 | 1;
Overlay_Load = 0x0200671C | 1;
Overlay_LoadAndStart = 0x02006724 | 1;
Overlay_LoadAndStartAsync = 0x0200675C | 1;
Overlay_LoadedInRegion = 0x020066C0 | 1;

/* pokemon.h */
BoxPokemon_Get = 0x02074570 | 1;
BoxPokemon_Set = 0x02074C60 | 1;
BoxPokemon_Lock = 0x02073D20 | 1;
BoxPokemon_Unlock = 0x02073D48 | 1;
Pokemon_Get = 0x02074470 | 1;
Pokemon_Set = 0x02074B30 | 1;
Pokemon_CalcGender = 0x02075D6C | 1;
Pokemon_CalcNature = 0x02075BCC | 1;
Pokemon_CalcShiny = 0x02075E0C | 1;
Pokemon_CalcExpForLevel = 0x02075AD0 | 1;
Pokemon_CalcFlavorAffinity = 0x0207762C | 1;
Pokemon_CheckPokerusImmune = 0x020778F8 | 1;
Pokemon_CheckPokerus = 0x020778D8 | 1;
Pokemon_RecalcFriendship = 0x02075C74 | 1;
Pokemon_CanBattle = 0x02054884 | 1;
Pokemon_Lock = 0x02073C88 | 1;
Pokemon_Unlock = 0x02073CD4 | 1;
PokemonBaseStats_Get = 0x020759F0 | 1;
PokemonBaseStats_GetWithForm = 0x020759CC | 1;
Form_GetTrueSpecies = 0x02078740 | 1;
Party_Count = 0x02054B04 | 1;

/* sound.h */
Sound_CheckAnySEsPlaying = 0x020057E0 | 1;
Sound_CheckMEPlaying = 0x020061E4 | 1;
Sound_PlaySE = 0x02005748 | 1;
Sound_PlayME = 0x02006150 | 1;

/* battle/client.h */
ClientCommand_Reset = 0x0225CBB0 | 1;
gClientFunctionTable_Old = 0x0226F068;

/* battle/common.h */
Battle_Type = 0x0223DF0C | 1;
Battle_MessageManager = 0x0223E05C | 1;
Battle_Random = 0x0223F4BC | 1;

/* battle/scio.h */
SCIO_Message = 0x02264A04 | 1;
SCIO_ClearQueue = 0x02266ABC | 1;

/* battle/scrcmd.h */
BattleScrCmd_ReadWord = 0x02248AD0 | 1;
gBattleScriptCommandTable_Old = 0x0226E72C;

/* battle/server.h */
Server_Get = 0x0225B45C | 1;
Server_Ability = 0x02255A4C | 1;
Server_CheckActiveMoveEffect = 0x02255F68 | 1;
Server_CheckAbility = 0x022555A4 | 1;
Server_CheckDefenderAbility = 0x02255AB4 | 1;
Server_HeldItemEffect = 0x02258AB8 | 1;
Server_HeldItemPower = 0x02258ACC | 1;
BattlePokemon_Get = 0x02252060 | 1;
gStatModifierTable = 0x0226EBE0;
gCriticalRateTable = 0x0226EBA0;

/* battle/ui.c */
BattleMessage_ExpandTags = 0x0223FDE4 | 1;
BattleMessage_ExpandMessage = 0x02240584 | 1;
CheckStillPrinting = 0x0201D6F8 | 1;

/* ui/battle.h */
Battle_GetClientActorSys = 0x0223E010 | 1;
Battle_GetClientActorRes = 0x0223E018 | 1;
Battle_GetPaletteFade = 0x0223E064 | 1;
PartyGauge_Load = 0x0226D094 | 1;
PartyGauge_Free = 0x0226D12C | 1;

/* ui/common.h */
UI_AddObject = 0x0200CDC4 | 1;
UI_FreeObject = 0x0200D0F4 | 1;
UI_GetObjectPos = 0x0200D550 | 1;
UI_SetObjectPos = 0x0200D4C4 | 1;
UI_SetAnimation = 0x02021D6C | 1;
UI_EnableObject = 0x0200D3EC | 1;
UI_UpdateObject = 0x0200D324 | 1;
UI_SetObjectOAMMode = 0x0200D810 | 1;
TaskControl_Add = 0x0200D9E8 | 1;
TaskControl_Delete = 0x0200DA58 | 1;

/* ui/summary.h */
Summary_PickStatusIcon = 0x0208E9F0 | 1;
Summary_SetPokemonData = 0x0208D200 | 1;
Summary_GetPokemonData = 0x0208DD48 | 1;
Summary_NumberToString = 0x02090184 | 1;
Summary_PrintString = 0x020900D8 | 1;
Summary_PrintCurrentOverMax = 0x020901D0 | 1;

/* ui/window.h */
Window_Add = 0x0201A7E8 | 1;
Window_Delete = 0x0201A8FC | 1;
Window_FillWithColor = 0x0201ADA4 | 1;
Window_ToVRAM = 0x0201A9A4 | 1;
Window_PrintString = 0x0201D738 | 1;
Window_Clear = 0x0200E084 | 1;