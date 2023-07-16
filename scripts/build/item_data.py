import json
import os
import subprocess
import sys

from ndspy.narc import NARC
from util import (
    Type,
    ItemHoldEffect,
    ItemMoveEffect,
    FieldPocket,
    FieldFunction,
    BattlePocket,
    BattleFunction,
    signed_int,
    sint_to_byte
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


def dump_raw_data(item: bytes, item_dict: dict) -> dict:
    item_dict['extra_raw_data'] = [b for b in item[14:34]]

    return item_dict


def dump_item(item: bytes, item_name: str) -> dict:
    #print(f'Dumping item {item_name}')
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
    else:
        item_core = dump_raw_data(item, item_core)

    return item_core


def pack_bitfield_1(item: dict) -> bytes:
    composite = Type[item['battle_effects']['move']['natural_gift']['type']].value
    composite = composite + (0x20 if not item['can_discard'] else 0)
    composite = composite + (0x40 if item['can_register'] else 0)
    
    field_pocket = FieldPocket[item['field_pocket']].value << 7
    battle_pocket = BattlePocket[item['battle_pocket']].value << 11
    composite = composite + field_pocket + battle_pocket
    
    return composite.to_bytes(2, 'little')


def pack_recovery(on_use: dict) -> bytes:
    recovery = 0
    if on_use.get('recover', {}).get('sleep', False):
        recovery = recovery + 1
    if on_use.get('recover', {}).get('poison', False):
        recovery = recovery + 2
    if on_use.get('recover', {}).get('burn', False):
        recovery = recovery + 4
    if on_use.get('recover', {}).get('freeze', False):
        recovery = recovery + 8
    if on_use.get('recover', {}).get('paralysis', False):
        recovery = recovery + 16
    if on_use.get('recover', {}).get('confusion', False):
        recovery = recovery + 32
    if on_use.get('recover', {}).get('attraction', False):
        recovery = recovery + 64
    if on_use.get('guard_spec', False):
        recovery = recovery + 128
    
    return recovery.to_bytes(1, 'little')


def pack_utility(on_use: dict) -> bytes:
    utility = 0
    if on_use.get('revive', False):
        utility = utility + 1
    if on_use.get('revive_all', False):
        utility = utility + 2
    if on_use.get('level_up', False):
        utility = utility + 4
    if on_use.get('evolution', False):
        utility = utility + 8
    
    if 'attack' in on_use.get('raise_stat', {}):
        utility = utility + ((on_use['raise_stat']['attack'] << 4) & 0xF0)
    
    return utility.to_bytes(1, 'little')


def pack_boost_1(on_use: dict) -> bytes:
    boost_1 = 0
    if 'raise_stat' not in on_use:
        return boost_1.to_bytes(1, 'little')

    if 'defense' in on_use['raise_stat']:
        boost_1 = boost_1 + (on_use['raise_stat']['defense'] & 0xF)
    if 'sp_attack' in on_use['raise_stat']:
        boost_1 = boost_1 + ((on_use['raise_stat']['sp_attack'] << 4) & 0xF0)
    
    return boost_1.to_bytes(1, 'little')


def pack_boost_2(on_use: dict) -> bytes:
    boost_2 = 0
    if 'raise_stat' not in on_use:
        return boost_2.to_bytes(1, 'little')

    if 'sp_defense' in on_use['raise_stat']:
        boost_2 = boost_2 + (on_use['raise_stat']['sp_defense'] & 0xF)
    if 'speed' in on_use['raise_stat']:
        boost_2 = boost_2 + ((on_use['raise_stat']['speed'] << 4) & 0xF0)
    
    return boost_2.to_bytes(1, 'little')


def pack_boost_3(on_use: dict) -> bytes:
    boost_3 = 0

    if 'accuracy' in on_use.get('raise_stat', {}):
        boost_3 = boost_3 + (on_use['raise_stat']['accuracy'] & 0xF)
    if 'critical' in on_use.get('raise_stat', {}):
        boost_3 = boost_3 + ((on_use['raise_stat']['critical'] << 4) & 0x30)
    if on_use.get('pp_up', False):
        boost_3 = boost_3 + 64
    if on_use.get('pp_max', False):
        boost_3 = boost_3 + 128
    
    return boost_3.to_bytes(1, 'little')


def pack_recovery_2(on_use: dict) -> bytes:
    recovery_2 = 0
    if 'pp' in on_use.get('recover', {}):
        recovery_2 = recovery_2 + 1
    if 'pp_all_moves' in on_use.get('recover', {}):
        recovery_2 = recovery_2 + 2
    if 'hp' in on_use.get('recover', {}):
        recovery_2 = recovery_2 + 4
    if 'hp' in on_use.get('evs', {}):
        recovery_2 = recovery_2 + 8
    if 'attack' in on_use.get('evs', {}):
        recovery_2 = recovery_2 + 16
    if 'defense' in on_use.get('evs', {}):
        recovery_2 = recovery_2 + 32
    if 'speed' in on_use.get('evs', {}):
        recovery_2 = recovery_2 + 64
    if 'sp_attack' in on_use.get('evs', {}):
        recovery_2 = recovery_2 + 128
    
    return recovery_2.to_bytes(1, 'little')


def pack_bitfield_2(on_use: dict) -> bytes:
    bitfield_2 = 0
    if 'sp_defense' in on_use.get('evs', {}):
        bitfield_2 = bitfield_2 + 1
    if 'below_100' in on_use.get('friendship', {}):
        bitfield_2 = bitfield_2 + 2
    if '100_to_200' in on_use.get('friendship', {}):
        bitfield_2 = bitfield_2 + 4
    if '200_or_more' in on_use.get('friendship', {}):
        bitfield_2 = bitfield_2 + 8
    
    return bitfield_2.to_bytes(1, 'little')


def build_use_data(on_use: dict) -> bytes:
    recovery = pack_recovery(on_use)            # 14
    utility = pack_utility(on_use)              # 15
    boost_1 = pack_boost_1(on_use)              # 16
    boost_2 = pack_boost_2(on_use)              # 17
    boost_3 = pack_boost_3(on_use)              # 18
    recovery_2 = pack_recovery_2(on_use)        # 19
    bitfield_2 = pack_bitfield_2(on_use)        # 20

    hp_ev = sint_to_byte(on_use.get('evs', {}).get('hp', 0))          # 21
    atk_ev = sint_to_byte(on_use.get('evs', {}).get('attack', 0))     # 22
    def_ev = sint_to_byte(on_use.get('evs', {}).get('defense', 0))    # 23
    spe_ev = sint_to_byte(on_use.get('evs', {}).get('speed', 0))      # 24
    spa_ev = sint_to_byte(on_use.get('evs', {}).get('sp_attack', 0))  # 25
    spd_ev = sint_to_byte(on_use.get('evs', {}).get('sp_defense', 0)) # 26

    hp_rcv = on_use.get('recover', {}).get('hp', 0).to_bytes(1, 'little') # 27
    pp_rcv = on_use.get('recover', {}).get('pp', 0)
    pp_rcv = on_use.get('recover', {}).get('pp_all_moves', pp_rcv).to_bytes(1, 'little')  # 28

    fs_1 = sint_to_byte(on_use.get('friendship', {}).get('below_100', 0))     # 29
    fs_2 = sint_to_byte(on_use.get('friendship', {}).get('100_to_200', 0))    # 30
    fs_3 = sint_to_byte(on_use.get('friendship', {}).get('200_or_more', 0))   # 31
    zero = 0

    use_data = bytearray([])
    use_data = use_data + recovery
    use_data = use_data + utility
    use_data = use_data + boost_1
    use_data = use_data + boost_2
    use_data = use_data + boost_3
    use_data = use_data + recovery_2
    use_data = use_data + bitfield_2
    use_data = use_data + hp_ev + atk_ev + def_ev + spe_ev + spa_ev + spd_ev
    use_data = use_data + hp_rcv + pp_rcv + fs_1 + fs_2 + fs_3
    use_data = use_data + zero.to_bytes(2, 'little')

    return use_data


def build_raw_data(raw_data: list[int]) -> bytes:
    binary = bytearray([])
    for b in raw_data:
        binary = binary + b.to_bytes(1, 'little')
    
    return binary


def build_item_binary(item: dict) -> bytearray:
    #print(f'Building item binary {item["name"]}')
    binary = bytearray([])
    zero = 0
    one  = 1

    binary = binary + item['price'].to_bytes(2, 'little')
    binary = binary + ItemHoldEffect[item['battle_effects']['hold']['effect']].value.to_bytes(1, 'little')
    binary = binary + item['battle_effects']['hold']['power'].to_bytes(1, 'little')
    binary = binary + ItemMoveEffect[item['battle_effects']['move']['pluck']].value.to_bytes(1, 'little')
    binary = binary + ItemMoveEffect[item['battle_effects']['move']['fling']['effect']].value.to_bytes(1, 'little')
    binary = binary + item['battle_effects']['move']['fling']['power'].to_bytes(1, 'little')
    binary = binary + item['battle_effects']['move']['natural_gift']['power'].to_bytes(1, 'little')
    binary = binary + pack_bitfield_1(item)
    binary = binary + FieldFunction[item['field_function']].value.to_bytes(1, 'little')
    binary = binary + BattleFunction[item['battle_function']].value.to_bytes(1, 'little')
    binary = binary + (one.to_bytes(1, 'little') if item['is_usable'] else zero.to_bytes(1, 'little'))

    binary = binary + zero.to_bytes(1, 'little')

    if item['is_usable']:
        binary = binary + build_use_data(item['on_use'])
    else:
        binary = binary + build_raw_data(item['extra_raw_data'])
    
    return binary


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


def build_itemdata():
    if not os.path.exists('build/narc/itemtool'):
        os.makedirs('build/narc/itemtool')
    if not os.path.exists('build/items'):
        os.makedirs('build/items')
    
    items_dir = 'data/items'
    for i, entry in enumerate(os.listdir(items_dir)):
        file = open(os.path.join(items_dir, entry), 'r')
        item_json = json.load(file)
        file.close()

        item_bytes = build_item_binary(item_json)
        with open(f'build/items/{i:03}.bin', 'wb') as out:
            out.write(item_bytes)
    
    narcpy.create('build/narc/itemtool/pl_item_data.narc', 'build/items')


if __name__ == '__main__':
    if sys.argv[1] == 'dump':
        dump_itemdata()
    elif sys.argv[1] == 'build':
        build_itemdata()
