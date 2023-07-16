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

# Item Data

ITEM_DATA_DIR = $(BUILD)/items
ITEM_DATA_NARC = $(BUILD_NARC)/itemtool/pl_item_data.narc
ITEM_DATA_DEP_DIR = data/items
ITEM_DATA_TARGET = $(FILESYS)/itemtool/itemdata/pl_item_data.narc

ITEM_DATA_SRCS := $(wildcard $(ITEM_DATA_DEP_DIR)/*.json)
ITEM_DATA_OBJS := $(patsubst $(ITEM_DATA_DEP_DIR)/%.json,$(ITEM_DATA_DIR)/%.bin,$(ITEM_DATA_SRCS))

$(ITEM_DATA_NARC): $(ITEM_DATA_SRCS)
	$(PYTHON) scripts/build/item_data.py build

NARC_FILES += $(ITEM_DATA_NARC)

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
