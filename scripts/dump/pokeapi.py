import json
import os
import re
import requests
import shutil

from scripts.build.util import GenderRatio, GrowthRate, EggGroup, BodyColor, Move, EvoMethod, Species


POKEMON_DATA_DIR = 'data/pokemon'


GENDER_RATIOS = {
    -1: GenderRatio.NO_GENDER,
    0: GenderRatio.MALE_ONLY,
    1: GenderRatio.FEMALE_12_5,
    2: GenderRatio.FEMALE_25,
    4: GenderRatio.FEMALE_50,
    6: GenderRatio.FEMALE_75,
    7: GenderRatio.FEMALE_87_5,
    8: GenderRatio.FEMALE_ONLY
}

EGG_GROUPS = {
    'monster': EggGroup.MONSTER,
    'water1': EggGroup.WATER_1,
    'bug': EggGroup.BUG,
    'flying': EggGroup.FLYING,
    'ground': EggGroup.FIELD,
    'fairy': EggGroup.FAIRY,
    'plant': EggGroup.GRASS,
    'humanshape': EggGroup.HUMAN_LIKE,
    'water3': EggGroup.WATER_3,
    'mineral': EggGroup.MINERAL,
    'indeterminate': EggGroup.AMORPHOUS,
    'water2': EggGroup.WATER_2,
    'ditto': EggGroup.DITTO,
    'dragon': EggGroup.DRAGON,
    'no-eggs': EggGroup.UNDISCOVERED,
}

BASIC_MOVES = {
    'NORMAL': Move.TACKLE,
    'FIGHTING': Move.KARATE_CHOP,
    'FLYING': Move.GUST,
    'POISON': Move.SMOG,
    'GROUND': Move.MUD_SHOT,
    'ROCK': Move.ROCK_THROW,
    'BUG': Move.LEECH_LIFE,
    'GHOST': Move.LICK,
    'STEEL': Move.METAL_CLAW,
    'FAIRY': Move.TACKLE,  # placeholder
    'FIRE': Move.EMBER,
    'WATER': Move.WATER_GUN,
    'GRASS': Move.VINE_WHIP,
    'ELECTRIC': Move.THUNDER_SHOCK,
    'PSYCHIC': Move.CONFUSION,
    'ICE': Move.POWDER_SNOW,
    'DRAGON': Move.DRAGON_RAGE,
    'DARK': Move.FAINT_ATTACK
}

GROWTH_RATES = {
    'slow': GrowthRate.SLOW,
    'medium': GrowthRate.MEDIUM_FAST,
    'fast': GrowthRate.FAST,
    'medium-slow': GrowthRate.MEDIUM_SLOW,
    'slow-then-very-fast': GrowthRate.ERRATIC,
    'fast-then-very-slow': GrowthRate.FLUCTUATING,
}

# key is evolving species
# value is the overriden evo methods
EVO_OVERRIDES = {
    'tranquill': [['LEVEL_MALE', 32, 'UNFEZANT'], ['LEVEL_FEMALE', 32, 'UNFEZANT_FEMALE']],
    
    'basculin': [['USE_ITEM_MALE', 'DUSK_STONE', 'BASCULEGION'], ['USE_ITEM_FEMALE', 'DUSK_STONE', 'BASCULEGION_FEMALE']],
    'basculin_red_striped': [],
    'basculin_blue_striped': [],

    'petilil': [['USE_ITEM', 'SUN_STONE', 'LILLIGANT'], ['USE_ITEM', 'LEAF_STONE', 'LILLIGANT_HISUI']],

    'darumaka': [['LEVEL_UP', 35, 'DARMANITAN']],

    'zorua': [['LEVEL_UP', 30, 'ZOROARK']],

    'yamask': [['LEVEL_UP', 34, 'COFAGRIGUS']],

    'karrablast': [['MON_IN_PARTY', 'SHELMET', 'ESCAVALIER']],  # original methods for these don't exist in gen4 and I'm not implementing them
    'shelmet': [['MON_IN_PARTY', 'KARRABLAST', 'ACCELGOR']],

    'frillish': [['LEVEL_MALE', 40, 'JELLICENT']],
    'frillish_female': [['LEVEL_FEMALE', 40, 'JELLICENT_FEMALE']],

    'deerling_summer': [['LEVEL_UP', 34, 'SAWSBUCK_SUMMER']],   # probably don't need to set these but w/e
    'deerling_autumn': [['LEVEL_UP', 34, 'SAWSBUCK_AUTUMN']],
    'deerling_winter': [['LEVEL_UP', 34, 'SAWSBUCK_WINTER']],

    'rufflet': [['LEVEL_UP', 54, 'BRAVIARY'], ['USE_ITEM', 'DAWN_STONE', 'BRAVIARY_HISUI']],

    'litleo': [['LEVEL_MALE', 35, 'PYROAR'], ['LEVEL_FEMALE', 35, 'PYROAR_FEMALE']],

    'espurr': [['LEVEL_MALE', 25, 'MEOWSTIC'], ['LEVEL_FEMALE', 25, 'MEOWSTIC_FEMALE']],

    'pancham': [['DARK_TYPE_IN_PARTY', 32, 'PANGORO']],

    'bergmite': [['LEVEL_UP', 37, 'AVALUGG'], ['KNOW_MOVE', 'ANCIENT_POWER', 'AVALUGG_HISUI']],

    'goomy': [['LEVEL_UP', 40, 'SLIGGOO'], ['USE_ITEM', 'METAL_COAT', 'SLIGOO_HISUI']],
    'sliggoo': [['LEVEL_RAIN', 50, 'GOODRA']],
    'sliggoo_hisui': [['LEVEL_RAIN', 50, 'GOODRA_HISUI']],

    'dartrix': [['LEVEL_UP', 34, 'DECIDUEYE'], ['USE_ITEM', 'SUN_STONE', 'DECIDUEYE_HISUI']],

    'lycanroc': [['LEVEL_DAY', 25, 'LYCANROC'], ['LEVEL_NIGHT', 25, 'LYCANROC_MIDNIGHT']],
    'lycanroc_own_tempo': [['LEVEL_UP', 25, 'LYCANROC_DUSK']],

    'crabrawler': [['USE_ITEM', 'ICE_STONE', 'CRABOMINABLE']],

    'rattata_alola': [['LEVEL_NIGHT', 20, 'RATICATE_ALOLA']],

    'sandshrew_alola': [['USE_ITEM', 'ICE_STONE', 'SANDSLASH_ALOLA']],

    'vulpix_alola': [['USE_ITEM', 'ICE_STONE', 'NINETALES_ALOLA']],

    'diglett_alola': [['LEVEL_UP', 26, 'DUGTRIO_ALOLA']],

    'meowth_alola': [['HAPPINESS', 'PERSIAN_ALOLA']],

    'geodude_alola': [['LEVEL_UP', 25, 'GRAVELER_ALOLA']],
    'graveler_alola': [['TRADE', 'GOLEM']],

    'grimer_alola': [['LEVEL_UP', 38, 'MUK_ALOLA']],

    'pikachu_cosplay': [],
    'pikachu_rock_star': [],
    'pikachu_belle': [],
    'pikachu_pop_star': [],
    'pikachu_phd': [],
    'pikachu_libre': [],
    'pikachu_original_cap': [],
    'pikachu_hoenn_cap': [],
    'pikachu_sinnoh_cap': [],
    'pikachu_unova_cap': [],
    'pikachu_kalos_cap': [],
    'pikachu_alola_cap': [],
    'pikachu_partner_cap': [],
    'pikachu_world_cap': [],

    'toxel': [['NATURE_AMPED', 30, 'TOXTRICITY'], ['NATURE_LOW_KEY', 30, 'TOXTRICITY_LOW_KEY']],

    'meowth_galar': [['LEVEL_UP', 28, 'PERRSERKER']],

    'ponyta_galar': [['LEVEL_UP', 40, 'RAPIDASH_GALAR']],

    'slowpoke_galar': [['USE_ITEM', 'GALARICA_CUFF', 'SLOWBRO_GALAR'], ['USE_ITEM', 'GALARICA_WREATH', 'SLOWKING_GALAR']],

    'farfetchd_galar': [['LEVEL_UP', 32, 'SIRFETCHD']],

    'mr_mime_galar': [['LEVEL_UP', 42, 'MR_RIME']],

    'corsola_galar': [['LEVEL_UP', 38, 'CURSOLA']],

    'zigzagoon_galar': [['LEVEL_UP', 20, 'LINOONE_GALAR']],

    'linoone_galar': [['LEVEL_NIGHT', 35, 'OBSTAGOON']],

    'darumaka_galar': [['USE_ITEM', 'ICE_STONE', 'DARMANITAN_GALAR']],

    'yamask_galar': [['LEVEL_UP', 34, 'RUNERIGUS']],

    'growlithe_hisui': [['USE_ITEM', 'FIRE_STONE', 'ARCANINE_HISUI']],

    'voltorb_hisui': [['USE_ITEM', 'LEAF_STONE', 'ELECTRODE_HISUI']],

    'qwilfish_hisui': [['KNOW_MOVE', 'EXPLOSION', 'OVERQWIL']],

    'sneasel_hisui': [['USE_ITEM', 'RAZOR_CLAW', 'SNEASLER']],

    'zorua_hisui': [['LEVEL_UP', 30, 'ZOROARK_HISUI']],
}


def snake_case(s: str) -> str:
    return '_'.join(
        re.sub('([A-Z][a-z]+)',
               r' \1',
               re.sub('([A-Z]+)',
                      r' \1',
                      s.replace('-', ' ')
                )
        ).split()
    ).lower()


def get_pokeapi_species(species: int) -> dict:
    return requests.get(f'https://pokeapi.co/api/v2/pokemon-species/{species}').json()


def get_pokeapi_pokemon(species: int) -> dict:
    return requests.get(f'https://pokeapi.co/api/v2/pokemon/{species}').json()


def parse_evo(evo_details: dict, target: str) -> list:
    evo = []
    trigger = evo_details['trigger']['name']
    if trigger == 'level-up':
        if isinstance(evo_details['min_happiness'], int):
            if evo_details['time_of_day'] == 'day':
                evo.append(EvoMethod.HAPPINESS_DAY.name)
            elif evo_details['time_of_day'] == 'night':
                evo.append(EvoMethod.HAPPINESS_NIGHT.name)
            elif isinstance(evo_details['relative_physical_stats'], int):
                if evo_details['relative_physical_stats'] == 1:
                    evo.append(EvoMethod.LEVEL_ATK_GT_DEF.name)
                elif evo_details['relative_physical_stats'] == -1:
                    evo.append(EvoMethod.LEVEL_ATK_LT_DEF.name)
                else:
                    evo.append(EvoMethod.LEVEL_ATK_EQ_DEF.name)
                evo.append(evo_details['min_level'])
            else:
                evo.append(EvoMethod.HAPPINESS.name)
        elif evo_details['known_move']:
            move_id = int(evo_details['known_move']['url'].split('/')[-2])

            evo.append(EvoMethod.KNOW_MOVE.name)
            evo.append(Move(move_id).name)
        elif evo_details['party_species']:
            mon = Species[snake_case(evo_details['party_species']['name']).upper()]

            evo.append(EvoMethod.MON_IN_PARTY.name)
            evo.append(mon.name)
        elif isinstance(evo_details['gender'], int):
            if evo_details['gender'] == 2:
                evo.append(EvoMethod.LEVEL_MALE.name)
            elif evo_details['gender'] == 1:
                evo.append(EvoMethod.LEVEL_FEMALE.name)
        else:
            evo.append(EvoMethod.LEVEL_UP.name)
        
        if isinstance(evo_details['min_level'], int):
            evo.append(evo_details['min_level'])
    elif trigger == 'trade':
        if evo_details['held_item']:
            evo.append(EvoMethod.TRADE_WITH_ITEM.name)
            evo.append(snake_case(evo_details['held_item']['name']).upper())
        else:
            evo.append(EvoMethod.TRADE.name)
    elif trigger == 'use-item':
        if isinstance(evo_details['gender'], int):
            if evo_details['gender'] == 2:
                evo.append(EvoMethod.USE_ITEM_MALE.name)
            elif evo_details['gender'] == 1:
                evo.append(EvoMethod.USE_ITEM_FEMALE.name)
        elif evo_details['time_of_day'] == 'day':
            evo.append(EvoMethod.USE_ITEM_DAY.name)
        elif evo_details['time_of_day'] == 'night':
            evo.append(EvoMethod.USE_ITEM_NIGHT.name)
        else:
            evo.append(EvoMethod.USE_ITEM.name)

        evo.append(snake_case(evo_details['item']['name']).upper())

    evo.append(target.upper())

    return evo


def build_json(species_json: dict,
               poke_json: dict,
               name_override: str | None = None,
               gender_override: GenderRatio | None = None,
               sub_form: bool = False) -> dict:
    poke = {}
    
    # name
    if sub_form:
        poke['name'] = '-----'
    else:
        for name in species_json['names']:
            if name['language']['name'] == 'en':
                poke['name'] = name['name']
                break
    
    # base_stats
    poke['base_stats'] = {}
    poke['base_stats']['hp'] = poke_json['stats'][0]['base_stat']
    poke['base_stats']['attack'] = poke_json['stats'][1]['base_stat']
    poke['base_stats']['defense'] = poke_json['stats'][2]['base_stat']
    poke['base_stats']['sp_attack'] = poke_json['stats'][3]['base_stat']
    poke['base_stats']['sp_defense'] = poke_json['stats'][4]['base_stat']
    poke['base_stats']['speed'] = poke_json['stats'][5]['base_stat']

    # types
    poke['types'] = [poke_json['types'][0]['type']['name'].upper()]
    if len(poke_json['types']) > 1:
        poke['types'].append(poke_json['types'][1]['type']['name'].upper())
    else:
        poke['types'].append(poke_json['types'][0]['type']['name'].upper())
    
    # abilities
    poke['abilities'] = {}
    for i in range(len(poke_json['abilities'])):
        key = str(i)
        if poke_json['abilities'][i]['is_hidden']:
            if i == 1:
                # if i is 1 and this ability is hidden, then stick an empty ability on slot 2
                poke['abilities'][1] = 'NONE'
            key = 'H'

        poke['abilities'][key] = snake_case(poke_json['abilities'][i]['ability']['name']).upper()
    
    # if pokeapi only gave us slot 0, fill out slots 1 and H with NONE
    if len(poke_json['abilities']) == 1:
        poke['abilities'][1] = 'NONE'
        poke['abilities']['H'] = 'NONE'
    
    # held_items (empty for now, both none)
    poke['held_items'] = {
        '50%': 'NONE',
        '5%': 'NONE'
    }

    poke['catch_rate'] = species_json['capture_rate']
    poke['base_exp_reward'] = min(255, 0 if not poke_json['base_experience'] else poke_json['base_experience'])

    poke['ev_yields'] = {}
    poke['ev_yields']['hp'] = poke_json['stats'][0]['effort']
    poke['ev_yields']['attack'] = poke_json['stats'][1]['effort']
    poke['ev_yields']['defense'] = poke_json['stats'][2]['effort']
    poke['ev_yields']['sp_attack'] = poke_json['stats'][3]['effort']
    poke['ev_yields']['sp_defense'] = poke_json['stats'][4]['effort']
    poke['ev_yields']['speed'] = poke_json['stats'][5]['effort']

    poke['gender_ratio'] = gender_override.name if gender_override else GENDER_RATIOS[species_json['gender_rate']].name
    poke['hatch_multiplier'] = species_json['hatch_counter']
    poke['base_happiness'] = species_json['base_happiness']
    poke['growth_rate'] = GROWTH_RATES[species_json['growth_rate']['name']].name

    poke['egg_groups'] = [EGG_GROUPS[species_json['egg_groups'][0]['name']].name]
    if len(species_json['egg_groups']) > 1:
        poke['egg_groups'].append(EGG_GROUPS[species_json['egg_groups'][1]['name']].name)
    else:
        poke['egg_groups'].append(EGG_GROUPS[species_json['egg_groups'][0]['name']].name)
    
    poke['flee_chance'] = 0
    poke['body_color'] = BodyColor[species_json['color']['name'].upper()].name
    poke['flip_sprite'] = False

    # build a minimal learnset for now
    poke['learnset'] = {}
    poke['learnset']['tms'] = []
    poke['learnset']['level_up'] = {}
    if poke['types'][0] == poke['types'][1]:
        poke['learnset']['level_up']['1'] = BASIC_MOVES[poke['types'][0]].name
    else:
        poke['learnset']['level_up']['1'] = [
            BASIC_MOVES[poke['types'][0]].name,
            BASIC_MOVES[poke['types'][1]].name
        ]
    
    if name_override in EVO_OVERRIDES:
        all_evos = EVO_OVERRIDES[name_override]
    else:
        evo_chain = requests.get(species_json['evolution_chain']['url']).json()['chain']
        name_id = species_json['name']
        queue = [evo_chain]
        this_mon = None
        while len(queue) > 0:
            this_mon = queue.pop(0)
            if this_mon['species']['name'] == name_id:   # if this is us, break out
                pass
            else:
                queue.extend(this_mon['evolves_to'])
        evo_queue = this_mon['evolves_to']               # get the set of evos branching from this mon
        
        all_evos = []
        for evo in evo_queue:                            # this breaks for eevee, but w/e
            for deets in evo['evolution_details']:
                target = snake_case(evo['species']['name']).upper()
                all_evos.append(parse_evo(deets, target))

    if all_evos:
        poke['evolutions'] = all_evos

    return poke


def build_species(species: int,
                  form_override: int | None = None,
                  name_override: str | None = None,
                  gender_override: GenderRatio | None = None,
                  sub_form: bool = False,
                  write: bool = True) -> (str, dict):
    species_json = get_pokeapi_species(species)
    if form_override:
        poke_json = get_pokeapi_pokemon(form_override)
    else:
        poke_json = get_pokeapi_pokemon(species)

    if name_override is None:
        name_override = snake_case(poke_json['name'])
    
    print(f'Dumping {name_override}')
    j = build_json(species_json, poke_json, name_override, gender_override, sub_form)
    if write:
        f = open(f'data/pokemon/{name_override}.json', 'w', encoding='utf8')
        json.dump(j, f, indent=4, ensure_ascii=False)
        f.close()
    
    return (name_override, j)


def copy_species(species: int,
                 name_override: str,
                 gender_override: GenderRatio | None = None):
    base_name = name_override.split('_')[0]

    print(f'Copying {name_override} from {base_name}')
    src_file = f'data/pokemon/{base_name}.json'
    dst_file = f'data/pokemon/{name_override}.json'
    if os.path.exists(src_file):
        src = open(src_file, 'r', encoding='utf8')
        dst = open(dst_file, 'w', encoding='utf8')

        base = json.load(src)
        base['name'] = '-----'
        if gender_override:
            base['gender_ratio'] = gender_override.name

        json.dump(base, dst, indent=4, ensure_ascii=False)

        src.close()
        dst.close()
    else:
        print(f'❌ {base_name}.json not defined')
        raise RuntimeError


def build_range(start: int, end: int):
    for i in range(start, end + 1):
        name, j = build_species(i)
        f = open(f'data/pokemon/{name}.json', 'w', encoding='utf8')
        json.dump(j, f, indent=4, ensure_ascii=False)
        f.close()


def build_gen5():
    build_range(494, 520)   # Victini - Tranquill
    build_species(521, name_override='unfezant',        gender_override=GenderRatio.MALE_ONLY)
    copy_species( 521, name_override='unfezant_female', gender_override=GenderRatio.FEMALE_ONLY)

    build_range(522, 549)   # Blitzle - Lilligant
    build_species(550,                      name_override='basculin_red_striped', sub_form=True)
    build_species(550, form_override=10016, name_override='basculin_blue_striped', sub_form=True)
    build_species(550, form_override=10247, name_override='basculin')   # basculin-white is form 0 for basculegion

    build_range(551, 554)  # Sandile - Darumaka
    build_species(555,                      name_override='darmanitan')
    build_species(555, form_override=10017, name_override='darmanitan_zen', sub_form=True)

    build_range(556, 584)  # Maractus - Vanilluxe
    build_species(585, name_override='deerling')
    copy_species(585, name_override='deerling_summer')
    copy_species(585, name_override='deerling_autumn')
    copy_species(585, name_override='deerling_winter')
    build_species(585, name_override='sawsbuck')
    copy_species(586, name_override='sawsbuck_summer')
    copy_species(586, name_override='sawsbuck_autumn')
    copy_species(586, name_override='sawsbuck_winter')

    build_range(587, 591)  # Emolga - Amoonguss
    build_species(592, name_override='frillish',        gender_override=GenderRatio.MALE_ONLY)
    copy_species( 592, name_override='frillish_female', gender_override=GenderRatio.FEMALE_ONLY)
    build_species(593, name_override='jellicent',        gender_override=GenderRatio.MALE_ONLY)
    copy_species( 593, name_override='jellicent_female', gender_override=GenderRatio.FEMALE_ONLY)

    build_range(594, 640)   # Alomomola - Virizion
    build_species(641,                      name_override='tornadus')
    build_species(641, form_override=10019, name_override='tornadus_therian', sub_form=True)
    build_species(642,                      name_override='thundurus')
    build_species(642, form_override=10020, name_override='thundurus_therian', sub_form=True)
    build_species(643)      # Reshiram
    build_species(644)      # Zekrom
    build_species(645,                      name_override='landorus')
    build_species(645, form_override=10021, name_override='landorus_therian', sub_form=True)
    build_species(646,                      name_override='kyurem')
    build_species(646, form_override=10022, name_override='kyurem_black', sub_form=True)
    build_species(646, form_override=10023, name_override='kyurem_white', sub_form=True)
    build_species(647,                      name_override='keldeo')
    build_species(647, form_override=10024, name_override='keldeo_resolute', sub_form=True)
    build_species(648,                      name_override='meloetta')
    build_species(648, form_override=10018, name_override='meloetta_pirouette', sub_form=True)
    build_species(649, name_override='genesect')
    copy_species(649, name_override='genesect_douse_drive')   # functional copies
    copy_species(649, name_override='genesect_shock_drive')
    copy_species(649, name_override='genesect_burn_drive')
    copy_species(649, name_override='genesect_chill_drive')


def build_gen6():
    build_range(650, 657)   # Chespin - Frogadier
    build_species(658,                      name_override='greninja')
    build_species(658, form_override=10116, name_override='greninja_battle_bond', sub_form=True)
    build_species(658, form_override=10117, name_override='greninja_ash', sub_form=True)

    build_range(659, 665)   # Bunnelby - Spewpa
    build_species(666, name_override='vivillon')      # Vivillon (Icy Snow)
    copy_species(666, name_override='vivillon_polar')
    copy_species(666, name_override='vivillon_tundra')
    copy_species(666, name_override='vivillon_continental')
    copy_species(666, name_override='vivillon_garden')
    copy_species(666, name_override='vivillon_elegant')
    copy_species(666, name_override='vivillon_meadow')
    copy_species(666, name_override='vivillon_modern')
    copy_species(666, name_override='vivillon_marine')
    copy_species(666, name_override='vivillon_archipelago')
    copy_species(666, name_override='vivillon_high_plains')
    copy_species(666, name_override='vivillon_sandstorm')
    copy_species(666, name_override='vivillon_river')
    copy_species(666, name_override='vivillon_monsoon')
    copy_species(666, name_override='vivillon_savanna')
    copy_species(666, name_override='vivillon_sun')
    copy_species(666, name_override='vivillon_ocean')
    copy_species(666, name_override='vivillon_jungle')
    copy_species(666, name_override='vivillon_fancy')
    copy_species(666, name_override='vivillon_poke_ball')
    build_species(667)      # Litleo
    build_species(668, name_override='pyroar', gender_override=GenderRatio.MALE_ONLY)
    copy_species( 668, name_override='pyroar_female', gender_override=GenderRatio.FEMALE_ONLY)
    build_species(669)      # Flabebe (Red)
    copy_species(669, name_override='flabebe_yellow')
    copy_species(669, name_override='flabebe_orange')
    copy_species(669, name_override='flabebe_blue')
    copy_species(669, name_override='flabebe_white')
    build_species(670)      # Floette (Red)
    copy_species(670, name_override='floette_yellow')
    copy_species(670, name_override='floette_orange')
    copy_species(670, name_override='floette_blue')
    copy_species(670, name_override='floette_white')
    build_species(670, form_override=10061, name_override='floette_eternal', sub_form=True)
    build_species(671)      # Florges (Red)
    copy_species(671, name_override='florges_yellow')
    copy_species(671, name_override='florges_orange')
    copy_species(671, name_override='florges_blue')
    copy_species(671, name_override='florges_white')

    build_range(672, 675)   # Skiddo - Pangoro
    build_species(676)      # Furfrou (Natural)
    copy_species(676, name_override='furfrou_heart')
    copy_species(676, name_override='furfrou_star')
    copy_species(676, name_override='furfrou_diamond')
    copy_species(676, name_override='furfrou_debutante')
    copy_species(676, name_override='furfrou_matron')
    copy_species(676, name_override='furfrou_dandy')
    copy_species(676, name_override='furfrou_la_reine')
    copy_species(676, name_override='furfrou_kabuki')
    copy_species(676, name_override='furfrou_pharoah')
    build_species(677)      # Espurr
    build_species(678,                      name_override='meowstic', gender_override=GenderRatio.MALE_ONLY)
    build_species(678, form_override=10025, name_override='meowstic_female', gender_override=GenderRatio.FEMALE_ONLY, sub_form=True)
    build_species(679)      # Honedge
    build_species(680)      # Doublade
    build_species(681,                      name_override='aegislash')
    build_species(681, form_override=10026, name_override='aegislash_blade', sub_form=True)

    build_range(682, 709)   # Spritzee - Trevenant
    build_species(710,                      name_override='pumpkaboo')   # medium
    build_species(710, form_override=10027, name_override='pumpkaboo_small', sub_form=True)
    build_species(710, form_override=10028, name_override='pumpkaboo_large', sub_form=True)
    build_species(710, form_override=10029, name_override='pumpkaboo_super', sub_form=True)
    build_species(711,                      name_override='gourgeist')   # medium
    build_species(711, form_override=10030, name_override='gourgeist_small', sub_form=True)
    build_species(711, form_override=10031, name_override='gourgeist_large', sub_form=True)
    build_species(711, form_override=10032, name_override='gourgeist_super', sub_form=True)

    build_range(712, 715)   # Bergmite - Noivern
    build_species(716)
    copy_species(716, name_override='xerneas_active')
    build_species(717)      # Yveltal
    build_species(718,                      name_override='zygarde')
    build_species(718, form_override=10118, name_override='zygarde_10_power_construct', sub_form=True)
    build_species(718, form_override=10119, name_override='zygarde_50_power_construct', sub_form=True)
    build_species(718, form_override=10120, name_override='zygarde_10_complete', sub_form=True)
    build_species(718, form_override=10120, name_override='zygarde_50_complete', sub_form=True)
    build_species(718, form_override=10181, name_override='zygarde_10', sub_form=True)
    build_species(719)      # Diancie
    build_species(720)      # Hoopa
    build_species(720, form_override=10086, name_override='hoopa_unbound', sub_form=True)
    build_species(721)      # Volcanion    
    
    # megas / primals
    build_species(  3, form_override=10033, name_override='venusaur_mega', sub_form=True)
    build_species(  6, form_override=10034, name_override='charizard_mega_x', sub_form=True)
    build_species(  6, form_override=10035, name_override='charizard_mega_y', sub_form=True)
    build_species(  9, form_override=10036, name_override='blastoise_mega', sub_form=True)
    build_species( 15, form_override=10090, name_override='beedrill_mega', sub_form=True)
    build_species( 18, form_override=10073, name_override='pidgeot_mega', sub_form=True)
    build_species( 65, form_override=10037, name_override='alakazam_mega', sub_form=True)
    build_species( 80, form_override=10071, name_override='slowbro_mega', sub_form=True)
    build_species( 94, form_override=10038, name_override='gengar_mega', sub_form=True)
    build_species(115, form_override=10039, name_override='kangaskhan_mega', sub_form=True)
    build_species(127, form_override=10040, name_override='pinsir_mega', sub_form=True)
    build_species(130, form_override=10041, name_override='gyarados_mega', sub_form=True)
    build_species(142, form_override=10042, name_override='aerodactyl_mega', sub_form=True)
    build_species(150, form_override=10043, name_override='mewtwo_mega_x', sub_form=True)
    build_species(150, form_override=10044, name_override='mewtwo_mega_y', sub_form=True)
    build_species(181, form_override=10045, name_override='ampharos_mega', sub_form=True)
    build_species(212, form_override=10046, name_override='scizor_mega', sub_form=True)
    build_species(214, form_override=10047, name_override='heracross_mega', sub_form=True)
    build_species(229, form_override=10048, name_override='houndoom_mega', sub_form=True)
    build_species(248, form_override=10049, name_override='tyranitar_mega', sub_form=True)
    build_species(254, form_override=10065, name_override='sceptile_mega', sub_form=True)
    build_species(257, form_override=10050, name_override='blaziken_mega', sub_form=True)
    build_species(260, form_override=10064, name_override='swampert_mega', sub_form=True)
    build_species(282, form_override=10051, name_override='gardevoir_mega', sub_form=True)
    build_species(302, form_override=10066, name_override='sableye_mega', sub_form=True)
    build_species(303, form_override=10052, name_override='mawile_mega', sub_form=True)
    build_species(306, form_override=10053, name_override='aggron_mega', sub_form=True)
    build_species(308, form_override=10054, name_override='medicham_mega', sub_form=True)
    build_species(310, form_override=10055, name_override='manectric_mega', sub_form=True)
    build_species(319, form_override=10070, name_override='sharpedo_mega', sub_form=True)
    build_species(323, form_override=10087, name_override='camerupt_mega', sub_form=True)
    build_species(334, form_override=10067, name_override='altaria_mega', sub_form=True)
    build_species(354, form_override=10056, name_override='banette_mega', sub_form=True)
    build_species(359, form_override=10057, name_override='absol_mega', sub_form=True)
    build_species(362, form_override=10074, name_override='glalie_mega', sub_form=True)
    build_species(373, form_override=10089, name_override='salamence_mega', sub_form=True)
    build_species(376, form_override=10076, name_override='metagross_mega', sub_form=True)
    build_species(380, form_override=10062, name_override='latias_mega', sub_form=True)
    build_species(381, form_override=10063, name_override='latios_mega', sub_form=True)
    build_species(382, form_override=10077, name_override='kyogre_primal', sub_form=True)
    build_species(383, form_override=10078, name_override='groudon_primal', sub_form=True)
    build_species(384, form_override=10079, name_override='rayquaza_mega', sub_form=True)
    build_species(428, form_override=10088, name_override='lopunny_mega', sub_form=True)
    build_species(445, form_override=10058, name_override='garchomp_mega', sub_form=True)
    build_species(448, form_override=10059, name_override='lucario_mega', sub_form=True)
    build_species(460, form_override=10060, name_override='abomasnow_mega', sub_form=True)
    build_species(475, form_override=10068, name_override='gallade_mega', sub_form=True)
    build_species(531, form_override=10069, name_override='audino_mega', sub_form=True)
    build_species(719, form_override=10075, name_override='diancie_mega', sub_form=True)


def build_gen7():
    build_range(722, 740)   # Rowlet - Crabominable
    build_species(741,                      name_override='oricorio_baile')
    build_species(741, form_override=10123, name_override='oricorio_pom_pom', sub_form=True)
    build_species(741, form_override=10124, name_override='oricorio_pau', sub_form=True)
    build_species(741, form_override=10125, name_override='oricorio_sensu', sub_form=True)
    build_species(742)      # Cutiefly
    build_species(743)      # Ribombee
    build_species(744)      # Rockruff
    build_species(744, form_override=10151, name_override='rockruff_own_tempo', sub_form=True)
    build_species(745,                      name_override='lycanroc_midday')
    build_species(745, form_override=10126, name_override='lycanroc_midnight', sub_form=True)
    build_species(745, form_override=10152, name_override='lycanroc_dusk', sub_form=True)
    build_species(746,                      name_override='wishiwashi')
    build_species(746, form_override=10127, name_override='wishiwashi_school', sub_form=True)

    build_range(747, 773)   # Mareanie - Silvally
    build_species(774,                      name_override='minior_red_meteor')
    build_species(774, form_override=10130, name_override='minior_orange_meteor', sub_form=True)
    build_species(774, form_override=10131, name_override='minior_yellow_meteor', sub_form=True)
    build_species(774, form_override=10132, name_override='minior_green_meteor', sub_form=True)
    build_species(774, form_override=10133, name_override='minior_blue_meteor', sub_form=True)
    build_species(774, form_override=10134, name_override='minior_indigo_meteor', sub_form=True)
    build_species(774, form_override=10135, name_override='minior_violet_meteor', sub_form=True)
    build_species(774, form_override=10136, name_override='minior_red', sub_form=True)
    build_species(774, form_override=10137, name_override='minior_orange', sub_form=True)
    build_species(774, form_override=10138, name_override='minior_yellow', sub_form=True)
    build_species(774, form_override=10139, name_override='minior_green', sub_form=True)
    build_species(774, form_override=10140, name_override='minior_blue', sub_form=True)
    build_species(774, form_override=10141, name_override='minior_indigo', sub_form=True)
    build_species(774, form_override=10142, name_override='minior_violet', sub_form=True)
    build_species(775)      # Komala
    build_species(776)      # Turtonator
    build_species(777)      # Togedemaru
    build_species(778,                      name_override='mimikyu')
    build_species(778, form_override=10143, name_override='mimikyu_busted', sub_form=True)

    build_range(779, 799)   # Bruxish - Guzzlord
    build_species(800,                      name_override='necrozma')
    build_species(800, form_override=10155, name_override='necrozma_dusk', sub_form=True)
    build_species(800, form_override=10156, name_override='necrozma_dawn', sub_form=True)
    build_species(800, form_override=10157, name_override='necrozma_ultra_dusk', sub_form=True)
    build_species(800, form_override=10157, name_override='necrozma_ultra_dawn', sub_form=True)
    build_species(801,                      name_override='magearna')
    build_species(801, form_override=10147, name_override='magearna_original', sub_form=True)

    build_range(802, 809)   # Marshadow - Melmetal

    # alolan forms
    build_species( 19, form_override=10091, name_override='rattata_alola', sub_form=True)
    build_species( 20, form_override=10092, name_override='raticate_alola', sub_form=True)
    build_species( 26, form_override=10100, name_override='raichu_alola', sub_form=True)
    build_species( 27, form_override=10101, name_override='sandshrew_alola', sub_form=True)
    build_species( 28, form_override=10102, name_override='sandslash_alola', sub_form=True)
    build_species( 37, form_override=10103, name_override='vulpix_alola', sub_form=True)
    build_species( 38, form_override=10104, name_override='ninetales_alola', sub_form=True)
    build_species( 50, form_override=10105, name_override='diglett_alola', sub_form=True)
    build_species( 51, form_override=10106, name_override='dugtrio_alola', sub_form=True)
    build_species( 52, form_override=10107, name_override='meowth_alola', sub_form=True)
    build_species( 53, form_override=10108, name_override='persian_alola', sub_form=True)
    build_species( 74, form_override=10109, name_override='geodude_alola', sub_form=True)
    build_species( 75, form_override=10110, name_override='graveler_alola', sub_form=True)
    build_species( 76, form_override=10111, name_override='golem_alola', sub_form=True)
    build_species( 88, form_override=10112, name_override='grimer_alola', sub_form=True)
    build_species( 89, form_override=10113, name_override='muk_alola', sub_form=True)
    build_species(103, form_override=10114, name_override='exeggutor_alola', sub_form=True)
    build_species(105, form_override=10115, name_override='marowak_alola', sub_form=True)


def build_extras():
    build_species( 25, form_override=10085, name_override='pikachu_cosplay', sub_form=True)
    build_species( 25, form_override=10080, name_override='pikachu_rock_star', sub_form=True)
    build_species( 25, form_override=10081, name_override='pikachu_belle', sub_form=True)
    build_species( 25, form_override=10082, name_override='pikachu_pop_star', sub_form=True)
    build_species( 25, form_override=10083, name_override='pikachu_phd', sub_form=True)
    build_species( 25, form_override=10084, name_override='pikachu_libre', sub_form=True)
    build_species( 25, form_override=10094, name_override='pikachu_original_cap', sub_form=True)
    build_species( 25, form_override=10095, name_override='pikachu_hoenn_cap', sub_form=True)
    build_species( 25, form_override=10096, name_override='pikachu_sinnoh_cap', sub_form=True)
    build_species( 25, form_override=10097, name_override='pikachu_unova_cap', sub_form=True)
    build_species( 25, form_override=10098, name_override='pikachu_kalos_cap', sub_form=True)
    build_species( 25, form_override=10099, name_override='pikachu_alola_cap', sub_form=True)
    build_species( 25, form_override=10148, name_override='pikachu_partner_cap', sub_form=True)
    build_species( 25, form_override=10160, name_override='pikachu_world_cap', sub_form=True)
    build_species(351, form_override=10013, name_override='castform_sunny', sub_form=True)
    build_species(351, form_override=10014, name_override='castform_rainy', sub_form=True)
    build_species(351, form_override=10015, name_override='castform_snowy', sub_form=True)
    build_species(421,                      name_override='cherrim_sunshine', sub_form=True)
    build_species(422,                      name_override='shellos_east_sea', sub_form=True)
    build_species(423,                      name_override='gastrodon_east_sea', sub_form=True)


def build_gen8():
    build_range(810, 844)   # Grookey - Sandaconda
    build_species(845,                      name_override='cramorant')
    build_species(845, form_override=10182, name_override='cramorant_gulping', sub_form=True)
    build_species(845, form_override=10183, name_override='cramorant_gorging', sub_form=True)
    build_species(846)      # Arrokuda
    build_species(847)      # Barraskewda
    build_species(848)      # Toxel
    build_species(849,                      name_override='toxtricity')
    build_species(849, form_override=10184, name_override='toxtricity_low_key', sub_form=True)
    build_species(850)      # Sizzlipede
    build_species(851)      # Centiskorch
    build_species(852)      # Clobbopus
    build_species(853)      # Grapploct
    build_species(854, name_override='sinistea')
    build_species(854, name_override='sinistea_antique', sub_form=True)    # functional copy
    build_species(855, name_override='polteageist')
    build_species(855, name_override='polteageist_antique', sub_form=True) # functional copy

    build_range(856, 868)   # Hatenna - Milcery
    build_species(869, name_override='alcremie')
    build_species(869, name_override='alcremie_berry_sweet', sub_form=True)
    build_species(869, name_override='alcremie_love_sweet', sub_form=True)
    build_species(869, name_override='alcremie_star_sweet', sub_form=True)
    build_species(869, name_override='alcremie_clover_sweet', sub_form=True)
    build_species(869, name_override='alcremie_flower_sweet', sub_form=True)
    build_species(869, name_override='alcremie_ribbon_sweet', sub_form=True)
    build_species(869, name_override='alcremie_filler_1', sub_form=True)
    build_species(869, name_override='alcremie_filler_2', sub_form=True)

    build_range(870, 874)  # Falinks - Stonjourner
    build_species(875,                      name_override='eiscue')
    build_species(875, form_override=10185, name_override='eiscue_no_ice', sub_form=True)
    build_species(876,                      name_override='indeedee')
    build_species(876, form_override=10186, name_override='indeedee_female', sub_form=True)
    build_species(877,                      name_override='morpeko')
    build_species(877, form_override=10187, name_override='morpeko_hangry', sub_form=True)

    build_range(878, 887)   # Cufant - Dragapult
    build_species(888,                      name_override='zacian')
    build_species(888, form_override=10188, name_override='zacian_crowned', sub_form=True)
    build_species(889,                      name_override='zamazenta')
    build_species(889, form_override=10189, name_override='zamazenta_crowned', sub_form=True)
    build_species(890,                      name_override='eternatus')
    build_species(890, form_override=10190, name_override='eternatus_eternamax', sub_form=True)
    build_species(891)      # Kubfu
    build_species(892,                      name_override='urshifu_single_strike')
    build_species(892, form_override=10191, name_override='urshifu_rapid_strike', sub_form=True)
    build_species(893,                      name_override='zarude')
    build_species(893, form_override=10192, name_override='zarude_dada', sub_form=True)

    build_range(894, 897)   # Regieleki - Spectrier
    build_species(898,                      name_override='calyrex')
    build_species(898, form_override=10193, name_override='calyrex_ice_rider', sub_form=True)
    build_species(898, form_override=10194, name_override='calyrex_shadow_rider', sub_form=True)

    build_species(899)      # Wyrdeer
    build_species(900)      # Kleavor
    build_species(901)      # Ursaluna
    build_species(902,                      name_override='basculegion', gender_override=GenderRatio.MALE_ONLY)
    build_species(902, form_override=10248, name_override='basculegion_female', gender_override=GenderRatio.FEMALE_ONLY, sub_form=True)
    build_species(903)      # Sneasler
    build_species(904)      # Overqwil
    build_species(905,                      name_override='enamorus')
    build_species(905, form_override=10249, name_override='enamorus_therian', sub_form=True)
    
    # galarian forms
    build_species( 52, form_override=10161, name_override='meowth_galar', sub_form=True)
    build_species( 77, form_override=10162, name_override='ponyta_galar', sub_form=True)
    build_species( 78, form_override=10163, name_override='rapidash_galar', sub_form=True)
    build_species( 79, form_override=10164, name_override='slowpoke_galar', sub_form=True)
    build_species( 80, form_override=10165, name_override='slowbro_galar', sub_form=True)
    build_species( 83, form_override=10166, name_override='farfetchd_galar', sub_form=True)
    build_species(110, form_override=10167, name_override='weezing_galar', sub_form=True)
    build_species(122, form_override=10168, name_override='mr_mime_galar', sub_form=True)
    build_species(144, form_override=10169, name_override='articuno_galar', sub_form=True)
    build_species(145, form_override=10170, name_override='zapdos_galar', sub_form=True)
    build_species(146, form_override=10171, name_override='moltres_galar', sub_form=True)
    build_species(199, form_override=10172, name_override='slowking_galar', sub_form=True)
    build_species(222, form_override=10173, name_override='corsola_galar', sub_form=True)
    build_species(263, form_override=10174, name_override='zigzagoon_galar', sub_form=True)
    build_species(264, form_override=10175, name_override='linoone_galar', sub_form=True)
    build_species(554, form_override=10176, name_override='darumaka_galar', sub_form=True)
    build_species(555, form_override=10177, name_override='darmanitan_galar', sub_form=True)
    build_species(555, form_override=10178, name_override='darmanitan_galar_zen', sub_form=True)
    build_species(562, form_override=10179, name_override='yamask_galar', sub_form=True)
    build_species(618, form_override=10180, name_override='stunfisk_galar', sub_form=True)

    # hisuian forms
    build_species( 58, form_override=10229, name_override='growlithe_hisui', sub_form=True)
    build_species( 59, form_override=10230, name_override='arcanine_hisui', sub_form=True)
    build_species(100, form_override=10231, name_override='voltorb_hisui', sub_form=True)
    build_species(101, form_override=10232, name_override='electrode_hisui', sub_form=True)
    build_species(157, form_override=10233, name_override='typhlosion_hisui', sub_form=True)
    build_species(211, form_override=10234, name_override='qwilfish_hisui', sub_form=True)
    build_species(215, form_override=10235, name_override='sneasel_hisui', sub_form=True)
    build_species(503, form_override=10236, name_override='samurott_hisui', sub_form=True)
    build_species(549, form_override=10237, name_override='lilligant_hisui', sub_form=True)
    build_species(570, form_override=10238, name_override='zorua_hisui', sub_form=True)
    build_species(571, form_override=10239, name_override='zoroark_hisui', sub_form=True)
    build_species(628, form_override=10240, name_override='braviary_hisui', sub_form=True)
    build_species(705, form_override=10241, name_override='sliggoo_hisui', sub_form=True)
    build_species(706, form_override=10242, name_override='goodra_hisui', sub_form=True)
    build_species(713, form_override=10243, name_override='avalugg_hisui', sub_form=True)
    build_species(724, form_override=10244, name_override='decidueye_hisui', sub_form=True)

    # dialga/palkia origin
    build_species(483, form_override=10245, name_override='dialga_origin', sub_form=True)
    build_species(484, form_override=10246, name_override='palkia_origin', sub_form=True)
