import json
import re
import requests

from scripts.build.util import GenderRatio, GrowthRate, EggGroup, BodyColor, Move, EvoMethod


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


def build_json(species_json: dict, poke_json: dict) -> dict:
    poke = {}
    
    # name
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
           key = 'H'

        poke['abilities'][key] = snake_case(poke_json['abilities'][i]['ability']['name']).upper()
    
    # held_items (empty for now, both none)
    poke['held_items'] = {
        '50%': 'NONE',
        '5%': 'NONE'
    }

    poke['catch_rate'] = species_json['capture_rate']
    poke['base_exp_reward'] = min(255, poke_json['base_experience'])

    poke['ev_yields'] = {}
    poke['ev_yields']['hp'] = poke_json['stats'][0]['effort']
    poke['ev_yields']['attack'] = poke_json['stats'][1]['effort']
    poke['ev_yields']['defense'] = poke_json['stats'][2]['effort']
    poke['ev_yields']['sp_attack'] = poke_json['stats'][3]['effort']
    poke['ev_yields']['sp_defense'] = poke_json['stats'][4]['effort']
    poke['ev_yields']['speed'] = poke_json['stats'][5]['effort']

    poke['gender_ratio'] = GENDER_RATIOS[species_json['gender_rate']].name
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


def build_species(species: int) -> (str, dict):
    species_json = get_pokeapi_species(species)
    poke_json = get_pokeapi_pokemon(species)
    return (snake_case(poke_json['name']), build_json(species_json, poke_json))


def build_range(start: int, end: int) -> dict:
    for i in range(start, end + 1):
        print(f'Dumping {i}')
        name, j = build_species(i)
        f = open(f'data/pokemon/{name}.json', 'w', encoding='utf8')
        json.dump(j, f, indent=4, ensure_ascii=False)
        f.close()
