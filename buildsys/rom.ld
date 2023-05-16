/* global.h */
GF_RAND = 0x0201D2E8 | 1;
Free = 0x020181C4 | 1;
Malloc = 0x02018144 | 1;

/* archive.h */
LoadFromNARC = 0x02006AA4 | 1;
LoadFromNARC_Malloc = 0x02006AC0 | 1;
LoadFromNARC_Offset = 0x02006AFC | 1;
LoadFromNARC_OffsetAndMalloc = 0x02006B18 | 1;

/* pokemon.h */
BoxPokemon_Get = 0x02074570 | 1;
BoxPokemon_Set = 0x02074C60 | 1;
BoxPokemon_Lock = 0x02073D20 | 1;
BoxPokemon_Unlock = 0x02073D48 | 1;
Pokemon_Get = 0x02074470 | 1;
Pokemon_CalcGender = 0x02075D6C | 1;
Pokemon_CalcNature = 0x02075BCC | 1;
Pokemon_CalcShiny = 0x02075E0C | 1;
Pokemon_CalcExpForLevel = 0x02075AD0 | 1;
Pokemon_CalcFlavorAffinity = 0x0207762C | 1;
Pokemon_CheckPokerusImmune = 0x020778F8 | 1;
Pokemon_CheckPokerus = 0x020778D8 | 1;
Pokemon_Lock = 0x02073C88 | 1;
Pokemon_Unlock = 0x02073CD4 | 1;
PokemonBaseStats_Get = 0x020759F0 | 1;
PokemonBaseStats_GetWithForm = 0x020759CC | 1;
Form_GetTrueSpecies = 0x02078740 | 1;

/* ui/summary.h */
Summary_PickStatusIcon = 0x0208E9F0 | 1;
Summary_SetPokemonData = 0x0208D200 | 1;
Summary_GetPokemonData = 0x0208DD48 | 1;
Summary_NumberToString = 0x02090184 | 1;
Summary_PrintString = 0x020900D8 | 1;
Summary_PrintCurrentOverMax = 0x020901D0 | 1;

/* ui/window.h */
Window_FillWithColor = 0x0201ADA4 | 1;
Window_ToVRAM = 0x0201A9A4 | 1;