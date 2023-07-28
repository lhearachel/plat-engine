POKEGRA_DIR := data/graphics
POKEGRA_SPRITES_DIR = $(POKEGRA_DIR)/pokesprites
POKEGRA_BUILD_DIR := $(BUILD)/pokesprites
POKEGRA_NARC := $(BUILD_NARC)/pl_pokegra.narc
POKEGRA_TARGET := $(FILESYS)/poketool/pokegra/pl_pokegra.narc

POKEGRA_GFX_FLAGS_SPRITE := -scanfronttoback -handleempty
POKEGRA_GFX_FLAGS_PAL := -bitdepth 8 -nopad -comp 10

# data/graphics/pokesprites/number/female/back.png
POKEGRA_FEMALE_BACK_FILES := $(wildcard $(POKEGRA_SPRITES_DIR)/*/female/back.png)
POKEGRA_FEMALE_BACK_OBJS := $(patsubst $(POKEGRA_SPRITES_DIR)/%/female/back.png,$(POKEGRA_BUILD_DIR)/%-00.NCGR,$(POKEGRA_FEMALE_BACK_FILES))
# data/graphics/pokesprites/number/male/back.png
POKEGRA_MALE_BACK_FILES := $(wildcard $(POKEGRA_SPRITES_DIR)/*/male/back.png)
POKEGRA_MALE_BACK_OBJS := $(patsubst $(POKEGRA_SPRITES_DIR)/%/male/back.png,$(POKEGRA_BUILD_DIR)/%-01.NCGR,$(POKEGRA_MALE_BACK_FILES))
# data/graphics/pokesprites/number/female/front.png
POKEGRA_FEMALE_FRONT_FILES := $(wildcard $(POKEGRA_SPRITES_DIR)/*/female/front.png)
POKEGRA_FEMALE_FRONT_OBJS := $(patsubst $(POKEGRA_SPRITES_DIR)/%/female/front.png,$(POKEGRA_BUILD_DIR)/%-02.NCGR,$(POKEGRA_FEMALE_FRONT_FILES))
# data/graphics/pokesprites/number/male/front.png
POKEGRA_MALE_FRONT_FILES := $(wildcard $(POKEGRA_SPRITES_DIR)/*/male/front.png)
POKEGRA_MALE_FRONT_OBJS := $(patsubst $(POKEGRA_SPRITES_DIR)/%/male/front.png,$(POKEGRA_BUILD_DIR)/%-03.NCGR,$(POKEGRA_MALE_FRONT_FILES))
# palettes
POKEGRA_NORMAL_PALS := $(patsubst $(POKEGRA_SPRITES_DIR)/%/female/back.png,$(POKEGRA_BUILD_DIR)/%-04.NCLR,$(POKEGRA_FEMALE_BACK_FILES))
POKEGRA_SHINY_PALS := $(patsubst $(POKEGRA_SPRITES_DIR)/%/female/back.png,$(POKEGRA_BUILD_DIR)/%-05.NCLR,$(POKEGRA_FEMALE_BACK_FILES))


$(POKEGRA_BUILD_DIR)/%-00.NCGR: $(POKEGRA_SPRITES_DIR)/%/female/back.png
	$(GFX) $< $@ $(POKEGRA_GFX_FLAGS_SPRITE)

$(POKEGRA_BUILD_DIR)/%-01.NCGR: $(POKEGRA_SPRITES_DIR)/%/male/back.png
	$(GFX) $< $@ $(POKEGRA_GFX_FLAGS_SPRITE)

$(POKEGRA_BUILD_DIR)/%-02.NCGR: $(POKEGRA_SPRITES_DIR)/%/female/front.png
	$(GFX) $< $@ $(POKEGRA_GFX_FLAGS_SPRITE)

$(POKEGRA_BUILD_DIR)/%-03.NCGR: $(POKEGRA_SPRITES_DIR)/%/male/front.png
	$(GFX) $< $@ $(POKEGRA_GFX_FLAGS_SPRITE)

$(POKEGRA_BUILD_DIR)/%-04.NCLR: $(POKEGRA_SPRITES_DIR)/%/male/front.png
	if test -s $<; then \
		$(GFX) $< $@ $(POKEGRA_GFX_FLAGS_PAL); \
	elif test -s $(patsubst $(POKEGRA_SPRITES_DIR)/%/male/front.png,$(POKEGRA_SPRITES_DIR)/%/female/front.png,$<); then \
		$(GFX) $(patsubst $(POKEGRA_SPRITES_DIR)/%/male/front.png,$(POKEGRA_SPRITES_DIR)/%/female/front.png,$<) $@ $(POKEGRA_GFX_FLAGS_PAL); \
	fi

$(POKEGRA_BUILD_DIR)/%-05.NCLR: $(POKEGRA_SPRITES_DIR)/%/male/back.png
	if test -s $<; then \
		$(GFX) $< $@ $(POKEGRA_GFX_FLAGS_PAL); \
	elif test -s $(patsubst $(POKEGRA_SPRITES_DIR)/%/male/back.png,$(POKEGRA_SPRITES_DIR)/%/female/back.png,$<); then \
		$(GFX) $(patsubst $(POKEGRA_SPRITES_DIR)/%/male/back.png,$(POKEGRA_SPRITES_DIR)/%/female/back.png,$<) $@ $(POKEGRA_GFX_FLAGS_PAL); \
	fi

$(POKEGRA_NARC) : $(POKEGRA_FEMALE_BACK_OBJS) $(POKEGRA_MALE_BACK_OBJS) $(POKEGRA_FEMALE_FRONT_OBJS) $(POKEGRA_MALE_FRONT_OBJS) $(POKEGRA_NORMAL_PALS) $(POKEGRA_SHINY_PALS)
	$(NARCHIVE) create $@ $(POKEGRA_BUILD_DIR) -nf

NARC_FILES += $(POKEGRA_NARC)
