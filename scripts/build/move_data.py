from enum import Enum, Flag, auto
import os
import json
import sys

from ndspy.narc import NARC
from util import Type, MoveClass, Move, MoveEffect, MoveTarget, sint_to_byte, signed_int, snake_case


BASE_MOVE_DATA_NARC = 'base/data/poketool/waza/pl_waza_tbl.narc'
BATTLE_MOVE_ARCHIVE = 0
MOVE_NAME_ARCHIVE = 647
MOVE_NAME_CAPS_ARCHIVE = 648


def dump_movedata(movedata_file: bytes, move_name: str) -> dict:
    return {
        'name': move_name,
        'type': Type(movedata_file[4]).name,
        'category': MoveClass(movedata_file[2]).name,
        'power': movedata_file[3],
        'accuracy': movedata_file[5],
        'base_pp': movedata_file[6],
        'effect': MoveEffect(int.from_bytes(movedata_file[0:2], 'little')).name,
        'effect_chance': movedata_file[7],
        'target_type': MoveTarget(int.from_bytes(movedata_file[8:10], 'little')).name,
        'priority': signed_int(movedata_file[10]),
        'flags': {
            'make_contact': bool(movedata_file[11] & 1),
            'blocked_by_protect': bool(movedata_file[11] & (1 << 1)),
            'bounced_by_magic_coat': bool(movedata_file[11] & (1 << 2)),
            'stolen_by_snatch': bool(movedata_file[11] & (1 << 3)),
            'can_be_mirror_moved': bool(movedata_file[11] & (1 << 4)),
            'triggers_kings_rock': bool(movedata_file[11] & (1 << 5)),
            'animation_hides_hp_bars': bool(movedata_file[11] & (1 << 6)),
            'animation_hides_shadows': bool(movedata_file[11] & (1 << 7)),
        },
        'contest_effect': movedata_file[12],
        'contest_type': movedata_file[13]
    }


def dump_moves():
    if not os.path.exists('data/moves'):
        os.makedirs('data/moves')
    
    movedata_narc = NARC.fromFile(BASE_MOVE_DATA_NARC)
    movenames_txt = open('data/text/647.txt', 'r', encoding='utf8')
    for i, movedata_file in enumerate(movedata_narc.files):
        move_name = movenames_txt.readline().strip()
        print(f'dumping {i}: {move_name}')
        dump_data = dump_movedata(movedata_file, move_name)
        move_fname = f'move_{i:03}' if i in [0, 468, 469, 470] else snake_case(move_name)
        j = open(f'data/moves/{snake_case(move_fname)}.json', 'w', encoding='utf8')
        json.dump(dump_data, j, indent=4, ensure_ascii=False)


def pack_flags(move_flags: dict) -> bytes:
    packed = 0
    packed = packed | int(move_flags['make_contact']) << 0
    packed = packed | int(move_flags['blocked_by_protect']) << 1
    packed = packed | int(move_flags['bounced_by_magic_coat']) << 2
    packed = packed | int(move_flags['stolen_by_snatch']) << 3
    packed = packed | int(move_flags['can_be_mirror_moved']) << 4
    packed = packed | int(move_flags['triggers_kings_rock']) << 5
    packed = packed | int(move_flags['animation_hides_hp_bars']) << 6
    packed = packed | int(move_flags['animation_hides_shadows']) << 7

    return packed


def build_movedata(move_data: dict) -> bytes:
    binary = bytearray([])
    binary = binary + MoveEffect[move_data['effect']].value.to_bytes(2, 'little')
    binary = binary + MoveClass[move_data['category']].value.to_bytes(1, 'little')
    binary = binary + move_data['power'].to_bytes(1, 'little')

    binary = binary + Type[move_data['type']].value.to_bytes(1, 'little')
    binary = binary + move_data['accuracy'].to_bytes(1, 'little')
    binary = binary + move_data['base_pp'].to_bytes(1, 'little')
    binary = binary + move_data['effect_chance'].to_bytes(1, 'little')
    
    binary = binary + MoveTarget[move_data['target_type']].value.to_bytes(2, 'little')
    binary = binary + sint_to_byte(move_data['priority'])
    binary = binary + pack_flags(move_data['flags']).to_bytes(1, 'little')

    binary = binary + move_data['contest_effect'].to_bytes(1, 'little')
    binary = binary + move_data['contest_type'].to_bytes(1, 'little')
    binary = binary + (0).to_bytes(2, 'little')

    return binary


def build_moves():
    if not os.path.exists('build/movedata'):
        os.makedirs('build/movedata')
    
    move_files = os.listdir('data/moves')
    move_names = [''] * len(move_files)
    for fname in os.listdir('data/moves'):
        j = open(f'data/moves/{fname}', 'r', encoding='utf8')
        move_data = json.load(j)
        move_name = move_data['name']
        move_idx = Move[fname.split('.')[0].upper()].value
        out_data = build_movedata(move_data)
        out_file = open(f'build/movedata/{move_idx:03}.bin', 'wb')
        
        out_file.write(out_data)
        move_names[move_idx] = move_name

        out_file.close()
        j.close()
    
    battlemoves_txt = open('data/text/000.txt', 'w', encoding='utf8')
    movenames_txt = open('data/text/647.txt', 'w', encoding='utf8')
    movenames_upper_txt = open('data/text/648.txt', 'w', encoding='utf8')
    for move_name in move_names:
        if move_name in ['-', '']:
            battlemoves_txt.write('!\r\n!\r\n!\r\n')
        else:
            battlemoves_txt.write(f'{{STRVAR_1 1, 0, 0}} used\\n{move_name}!\r\n')
            battlemoves_txt.write(f'The wild {{STRVAR_1 1, 0, 0}} used\\n{move_name}!\r\n')
            battlemoves_txt.write(f'The foe’s {{STRVAR_1 1, 0, 0}} used\\n{move_name}!\r\n')

        movenames_txt.write(f'{move_name}\r\n')
        movenames_upper_txt.write(f'{move_name.upper()}\r\n')
    
    movenames_txt.close()
    movenames_upper_txt.close()


if __name__ == '__main__':
    if sys.argv[1] == 'dump':
        dump_moves()
    elif sys.argv[1] == 'build':
        build_moves()
