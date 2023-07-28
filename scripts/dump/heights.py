import os

from ndspy.narc import NARC
from scripts.build.util import Species


HEIGHTS_NARC = 'base/data/poketool/pokegra/height.narc'

def dump():
    narc = NARC.fromFile(HEIGHTS_NARC)
    for i in range(494):
        species = Species(i).name
        species = (species if species.startswith('SPECIES_') else 'SPECIES_' + species)

        f_back_file = (i * 4)
        m_back_file = (i * 4) + 1
        f_front_file = (i * 4) + 2
        m_front_file = (i * 4) + 3

        f_back = '"null"' if len(narc.files[f_back_file]) == 0 else narc.files[f_back_file][0]
        m_back = '"null"' if len(narc.files[m_back_file]) == 0 else narc.files[m_back_file][0]
        f_front = '"null"' if len(narc.files[f_front_file]) == 0 else narc.files[f_front_file][0]
        m_front = '"null"' if len(narc.files[m_front_file]) == 0 else narc.files[m_front_file][0]

        print(f'entry {species}, {f_back}, {m_back}, {f_front}, {m_front}')
