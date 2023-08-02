from scripts.build.util import Species

'''
    This table is only meant to be used to map Species values to
    appropriate base species + form number combinations for
    compatibility with the evotable data NARC. It is, thus, limited
    in scope compared to the full set of forms.
'''
FORM_TABLE = {
    Species.RATICATE_ALOLA: (Species.RATICATE, 1),

    Species.SANDSLASH_ALOLA: (Species.SANDSLASH, 1),

    Species.NINETALES_ALOLA: (Species.NINETALES, 1),

    Species.DUGTRIO_ALOLA: (Species.DUGTRIO, 1),

    Species.PERSIAN_ALOLA: (Species.PERSIAN, 1),

    Species.GRAVELER_ALOLA: (Species.GRAVELER, 1),
    Species.GOLEM_ALOLA: (Species.GOLEM, 1),

    Species.MUK_ALOLA: (Species.MUK, 1),

    Species.EXEGGUTOR_ALOLA: (Species.EXEGGUTOR, 1),

    Species.MAROWAK_ALOLA: (Species.MAROWAK, 1),

    Species.RAPIDASH_GALAR: (Species.RAPIDASH, 1),

    Species.SLOWBRO_GALAR: (Species.SLOWBRO, 1),    # form 2 is mega

    Species.WEEZING_GALAR: (Species.WEEZING, 1),

    Species.MR_MIME_GALAR: (Species.MR_MIME, 1),

    Species.SLOWKING_GALAR: (Species.SLOWKING, 1),

    Species.LINOONE_GALAR: (Species.LINOONE, 1),

    Species.DARMANITAN_GALAR: (Species.DARMANITAN, 2),

    Species.GASTRODON_EAST_SEA: (Species.GASTRODON, 1), # not actually used, but here anyways

    Species.SAWSBUCK_SUMMER: (Species.SAWSBUCK, 1),
    Species.SAWSBUCK_AUTUMN: (Species.SAWSBUCK, 2),
    Species.SAWSBUCK_WINTER: (Species.SAWSBUCK, 3),

    Species.FLOETTE_YELLOW_FLOWER: (Species.FLOETTE, 1),
    Species.FLOETTE_ORANGE_FLOWER: (Species.FLOETTE, 2),
    Species.FLOETTE_BLUE_FLOWER: (Species.FLOETTE, 3),
    Species.FLOETTE_WHITE_FLOWER: (Species.FLOETTE, 4),

    Species.FLORGES_YELLOW_FLOWER: (Species.FLORGES, 1),
    Species.FLORGES_ORANGE_FLOWER: (Species.FLORGES, 2),
    Species.FLORGES_BLUE_FLOWER: (Species.FLORGES, 3),
    Species.FLORGES_WHITE_FLOWER: (Species.FLORGES, 4),

    Species.GOURGEIST_SMALL: (Species.GOURGEIST, 1),
    Species.GOURGEIST_LARGE: (Species.GOURGEIST, 2),
    Species.GOURGEIST_SUPER: (Species.GOURGEIST, 3),

    Species.LYCANROC_DUSK: (Species.LYCANROC, 1),   # match up with Lycanroc-Own-Tempo
    Species.LYCANROC_MIDNIGHT: (Species.LYCANROC, 2),

    Species.POLTEAGEIST_ANTIQUE: (Species.POLTEAGEIST, 1),

    Species.ALCREMIE_BERRY_SWEET: (Species.ALCREMIE, 1),
    Species.ALCREMIE_LOVE_SWEET: (Species.ALCREMIE, 2),
    Species.ALCREMIE_STAR_SWEET: (Species.ALCREMIE, 3),
    Species.ALCREMIE_CLOVER_SWEET: (Species.ALCREMIE, 4),
    Species.ALCREMIE_FLOWER_SWEET: (Species.ALCREMIE, 5),
    Species.ALCREMIE_RIBBON_SWEET: (Species.ALCREMIE, 6),
    Species.ALCREMIE_FILLER_1: (Species.ALCREMIE, 7),
    Species.ALCREMIE_FILLER_2: (Species.ALCREMIE, 8),

    Species.URSHIFU_RAPID_STRIKE: (Species.URSHIFU, 1),

    Species.ARCANINE_HISUI: (Species.ARCANINE, 1),

    Species.ELECTRODE_HISUI: (Species.ELECTRODE, 1),

    Species.TYPHLOSION_HISUI: (Species.TYPHLOSION, 1),

    Species.SAMUROTT_HISUI: (Species.SAMUROTT, 1),

    Species.LILLIGANT_HISUI: (Species.LILLIGANT, 1),

    Species.ZOROARK_HISUI: (Species.ZOROARK, 1),

    Species.BRAVIARY_HISUI: (Species.BRAVIARY, 1),

    Species.SLIGGOO_HISUI: (Species.SLIGGOO, 1),
    Species.GOODRA_HISUI: (Species.GOODRA, 1),

    Species.AVALUGG_HISUI: (Species.AVALUGG, 1),

    Species.DECIDUEYE_HISUI: (Species.DECIDUEYE, 1),

    Species.UNFEZANT_FEMALE: (Species.UNFEZANT, 1),

    Species.JELLICENT_FEMALE: (Species.JELLICENT, 1),

    Species.PYROAR_FEMALE: (Species.PYROAR, 1),

    Species.MEOWSTIC_FEMALE: (Species.MEOWSTIC, 1),

    Species.INDEEDEE_FEMALE: (Species.INDEEDEE, 1),

    Species.BASCULEGION_FEMALE: (Species.BASCULEGION, 3),   # need to keep room for forms 1 and 2 of basculin
}