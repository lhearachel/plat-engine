ifeq ($(strip $DEVKITPRO),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro)
endif

ifeq ($(strip $DEVKITARM),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

TOOLCHAIN := $(DEVKITARM)

.PHONY: clean all

SYSTEM = $(shell grep -i -q 'microsoft' /proc/version; echo $$?)

ifeq ($(SYSTEM), 0)
EXE := .exe
SEP := \\

WAV2SWAV := tools/wav2swav.exe
SWAV2SWAR := tools/swav2swar.exe
else
EXE := 
SEP := /

WAV2SWAV := wine tools/wav2swav.exe
SWAV2SWAR := mono tools/swav2swar.exe
endif

default: compile_rom

ROMNAME = rom.nds
BUILDROM = test.nds
OUTPUT_FMT = \033[4;37m\033[1;37m
FMT_OFF = \033[0m
####################### Tools #########################
PYTHON = python3
O2NARC = tools/o2narc
MSGENC = tools/msgenc
NDSTOOL = tools/ndstool
BLZ = tools/blz
ARMIPS = tools/armips
NARCHIVE = $(PYTHON) tools/narcpy.py
GFX = tools/nitrogfx
BTX = tools/pngtobtx0.exe
SDATTOOL = $(PYTHON) tools/SDATTool.py
###################### Settings ########################
PREFIX = bin/arm-none-eabi-
AS = $(DEVKITARM)/$(PREFIX)as
CC = $(DEVKITARM)/$(PREFIX)gcc
LD = $(DEVKITARM)/$(PREFIX)ld
OBJCOPY = $(DEVKITARM)/$(PREFIX)objcopy
CSC = csc$(EXE)

BUILDSYS := buildsys

LDFLAGS = $(BUILDSYS)/rom.ld -T $(BUILDSYS)/linker.ld
LDFLAGS_FIELD = $(BUILDSYS)/rom_gen.ld -T $(BUILDSYS)/linker_field.ld
LDFLAGS_BATTLE = $(BUILDSYS)/rom_gen.ld -T $(BUILDSYS)/linker_battle.ld
ASFLAGS = -mthumb -I ./data
CFLAGS = -I ./include -mthumb -mno-thumb-interwork -mcpu=arm7tdmi -mtune=arm7tdmi -mno-long-calls -march=armv4t -Wall -Wextra -Os -fira-loop-pressure -fipa-pta

LINK = build/linked.o
OUTPUT = build/output.bin
BATTLE_LINK = build/battle_linked.o
BATTLE_OUTPUT = build/output_battle.bin
FIELD_LINK = build/field_linked.o
FIELD_OUTPUT = build/output_field.bin
####################### output ########################
C_SUBDIR = src
ASM_SUBDIR = asm
INCLUDE_SUBDIR = include
BUILD := build
BUILD_NARC := $(BUILD)/narc
BASE := base
FILESYS := $(BASE)/data

SYNTH_NARC_NAME := weather_sys
SYNTH_NARC_PATH := $(FILESYS)/data/$(SYNTH_NARC_NAME)
SYNTH_NARC_BUILD_TARGET := $(BUILD)/$(SYNTH_NARC_NAME)/$(SYNTH_NARC_NAME).narc_09


INCLUDE_SRCS := $(wildcard $(INCLUDE_SUBDIR)/*.h)

C_SRCS := $(wildcard $(C_SUBDIR)/*.c)
C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(BUILD)/%.o,$(C_SRCS))

ASM_SRCS := $(wildcard $(ASM_SUBDIR)/*.s)
ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(BUILD)/%.d,$(ASM_SRCS))
OBJS     := $(C_OBJS) $(ASM_OBJS)

BATTLE_C_SRCS := $(wildcard $(C_SUBDIR)/battle/*.c)
BATTLE_C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(BUILD)/%.o,$(BATTLE_C_SRCS))
BATTLE_ASM_SRCS := $(wildcard $(ASM_SUBDIR)/battle/*.s)
BATTLE_ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(BUILD)/%.d,$(BATTLE_ASM_SRCS))
BATTLE_OBJS   := $(BATTLE_C_OBJS) $(BATTLE_ASM_OBJS) build/thumb_help.d

FIELD_C_SRCS := $(wildcard $(C_SUBDIR)/field/*.c)
FIELD_C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(BUILD)/%.o,$(FIELD_C_SRCS))
FIELD_ASM_SRCS := $(wildcard $(ASM_SUBDIR)/field/*.s)
FIELD_ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(BUILD)/%.d,$(FIELD_ASM_SRCS))
FIELD_OBJS   := $(FIELD_C_OBJS) $(FIELD_ASM_OBJS) build/thumb_help.d

###################### Includes #######################
include narcs.mk

####################### Build #########################
rom_gen.ld: $(BUILDSYS)/rom.ld
	cp $(BUILDSYS)/rom.ld $(BUILDSYS)/rom_gen.ld
	$(PYTHON) scripts/generate_ld.py

$(BUILD)/%.d:asm/%.s
	$(AS) $(ASFLAGS) -c $< -o $@

$(BUILD)/%.o:src/%.c
	mkdir -p $(BUILD) $(BUILD)/field $(BUILD)/battle
	@echo -e "Compiling"
	$(CC) $(CFLAGS) -c $< -o $@

$(LINK):$(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

$(OUTPUT):$(LINK) rom_gen.ld
	$(OBJCOPY) -O binary $< $@

$(FIELD_LINK):$(FIELD_OBJS) rom_gen.ld
	$(LD) $(LDFLAGS_FIELD) -o $@ $(FIELD_OBJS)

$(FIELD_OUTPUT):$(FIELD_LINK)
	$(OBJCOPY) -O binary $< $@

$(BATTLE_LINK):$(BATTLE_OBJS) rom_gen.ld
	$(LD) $(LDFLAGS_BATTLE) -o $@ $(BATTLE_OBJS)

$(BATTLE_OUTPUT):$(BATTLE_LINK)
	$(OBJCOPY) -O binary $< $@


arm9_extension: $(OUTPUT)

battle_extensions: $(BATTLE_OUTPUT)

c_binaries: arm9_extension battle_extensions
	@echo "✅ $(OUTPUT_FMT)Compiled C binaries from /$(C_SUBDIR)$(FMT_OFF)"
	@echo ""


output_dirs:
	mkdir -p $(BASE)
	mkdir -p $(BUILD)
	mkdir -p $(BUILD)/battle/scr/effscr $(BUILD)/battle/scr/movscr $(BUILD)/battle/scr/subscr
	mkdir -p $(BUILD)/msgdata
	mkdir -p $(BUILD)/itemtool
	mkdir -p $(BUILD)/zukan
	mkdir -p $(BUILD)/pokeicon
	mkdir -p $(BUILD)/poketool/personal/pl_personal $(BUILD)/poketool/personal/evo $(BUILD)/poketool/personal/wotbl
	mkdir -p $(BUILD)/narc/battle/skill
	mkdir -p $(BUILD)/narc/msgdata
	mkdir -p $(BUILD)/narc/itemtool
	mkdir -p $(BUILD)/narc/poketool/personal
	mkdir -p $(BUILD)/narc/resource/eng


decompress_rom:
	$(NDSTOOL) -x $(ROMNAME) -9 $(BASE)/arm9.bin -7 $(BASE)/arm7.bin -y9 $(BASE)/y9.bin -y $(BASE)/y7.bin -d $(FILESYS) -y $(BASE)/overlay -t $(BASE)/banner.bin -h $(BASE)/header.bin
	@echo "✅ $(OUTPUT_FMT)Decompiled ROM to /$(BASE)$(FMT_OFF)"
	@echo ""


clean_output_dirs:
	rm -rf $(BASE)
	rm -rf $(BUILD)
	@$(MAKE) --no-print-directory output_dirs
	@echo "✅ $(OUTPUT_FMT)Cleaned up output directories$(FMT_OFF)"
	@echo ""


rom_hooks: decompress_rom c_binaries
	$(PYTHON) scripts/make.py
	@echo "✅ $(OUTPUT_FMT)Compiled overlays and code hooks$(FMT_OFF)"
	@echo ""

	$(ARMIPS) armips/global.s
	@echo "✅ $(OUTPUT_FMT)Compiled ARM9 expansion and overlay table$(FMT_OFF)"
	@echo ""


narcs: $(NARC_FILES)
	@echo "✅ $(OUTPUT_FMT)Compiled new NARCs$(FMT_OFF)"
	@echo ""


copy_narcs: narcs
	cp $(BATTLE_OBJ_NARC) $(BATTLE_OBJ_TARGET)
	cp $(BATTLE_EFFSCR_NARC) $(BATTLE_EFFSCR_TARGET)
	cp $(BATTLE_MOVSCR_NARC) $(BATTLE_MOVSCR_TARGET)
	cp $(BATTLE_SUBSCR_NARC) $(BATTLE_SUBSCR_TARGET)
	cp $(ITEM_DATA_NARC) $(ITEM_DATA_TARGET)
	cp $(PERSONAL_NARC) $(PERSONAL_TARGET)
	cp $(EVO_NARC) $(EVO_TARGET)
	cp $(WOTBL_NARC) $(WOTBL_TARGET)
	cp $(ENCDATA_NARC) $(ENCDATA_TARGET)
	cp $(ZUKAN_NARC) $(ZUKAN_TARGET)
	cp $(TEXT_ARCHIVE_NARC) $(TEXT_ARCHIVE_TARGET)
	cp $(POKEMON_ICONS_NARC) $(POKEMON_ICONS_TARGET)
	@echo "✅ $(OUTPUT_FMT)Copied new NARCs into /$(BASE)$(FMT_OFF)"
	@echo ""


compile_rom: output_dirs rom_hooks copy_narcs
	$(NDSTOOL) -c $(BUILDROM) -9 $(BASE)/arm9.bin -7 $(BASE)/arm7.bin -y9 $(BASE)/y9.bin -y $(BASE)/y7.bin -d $(FILESYS) -y $(BASE)/overlay -t $(BASE)/banner.bin -h $(BASE)/header.bin
	@echo "✅ $(OUTPUT_FMT)Compiled new ROM as /$(BUILDROM)!$(FMT_OFF)"
	@echo "🎉 $(OUTPUT_FMT)Happy testing!$(FMT_OFF)"


build_nitrogfx:
	cd tools/source/nitrogfx ; $(MAKE)
	mv tools/source/nitrogfx/nitrogfx tools/nitrogfx
	cd tools/source/o2narc ; $(MAKE)
	mv tools/source/o2narc/o2narc tools/o2narc


clean:
	rm -rf $(BUILD)
	rm -rf $(BASE)


clean_tools:
	rm -f tools/msgenc
	rm -f tools/pngtobtx0.exe
	rm -f tools/swav2swar.exe
	rm -f tools/ndstool
	rm -f tools/armips
	rm -f tools/nitrogfx
	rm -rf tools/source/ndstool
	rm -rf tools/source/armips


clean_code:
	rm $(BUILD)/*.o
	rm $(BUILD)/*.bin
	rm $(BUILD)/*.d
