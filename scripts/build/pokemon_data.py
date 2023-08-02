import json
import os
import sys

from ndspy.narc import NARC
from form_table import FORM_TABLE
from util import (
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
POKEMON_ARTICLES   = 413
POKEDEX_NAMES_BANK = 712
BUILD_PERSONAL_DIR = 'build/poketool/personal'


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
        EvoMethod.USE_ITEM,
        EvoMethod.USE_ITEM_MALE,
        EvoMethod.USE_ITEM_FEMALE,
        EvoMethod.USE_ITEM_DAY,
        EvoMethod.USE_ITEM_NIGHT]):
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
        if i < 496:
            name = name_txt.readline().strip()
        else:
            name = extra_names[i - 494]

        print(f'Dumping {name}')
        pokemon = dump_personal(personal.files[i], name)
        pokemon = dump_levelup_learnset(learnset.files[i], pokemon)
        pokemon = dump_evolutions(evotable.files[i], pokemon)

        with open(f'data/pokemon/{i:04}.json', 'w', encoding='utf8') as out:
            json.dump(pokemon, out, indent=4, ensure_ascii=False)
    
    name_txt.close()


def pack_ev_yields(ev_yields: dict) -> bytes:
    packed = ev_yields['hp']
    packed = packed + (ev_yields['attack'] << 2)
    packed = packed + (ev_yields['defense'] << 4)
    packed = packed + (ev_yields['speed'] << 6)
    packed = packed + (ev_yields['sp_attack'] << 8)
    packed = packed + (ev_yields['sp_defense'] << 10)

    return packed.to_bytes(2, 'little')


def pack_color(body_color: BodyColor, flip: bool) -> bytes:
    packed = BodyColor[body_color].value
    packed = packed + ((1 if flip else 0) << 7)
    return packed.to_bytes(1, 'little')


def pack_tms(tms: list[str]) -> bytes:
    tms_1, tms_2, tms_3, tms_4 = (0, 0, 0, 0)
    for tm_str in tms:
        tm_idx = Item[tm_str].value - 328
        if tm_idx < 32:
            tms_1 = tms_1 | (1 << tm_idx)
        elif tm_idx < 64:
            tms_2 = tms_2 | (1 << tm_idx - 32)
        elif tm_idx < 96:
            tms_3 = tms_3 | (1 << tm_idx - 64)
        else:
            tms_4 = tms_4 | (1 << tm_idx - 96)

    
    binary = bytearray([])
    binary = binary + tms_1.to_bytes(4, 'little')
    binary = binary + tms_2.to_bytes(4, 'little')
    binary = binary + tms_3.to_bytes(4, 'little')
    binary = binary + tms_4.to_bytes(4, 'little')
    return binary


def build_personal(pokemon: dict, i: int):
    if not pokemon:
        return
    
    binary = bytearray([])

    # base stats
    base_stats = pokemon['base_stats']
    binary = binary + base_stats['hp'].to_bytes(1, 'little')
    binary = binary + base_stats['attack'].to_bytes(1, 'little')
    binary = binary + base_stats['defense'].to_bytes(1, 'little')
    binary = binary + base_stats['speed'].to_bytes(1, 'little')
    binary = binary + base_stats['sp_attack'].to_bytes(1, 'little')
    binary = binary + base_stats['sp_defense'].to_bytes(1, 'little')

    # types
    binary = binary + Type[pokemon['types'][0]].value.to_bytes(1, 'little')
    binary = binary + Type[pokemon['types'][1]].value.to_bytes(1, 'little')
    
    # catch rate
    binary = binary + pokemon['catch_rate'].to_bytes(1, 'little')

    # base experience
    binary = binary + pokemon['base_exp_reward'].to_bytes(1, 'little')

    # ev yields
    binary = binary + pack_ev_yields(pokemon['ev_yields'])

    # held items
    binary = binary + Item[pokemon['held_items']['50%']].value.to_bytes(2, 'little')
    binary = binary + Item[pokemon['held_items']['5%']].value.to_bytes(2, 'little')
    
    # gender ratio
    binary = binary + GenderRatio[pokemon['gender_ratio']].value.to_bytes(1, 'little')

    # hatch multiplier
    binary = binary + (0 if not pokemon['hatch_multiplier'] else pokemon['hatch_multiplier']).to_bytes(1, 'little')

    # base happiness
    binary = binary + (0 if not pokemon['base_happiness'] else pokemon['base_happiness']).to_bytes(1, 'little')

    # growth rate
    binary = binary + GrowthRate[pokemon['growth_rate']].value.to_bytes(1, 'little')

    # egg groups
    binary = binary + EggGroup[pokemon['egg_groups'][0]].value.to_bytes(1, 'little')
    binary = binary + EggGroup[pokemon['egg_groups'][1]].value.to_bytes(1, 'little')

    # abilities
    # TODO: Figure out how to expand the ability structure to support more than 8 bits
    # in the personal file
    binary = binary + (Ability[pokemon['abilities']['0']].value & 0xFF).to_bytes(1, 'little')
    if '1' in pokemon['abilities']:
        binary = binary + (Ability[pokemon['abilities']['1']].value & 0xFF).to_bytes(1, 'little')
    else:
        binary = binary + (0).to_bytes(1, 'little')

    # flee chance
    binary = binary + pokemon['flee_chance'].to_bytes(1, 'little')

    # body color + flip sprite
    binary = binary + pack_color(pokemon['body_color'], pokemon['flip_sprite'])

    # 2 bytes of padding
    binary = binary + (0).to_bytes(2, 'little')

    # tm learnset
    binary = binary + pack_tms(pokemon['learnset']['tms'])

    with open(BUILD_PERSONAL_DIR + f'/pl_personal/{i:04}.bin', 'wb') as out:
        out.write(binary)


def build_evo_params(method: EvoMethod, evo: list) -> bytes:
    maybe_param = evo[1]
    final_param = 0
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
        final_param = 0
    # These all specify a basic integer param
    elif method in set([
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
        final_param = maybe_param
    # These specify an item
    elif method in set([
        EvoMethod.TRADE_WITH_ITEM,
        EvoMethod.USE_ITEM,
        EvoMethod.USE_ITEM_MALE,
        EvoMethod.USE_ITEM_FEMALE,
        EvoMethod.USE_ITEM_DAY,
        EvoMethod.USE_ITEM_NIGHT]):
        final_param = Item[maybe_param].value
    elif method == EvoMethod.KNOW_MOVE:
        final_param = Move[maybe_param].value
    elif method == EvoMethod.MON_IN_PARTY:
        final_param = Species[maybe_param].value
    
    return final_param.to_bytes(2, 'little')


def build_evotable(pokemon: dict, i: int):
    out = open(BUILD_PERSONAL_DIR + f'/evo/{i:04}.bin', 'wb')
    if 'evolutions' not in pokemon: # no evos, write all 0s
        out.write((0).to_bytes(44, 'little'))
        return
    
    evos = pokemon['evolutions']
    if len(evos) > 7:
        print(f'Found {len(evos)} evolutions in file {i:04}.json')
        print(f'Only the first 7 evolutions will be translated')

    # 6 bytes per entry, 7 entries total = 42 bytes
    # 2 bytes of 0 padding at the end = 44 bytes
    binary = bytearray([])
    for j in range(min(len(evos), 7)):
        evo = evos[j]
        method = EvoMethod[evo[0]]
        params = build_evo_params(method, evo)

        raw_target = Species[evo[-1]]
        if raw_target.value > Species.ENAMORUS.value: # Must be a form, check the form table
            if raw_target.name not in FORM_TABLE.keys():
                print(f'❌ Unrecognized evo target {raw_target.name}; did you update the form table?')
                raise RuntimeError

            target, form = FORM_TABLE[raw_target.name]
            target = target.value | (form << 11)
        else:
            target = raw_target.value

        binary = binary + method.value.to_bytes(2, 'little')
        binary = binary + params
        binary = binary + target.to_bytes(2, 'little')

    if len(binary) < 42:
        binary = binary + (0).to_bytes(42 - len(binary), 'little')
    
    binary = binary + (0).to_bytes(2, 'little')
    out.write(binary)
    out.close()


def build_learnset(pokemon: dict, i: int):
    out = open(BUILD_PERSONAL_DIR + f'/wotbl/{i:04}.bin', 'wb')
    if 'learnset' not in pokemon or 'level_up' not in pokemon['learnset']:
        out.write((65535).to_bytes(4, 'little'))
        out.close()
        return

    level_up = { int(k): v for (k, v) in pokemon['learnset']['level_up'].items() }
    num_moves = 0
    binary = bytearray([])
    for level in sorted(level_up.keys()):
        if num_moves >= 20:
            break
        if isinstance(level_up[level], list):
            for move in level_up[level]:
                if num_moves >= 20:
                    break
                packed = ((level & 0x7f) << 9) | (Move[move].value & 0x1ff)
                binary = binary + packed.to_bytes(2, 'little')
                num_moves = num_moves + 1
        else:
            move = level_up[level]
            packed = ((level & 0x7f) << 9) | (Move[move].value & 0x1ff)
            binary = binary + packed.to_bytes(2, 'little')
            num_moves = num_moves + 1

    if (num_moves * 2) % 4 == 0:
        binary = binary + (65535).to_bytes(4, 'little')
    else:
        binary = binary + (65535).to_bytes(2, 'little')
    
    out.write(binary)
    out.close()


def build_pokemon():
    if not os.path.exists(BUILD_PERSONAL_DIR):
        os.makedirs(BUILD_PERSONAL_DIR)
    if not os.path.exists(BUILD_PERSONAL_DIR + '/pl_personal'):
        os.makedirs(BUILD_PERSONAL_DIR + '/pl_personal')
    if not os.path.exists(BUILD_PERSONAL_DIR + '/evo'):
        os.makedirs(BUILD_PERSONAL_DIR + '/evo')
    if not os.path.exists(BUILD_PERSONAL_DIR + '/wotbl'):
        os.makedirs(BUILD_PERSONAL_DIR + '/wotbl')

    names_file = open(TEXT_DUMP_TARGET.format(archive=POKEMON_NAMES_BANK), 'w', encoding='utf8')
    articles_file = open(TEXT_DUMP_TARGET.format(archive=POKEMON_ARTICLES), 'w', encoding='utf8')
    pokedex_file = open(TEXT_DUMP_TARGET.format(archive=POKEDEX_NAMES_BANK), 'w', encoding='utf8')
    mon_ids_to_names = {}
    for fname in os.listdir('data/pokemon'):
        print(f'-- Building {fname}')
        with open(f'data/pokemon/{fname}', 'r', encoding='utf8') as data:
            pokemon = json.load(data)
            name = pokemon['name']
            i = Species[fname.split('.')[0].upper()].value

            if i <= Species.ENAMORUS.value: # everything after enamorus is a form
                mon_ids_to_names[i] = name

            build_personal(pokemon, i)
            build_evotable(pokemon, i)
            build_learnset(pokemon, i)
    
    # Sort the keys of the dictionary (numerical species IDs)
    sorted_mon_ids = list(mon_ids_to_names.keys())
    sorted_mon_ids.sort()

    dex_counter = 0
    for mon_id in sorted_mon_ids:
        name = mon_ids_to_names[mon_id]
        if name == '-----' or (mon_id > 493 and mon_id < 544):
            articles_file.write('\r\n')
            pokedex_file.write('----------\r\n')
            name = '-----'
        else:
            dex_counter += 1
            article = 'a '
            if name[0] in ['A', 'E', 'I', 'O', 'U']:
                article = 'an '

            articles_file.write(f'{article}{{COLOR 255}}{name}{{COLOR 0}}\r\n')
            pokedex_file.write(f'{dex_counter:03}  {name}\r\n')

        names_file.write(f'{name}\r\n')
    
    names_file.close()
    articles_file.close()
    pokedex_file.close()


if __name__ == '__main__':
    if sys.argv[1] == 'dump':
        dump_pokemon()
    elif sys.argv[1] == 'build':
        build_pokemon()
