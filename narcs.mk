# Battle scripting NARCs

BATTLE_SKILL_NARC_DIR := $(BUILD_NARC)/battle/skill
BATTLE_SKILL_TARGET := $(FILESYS)/battle/skill
BATTLE_SKILL_DEP_DIR := armips/asm/battle

## be_seq (Effect Scripts)

BATTLE_EFFSCR_DIR := $(BUILD)/battle/scr/effscr
BATTLE_EFFSCR_NARC := $(BATTLE_SKILL_NARC_DIR)/be_seq.narc
BATTLE_EFFSCR_DEP_DIR := $(BATTLE_SKILL_DEP_DIR)/effscr
BATTLE_EFFSCR_TARGET := $(FILESYS)/battle/skill/be_seq.narc

BATTLE_EFFSCR_SRCS := $(wildcard $(BATTLE_EFFSCR_DEP_DIR)/*.s)
BATTLE_EFFSCR_OBJS := $(patsubst $(BATTLE_EFFSCR_DEP_DIR)/effscr_%.s,$(BATTLE_EFFSCR_DIR)/be_seq_%.bin,$(BATTLE_EFFSCR_SRCS))

$(BATTLE_EFFSCR_DIR)/be_seq_%.bin: $(BATTLE_EFFSCR_DEP_DIR)/effscr_%.s
	$(ARMIPS) $<

$(BATTLE_EFFSCR_NARC): $(BATTLE_EFFSCR_OBJS)
	$(NARCHIVE) create $@ $(BATTLE_EFFSCR_DIR) -nf

NARC_FILES += $(BATTLE_EFFSCR_NARC)

## waza_seq (Move Scripts)

BATTLE_MOVSCR_DIR := $(BUILD)/battle/scr/movscr
BATTLE_MOVSCR_NARC := $(BATTLE_SKILL_NARC_DIR)/waza_seq.narc
BATTLE_MOVSCR_DEP_DIR := $(BATTLE_SKILL_DEP_DIR)/movscr
BATTLE_MOVSCR_TARGET := $(FILESYS)/battle/skill/waza_seq.narc

BATTLE_MOVSCR_SRCS := $(wildcard $(BATTLE_MOVSCR_DEP_DIR)/*.s)
BATTLE_MOVSCR_OBJS := $(patsubst $(BATTLE_MOVSCR_DEP_DIR)/movscr_%.s,$(BATTLE_MOVSCR_DIR)/waza_seq_%.bin,$(BATTLE_MOVSCR_SRCS))

$(BATTLE_MOVSCR_DIR)/waza_seq_%.bin: $(BATTLE_MOVSCR_DEP_DIR)/movscr_%.s
	$(ARMIPS) $<

$(BATTLE_MOVSCR_NARC): $(BATTLE_MOVSCR_OBJS)
	$(NARCHIVE) create $@ $(BATTLE_MOVSCR_DIR) -nf

NARC_FILES += $(BATTLE_MOVSCR_NARC)

## sub_seq (Subroutine Scripts)

BATTLE_SUBSCR_DIR := $(BUILD)/battle/scr/subscr
BATTLE_SUBSCR_NARC := $(BATTLE_SKILL_NARC_DIR)/sub_seq.narc
BATTLE_SUBSCR_DEP_DIR := $(BATTLE_SKILL_DEP_DIR)/subscr
BATTLE_SUBSCR_TARGET := $(FILESYS)/battle/skill/sub_seq.narc

BATTLE_SUBSCR_SRCS := $(wildcard $(BATTLE_SUBSCR_DEP_DIR)/*.s)
BATTLE_SUBSCR_OBJS := $(patsubst $(BATTLE_SUBSCR_DEP_DIR)/subscr_%.s,$(BATTLE_SUBSCR_DIR)/sub_seq_%.bin,$(BATTLE_SUBSCR_SRCS))

$(BATTLE_SUBSCR_DIR)/sub_seq_%.bin: $(BATTLE_SUBSCR_DEP_DIR)/subscr_%.s
	$(ARMIPS) $<

$(BATTLE_SUBSCR_NARC): $(BATTLE_SUBSCR_OBJS)
	$(NARCHIVE) create $@ $(BATTLE_SUBSCR_DIR) -nf

NARC_FILES += $(BATTLE_SUBSCR_NARC)

# Battle graphics

BATTLE_OBJ_DIR := $(BUILD)/pl_batt_obj
BATTLE_OBJ_NARC := $(BUILD_NARC)/battle/pl_batt_obj.narc
BATTLE_OBJ_TARGET := $(FILESYS)/battle/graphic/pl_batt_obj.narc
BATTLE_OBJ_DEPS_DIR := data/raw/pl_batt_obj
BATTLE_OBJ_DEPS := $(wildcard $(BATTLE_OBJ_DEPS_DIR)/*)

$(BATTLE_OBJ_NARC): $(BATTLE_OBJ_DEPS)
	$(NARCHIVE) extract $(BATTLE_OBJ_TARGET) -o $(BATTLE_OBJ_DIR) -nf
	cp -r $(BATTLE_OBJ_DEPS_DIR)/. $(BATTLE_OBJ_DIR)
	$(NARCHIVE) create $@ $(BATTLE_OBJ_DIR) -nf

NARC_FILES += $(BATTLE_OBJ_NARC)

# Pokedex graphics

ZUKAN_DIR := $(BUILD)/zukan
ZUKAN_NARC := $(BUILD_NARC)/resource/eng/zukan.narc
ZUKAN_TARGET := $(FILESYS)/resource/eng/zukan/zukan.narc
ZUKAN_DEPS_DIR := data/raw/zukan
ZUKAN_DEPS := $(wildcard $(BATTLE_OBJ_DEPS_DIR)/*)

$(ZUKAN_NARC): $(ZUKAN_DEPS)
	$(NARCHIVE) extract $(ZUKAN_TARGET) -o $(ZUKAN_DIR) -nf
	cp -r $(ZUKAN_DEPS_DIR)/. $(ZUKAN_DIR)
	$(NARCHIVE) create $@ $(ZUKAN_DIR) -nf

NARC_FILES += $(ZUKAN_NARC)

# Item Data

ITEM_DATA_DIR := $(BUILD)/itemtool
ITEM_DATA_NARC := $(BUILD_NARC)/itemtool/pl_item_data.narc
ITEM_DATA_DEP_DIR := data/items
ITEM_DATA_TARGET := $(FILESYS)/itemtool/itemdata/pl_item_data.narc

ITEM_DATA_SRCS := $(wildcard $(ITEM_DATA_DEP_DIR)/*.json)
ITEM_DATA_OBJS := $(patsubst $(ITEM_DATA_DEP_DIR)/%.json,$(ITEM_DATA_DIR)/%.bin,$(ITEM_DATA_SRCS))

$(ITEM_DATA_NARC):
	$(PYTHON) scripts/build/item_data.py build
	$(NARCHIVE) create $@ $(ITEM_DATA_DIR) -nf

NARC_FILES += $(ITEM_DATA_NARC)

# Pokemon Data

PERSONAL_DATA_DIR := $(BUILD)/poketool/personal/pl_personal
PERSONAL_NARC := $(BUILD_NARC)/poketool/personal/pl_personal.narc
PERSONAL_TARGET := $(FILESYS)/poketool/personal/pl_personal.narc
EVO_DATA_DIR := $(BUILD)/poketool/personal/evo
EVO_NARC := $(BUILD_NARC)/poketool/personal/evo.narc
EVO_TARGET := $(FILESYS)/poketool/personal/evo.narc
WOTBL_DATA_DIR := $(BUILD)/poketool/personal/wotbl
WOTBL_NARC := $(BUILD_NARC)/poketool/personal/wotbl.narc
WOTBL_TARGET := $(FILESYS)/poketool/personal/wotbl.narc

POKEMON_DATA_DIR := data/pokemon
POKEMON_DATA_OBJS := $(wildcard $(POKEMON_DATA_DIR)/*.json)

$(PERSONAL_NARC):
	$(PYTHON) scripts/build/pokemon_data.py build
	$(NARCHIVE) create $(EVO_NARC) $(EVO_DATA_DIR) -nf
	$(NARCHIVE) create $(WOTBL_NARC) $(WOTBL_DATA_DIR) -nf
	$(NARCHIVE) create $@ $(PERSONAL_DATA_DIR) -nf

NARC_FILES += $(PERSONAL_NARC)	# Only track the last one since they all get built at the same time

# Encounter Tables

ENCDATA_DATA_DIR = $(BUILD)/encdata
ENCDATA_NARC := $(BUILD_NARC)/pl_enc_data.narc
ENCDATA_TARGET := $(FILESYS)/fielddata/encountdata/pl_enc_data.narc

$(ENCDATA_NARC):
	$(PYTHON) scripts/build/enc_data.py build
	$(NARCHIVE) create $(ENCDATA_NARC) $(ENCDATA_DATA_DIR) -nf

NARC_FILES += $(ENCDATA_NARC)

# Text Archives

CHARMAP = data/charmap.txt

TEXT_ARCHIVE_DIR = $(BUILD)/msgdata
TEXT_ARCHIVE_NARC = $(BUILD_NARC)/msgdata/pl_msg.narc
TEXT_ARCHIVE_TARGET = $(FILESYS)/msgdata/pl_msg.narc

TEXT_FILES = $(wildcard data/text/*.txt)

$(TEXT_ARCHIVE_NARC): $(TEXT_FILES)
	$(NARCHIVE) extract $(TEXT_ARCHIVE_TARGET) -o $(TEXT_ARCHIVE_DIR) -nf
	for file in $^; do $(MSGENC) -e -c $(CHARMAP) $$file $(TEXT_ARCHIVE_DIR)/pl_msg.narc_$$(basename $$file .txt); done
	$(NARCHIVE) create $@ $(TEXT_ARCHIVE_DIR) -nf

NARC_FILES += $(TEXT_ARCHIVE_NARC)

# Pokemon Icons

POKEMON_ICONS_DIR := $(BUILD)/pokeicon
POKEMON_ICONS_NARC := $(BUILD_NARC)/pokeicon.narc
POKEMON_ICONS_TARGET := $(FILESYS)/poketool/icongra/pl_poke_icon.narc
POKEMON_ICONS_DEPS_DIR := data/graphics/pokeicons
POKEMON_ICONS_RAWS_DIR := data/raw/pl_poke_icon

POKEMON_ICONS_SRCS := $(wildcard $(POKEMON_ICONS_DEPS_DIR)/*.png)
POKEMON_ICONS_OBJS := $(patsubst $(POKEMON_ICONS_DEPS_DIR)/%.png,$(POKEMON_ICONS_DIR)/1_%.NCGR,$(POKEMON_ICONS_SRCS))

$(POKEMON_ICONS_DIR)/1_%.NCGR: $(POKEMON_ICONS_DEPS_DIR)/%.png
	$(GFX) $< $@ -clobbersize -version101

$(POKEMON_ICONS_NARC): $(POKEMON_ICONS_OBJS)
	cp -r $(POKEMON_ICONS_RAWS_DIR)/. $(POKEMON_ICONS_DIR)
	$(NARCHIVE) create $@ $(POKEMON_ICONS_DIR) -nf

NARC_FILES += $(POKEMON_ICONS_NARC)
