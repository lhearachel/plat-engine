#include "archive.h"
#include "pokemon.h"
#include "sprite.h"

#include "constants/abilities.h"
#include "constants/species.h"

#include "battle/common.h"

extern u32 gFormWord;
extern u32 gPokeData;

struct EncounterInfo {
    u32  trainerID;
    BOOL checkRepel;
    BOOL cannotAvoid;
    u8   level;
    u8   isEgg;
    u8   playerLeadAbility; // Synchronize, Pressure, etc.
    u8   formChance[2];
    u8   unownTableType;
};

// Called from Pokemon_LoadSprite
u8 Form_LoadSprite(struct PokemonSprite *pokeSprite, u16 species, u8 direction, u8 shiny, u8 formNum)
{
    gFormWord = formNum;

    if (!formNum) {
        return FALSE;
    }

    for (unsigned int i = 0; i < NELEMS(gPokemonFormTable); i++) {
        if (species == gPokemonFormTable[i].species && formNum == gPokemonFormTable[i].formNum) {
            pokeSprite->archiveNum = ARCHIVE_POKESPRITE;
            pokeSprite->indexPic   = (gPokemonFormTable[i].target) * 6 + direction;
            pokeSprite->indexPal   = (gPokemonFormTable[i].target) * 6 + 4 + shiny;

            return TRUE;
        }
    }

    return FALSE;
}

// 
BOOL Encounter_AddToWildParty(int partyIdx, struct EncounterInfo *encounterInfo, struct Pokemon *encounter, struct BattleParams *battleParams)
{
    int itemRange = 0;
    if (encounterInfo->isEgg == FALSE && encounterInfo->playerLeadAbility == ABILITY_COMPOUND_EYES) {
        itemRange = 1;
    }

    
}

extern const struct PokemonForm gPokemonFormTable[258] = {
    {
        .species = SPECIES_VENUSAUR,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_VENUSAUR_MEGA,
    },
    {
        .species = SPECIES_CHARIZARD,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_CHARIZARD_MEGA_X,
    },
    {
        .species = SPECIES_CHARIZARD,
        .formNum = 2,
        .reverts = TRUE,
        .target  = SPECIES_CHARIZARD_MEGA_Y,
    },
    {
        .species = SPECIES_BLASTOISE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_BLASTOISE_MEGA,
    },
    {
        .species = SPECIES_BEEDRILL,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_BEEDRILL_MEGA,
    },
    {
        .species = SPECIES_PIDGEOT,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_PIDGEOT_MEGA,
    },
    {
        .species = SPECIES_ALAKAZAM,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_ALAKAZAM_MEGA,
    },
    {
        .species = SPECIES_SLOWBRO,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_SLOWBRO_MEGA,
    },
    {
        .species = SPECIES_GENGAR,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_GENGAR_MEGA,
    },
    {
        .species = SPECIES_KANGASKHAN,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_KANGASKHAN_MEGA,
    },
    {
        .species = SPECIES_PINSIR,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_PINSIR_MEGA,
    },
    {
        .species = SPECIES_GYARADOS,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_GYARADOS_MEGA,
    },
    {
        .species = SPECIES_AERODACTYL,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_AERODACTYL_MEGA,
    },
    {
        .species = SPECIES_MEWTWO,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MEWTWO_MEGA_X,
    },
    {
        .species = SPECIES_MEWTWO,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MEWTWO_MEGA_Y,
    },
    {
        .species = SPECIES_AMPHAROS,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_AMPHAROS_MEGA,
    },
    {
        .species = SPECIES_STEELIX,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_STEELIX_MEGA,
    },
    {
        .species = SPECIES_SCIZOR,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_SCIZOR_MEGA,
    },
    {
        .species = SPECIES_HERACROSS,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_HERACROSS_MEGA,
    },
    {
        .species = SPECIES_HOUNDOOM,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_HOUNDOOM_MEGA,
    },
    {
        .species = SPECIES_TYRANITAR,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_TYRANITAR_MEGA,
    },
    {
        .species = SPECIES_SCEPTILE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_SCEPTILE_MEGA,
    },
    {
        .species = SPECIES_BLAZIKEN,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_BLAZIKEN_MEGA,
    },
    {
        .species = SPECIES_SWAMPERT,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_SWAMPERT_MEGA,
    },
    {
        .species = SPECIES_GARDEVOIR,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_GARDEVOIR_MEGA,
    },
    {
        .species = SPECIES_SABLEYE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_SABLEYE_MEGA,
    },
    {
        .species = SPECIES_MAWILE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MAWILE_MEGA,
    },
    {
        .species = SPECIES_AGGRON,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_AGGRON_MEGA,
    },
    {
        .species = SPECIES_MEDICHAM,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MEDICHAM_MEGA,
    },
    {
        .species = SPECIES_MANECTRIC,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MANECTRIC_MEGA,
    },
    {
        .species = SPECIES_SHARPEDO,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_SHARPEDO_MEGA,
    },
    {
        .species = SPECIES_CAMERUPT,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_CAMERUPT_MEGA,
    },
    {
        .species = SPECIES_ALTARIA,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_ALTARIA_MEGA,
    },
    {
        .species = SPECIES_BANETTE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_BANETTE_MEGA,
    },
    {
        .species = SPECIES_ABSOL,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_ABSOL_MEGA,
    },
    {
        .species = SPECIES_GLALIE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_GLALIE_MEGA,
    },
    {
        .species = SPECIES_SALAMENCE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_SALAMENCE_MEGA,
    },
    {
        .species = SPECIES_METAGROSS,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_METAGROSS_MEGA,
    },
    {
        .species = SPECIES_LATIAS,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_LATIAS_MEGA,
    },
    {
        .species = SPECIES_LATIOS,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_LATIOS_MEGA,
    },
    {
        .species = SPECIES_RAYQUAZA,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_RAYQUAZA_MEGA,
    },
    {
        .species = SPECIES_LOPUNNY,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_LOPUNNY_MEGA,
    },
    {
        .species = SPECIES_GARCHOMP,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_GARCHOMP_MEGA,
    },
    {
        .species = SPECIES_LUCARIO,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_LUCARIO_MEGA,
    },
    {
        .species = SPECIES_ABOMASNOW,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_ABOMASNOW_MEGA,
    },
    {
        .species = SPECIES_GALLADE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_GALLADE_MEGA,
    },
    {
        .species = SPECIES_AUDINO,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_AUDINO_MEGA,
    },
    {
        .species = SPECIES_DIANCIE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_DIANCIE_MEGA,
    },
    {
        .species = SPECIES_KYOGRE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_KYOGRE_PRIMAL,
    },
    {
        .species = SPECIES_GROUDON,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_GROUDON_PRIMAL,
    },

    // ===== Alolan Forms =====
    {
        .species = SPECIES_RATTATA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_RATTATA_ALOLA,
    },
    {
        .species = SPECIES_RATICATE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_RATICATE_ALOLA,
    },
    {
        .species = SPECIES_RAICHU,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_RAICHU_ALOLA,
    },
    {
        .species = SPECIES_SANDSHREW,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SANDSHREW_ALOLA,
    },
    {
        .species = SPECIES_SANDSLASH,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SANDSLASH_ALOLA,
    },
    {
        .species = SPECIES_VULPIX,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_VULPIX_ALOLA,
    },
    {
        .species = SPECIES_NINETALES,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_NINETALES_ALOLA,
    },
    {
        .species = SPECIES_DIGLETT,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_DIGLETT_ALOLA,
    },
    {
        .species = SPECIES_DUGTRIO,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_DUGTRIO_ALOLA,
    },
    {
        .species = SPECIES_MEOWTH,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_MEOWTH_ALOLA,
    },
    {
        .species = SPECIES_PERSIAN,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_PERSIAN_ALOLA,
    },
    {
        .species = SPECIES_GEODUDE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GEODUDE_ALOLA,
    },
    {
        .species = SPECIES_GRAVELER,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GRAVELER_ALOLA,
    },
    {
        .species = SPECIES_GOLEM,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GOLEM_ALOLA,
    },
    {
        .species = SPECIES_GRIMER,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GRIMER_ALOLA,
    },
    {
        .species = SPECIES_MUK,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_MUK_ALOLA,
    },
    {
        .species = SPECIES_EXEGGUTOR,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_EXEGGUTOR_ALOLA,
    },
    {
        .species = SPECIES_MAROWAK,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_MAROWAK_ALOLA,
    },

    // ===== Galarian Forms =====
    {
        .species = SPECIES_MEOWTH,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_MEOWTH_GALAR,
    },
    {
        .species = SPECIES_PONYTA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_PONYTA_GALAR,
    },
    {
        .species = SPECIES_RAPIDASH,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_RAPIDASH_GALAR,
    },
    {
        .species = SPECIES_SLOWPOKE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SLOWPOKE_GALAR,
    },
    {
        .species = SPECIES_SLOWBRO,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SLOWBRO_GALAR,
    },
    {
        .species = SPECIES_FARFETCHD,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_FARFETCHD_GALAR,
    },
    {
        .species = SPECIES_WEEZING,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_WEEZING_GALAR,
    },
    {
        .species = SPECIES_MR_MIME,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_MR_MIME_GALAR,
    },
    {
        .species = SPECIES_ARTICUNO,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ARTICUNO_GALAR,
    },
    {
        .species = SPECIES_ZAPDOS,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZAPDOS_GALAR,
    },
    {
        .species = SPECIES_MOLTRES,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_MOLTRES_GALAR,
    },
    {
        .species = SPECIES_SLOWKING,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SLOWKING_GALAR,
    },
    {
        .species = SPECIES_CORSOLA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_CORSOLA_GALAR,
    },
    {
        .species = SPECIES_ZIGZAGOON,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZIGZAGOON_GALAR,
    },
    {
        .species = SPECIES_LINOONE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_LINOONE_GALAR,
    },
    {
        .species = SPECIES_DARUMAKA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_DARUMAKA_GALAR,
    },
    {
        .species = SPECIES_DARMANITAN,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_DARMANITAN_GALAR,
    },
    {
        .species = SPECIES_YAMASK,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_YAMASK_GALAR,
    },
    {
        .species = SPECIES_STUNFISK,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_STUNFISK_GALAR,
    },

    // ===== Miscellaneous Forms =====
    {
        .species = SPECIES_PIKACHU,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_COSPLAY,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_ROCK_STAR,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_BELLE,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_POP_STAR,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 5,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_PHD,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 6,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_LIBRE,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 7,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_ORIGINAL_CAP,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 8,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_HOENN_CAP,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 9,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_SINNOH_CAP,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 10,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_UNOVA_CAP,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 11,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_KALOS_CAP,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 12,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_ALOLA_CAP,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 13,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_PARTNER_CAP,
    },
    {
        .species = SPECIES_PIKACHU,
        .formNum = 14,
        .reverts = FALSE,
        .target  = SPECIES_PIKACHU_WORLD_CAP,
    },
    {   // The next 4 are only present because they do not have icon support in vanilla Platinum
        .species = SPECIES_CASTFORM,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_CASTFORM_SUNNY,
    },
    {
        .species = SPECIES_CASTFORM,
        .formNum = 2,
        .reverts = TRUE,
        .target  = SPECIES_CASTFORM_RAINY,
    },
    {
        .species = SPECIES_CASTFORM,
        .formNum = 3,
        .reverts = TRUE,
        .target  = SPECIES_CASTFORM_SNOWY,
    },
    {
        .species = SPECIES_CHERRIM,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_CHERRIM_SUNSHINE,
    },
    {
        .species = SPECIES_DIALGA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_DIALGA_ORIGIN,
    },
    {
        .species = SPECIES_PALKIA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_PALKIA_ORIGIN,
    },
    {
        .species = SPECIES_BASCULIN,
        .formNum = 1,
        .reverts = 0,
        .target  = SPECIES_BASCULIN_RED_STRIPED,
    },
    {
        .species = SPECIES_BASCULIN,
        .formNum = 2,
        .reverts = 0,
        .target  = SPECIES_BASCULIN_BLUE_STRIPED,
    },
    {
        .species = SPECIES_DARMANITAN,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_DARMANITAN_ZEN,
    },
    {
        .species = SPECIES_DARMANITAN,
        .formNum = 3,
        .reverts = TRUE,
        .target  = SPECIES_DARMANITAN_GALAR_ZEN,
    },
    {
        .species = SPECIES_DEERLING,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_DEERLING_SUMMER,
    },
    {
        .species = SPECIES_DEERLING,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_DEERLING_AUTUMN,
    },
    {
        .species = SPECIES_DEERLING,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_DEERLING_WINTER,
    },
    {
        .species = SPECIES_SAWSBUCK,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SAWSBUCK_SUMMER,
    },
    {
        .species = SPECIES_SAWSBUCK,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_SAWSBUCK_AUTUMN,
    },
    {
        .species = SPECIES_SAWSBUCK,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_SAWSBUCK_WINTER,
    },
    {
        .species = SPECIES_TORNADUS,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_TORNADUS_THERIAN,
    },
    {
        .species = SPECIES_THUNDURUS,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_THUNDURUS_THERIAN,
    },
    {
        .species = SPECIES_LANDORUS,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_LANDORUS_THERIAN,
    },
    {
        .species = SPECIES_KYUREM,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_KYUREM_WHITE,
    },
    {
        .species = SPECIES_KYUREM,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_KYUREM_BLACK,
    },
    {
        .species = SPECIES_KELDEO,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_KELDEO_RESOLUTE,
    },
    {
        .species = SPECIES_MELOETTA,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MELOETTA_PIROUETTE,
    },
    {
        .species = SPECIES_GENESECT,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GENESECT_DOUSE_DRIVE,
    },
    {
        .species = SPECIES_GENESECT,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_GENESECT_SHOCK_DRIVE,
    },
    {
        .species = SPECIES_GENESECT,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_GENESECT_BURN_DRIVE,
    },
    {
        .species = SPECIES_GENESECT,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_GENESECT_CHILL_DRIVE,
    },
    {
        .species = SPECIES_GRENINJA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GRENINJA_BATTLE_BOND,
    },
    {
        .species = SPECIES_GRENINJA,
        .formNum = 2,
        .reverts = TRUE,
        .target  = SPECIES_GRENINJA_ASH,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_POLAR,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_TUNDRA,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_CONTINENTAL,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_GARDEN,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 5,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_ELEGANT,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 6,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_MEADOW,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 7,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_MODERN,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 8,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_MARINE,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 9,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_ARCHIPELAGO,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 10,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_HIGH_PLAINS,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 11,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_SANDSTORM,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 12,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_RIVER,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 13,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_MONSOON,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 14,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_SAVANNA,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 15,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_SUN,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 16,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_OCEAN,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 17,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_JUNGLE,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 18,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_FANCY,
    },
    {
        .species = SPECIES_VIVILLON,
        .formNum = 19,
        .reverts = FALSE,
        .target  = SPECIES_VIVILLON_POKE_BALL,
    },
    {
        .species = SPECIES_FLABEBE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_FLABEBE_YELLOW_FLOWER,
    },
    {
        .species = SPECIES_FLABEBE,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_FLABEBE_ORANGE_FLOWER,
    },
    {
        .species = SPECIES_FLABEBE,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_FLABEBE_BLUE_FLOWER,
    },
    {
        .species = SPECIES_FLABEBE,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_FLABEBE_WHITE_FLOWER,
    },
    {
        .species = SPECIES_FLOETTE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_FLOETTE_YELLOW_FLOWER,
    },
    {
        .species = SPECIES_FLOETTE,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_FLOETTE_ORANGE_FLOWER,
    },
    {
        .species = SPECIES_FLOETTE,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_FLOETTE_BLUE_FLOWER,
    },
    {
        .species = SPECIES_FLOETTE,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_FLOETTE_WHITE_FLOWER,
    },
    {
        .species = SPECIES_FLOETTE,
        .formNum = 5,
        .reverts = FALSE,
        .target  = SPECIES_FLOETTE_ETERNAL_FLOWER,
    },
    {
        .species = SPECIES_FLORGES,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_FLORGES_YELLOW_FLOWER,
    },
    {
        .species = SPECIES_FLORGES,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_FLORGES_ORANGE_FLOWER,
    },
    {
        .species = SPECIES_FLORGES,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_FLORGES_BLUE_FLOWER,
    },
    {
        .species = SPECIES_FLORGES,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_FLORGES_WHITE_FLOWER,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_HEART,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_STAR,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_DANDY,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_DEBUTANTE,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 5,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_MATRON,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 6,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_DANDY,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 7,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_LA_REINE,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 8,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_KABUKI,
    },
    {
        .species = SPECIES_FURFROU,
        .formNum = 9,
        .reverts = FALSE,
        .target  = SPECIES_FURFROU_PHARAOH,
    },
    {
        .species = SPECIES_AEGISLASH,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_AEGISLASH_BLADE,
    },
    {
        .species = SPECIES_PUMPKABOO,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_PUMPKABOO_SMALL,
    },
    {
        .species = SPECIES_PUMPKABOO,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_PUMPKABOO_LARGE,
    },
    {
        .species = SPECIES_PUMPKABOO,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_PUMPKABOO_SUPER,
    },
    {
        .species = SPECIES_GOURGEIST,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GOURGEIST_SMALL,
    },
    {
        .species = SPECIES_GOURGEIST,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_GOURGEIST_LARGE,
    },
    {
        .species = SPECIES_GOURGEIST,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_GOURGEIST_SUPER,
    },
    {
        .species = SPECIES_XERNEAS,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_XERNEAS_ACTIVE,
    },
    {
        .species = SPECIES_ZYGARDE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZYGARDE_10,
    },
    {
        .species = SPECIES_ZYGARDE,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_ZYGARDE_10_POWER_CONSTRUCT,
    },
    {
        .species = SPECIES_ZYGARDE,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_ZYGARDE_50_POWER_CONSTRUCT,
    },
    {
        .species = SPECIES_ZYGARDE,
        .formNum = 4,
        .reverts = TRUE,
        .target  = SPECIES_ZYGARDE_10_COMPLETE,
    },
    {
        .species = SPECIES_ZYGARDE,
        .formNum = 5,
        .reverts = TRUE,
        .target  = SPECIES_ZYGARDE_50_COMPLETE,
    },
    {
        .species = SPECIES_HOOPA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_HOOPA_UNBOUND,
    },
    {
        .species = SPECIES_ORICORIO,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ORICORIO_POM_POM,
    },
    {
        .species = SPECIES_ORICORIO,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_ORICORIO_PAU,
    },
    {
        .species = SPECIES_ORICORIO,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_ORICORIO_SENSU,
    },
    {
        .species = SPECIES_ROCKRUFF,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ROCKRUFF_OWN_TEMPO,
    },
    {
        .species = SPECIES_LYCANROC,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_LYCANROC_DUSK,
    },
    {
        .species = SPECIES_LYCANROC,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_LYCANROC_MIDNIGHT,
    },
    {
        .species = SPECIES_WISHIWASHI,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_WISHIWASHI_SCHOOL,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MINIOR_ORANGE_METEOR,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 2,
        .reverts = TRUE,
        .target  = SPECIES_MINIOR_YELLOW_METEOR,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 3,
        .reverts = TRUE,
        .target  = SPECIES_MINIOR_GREEN_METEOR,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 4,
        .reverts = TRUE,
        .target  = SPECIES_MINIOR_BLUE_METEOR,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 5,
        .reverts = TRUE,
        .target  = SPECIES_MINIOR_INDIGO_METEOR,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 6,
        .reverts = TRUE,
        .target  = SPECIES_MINIOR_VIOLET_METEOR,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 7,
        .reverts = FALSE,
        .target  = SPECIES_MINIOR_RED,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 8,
        .reverts = FALSE,
        .target  = SPECIES_MINIOR_ORANGE,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 9,
        .reverts = FALSE,
        .target  = SPECIES_MINIOR_YELLOW,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 10,
        .reverts = FALSE,
        .target  = SPECIES_MINIOR_GREEN,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 11,
        .reverts = FALSE,
        .target  = SPECIES_MINIOR_BLUE,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 12,
        .reverts = FALSE,
        .target  = SPECIES_MINIOR_INDIGO,
    },
    {
        .species = SPECIES_MINIOR,
        .formNum = 13,
        .reverts = FALSE,
        .target  = SPECIES_MINIOR_VIOLET,
    },
    {
        .species = SPECIES_MIMIKYU,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MIMIKYU_BUSTED,
    },
    {
        .species = SPECIES_NECROZMA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_NECROZMA_DUSK,
    },
    {
        .species = SPECIES_NECROZMA,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_NECROZMA_DAWN,
    },
    {
        .species = SPECIES_NECROZMA,
        .formNum = 3,
        .reverts = TRUE,
        .target  = SPECIES_NECROZMA_ULTRA_DUSK_MANE,
    },
    {
        .species = SPECIES_NECROZMA,
        .formNum = 4,
        .reverts = TRUE,
        .target  = SPECIES_NECROZMA_ULTRA_DAWN_WINGS,
    },
    {
        .species = SPECIES_MAGEARNA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_MAGEARNA_ORIGINAL,
    },
    {
        .species = SPECIES_CRAMORANT,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_CRAMORANT_GULPING,
    },
    {
        .species = SPECIES_CRAMORANT,
        .formNum = 2,
        .reverts = TRUE,
        .target  = SPECIES_CRAMORANT_GORGING,
    },
    {
        .species = SPECIES_TOXTRICITY,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_TOXTRICITY_LOW_KEY,
    },
    {
        .species = SPECIES_SINISTEA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SINISTEA_ANTIQUE,
    },
    {
        .species = SPECIES_POLTEAGEIST,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_POLTEAGEIST_ANTIQUE,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_BERRY_SWEET,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 3,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_LOVE_SWEET,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 4,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_STAR_SWEET,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 5,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_CLOVER_SWEET,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 6,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_FLOWER_SWEET,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 7,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_RIBBON_SWEET,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 8,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_FILLER_1,
    },
    {
        .species = SPECIES_ALCREMIE,
        .formNum = 9,
        .reverts = FALSE,
        .target  = SPECIES_ALCREMIE_FILLER_2,
    },
    {
        .species = SPECIES_EISCUE,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_EISCUE_NOICE,
    },
    {
        .species = SPECIES_MORPEKO,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_MORPEKO_HANGRY,
    },
    {
        .species = SPECIES_ZACIAN,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZACIAN_CROWNED,
    },
    {
        .species = SPECIES_ZAMAZENTA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZAMAZENTA_CROWNED,
    },
    {
        .species = SPECIES_ETERNATUS,
        .formNum = 1,
        .reverts = TRUE,
        .target  = SPECIES_ETERNATUS_ETERNAMAX,
    },
    {
        .species = SPECIES_URSHIFU,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_URSHIFU_RAPID_STRIKE,
    },
    {
        .species = SPECIES_ZARUDE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZARUDE_DADA,
    },
    {
        .species = SPECIES_CALYREX,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_CALYREX_ICE_RIDER,
    },
    {
        .species = SPECIES_CALYREX,
        .formNum = 2,
        .reverts = FALSE,
        .target  = SPECIES_CALYREX_SHADOW_RIDER,
    },

    // ===== Hisuian Forms =====
    {
        .species = SPECIES_GROWLITHE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GROWLITHE_HISUI,
    },
    {
        .species = SPECIES_ARCANINE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ARCANINE_HISUI,
    },
    {
        .species = SPECIES_VOLTORB,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_VOLTORB_HISUI,
    },
    {
        .species = SPECIES_ELECTRODE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ELECTRODE_HISUI,
    },
    {
        .species = SPECIES_TYPHLOSION,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_TYPHLOSION_HISUI,
    },
    {
        .species = SPECIES_QWILFISH,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_QWILFISH_HISUI,
    },
    {
        .species = SPECIES_SNEASEL,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SNEASEL_HISUI,
    },
    {
        .species = SPECIES_SAMUROTT,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SAMUROTT_HISUI,
    },
    {
        .species = SPECIES_LILLIGANT,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_LILLIGANT_HISUI,
    },
    {
        .species = SPECIES_ZORUA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZORUA_HISUI,
    },
    {
        .species = SPECIES_ZOROARK,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_ZOROARK_HISUI,
    },
    {
        .species = SPECIES_BRAVIARY,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_BRAVIARY_HISUI,
    },
    {
        .species = SPECIES_SLIGGOO,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_SLIGGOO_HISUI,
    },
    {
        .species = SPECIES_GOODRA,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_GOODRA_HISUI,
    },
    {
        .species = SPECIES_AVALUGG,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_AVALUGG_HISUI,
    },
    {
        .species = SPECIES_DECIDUEYE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_DECIDUEYE_HISUI,
    },

    // ===== Significant Gender Variants =====
    {
        .species = SPECIES_UNFEZANT,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_UNFEZANT_FEMALE,
    },
    {
        .species = SPECIES_FRILLISH,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_FRILLISH_FEMALE,
    },
    {
        .species = SPECIES_JELLICENT,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_JELLICENT_FEMALE,
    },
    {
        .species = SPECIES_PYROAR,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_PYROAR_FEMALE,
    },
    {
        .species = SPECIES_MEOWSTIC,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_MEOWSTIC_FEMALE,
    },
    {
        .species = SPECIES_INDEEDEE,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_INDEEDEE_FEMALE,
    },
    {
        .species = SPECIES_BASCULEGION,
        .formNum = 1,
        .reverts = FALSE,
        .target  = SPECIES_BASCULEGION_FEMALE,
    },
};