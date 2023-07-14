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

default: all

ROMNAME = rom.nds
BUILDROM = test.nds
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


all: $(OUTPUT) $(BATTLE_OUTPUT)
	rm -rf $(BASE)
	mkdir -p $(BASE)
	mkdir -p $(BUILD)
	mkdir -p $(BUILD)/battle/scr/effscr $(BUILD)/battle/scr/movscr $(BUILD)/battle/scr/subscr
	mkdir -p $(BUILD)/narc/battle/skill $(BUILD)/narc/poketool

	$(NDSTOOL) -x $(ROMNAME) -9 $(BASE)/arm9.bin -7 $(BASE)/arm7.bin -y9 $(BASE)/y9.bin -y $(BASE)/y7.bin -d $(FILESYS) -y $(BASE)/overlay -t $(BASE)/banner.bin -h $(BASE)/header.bin
	@echo " === ROM decompression successful! === "
	@echo " ==== Starting code injection... ===== "

	$(PYTHON) scripts/make.py
	$(ARMIPS) armips/global.s

	$(MAKE) narcs
	$(MAKE) copy_narcs
	
	@echo " =========== Making ROM... =========== "
	$(NDSTOOL) -c $(BUILDROM) -9 $(BASE)/arm9.bin -7 $(BASE)/arm7.bin -y9 $(BASE)/y9.bin -y $(BASE)/y7.bin -d $(FILESYS) -y $(BASE)/overlay -t $(BASE)/banner.bin -h $(BASE)/header.bin
	@echo " =============== Done! =============== "


build_tools:
	cd tools/source/msgenc ; $(MAKE)
	mv tools/source/msgenc/msgenc tools/msgenc

	cd tools ; $(CSC) /target:exe /out:pngtobtx0.exe "source$(SEP)BTX Editor$(SEP)Program-P.cs" "source$(SEP)BTX Editor$(SEP)pngtobtx0.cs" "source$(SEP)BTX Editor$(SEP)BTX0.cs"

	cd tools ; $(CSC) /target:exe /out:swav2swar.exe "source$(SEP)swav2swar$(SEP)Principal.cs"

	rm -r -f tools/source/ndstool
	cd tools/source ; git clone https://github.com/devkitPro/ndstool.git
	cd tools/source/ndstool ; git checkout fa6b6d01881363eb2cd6e31d794f51440791f336
	cd tools/source/ndstool ; find . -name '*.sh' -execdir chmod +x {} \;
	cd tools/source/ndstool ; ./autogen.sh
	cd tools/source/ndstool ; ./configure && $(MAKE)
	mv tools/source/ndstool/ndstool tools/ndstool
	rm -r -f tools/source/ndstool

	rm -r -f tools/source/armips
	cd tools/source ; git clone --recursive https://github.com/Kingcom/armips.git
	cd tools/source/armips ; mkdir build
	cd tools/source/armips/build ; cmake -DCMAKE_BUILD_TYPE=Release ..
	cd tools/source/armips/build ; cmake --build .
	mv tools/source/armips/build/armips tools/armips
	rm -r -f tools/source/armips


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


narcs: $(NARC_FILES)

copy_narcs:
	@echo "copying narcs..."
	cp $(BATTLE_EFFSCR_NARC) $(BATTLE_EFFSCR_TARGET)
	cp $(BATTLE_MOVSCR_NARC) $(BATTLE_MOVSCR_TARGET)
	cp $(BATTLE_SUBSCR_NARC) $(BATTLE_SUBSCR_TARGET)