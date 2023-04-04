import re
import requests
import typing

UNOVA_DEX_START = 494
KALOS_DEX_START = 650
ALOLA_DEX_START = 722
GALAR_DEX_START = 810
PALDEA_DEX_START = 906
DEX_END = 1010
DEX_EXPANSION_START = 544

POKE_API_URL = 'https://pokeapi.co/api/v2'
POKEMON_ENDPOINT = '/pokemon/{num}'
SPECIES_ENDPOINT = '/pokemon-species/{num}'
GENERATED_FILE = 'generated'
TMS_FILE = 'generated_tms'

BASE_STATS_TEMPLATE = """
    [SPECIES_{species}] = {{
        .baseHP        = {base_hp},
        .baseAttack    = {base_attack},
        .baseDefense   = {base_defense},
        .baseSpAttack  = {base_spatk},
        .baseSpDefense = {base_spdef},
        .baseSpeed     = {base_speed},
        
        .type1 = TYPE_{type_1},
        .type2 = TYPE_{type_2},

        .ability1 = ABILITY_{ability1},
        .ability2 = ABILITY_{ability2},

        .itemUncommon = ITEM_{item1},
        .itemRare     = ITEM_{item2},

        .evYieldHP        = {ev_hp},
        .evYieldAttack    = {ev_attack},
        .evYieldDefense   = {ev_defense},
        .evYieldSpAttack  = {ev_spatk},
        .evYieldSpDefense = {ev_spdef},
        .evYieldSpeed     = {ev_speed},

        .catchRate = {catch_rate},
        .fleeRate = {flee_rate},
        .genderRatio = {gender_ratio},
        .baseFriendship = {base_friendship},
        .expCurve = GROWTH_{exp_curve},
        .expYield = {exp_yield},
        .eggCycles = {egg_cycles},
        .eggGroup1 = EGG_GROUP_{egg_group1},
        .eggGroup2 = EGG_GROUP_{egg_group2},
        .bodyColor = BODY_COLOR_{body_color},
        .reverse = {reverse},

        .tmLearnsets = {{
            TM_LEARNSET_1_{species},
            TM_LEARNSET_2_{species},
            TM_LEARNSET_3_{species},
            TM_LEARNSET_4_{species}
        }},
    }},
"""

TM_LEARNSETS_TEMPLATE = """

#define TM_LEARNSET_1_{species} (0)
#define TM_LEARNSET_2_{species} (0)
#define TM_LEARNSET_3_{species} (0)
#define TM_LEARNSET_4_{species} (0)
"""

POKE_API_EGG_GROUPS = {
    'monster': 'MONSTER',
    'water1': 'WATER_1',
    'bug': 'BUG',
    'flying': 'FLYING',
    'ground': 'FIELD',
    'fairy': 'FAIRY',
    'plant': 'GRASS',
    'humanshape': 'HUMAN_LIKE',
    'water3': 'WATER_3',
    'mineral': 'MINERAL',
    'indeterminate': 'AMORPHOUS',
    'water2': 'WATER_2',
    'ditto': 'DITTO',
    'dragon': 'DRAGON',
    'no-eggs': 'UNDISCOVERED',
}


POKE_API_EXP_CURVES = {
    'slow': 'SLOW',
    'medium': 'MEDIUM_FAST',
    'fast': 'FAST',
    'medium-slow': 'MEDIUM_SLOW',
    'slow-then-very-fast': 'ERRATIC',
    'fast-then-very-slow': 'FLUCTUATING',
}


def upper_snake(s):
    return '_'.join(
        re.sub('([A-Z][a-z]+)', r' \1',
        re.sub('([A-Z]+)', r' \1',
        s.replace('-', ' '))).split()).upper()


def get_mon_data(mon_num: int) -> dict:
    url = f'{POKE_API_URL}{POKEMON_ENDPOINT.format(num=mon_num)}'
    return requests.get(url).json()


def get_species_data(species_num: int) -> dict:
    url = f'{POKE_API_URL}{SPECIES_ENDPOINT.format(num=species_num)}'
    return requests.get(url).json()


def gen(dex_nums: iter, tms: bool = True):
    with open(GENERATED_FILE, 'w') as gen, open(TMS_FILE, 'w') as tms:
        for dex_num in dex_nums:
            species_data = get_species_data(dex_num)
            print(f'Species: {dex_num}; Name: {species_data["name"]}')
            varieties = species_data['varieties']
            for v in varieties:
                if v['pokemon']['name'][-5:] == '-gmax':    # skip cringe gmax forms
                    pass
                name = species_data['name'] if v['is_default'] else v['pokemon']['name']
                gen_mon(v['pokemon']['url'], species_data, upper_snake(name), gen)
                if tms:
                    gen_tms(upper_snake(name), tms)


def get_type_2(types: list) -> str:
    if len(types) < 2:
        ret = types[0]['type']
    else:
        ret = types[1]['type']
    return ret['name'].upper()


def get_ability_2(abilities: list) -> str:
    if len(abilities) < 2:
        ret = 'none'
    elif abilities[1]['is_hidden']:
        ret = 'none'
    else:
        ret = abilities[1]['ability']['name']
    return upper_snake(ret)


def get_egg_group_2(egg_groups: list) -> str:
    if len(egg_groups) < 2:
        ret = egg_groups[0]
    else:
        ret = egg_groups[1]
    return POKE_API_EGG_GROUPS[ret['name']]


def gen_mon(mon_data_url, species_data: dict, mon_name: str, fout: typing.TextIO):
    mon_data = requests.get(mon_data_url).json()
    fout.write(BASE_STATS_TEMPLATE.format(
        species=mon_name,
        base_hp=mon_data['stats'][0]['base_stat'],
        base_attack=mon_data['stats'][1]['base_stat'],
        base_defense=mon_data['stats'][2]['base_stat'],
        base_speed=mon_data['stats'][5]['base_stat'],
        base_spatk=mon_data['stats'][3]['base_stat'],
        base_spdef=mon_data['stats'][4]['base_stat'],
        type_1=mon_data['types'][0]['type']['name'].upper(),
        type_2=get_type_2(mon_data['types']),
        ability1=upper_snake(mon_data['abilities'][0]['ability']['name']),
        ability2=get_ability_2(mon_data['abilities']),
        item1='NONE',   # dex expansion mons don't have default item data (for now)
        item2='NONE',
        ev_hp=mon_data['stats'][0]['effort'],
        ev_attack=mon_data['stats'][1]['effort'],
        ev_defense=mon_data['stats'][2]['effort'],
        ev_speed=mon_data['stats'][5]['effort'],
        ev_spatk=mon_data['stats'][3]['effort'],
        ev_spdef=mon_data['stats'][4]['effort'],
        catch_rate=species_data['capture_rate'],
        flee_rate='0',  # dex expansion mons are not in the safari zone (for now)
        gender_ratio=(255 if species_data['gender_rate'] == -1 else species_data['gender_rate']),
        base_friendship=species_data['base_happiness'],
        exp_curve=POKE_API_EXP_CURVES[species_data['growth_rate']['name']],
        exp_yield=('0' if not mon_data['base_experience'] else mon_data['base_experience']),
        egg_cycles=species_data['hatch_counter'],
        egg_group1=POKE_API_EGG_GROUPS[species_data['egg_groups'][0]['name']],
        egg_group2=get_egg_group_2(species_data['egg_groups']),
        body_color=species_data['color']['name'].upper(),
        reverse='FALSE',
    ))


def gen_tms(mon_name: str, fout: typing.TextIO):
    name = mon_name
    if mon_name[-5:] == '_MEGA':    # Megas don't have special TM learnsets
        name = mon_name[:-5]
    fout.write(TM_LEARNSETS_TEMPLATE.format(species=name))
