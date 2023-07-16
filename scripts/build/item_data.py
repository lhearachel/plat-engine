import json
import os
import subprocess

from ndspy.narc import NARC
from .util import (
    Type,
    ItemHoldEffect,
    ItemMoveEffect,
    FieldPocket,
    FieldFunction,
    BattlePocket,
    BattleFunction,
    signed_int
)

import tools.narcpy as narcpy


BASE_ITEMDATA_NARC = 'base/data/itemtool/itemdata/pl_item_data.narc'
BASE_MSGDATA_NARC  = 'base/data/msgdata/pl_msg.narc'
ITEM_NAMES_BANK    = 392
TEXT_DUMP_TARGET   = 'data/text/{archive}.txt'
TEMP_DUMP_TARGET   = 'tmp'

MSGENC_DECODE      = ['./tools/msgenc', '-c', 'data/charmap.txt', '-d']
MSGENC_ENCODE      = ['./tools/msgenc', '-c', 'data/charmap.txt', '-e']


def dump_item_names():
    msgdata = NARC.fromFile(BASE_MSGDATA_NARC)
    item_names = msgdata.files[ITEM_NAMES_BANK]
    narcpy.extract(BASE_MSGDATA_NARC, True, TEMP_DUMP_TARGET)
    subprocess.run(MSGENC_DECODE + [f'tmp/pl_msg.narc_{ITEM_NAMES_BANK}', TEXT_DUMP_TARGET.format(archive=ITEM_NAMES_BANK)],
        shell=True,
        check=True
    )


def dump_use_data(item: bytes, item_dict: dict) -> dict:
    # byte 13 is padding
    # bytes 14 through 20 are a tightly-packed sequence
    # 
    # the goal here is to make this structure as sparsely-populated as possible
    # for the sake of user accessibility
    use_params = {}
    recovery = item[14]
    utility = item[15]
    boost_1 = item[16]
    boost_2 = item[17]
    boost_3 = item[18]
    recovery_2 = item[19]
    bitfield_2 = item[20]
    
    if recovery or (recovery_2 & 0x7):
        use_params.setdefault('recover', {})
    if (utility & 0xF0) or boost_1 or boost_2 or (boost_3 & 0x3F):
        use_params.setdefault('raise_stat', {})
    if (recovery_2 & 0xF8) or (bitfield_2 & 1):
        use_params.setdefault('evs', {})
    if bitfield_2 & 0x0E:
        use_params.setdefault('friendship', {})

    if recovery & 1:        # sleep recovery
        use_params['recover']['sleep'] = True
    if recovery & (1 << 1): # poison recovery
        use_params['recover']['poison'] = True
    if recovery & (1 << 2): # burn recovery
        use_params['recover']['burn'] = True
    if recovery & (1 << 3): # freeze recovery
        use_params['recover']['freeze'] = True
    if recovery & (1 << 4): # paralysis recovery
        use_params['recover']['paralysis'] = True
    if recovery & (1 << 5): # confusion recovery
        use_params['recover']['confusion'] = True
    if recovery & (1 << 6): # attract recovery
        use_params['recover']['attraction'] = True
    if recovery & (1 << 7): # guard spec
        use_params['guard_spec'] = True
    
    if utility & 1:         # revive one
        use_params['revive'] = True
    if utility & (1 << 1):  # revive all (sacred ash)
        use_params['revive_all'] = True
    if utility & (1 << 2):  # rare candy
        use_params['level_up'] = True
    if utility & (1 << 3):  # evolution item
        use_params['evolution'] = True

    if utility & 0xF0:      # attack up
        use_params['raise_stat']['attack'] = (utility >> 4) & 0xF
    if boost_1 & 0xF:       # defense up
        use_params['raise_stat']['defense'] = boost_1 & 0xF
    if boost_1 & 0xF0:      # spatk up
        use_params['raise_stat']['sp_attack'] = (boost_1 >> 4) & 0xF
    if boost_2 & 0xF:       # spdef up
        use_params['raise_stat']['sp_defense'] = boost_2 & 0xF
    if boost_2 & 0xF0:      # speed up
        use_params['raise_stat']['speed'] = (boost_2 >> 4) & 0xF
    if boost_3 & 0xF:       # accuracy up
        use_params['raise_stat']['accuracy'] = boost_3 & 0xF
    if boost_3 & 0x30:      # crit rate up
        use_params['raise_stat']['critical'] = (boost_3 >> 4) & 0x3
    
    if boost_3 & 0x40:      # pp up flag
        use_params['pp_up'] = True
    if boost_3 & 0x80:      # pp max flag
        use_params['pp_max'] = True
    if recovery_2 & 1:      # pp recovery flag
        use_params['recover']['pp'] = item[28]
    if recovery_2 & (1 << 1):   # recover all pp flag
        use_params['recover']['pp_all_moves'] = item[28]
    if recovery_2 & (1 << 2):   # recover hp flag
        use_params['recover']['hp'] = item[27]

    if recovery_2 & (1 << 3):   # hp evs flag
        use_params['evs']['hp'] = signed_int(item[21])
    if recovery_2 & (1 << 4):   # atk evs flag
        use_params['evs']['attack'] = signed_int(item[22])
    if recovery_2 & (1 << 5):   # def evs flag
        use_params['evs']['defense'] = signed_int(item[23])
    if recovery_2 & (1 << 6):   # speed evs flag
        use_params['evs']['speed'] = signed_int(item[24])
    if recovery_2 & (1 << 7):   # spatk evs flag
        use_params['evs']['sp_attack'] = signed_int(item[25])
    if bitfield_2 & 1:          # spdef evs flag
        use_params['evs']['sp_defense'] = signed_int(item[26])

    if bitfield_2 & (1 << 1):   # friendship adjustment if below 100
        use_params['friendship']['below_100'] = signed_int(item[29])
    if bitfield_2 & (1 << 2):   # friendship adjustment if below 200
        use_params['friendship']['100_to_200'] = signed_int(item[30])
    if bitfield_2 & (1 << 3):   # friendship adjustment if above 200
        use_params['friendship']['200_or_more'] = signed_int(item[31])

    item_dict['on_use'] = use_params
    return item_dict


def dump_item(item: bytes, item_name: str) -> dict:
    print(f'Dumping item {item_name}')
    bitfield_1 = int.from_bytes(item[8:10], 'little')
    item_core = {
        'name': item_name,
        'price': int.from_bytes(item[0:2], 'little'),
        'battle_effects': {
            'hold': {
                'effect': ItemHoldEffect(item[2]).name,
                'power': item[3],
            },
            'move': {
                'pluck': ItemMoveEffect(item[4]).name,
                'fling': {
                    'effect': ItemMoveEffect(item[5]).name,
                    'power': item[6],
                },
                'natural_gift': {
                    'type': Type(bitfield_1 & 0x1F).name,
                    'power': item[7],
                }
            }
        },
        'can_discard': not bool((bitfield_1 >> 5) & 1),    # this is an inversion of the actual flag here
        'can_register': bool((bitfield_1 >> 6) & 1),
        'field_pocket': FieldPocket((bitfield_1 >> 7) & 0xF).name,
        'field_function': FieldFunction(item[10]).name,
        'battle_pocket': BattlePocket((bitfield_1 >> 11) & 0x1F).name,
        'battle_function': BattleFunction(item[11]).name,
        'is_usable': bool(item[12]),
    }

    if item_core['is_usable']:
        item_core = dump_use_data(item, item_core)

    return item_core


def dump_itemdata():
    if not os.path.exists('data/items'):
        os.makedirs('data/items')
    
    itemdata = NARC.fromFile(BASE_ITEMDATA_NARC)
    item_names = open(TEXT_DUMP_TARGET.format(ITEM_NAMES_BANK, archive=ITEM_NAMES_BANK), 'r')
    for i, item in enumerate(itemdata.files):
        if i == 113:    # need to skip ahead at this point
            for j in range(113, 135):
                item_names.readline()
        item_name = item_names.readline().strip()
        item_dict = dump_item(item, item_name)
        with open(f'data/items/{i:03}.json', 'w', encoding='utf8') as out:
            json.dump(item_dict, out, indent=4, ensure_ascii=False)

    item_names.close()

