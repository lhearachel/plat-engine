import json
import os
import sys

from ndspy.narc import NARC
from util import Item, Species, Move, TrainerClass


BASE_TRDATA_NARC = 'base/data/poketool/trainer/trdata.narc'
BASE_TRPOKE_NARC = 'base/data/poketool/trainer/trpoke.narc'
BASE_TRNAME_FILE = 'data/text/618.txt'


def parse_data_flags(data_flags: int) -> dict:
    return {
        'defined_moveset': bool(data_flags & 1),
        'defined_held_items': bool(data_flags & 2),
    }


def parse_ai_flags(ai_flags: int) -> dict:
    return {
        'prioritize_effectiveness': bool(ai_flags & 1),
        'check_bad_move': bool(ai_flags & (1 << 1)),
        'expert': bool(ai_flags & (1 << 2)),
        'setup_first_turn': bool(ai_flags & (1 << 3)),
        'risky': bool(ai_flags & (1 << 4)),
        'prioritize_damage': bool(ai_flags & (1 << 5)),
        'partner': bool(ai_flags & (1 << 6)),
        'doubles': bool(ai_flags & (1 << 7)),
        'check_hp': bool(ai_flags & (1 << 8)),
        'weather': bool(ai_flags & (1 << 9)),
        'harrassment': bool(ai_flags & (1 << 10)),
    }


def parse_party(party_data: bytes, data_flags: dict, party_size: int) -> list[dict]:
    party = []
    member_size = 8
    if data_flags['defined_moveset']:
        member_size = member_size + 8
    if data_flags['defined_held_items']:
        member_size = member_size + 2

    for i in range(party_size):
        start = (member_size * i)
        seal_idx = (member_size * (i + 1)) - 2
        party.append({
            'difficulty_value': party_data[start],
            'ability_slot': party_data[start+1],
            'level': int.from_bytes(party_data[start+2:start+4], 'little'),
            'species': Species(int.from_bytes(party_data[start+4:start+6], 'little') & 0x3FF).name,
            'form': int.from_bytes(party_data[start+4:start+6], 'little') >> 10,
            'ball_seal': int.from_bytes(party_data[seal_idx:seal_idx+2], 'little'),
        })

        moves_offs = start + 6
        if data_flags['defined_held_items']:
            moves_offs = moves_offs + 2
            party[i]['held_item'] = Item(int.from_bytes(party_data[start+6:start+8], 'little')).name
        else:
            party[i]['held_item'] = Item.NONE.name
        
        if data_flags['defined_moveset']:
            party[i]['moves'] = [
                Move(int.from_bytes(party_data[moves_offs:moves_offs+2], 'little')).name,
                Move(int.from_bytes(party_data[moves_offs+2:moves_offs+4], 'little')).name,
                Move(int.from_bytes(party_data[moves_offs+4:moves_offs+6], 'little')).name,
                Move(int.from_bytes(party_data[moves_offs+6:moves_offs+8], 'little')).name,
            ]
        else:
            party[i]['moves'] = []
    
    return party


def dump_trainer(trainer_data: bytes, party_data: bytes, name: str) -> dict:
    # Size of the trainer data structure is constant: 20 bytes
    #   - last 3 bytes are padding
    #   - byte index 2 is also padding (?)
    # Size (and interpretation) of the party data is dependent on a flag field in the trainer data
    data_flags = parse_data_flags(trainer_data[0])
    return {
        'name': name,
        'class': TrainerClass(trainer_data[1]).name,
        'double_battle': bool(trainer_data[16]),
        'party_size': trainer_data[3],
        'items': [
            Item(int.from_bytes(trainer_data[4:6], 'little')).name,
            Item(int.from_bytes(trainer_data[6:8], 'little')).name,
            Item(int.from_bytes(trainer_data[8:10], 'little')).name,
            Item(int.from_bytes(trainer_data[10:12], 'little')).name,
        ],
        'ai_flags': parse_ai_flags(int.from_bytes(trainer_data[12:16], 'little')),
        'data_flags': data_flags,
        'party': parse_party(party_data, data_flags, trainer_data[3])
    }


def dump_trainers():
    if not os.path.exists('data/trainers'):
        os.makedirs('data/trainers')

    trdata = NARC.fromFile(BASE_TRDATA_NARC)
    trpoke = NARC.fromFile(BASE_TRPOKE_NARC)
    trname = open(BASE_TRNAME_FILE, 'r', encoding='utf8')

    assert len(trdata.files) == len(trpoke.files), 'TRDATA AND TRPOKE ARE NOT EQUAL SIZE'

    for i in range(len(trdata.files)):
        trdata_file = trdata.files[i]
        trpoke_file = trpoke.files[i]
        trname_entry = trname.readline().strip()

        if trname_entry.startswith('{TRNAME}'):
            trname_entry = trname_entry[8:]
        
        print(f'Dumping trainer {i}: {trname_entry}')
        trainer = dump_trainer(trdata_file, trpoke_file, trname_entry)
        with open(f'data/trainers/{i:04}.json', 'w', encoding='utf8') as out:
            json.dump(trainer, out, indent=4, ensure_ascii=False)


def pack_data_flags(data_flags: dict) -> bytes:
    packed = 0
    packed = packed | (int(data_flags['defined_moveset']))
    packed = packed | (int(data_flags['defined_held_items']) << 1)

    return packed.to_bytes(1, 'little')


def pack_ai_flags(ai_flags: dict) -> bytes:
    packed = 0
    packed = packed | (int(ai_flags['prioritize_effectiveness']) << 0)
    packed = packed | (int(ai_flags['check_bad_move']) << 1)
    packed = packed | (int(ai_flags['expert']) << 2)
    packed = packed | (int(ai_flags['setup_first_turn']) << 3)
    packed = packed | (int(ai_flags['risky']) << 4)
    packed = packed | (int(ai_flags['prioritize_damage']) << 5)
    packed = packed | (int(ai_flags['partner']) << 6)
    packed = packed | (int(ai_flags['doubles']) << 7)
    packed = packed | (int(ai_flags['check_hp']) << 8)
    packed = packed | (int(ai_flags['weather']) << 9)
    packed = packed | (int(ai_flags['harrassment']) << 10)

    return packed.to_bytes(4, 'little')


def build_trainer(trainer: dict) -> bytes:
    binary = bytearray([])
    binary = binary + pack_data_flags(trainer['data_flags'])
    binary = binary + TrainerClass[trainer['class']].value.to_bytes(1, 'little')
    binary = binary + (0).to_bytes(1, 'little')
    binary = binary + trainer['party_size'].to_bytes(1, 'little')

    binary = binary + Item[trainer['items'][0]].value.to_bytes(2, 'little')
    binary = binary + Item[trainer['items'][1]].value.to_bytes(2, 'little')
    binary = binary + Item[trainer['items'][2]].value.to_bytes(2, 'little')
    binary = binary + Item[trainer['items'][3]].value.to_bytes(2, 'little')

    binary = binary + pack_ai_flags(trainer['ai_flags'])
    binary = binary + (2 if trainer['double_battle'] else 0).to_bytes(1, 'little')
    binary = binary + (0).to_bytes(3, 'little')

    return binary


def pack_species_and_form(party_mon: dict) -> bytes:
    packed = Species[party_mon['species']].value
    packed = packed | (party_mon['form'] << 10)

    return packed.to_bytes(2, 'little')


def build_party(trainer: dict) -> bytes:
    held_items = trainer['data_flags']['defined_held_items']
    movesets = trainer['data_flags']['defined_movesets']
    party_size = trainer['party_size']
    party = trainer['party']

    binary = bytearray([])
    for i in range(len(party_size)):
        binary = binary + party[i]['difficulty_value'].to_bytes(1, 'little')
        binary = binary + party[i]['ability_slot'].to_bytes(1, 'little')
        binary = binary + party[i]['level'].to_bytes(2, 'little')
        binary = binary + pack_species_and_form(party[i])

        if held_items:
            binary = binary + Item[party[i]['held_item']].value.to_bytes(2, 'little')
        if movesets:
            binary = binary + Move[party[i]['moves'][0]].value.to_bytes(2, 'little')
            binary = binary + Move[party[i]['moves'][1]].value.to_bytes(2, 'little')
            binary = binary + Move[party[i]['moves'][2]].value.to_bytes(2, 'little')
            binary = binary + Move[party[i]['moves'][3]].value.to_bytes(2, 'little')
        
        binary = binary + party[i]['ball_seal'].to_bytes(2, 'little')
    
    return binary


def build_trainers_and_parties():
    if not os.path.exists('build/trainers'):
        os.makedirs('build/trainers')
    if not os.path.exists('build/trainers/trdata'):
        os.makedirs('build/trainers/trdata')
    if not os.path.exists('build/trainers/trpoke'):
        os.makedirs('build/trainers/trpoke')

    names_file = open(BASE_TRNAME_FILE, 'w', encoding='utf8')
    for i, fname in enumerate(sorted(os.listdir('data/trainers'))):
        json_data = {}
        with open(f'data/trainers/{fname}', 'r', encoding='utf8') as data_file:
            json_data = json.load(data_file)

        print(f'Building trainer {i}: {json_data["name"]}')
        trdata = build_trainer(json_data)
        trpoke = build_trainer(json_data)

        with open(f'build/trainers/trdata/{i:04}.bin', 'wb') as trdata_bin:
            trdata_bin.write(trdata)
        with open(f'build/trainers/trpoke/{i:04}.bin', 'wb') as trpoke_bin:
            trpoke_bin.write(trpoke)
        
        names_file.write(f'{{TRNAME}}{json_data["name"]}\r\n')

if __name__ == '__main__':
    if sys.argv[1] == 'dump':
        dump_trainers()
    elif sys.argv[1] == 'build':
        build_trainers_and_parties()
