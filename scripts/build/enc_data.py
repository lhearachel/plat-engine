import json
import os
import sys

from ndspy.narc import NARC
from util import Species


BASE_ENCOUNTER_NARC = 'base/data/fielddata/encountdata/pl_enc_data.narc'


def dump_grass_encs(grass_encs: bytes) -> dict:
    encs = []
    for i in range(12):
        encs.append({
            'level': int.from_bytes(grass_encs[i*8:(i*8)+4], 'little'),
            'species': Species(int.from_bytes(grass_encs[(i*8)+4:(i*8)+8], 'little')).name
        })

    return encs


def dump_44_slots(slots: bytes) -> list:
    encs = []
    for i in range(5):
        encs.append({
            'min_level': slots[(i*8)+1],
            'max_level': slots[(i*8)],
            # 2 bytes of padding
            'species': Species(int.from_bytes(slots[(i*8)+4:(i*8)+8], 'little')).name
        })

    return encs


def dump_44_chunk(chunk: bytes) -> dict:
    return {
        'rate': int.from_bytes(chunk[0:4], 'little'),
        'slots': dump_44_slots(chunk[4:44])
    }


def dump_encfile(encfile: bytes) -> dict:
    return {
        'grass': {
            'rate': int.from_bytes(encfile[0:4], 'little'),
            'slots': dump_grass_encs(encfile[4:100]),
            'swarm': [
                Species(int.from_bytes(encfile[100:104], 'little')).name,
                Species(int.from_bytes(encfile[104:108], 'little')).name
            ],
            'day_only': [
                Species(int.from_bytes(encfile[108:112], 'little')).name,
                Species(int.from_bytes(encfile[112:116], 'little')).name
            ],
            'night_only': [
                Species(int.from_bytes(encfile[116:120], 'little')).name,
                Species(int.from_bytes(encfile[120:124], 'little')).name
            ],
            'poke_radar': [
                Species(int.from_bytes(encfile[124:128], 'little')).name,
                Species(int.from_bytes(encfile[128:132], 'little')).name,
                Species(int.from_bytes(encfile[132:136], 'little')).name,
                Species(int.from_bytes(encfile[136:140], 'little')).name
            ],
            'dual_pack': {
                'ruby': [
                    Species(int.from_bytes(encfile[164:168], 'little')).name,
                    Species(int.from_bytes(encfile[168:172], 'little')).name
                ],
                'sapphire': [
                    Species(int.from_bytes(encfile[172:176], 'little')).name,
                    Species(int.from_bytes(encfile[176:180], 'little')).name
                ],
                'emerald': [
                    Species(int.from_bytes(encfile[180:184], 'little')).name,
                    Species(int.from_bytes(encfile[184:188], 'little')).name
                ],
                'fire_red': [
                    Species(int.from_bytes(encfile[188:192], 'little')).name,
                    Species(int.from_bytes(encfile[192:196], 'little')).name
                ],
                'leaf_green': [
                    Species(int.from_bytes(encfile[196:200], 'little')).name,
                    Species(int.from_bytes(encfile[200:204], 'little')).name
                ],
            }
        },
        'surfing': dump_44_chunk(encfile[204:248]),
        'fishing': {
            'old': dump_44_chunk(encfile[292:336]),
            'good': dump_44_chunk(encfile[336:380]),
            'super': dump_44_chunk(encfile[380:424])
        },
        'forms': {
            'shellos': 'WEST' if int.from_bytes(encfile[140:144], 'little') == 0 else 'EAST',
            'gastrodon': 'WEST' if int.from_bytes(encfile[144:148], 'little') == 0 else 'EAST',
            # 148 through 160 unused atm
            'unown_table': int.from_bytes(encfile[160:164], 'little')
        },
    }


def build_grass_slots(grass_slots: list) -> bytes:
    binary = bytearray([])
    for slot in grass_slots:
        binary = binary + slot['level'].to_bytes(4, 'little')
        binary = binary + Species[slot['species']].value.to_bytes(4, 'little')
    
    return binary


def build_forms_data(forms: dict) -> bytes:
    binary = bytearray([])
    binary = binary + ((0 if forms['shellos'] == 'WEST' else 100)).to_bytes(4, 'little')
    binary = binary + ((0 if forms['gastrodon'] == 'WEST' else 100)).to_bytes(4, 'little')
    binary = binary + (0).to_bytes(12, 'little')    # 12 unused bytes
    binary = binary + forms['unown_table'].to_bytes(4, 'little')

    return binary


def build_44_chunk(chunk: dict):
    binary = bytearray([])
    binary = binary + chunk['rate'].to_bytes(4, 'little')
    
    for i in range(5):
        binary = binary + chunk['slots'][i]['max_level'].to_bytes(1, 'little')
        binary = binary + chunk['slots'][i]['min_level'].to_bytes(1, 'little')
        binary = binary + (0).to_bytes(2, 'little') # 2 bytes of padding
        binary = binary + Species[chunk['slots'][i]['species']].value.to_bytes(4, 'little')
    
    return binary


def build_encfile(encjson: dict) -> bytes:
    binary = bytearray([])
    binary = binary + encjson['grass']['rate'].to_bytes(4, 'little')
    binary = binary + build_grass_slots(encjson['grass']['slots'])
    binary = binary + Species[encjson['grass']['swarm'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['swarm'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['day_only'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['day_only'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['night_only'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['night_only'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['poke_radar'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['poke_radar'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['poke_radar'][2]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['poke_radar'][3]].value.to_bytes(4, 'little')
    binary = binary + build_forms_data(encjson['forms'])
    binary = binary + Species[encjson['grass']['dual_pack']['ruby'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['ruby'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['sapphire'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['sapphire'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['emerald'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['emerald'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['fire_red'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['fire_red'][1]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['leaf_green'][0]].value.to_bytes(4, 'little')
    binary = binary + Species[encjson['grass']['dual_pack']['leaf_green'][1]].value.to_bytes(4, 'little')
    binary = binary + build_44_chunk(encjson['surfing'])
    # 44 bytes of padding (will use this eventually for rock smash)
    binary = binary + (0).to_bytes(44, 'little')
    binary = binary + build_44_chunk(encjson['fishing']['old'])
    binary = binary + build_44_chunk(encjson['fishing']['good'])
    binary = binary + build_44_chunk(encjson['fishing']['super'])

    return binary


def dump_encounters():
    if not os.path.exists('data/encounters'):
        os.makedirs('data/encounters')
    
    encnarc = NARC.fromFile(BASE_ENCOUNTER_NARC)
    for i in range(len(encnarc.files)):
        print(f'Dumping file {i}')
        encdata = dump_encfile(encnarc.files[i])
        with open(f'data/encounters/{i:03}.json', 'w', encoding='utf8') as out:
            json.dump(encdata, out, indent=4, ensure_ascii=False)


def build_encounters():
    if not os.path.exists('build/encdata'):
        os.makedirs('build/encdata')
    
    for i, name in enumerate(sorted(os.listdir('data/encounters'))):
        fin = open(os.path.join('data/encounters', name), 'r', encoding='utf8')
        encjson = json.load(fin)
        encdata = build_encfile(encjson)
        with open(f'build/encdata/{i:03}.bin', 'wb') as fout:
            fout.write(encdata)
        fin.close()


if __name__ == '__main__':
    if sys.argv[1] == 'dump':
        dump_encounters()
    elif sys.argv[1] == 'build':
        build_encounters()
