import requests

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
SPECIES_DEF_TEMPLATE = '#define SPECIES_{name}    {species_id:#06X}\n'


def get_mon_data(mon_num: int) -> dict:
    url = f'{POKE_API_URL}{POKEMON_ENDPOINT.format(num=mon_num)}'
    return requests.get(url).json()


def get_species_data(species_num: int) -> dict:
    url = f'{POKE_API_URL}{SPECIES_ENDPOINT.format(num=species_num)}'
    return requests.get(url).json()


def offset(dex_num: int) -> int:
    return DEX_EXPANSION_START - UNOVA_DEX_START + dex_num


def gen(start: int, end: int):
    with open(GENERATED_FILE, 'w') as gen:
        for dex_num in range(start, end):
            try:
                species_data = get_species_data(dex_num)
                species_name = species_data['name']
                gen.write(SPECIES_DEF_TEMPLATE.format(name=species_name.upper(), species_id=offset(dex_num)))
            except Exception as e:
                print(e)


def gen_5():
    gen(UNOVA_DEX_START, KALOS_DEX_START)


def gen_6():
    gen(KALOS_DEX_START, ALOLA_DEX_START)


def gen_7():
    gen(ALOLA_DEX_START, GALAR_DEX_START)


def gen_8():
    gen(GALAR_DEX_START, PALDEA_DEX_START)


def gen_9():
    gen(PALDEA_DEX_START, DEX_END + 1)
