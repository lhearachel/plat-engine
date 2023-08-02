from scripts.build.util import Species

'''
    This table is only meant to be used to map Species values to
    appropriate base species + form number combinations for
    compatibility with the evotable data NARC. It is, thus, limited
    in scope compared to the full set of forms.
'''
FORM_TABLE = {
    'RATICATE_ALOLA': (Species.RATICATE, 1),

    'RAICHU_ALOLA': (Species.RAICHU, 1),

    'SANDSLASH_ALOLA': (Species.SANDSLASH, 1),

    'NINETALES_ALOLA': (Species.NINETALES, 1),

    'DUGTRIO_ALOLA': (Species.DUGTRIO, 1),

    'PERSIAN_ALOLA': (Species.PERSIAN, 1),

    'GRAVELER_ALOLA': (Species.GRAVELER, 1),
    'GOLEM_ALOLA': (Species.GOLEM, 1),

    'MUK_ALOLA': (Species.MUK, 1),

    'EXEGGUTOR_ALOLA': (Species.EXEGGUTOR, 1),

    'MAROWAK_ALOLA': (Species.MAROWAK, 1),

    'RAPIDASH_GALAR': (Species.RAPIDASH, 1),

    'SLOWBRO_GALAR': (Species.SLOWBRO, 1),    # form 2 is mega

    'WEEZING_GALAR': (Species.WEEZING, 1),

    'MR_MIME_GALAR': (Species.MR_MIME, 1),

    'SLOWKING_GALAR': (Species.SLOWKING, 1),

    'LINOONE_GALAR': (Species.LINOONE, 1),

    'DARMANITAN_GALAR': (Species.DARMANITAN, 2),

    'GASTRODON_EAST_SEA': (Species.GASTRODON, 1), # not actually used, but here anyways

    'SAWSBUCK_SUMMER': (Species.SAWSBUCK, 1),
    'SAWSBUCK_AUTUMN': (Species.SAWSBUCK, 2),
    'SAWSBUCK_WINTER': (Species.SAWSBUCK, 3),

    'FLOETTE_YELLOW_FLOWER': (Species.FLOETTE, 1),
    'FLOETTE_ORANGE_FLOWER': (Species.FLOETTE, 2),
    'FLOETTE_BLUE_FLOWER': (Species.FLOETTE, 3),
    'FLOETTE_WHITE_FLOWER': (Species.FLOETTE, 4),

    'FLORGES_YELLOW_FLOWER': (Species.FLORGES, 1),
    'FLORGES_ORANGE_FLOWER': (Species.FLORGES, 2),
    'FLORGES_BLUE_FLOWER': (Species.FLORGES, 3),
    'FLORGES_WHITE_FLOWER': (Species.FLORGES, 4),

    'GOURGEIST_SMALL': (Species.GOURGEIST, 1),
    'GOURGEIST_LARGE': (Species.GOURGEIST, 2),
    'GOURGEIST_SUPER': (Species.GOURGEIST, 3),

    'LYCANROC_DUSK': (Species.LYCANROC, 1),   # match up with Lycanroc-Own-Tempo
    'LYCANROC_MIDNIGHT': (Species.LYCANROC, 2),

    'POLTEAGEIST_ANTIQUE': (Species.POLTEAGEIST, 1),

    'ALCREMIE_BERRY_SWEET': (Species.ALCREMIE, 1),
    'ALCREMIE_LOVE_SWEET': (Species.ALCREMIE, 2),
    'ALCREMIE_STAR_SWEET': (Species.ALCREMIE, 3),
    'ALCREMIE_CLOVER_SWEET': (Species.ALCREMIE, 4),
    'ALCREMIE_FLOWER_SWEET': (Species.ALCREMIE, 5),
    'ALCREMIE_RIBBON_SWEET': (Species.ALCREMIE, 6),
    'ALCREMIE_FILLER_1': (Species.ALCREMIE, 7),
    'ALCREMIE_FILLER_2': (Species.ALCREMIE, 8),

    'TOXTRICITY_LOW_KEY': (Species.TOXTRICITY, 1),

    'URSHIFU_RAPID_STRIKE': (Species.URSHIFU, 1),

    'ARCANINE_HISUI': (Species.ARCANINE, 1),

    'ELECTRODE_HISUI': (Species.ELECTRODE, 1),

    'TYPHLOSION_HISUI': (Species.TYPHLOSION, 1),

    'SAMUROTT_HISUI': (Species.SAMUROTT, 1),

    'LILLIGANT_HISUI': (Species.LILLIGANT, 1),

    'ZOROARK_HISUI': (Species.ZOROARK, 1),

    'BRAVIARY_HISUI': (Species.BRAVIARY, 1),

    'SLIGGOO_HISUI': (Species.SLIGGOO, 1),
    'GOODRA_HISUI': (Species.GOODRA, 1),

    'AVALUGG_HISUI': (Species.AVALUGG, 1),

    'DECIDUEYE_HISUI': (Species.DECIDUEYE, 1),

    'UNFEZANT_FEMALE': (Species.UNFEZANT, 1),

    'JELLICENT_FEMALE': (Species.JELLICENT, 1),

    'PYROAR_FEMALE': (Species.PYROAR, 1),

    'MEOWSTIC_FEMALE': (Species.MEOWSTIC, 1),

    'INDEEDEE_FEMALE': (Species.INDEEDEE, 1),

    'BASCULEGION_FEMALE': (Species.BASCULEGION, 3),   # need to keep room for forms 1 and 2 of basculin
}