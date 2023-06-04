from ndspy.narc import NARC

ORIGINAL_NARC = 'base/data/battle/skill/sub_seq.narc'
BUILT_BINARY  = 'build/battle/scr/subscr/sub_seq_{i}.bin'

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