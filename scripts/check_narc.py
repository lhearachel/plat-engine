from ndspy.narc import NARC

import sys

INPUT_DICT = {
    'move_data': ('narcs', 'base/data/poketool/waza/pl_waza_tbl.narc', 'build/narc/poketool/waza/pl_waza_tbl.narc', False),
    'be_seq': ('narcs', 'base/data/battle/skill/be_seq.narc', 'build/narc/battle/skill/be_seq.narc', True),
    'waza_seq': ('narcs', 'base/data/battle/skill/waza_seq.narc', 'build/narc/battle/skill/waza_seq.narc', True),
    'sub_seq': ('narcs', 'base/data/battle/skill/sub_seq.narc', 'build/narc/battle/skill/sub_seq.narc', True),
    'item_data': ('narcs', 'base/data/itemtool/itemdata/pl_item_data.narc', 'build/narc/itemtool/pl_item_data.narc', False),
    'personal': ('narcs', 'base/data/poketool/personal/pl_personal.narc', 'build/narc/pl_personal.narc', False),
    'evo': ('narcs', 'base/data/poketool/personal/evo.narc', 'build/narc/evo.narc', False),
    'wotbl': ('narcs', 'base/data/poketool/personal/wotbl.narc', 'build/narc/wotbl.narc', False),
}

def compare_narcs(orig_f, made_f, word_mode):
    orig = NARC.fromFile(orig_f)
    made = NARC.fromFile(made_f)

    assert len(orig.files) == len(made.files)
    for i in range(len(orig.files)):
        og_hex = orig.files[i].hex()
        md_hex = made.files[i].hex()

        if og_hex != md_hex:
            print(f'diff in file {i}')
            if word_mode:
                for j in range(0, len(orig.files[i]), 4):
                    og_word = orig.files[i][j:j+4]
                    md_word = made.files[i][j:j+4]

                    if og_word.hex() != md_word.hex():
                        print(f'-- @ {j // 4} ; e: {og_word.hex()} ; a: {md_word.hex()}')
            else:
                for j in range(0, len(orig.files[i])):
                    og_byte = orig.files[i][j]
                    md_byte = made.files[i][j]

                    if og_byte != md_byte:
                        print(f'-- @ {j} ; e: {og_byte} ; a: {md_byte}')
            

params = INPUT_DICT[sys.argv[1]]
if params[0] == 'narcs':
    compare_narcs(params[1], params[2], params[3])

ORIGINAL_NARC = 'base/data/battle/skill/sub_seq.narc'
BUILT_BINARY  = 'build/battle/scr/subscr/sub_seq_{i}.bin'

BUILT_NARC    = 'build/narc/poketool/waza/pl_waza_tbl.narc'

'''
original = NARC.fromFile(ORIGINAL_NARC)
for i in range(len(original.files)):
    og_hex = original.files[i].hex()

    built = ''
    with open(BUILT_BINARY.format(i=i), 'rb') as built_bin:
        built = built_bin.read()
    
    if og_hex != built.hex():
        print(f'diff in file {i}')

        for j in range(0, len(original.files[i]), 4):
            og_word = original.files[i][j:j+4].hex()
            md_word = built[j:j+4].hex()
            if og_word != md_word:
                print(f'  diff at word {j}')
                print(f'    orig: {og_word}')
                print(f'    made: {md_word}')

print('check done')
'''