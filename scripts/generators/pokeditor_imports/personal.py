import csv
import re

BASE_STATS_TEMPLATE = """
    [SPECIES_{species}] = {{
        .baseHP        = {base_hp},
        .baseAttack    = {base_attack},
        .baseDefense   = {base_defense},
        .baseSpeed     = {base_speed},
        .baseSpAttack  = {base_spatk},
        .baseSpDefense = {base_spdef},
        
        .type1 = TYPE_{type_1},
        .type2 = TYPE_{type_2},

        .ability1 = ABILITY_{ability1},
        .ability2 = ABILITY_{ability2},

        .itemUncommon = ITEM_{item1},
        .itemRare     = ITEM_{item2},

        .evYieldHP        = {ev_hp},
        .evYieldAttack    = {ev_attack},
        .evYieldDefense   = {ev_defense},
        .evYieldSpeed     = {ev_speed},
        .evYieldSpAttack  = {ev_spatk},
        .evYieldSpDefense = {ev_spdef},

        .catchRate = {catch_rate},
        .fleeRate = {flee_rate},
        .genderRatio = {gender_ratio},
        .baseFriendship = {base_friendship},
        .expCurve = GROWTH_{exp_curve},
        .expYield = {exp_yield},
        .eggCycles = {egg_cycles},
        .eggGroup1 = EGG_GROUP_{egg_group1},
        .eggGroup2 = EGG_GROUP_{egg_group2},
        .bodyColor = BODY_COLOR_{body_color},
        .reverse = {reverse},

        .tmLearnsets = {{
            TM_LEARNSET_1_{species},
            TM_LEARNSET_2_{species},
            TM_LEARNSET_3_{species},
            TM_LEARNSET_4_{species}
        }},
    }},
"""

TM_LEARNSETS_TEMPLATE = """

#define TM_LEARNSET_1_{species} ({learnset_1})
#define TM_LEARNSET_2_{species} ({learnset_2})
#define TM_LEARNSET_3_{species} ({learnset_3})
#define TM_LEARNSET_4_{species} ({learnset_4})
"""

POKEDITOR_PERSONAL_SHEET = "Personal.csv"
POKEDTIOR_TMS_SHEET = "TM Learnsets.csv"

IRREGULAR_NAMES = {
    '-----': 'NONE',
    'NIDORAN♀': 'NIDORAN_F',
    'NIDORAN♂': 'NIDORAN_M',
    'FARFETCH’D': 'FARFETCHD',
    'MR. MIME': 'MR_MIME',
    'HO-OH': 'HO_OH',
    'MIME JR.': 'MIME_JR',
    'PORYGON-Z': 'PORYGON_Z',
}

IRREGULAR_ABILITIES = {
    'COMPOUNDEYES': 'COMPOUND_EYES',
    'LIGHTNINGROD': 'LIGHTNING_ROD',
}

IDENTICAL_ABILITIES = {
    'SHELL_ARMOR':  'BATTLE_ARMOR',
    'AIR_LOCK':     'CLOUD_NINE',
    'VITAL_SPIRIT': 'INSOMNIA',
    'WHITE_SMOKE':  'CLEAR_BODY',
    'PURE_POWER':   'HUGE_POWER',
    'SOLID_ROCK':   'FILTER',
}

IRREGULAR_ITEMS = {
    'KING’S_ROCK': 'KINGS_ROCK'
}

BODY_COLORS = ['RED', 'BLUE', 'YELLOW', 'GREEN', 'BLACK', 'BROWN', 'PURPLE', 'GRAY', 'WHITE', 'PINK', 'EGG']

def snake_case(s):
    return '_'.join(
        re.sub('([A-Z][a-z]+)', r' \1',
        re.sub('([A-Z]+)', r' \1',
        s.replace('-', ' '))).split()).lower()

def sanitize_ability(ability: str) -> str:
    snake = snake_case(ability).upper()
    if snake == '':
        return 'NONE'
    
    if snake in IRREGULAR_ABILITIES:
        return IRREGULAR_ABILITIES[snake]
    
    if snake in IDENTICAL_ABILITIES:
        return IDENTICAL_ABILITIES[snake]

    return snake

def sanitize_item(item:str) -> str:
    snake = snake_case(item).upper()
    if snake == '':
        return 'NONE'
    
    if snake in IRREGULAR_ITEMS:
        return IRREGULAR_ITEMS[snake]
    
    return snake

def generate_base_stats():
    personal_file = open(POKEDITOR_PERSONAL_SHEET, 'r')
    personal_csv = csv.reader(personal_file)
    output_file = open('generated', 'w')

    for row in personal_csv:
        species_name = row[1] if row[1] not in IRREGULAR_NAMES else IRREGULAR_NAMES[row[1]]
        output_file.write(BASE_STATS_TEMPLATE.format(
            species=species_name,

            base_hp=row[2],
            base_attack=row[3],
            base_defense=row[4],
            base_speed=row[5],
            base_spatk=row[6],
            base_spdef=row[7],

            type_1=row[8].upper(),
            type_2=row[9].upper(),

            ability1=sanitize_ability(row[26]),
            ability2=sanitize_ability(row[27]),

            item1=sanitize_item(row[18]),
            item2=sanitize_item(row[19]),

            ev_hp=row[12],
            ev_attack=row[14],
            ev_defense=row[15],
            ev_speed=row[13],
            ev_spatk=row[16],
            ev_spdef=row[17],

            catch_rate=row[10],
            flee_rate=row[28],
            gender_ratio=row[20],
            base_friendship=row[22],
            exp_curve=snake_case(row[23]).upper(),
            exp_yield=row[11],
            egg_cycles=row[21],
            egg_group1=snake_case(row[24]).upper(),
            egg_group2=snake_case(row[25]).upper(),
            body_color=BODY_COLORS[int(row[29]) & 127],
            reverse=str(bool(int(row[29]) & 128)).upper(),
        ))
    
    personal_file.close()
    output_file.close()

def generate_tm_learnsets():
    learnsets_file = open(POKEDTIOR_TMS_SHEET, 'r')
    learnsets_csv = csv.reader(learnsets_file)
    output_file = open('generated', 'w')

    for row in learnsets_csv:    
        # Index 0 is the species index
        species_name = row[1] if row[1] not in IRREGULAR_NAMES else IRREGULAR_NAMES[row[1]]

        learnset_1_arr = []
        learnset_2_arr = []
        learnset_3_arr = []
        learnset_4_arr = []
        for tm in range(1, 33):
            check_and_add_to_learnset(row, tm, learnset_1_arr)
        for tm in range(33, 65):
            check_and_add_to_learnset(row, tm, learnset_2_arr)
        for tm in range(65, 97):
            check_and_add_to_learnset(row, tm, learnset_3_arr)
        for tm in range(97, 101):
            check_and_add_to_learnset(row, tm, learnset_4_arr)
        if len(learnset_1_arr) == 0:
            learnset_1_arr.append('0')
        if len(learnset_2_arr) == 0:
            learnset_2_arr.append('0')
        if len(learnset_3_arr) == 0:
            learnset_3_arr.append('0')
        if len(learnset_4_arr) == 0:
            learnset_4_arr.append('0')
        
        learnset_1_str = ' | '.join(learnset_1_arr)
        learnset_2_str = ' | '.join(learnset_2_arr)
        learnset_3_str = ' | '.join(learnset_3_arr)
        learnset_4_str = ' | '.join(learnset_4_arr)

        output_file.write(TM_LEARNSETS_TEMPLATE.format(
            species=species_name,
            learnset_1=learnset_1_str,
            learnset_2=learnset_2_str,
            learnset_3=learnset_3_str,
            learnset_4=learnset_4_str,
        ))
    
    learnsets_file.close()
    output_file.close()

def check_and_add_to_learnset(row: list[str], tm: int, learnset: list[str]):
    tm_entry = row[tm + 1]
    if tm_entry == 'TRUE':
        if tm < 93:
            learnset.append(f'TM{str(tm).zfill(3)}')
        else:
            learnset.append(f'HM{str(tm - 92).zfill(3)}')
