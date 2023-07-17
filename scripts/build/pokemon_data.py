import json
import os

from ndspy.narc import NARC
from .util import (
    Type,
    Ability,
    GenderRatio,
    GrowthRate,
    Item,
    EggGroup,
    BodyColor,
    Move,
    EvoMethod,
    Species
)

BASE_PERSONAL_NARC = 'base/data/poketool/personal/pl_personal.narc'
BASE_EVOTABLE_NARC = 'base/data/poketool/personal/evo.narc'
BASE_LEARNSET_NARC = 'base/data/poketool/personal/wotbl.narc'
TEXT_DUMP_TARGET   = 'data/text/{archive}.txt'
POKEMON_NAMES_BANK = 412


def dump_tm_list(packed_tms_1: int, packed_tms_2: int, packed_tms_3: int, packed_tms_4: int) -> list[int]:
    tm_list_1 = []
    tm_list_2 = []
    tm_list_3 = []
    tm_list_4 = []
    for i in range(32):
        bit = 1 << i
        if packed_tms_1 & bit:
            tm_list_1.append(Item(328 + i).name)
        if packed_tms_2 & bit:
            tm_list_2.append(Item(328 + 32 + i).name)
        if packed_tms_3 & bit:
            tm_list_3.append(Item(328 + 64 + i).name)
        if packed_tms_4 & bit:
            tm_list_4.append(Item(328 + 96 + i).name)
    
    return tm_list_1 + tm_list_2 + tm_list_3 + tm_list_4


def dump_personal(personal_file: bytes, name: str) -> dict:
    packed_evs = int.from_bytes(personal_file[10:12], 'little')
    packed_tms_1 = int.from_bytes(personal_file[28:32], 'little')
    packed_tms_2 = int.from_bytes(personal_file[32:36], 'little')
    packed_tms_3 = int.from_bytes(personal_file[36:40], 'little')
    packed_tms_4 = int.from_bytes(personal_file[40:44], 'little')
    return {
        'name': name,
        'base_stats': {
            'hp': personal_file[0],
            'attack': personal_file[1],
            'defense': personal_file[2],
            'sp_attack': personal_file[4],
            'sp_defense': personal_file[5],
            'speed': personal_file[3]
        },
        'types': [
            Type(personal_file[6]).name,
            Type(personal_file[7]).name
        ],
        'abilities': {
            '0': Ability(personal_file[22]).name,
            '1': Ability(personal_file[23]).name
        },
        'held_items': {
            '50%': Item(int.from_bytes(personal_file[12:14], 'little')).name,
            '5%': Item(int.from_bytes(personal_file[14:16], 'little')).name
        },
        'catch_rate': personal_file[8],
        'base_exp_reward': personal_file[9],
        'ev_yields': { # 10, 11
            'hp': (packed_evs & 0x0003),
            'attack': (packed_evs & 0x000C) >> 2,
            'defense': (packed_evs & 0x0030) >> 4,
            'sp_attack': (packed_evs & 0x0300) >> 8,
            'sp_defense': (packed_evs & 0x0C00) >> 10,
            'speed': (packed_evs & 0x00C0) >> 6
        },
        'gender_ratio': GenderRatio(personal_file[16]).name,
        'hatch_multiplier': personal_file[17],
        'base_happiness': personal_file[18],
        'growth_rate': GrowthRate(personal_file[19]).name,
        'egg_groups': [
            EggGroup(personal_file[20]).name,
            EggGroup(personal_file[21]).name
        ],
        'flee_chance': personal_file[24],
        'body_color': BodyColor(personal_file[25] & 0x7F).name,
        'flip_sprite': bool((personal_file[25] & 0x80) >> 7),
        'learnset': {
            'tms': dump_tm_list(packed_tms_1, packed_tms_2, packed_tms_3, packed_tms_4)
        }
    }


def dump_levelup_learnset(learnset_file: bytes, pokemon: dict) -> dict:
    pokemon['learnset']['level_up'] = {}
    terminator = [255, 255, 0, 0]
    if learnset_file[-4] == terminator:
        num_moves = (len(learnset_file) - 4) / 2
    else:
        num_moves = (len(learnset_file) - 2) / 2
    
    for i in range(0, len(learnset_file), 2):
        pair = learnset_file[i:i+2]
        if pair[0] == 255 and pair[1] == 255:
            break

        move_data = int.from_bytes(pair, 'little')
        level = str((move_data >> 9) & 0x7F)
        move = Move(move_data & 0x1FF).name
        if level not in pokemon['learnset']['level_up']:
            # no move here yet; just store the value
            pokemon['learnset']['level_up'][level] = move
        elif isinstance(pokemon['learnset']['level_up'][level], str):
            # already a move here; merge into a list
            tmp = [pokemon['learnset']['level_up'][level], move]
            pokemon['learnset']['level_up'][level] = tmp
        elif isinstance(pokemon['learnset']['level_up'][level], list):
            # already multiple moves here; add onto the list
            pokemon['learnset']['level_up'][level].append(move)

    return pokemon


def parse_evo_params(params: bytes, method: EvoMethod) -> int | str | None:
    # None of these take an extra parameter    
    if method in set([
        EvoMethod.NONE,
        EvoMethod.HAPPINESS,
        EvoMethod.HAPPINESS_DAY,
        EvoMethod.HAPPINESS_NIGHT,
        EvoMethod.TRADE,
        EvoMethod.ELECTRIC_FIELD,
        EvoMethod.MOSSY_STONE,
        EvoMethod.ICY_STONE]):
        return None
    
    # These all specify a basic integer param
    if method in set([
        EvoMethod.LEVEL_UP,
        EvoMethod.LEVEL_ATK_GT_DEF,
        EvoMethod.LEVEL_ATK_EQ_DEF,
        EvoMethod.LEVEL_ATK_LT_DEF,
        EvoMethod.LEVEL_PID_LOW,
        EvoMethod.LEVEL_PID_HIGH,
        EvoMethod.LEVEL_NINJASK,
        EvoMethod.LEVEL_SHEDINJA,
        EvoMethod.LEVEL_MALE,
        EvoMethod.LEVEL_FEMALE,
        EvoMethod.BEAUTY]):
        return int.from_bytes(params, 'little')
    
    # These specify an item
    if method in set([
        EvoMethod.TRADE_WITH_ITEM,
        EvoMethod.USE_ITEM]):
        return Item(int.from_bytes(params, 'little')).name

    if method == EvoMethod.KNOW_MOVE:
        return Move(int.from_bytes(params, 'little')).name

    if method == EvoMethod.MON_IN_PARTY:
        return Species(int.from_bytes(params, 'little')).name


def dump_evolutions(evolution_file: bytes, pokemon: dict) -> dict:
    for i in range(7):
        offset = i * 6
        method_idx = 0 + offset
        params_idx = 2 + offset
        target_idx = 4 + offset

        method = EvoMethod(evolution_file[method_idx])
        if method == EvoMethod.NONE:
            continue

        # params casting depends on the input method
        params = parse_evo_params(evolution_file[params_idx:params_idx+2], method)
        target = Species(int.from_bytes(evolution_file[target_idx:target_idx+2], 'little')).name
        if 'evolutions' not in pokemon:
            pokemon['evolutions'] = []
        if params is None:
            pokemon['evolutions'].append((method.name, target))
        else:
            pokemon['evolutions'].append((method.name, params, target))
    
    return pokemon


def dump_pokemon():
    # TODO: Egg moves, move tutor data
    # FUTURE: Hidden abilities
    if not os.path.exists('data/pokemon'):
        os.makedirs('data/pokemon')
    
    personal = NARC.fromFile(BASE_PERSONAL_NARC)
    evotable = NARC.fromFile(BASE_EVOTABLE_NARC)
    learnset = NARC.fromFile(BASE_LEARNSET_NARC)
    name_txt = open(TEXT_DUMP_TARGET.format(archive=POKEMON_NAMES_BANK), 'r')
    extra_names = [
        'Egg',
        'Bad Egg',
        'Deoxys-Attack',
        'Deoxys-Defense',
        'Deoxys-Speed',
        'Wormadam-Sandy',
        'Wormadam-Trash',
        'Giratina-Origin',
        'Shaymin-Sky',
        'Rotom-Heat',
        'Rotom-Wash',
        'Rotom-Frost',
        'Rotom-Fan',
        'Rotom-Mow'
    ]
    for i in range(508):
        if i < 494:
            name = name_txt.readline().strip()
        else:
            name = extra_names[i - 494]

        print(f'Dumping {name}')
        pokemon = dump_personal(personal.files[i], name)
        pokemon = dump_levelup_learnset(learnset.files[i], pokemon)
        pokemon = dump_evolutions(evotable.files[i], pokemon)

        folder = f'{i // 100:02}'
        with open(f'data/pokemon/{folder}/{i:04}.json', 'w', encoding='utf8') as out:
            json.dump(pokemon, out, indent=4, ensure_ascii=False)
    
    name_txt.close()
