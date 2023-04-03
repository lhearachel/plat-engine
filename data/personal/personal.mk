PERSONAL_NARC   := $(BUILD_NARC)/pl_personal.narc
PERSONAL_TARGET := $(FILESYS)/poketool/personal
PERSONAL_BUILD  := $(BUILD)/pl_personal
PERSONAL_DEPS   := data/personal/base_stats.c
PERSONAL_OBJS   := $(patsubst %.c,%.o,$(PERSONAL_DEPS))

$(PERSONAL_NARC): $(PERSONAL_DEPS)
	$(CC) $(CFLAGS) -c $< -o $(PERSONAL_OBJS)
	$(O2NARC) $(PERSONAL_OBJS) $@ -n -p 255

NARC_FILES += $(PERSONAL_NARC)
