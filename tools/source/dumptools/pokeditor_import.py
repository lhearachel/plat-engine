from csv import DictReader
from re import sub

# for saucy: Personal, trainer data / trainer poke, levelup learnsets, move data, and evolutions

PERSONAL_HEADER = [
    "ID Number",
    "Name",
    "HP",
    "Attack",
    "Defense",
    "Speed",
    "Sp. Atk",
    "Sp. Def",
    "Type 1",
    "Type 2",
    "Catch Rate",
    "Exp Drop",
    "HP EV Yield",
    "Spe EV Yield",
    "Attack EV Yield",
    "Defense EV Yield",
    "Sp. Atk EV Yield",
    "Sp. Def EV Yield",
    "Uncommon Held Item",
    "Rare Held Item",
    "Gender Ratio",
    "Hatch Multiplier",
    "Base Happiness",
    "Growth Rate",
    "Egg Group 1",
    "Egg Group 2",
    "Ability 1",
    "Ability 2",
    "Run Chance (Safari Zone only)",
    "DO NOT TOUCH",
]

BODY_COLORS = [
    "BODY_COLOR_RED",
    "BODY_COLOR_BLUE",
    "BODY_COLOR_YELLOW",
    "BODY_COLOR_GREEN",
    "BODY_COLOR_BLACK",
    "BODY_COLOR_BROWN",
    "BODY_COLOR_PURPLE",
    "BODY_COLOR_GRAY",
    "BODY_COLOR_WHITE",
    "BODY_COLOR_PINK",
    "BODY_COLOR_EGG",
]

FLIPPED_MONS = set(
    "POLIWAG",
    "POLIWHIRL",
    "POLIWRATH",
    "MACHOKE",
    "KINGLER",
    "STARYU",
    "ELECTABUZZ",
    "CROCONAW",
    "PICHU",
    "IGGLYBUFF",
    "POLITOED",
    "UNOWN",
    "SNEASEL",
    "TEDDIURSA",
    "ELEKID",
    "MAGBY",
    "ROSELIA",
    "SPINDA",
    "ZANGOOSE",
    "SEVIPER",
    "ABSOL",
    "TORTERRA",
    "CHIMCHAR",
    "MONFERNO",
    "BUDEW",
    "ROSERADE",
    "MAGMORTAR",
    "TOGEKISS",
    "SHAYMIN_SKY",
)

MONDATA_DUMP_TARGET = "armips/data/mondata.s"

def upper_snake_case(s: str) -> str:
    return '_'.join(
        sub(
            '([A-Z][a-z]+)',
            r' \1',
            sub(
                '([A-Z]+)',
                r' \1',
                s.replace('-', ' ')
            )
        ).split()
    ).upper()

def map_personal_string(personal_str: str, personal_val: str, engine_val: str):
    mapped = engine_val if personal_str.strip() == personal_val else personal_str
    return upper_snake_case(mapped)

def import_personal(personal_sheet_fname: str):
    dump_header = """.nds
    .thumb

    .include "armips/include/macros.s"
    .include "armips/include/monnums.s"
    .include "armips/include/itemnums.s"
    .include "armips/include/constants.s"
    .include "armips/include/abilities.s"
    .include "armips/include/config.s"
    .include "armips/data/tmlearnset.s"

    // all the mon personal data.  tm learnsets are specifically in tmlearnset.s
    // basestats and evyields fields are formatted as such:  hp atk def speed spatk spdef
    """


    dump_template = """


    mondata {species}
        basestats {base_hp:d}, {base_atk:d}, {base_def:d}, {base_spe:d}, {base_spa:d}, {base_spd:d}
        types {type_1}, {type_2}
        catchrate {catch_rate:d}
        baseexp {exp_yield:d}
        evyields {ev_yield_hp:d}, {ev_yield_atk:d}, {ev_yield_def:d}, {ev_yield_spe:d}, {ev_yield_spa:d}, {ev_yield_spd:d}
        items {item_uncommon}, {item_rare}
        genderratio {gender_ratio:d}
        eggcycles {hatch_multi:d}
        growthrate {growth_rate:d}
        egggroups {egg_group_1}, {egg_group_2}
        abilities {ability_1}, {ability_2}
        runchance {run_chance:d}
        colorflip {body_color}, {flip:d}
        tmdata {species}_TM_DATA_0, {species}_TM_DATA_1, {species}_TM_DATA_2, {species}_TM_DATA_3
    """

    with open(personal_sheet_fname) as personal_csv, open(MONDATA_DUMP_TARGET, 'w') as mondata_dump:
        mondata_dump.write(dump_header)
        reader = DictReader(personal_csv, fieldnames=PERSONAL_HEADER)
        for row in reader:
            dump_data = dump_template.format(
                species=f'SPECIES_{row["Name"].upper()}',
                base_hp=row["HP"],
                base_atk=row["Attack"],
                base_def=row["Defense"],
                base_spe=row["Speed"],
                base_spa=row["Sp. Attack"],
                base_spd=row["Sp. Defense"],
                type_1=f'TYPE_{map_personal_string(row["Type 1"], "???", "Mystery")}',
                type_2=f'TYPE_{map_personal_string(row["Type 2"], "???", "Mystery")}',
                catch_rate=row["Catch Rate"],
                exp_yield=row["Exp Drop"],
                ev_yield_hp=row["HP EV Yield"],
                ev_yield_atk=row["Attack EV Yield"],
                ev_yield_def=row["Defense EV Yield"],
                ev_yield_spe=row["Spe EV Yield"],
                ev_yield_spa=row["Sp. Atk EV Yield"],
                ev_yield_spd=row["Sp. Def EV Yield"],
                item_uncommon=f'ITEM_{upper_snake_case(row["Uncommon Held Item"])}',
                item_rare=f'ITEM_{upper_snake_case(row["Rare Held Item"])}',
                gender_ratio=row["Gender Ratio"],
                hatch_multi=row["Hatch Multiplier"],
                growth_rate=upper_snake_case(row["Growth Rate"]),
                egg_group_1=f'EGG_GROUP_{upper_snake_case(row["Egg Group 1"])}',
                egg_group_2=f'EGG_GROUP_{upper_snake_case(row["Egg Group 2"])}',
                ability_1=f'ABILITY_{map_personal_string(row["Ability 1"], "-", "None")}',
                ability_2=f'ABILITY_{map_personal_string(row["Ability 2"], "-", "None")}',
                run_chance=row["Run Chance (Safari Zone only)"],
                body_color=BODY_COLORS[int(row["DO NOT TOUCH"])]
                flip=f'{"1" if row["Name"].upper() in FLIPPED_MONS else "0"}'
            )

            mondata_dump.write(dump_data)
