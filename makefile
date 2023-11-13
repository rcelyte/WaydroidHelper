#!/bin/make
MAKEFLAGS += --no-print-directory -j
.SILENT:
.SUFFIXES:
.SECONDARY:

sinclude makefile.user
VERSION := 1.0.0-sl2test

CC := $(NDK)/toolchains/llvm/prebuilt/linux-x86_64/bin/clang --target=aarch64-linux-android26
CXX := $(NDK)/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-linux-android26

ifdef NDK
OBJDIR := .obj/$(shell $(CXX) -dumpmachine)
else
OBJDIR := .obj/unknown
ndk:
	$(error Android NDK path not set)
endif

CFLAGS := -std=c2x -fPIC -fvisibility=hidden -DVERSION=\"$(VERSION)\" -isystem extern/includes -isystem src/include \
	-isystem extern/includes/libil2cpp/il2cpp/libil2cpp -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS := -std=c++20 -fPIC -fvisibility=hidden -fdeclspec -DVERSION=\"$(VERSION)\" -isystem extern/includes/flamingo/shared
LDFLAGS = -static-libstdc++ -shared -Wl,--no-undefined,--gc-sections,--fatal-warnings -Lextern/libs -L.obj -lil2cpp -lsl2 -llog

CFILES := $(wildcard src/*.c) extern/includes/flamingo/src/And64InlineHook.cpp

all: WaydroidHelper.qmod

WaydroidHelper.qmod: cover.png $(wildcard overrides/*.so) libWaydroidHelper.so .obj/WaydroidHelper.qmod/mod.json
	@echo "[zip $@]"
	zip -j "$@" $^

libWaydroidHelper.so: $(CFILES:%=$(OBJDIR)/%.o) .obj/libil2cpp.so | ndk
	@echo "[cxx $@]"
	$(CXX) $(LDFLAGS) $(CFILES:%=$(OBJDIR)/%.o) -o "$@"

$(OBJDIR)/src/%.c.o: CFLAGS += 
$(OBJDIR)/%.c.o: %.c extern makefile | ndk
	@echo "[cc $(notdir $@)]"
	@mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c "$<" -o "$@" -MMD -MP

$(OBJDIR)/%.cpp.o: %.cpp extern makefile | ndk
	@echo "[cxx $(notdir $@)]"
	@mkdir -p "$(@D)"
	$(CXX) $(CXXFLAGS) -c "$<" -o "$@" -MMD -MP

.obj/WaydroidHelper.qmod/mod.json: extern
	@echo "[printf $(notdir $@)]"
	@mkdir -p "$(@D)"
	printf "{\n\
		\"\$$schema\": \"https://raw.githubusercontent.com/Lauriethefish/QuestPatcher.QMod/main/QuestPatcher.QMod/Resources/qmod.schema.json\",\n\
		\"_QPVersion\": \"0.1.1\",\n\
		\"modloader\": \"Scotland2\",\n\
		\"name\": \"Waydroid Helper (scotland2 test)\",\n\
		\"id\": \"WaydroidHelper\",\n\
		\"author\": \"rcelyte\",\n\
		\"version\": \"$(VERSION)\",\n\
		\"packageId\": \"com.beatgames.beatsaber\",\n\
		\"packageVersion\": \"1.31.0_5257753291\",\n\
		\"description\": \"Questless any%%\",\n\
		\"coverImage\": \"cover.png\",\n\
		\"dependencies\": [],\n\
		\"modFiles\": [\"libWaydroidHelper.so\"],\n\
		\"libraryFiles\": [\"libopenxr_loader.so\", \"libUnityOpenXR.so\"]\n\
	}" > $@

.obj/libil2cpp.so: extern makefile
	@echo "[cc $(notdir $@)]"
	printf "char il2cpp_defaults[1];\n" | $(CC) -xc -std=c11 - extern/includes/libil2cpp/il2cpp/libil2cpp/il2cpp-api-functions.h -o $@ \
		-D'DO_API(result_, name_, params_)=char name_[1];' -fPIC -fvisibility=default -nodefaultlibs -nostartfiles -shared

extern: qpm.json
	@echo "[qpm restore]"
	qpm-rust restore
	touch extern

clean:
	@echo "[cleaning]"
	$(RM) -r .obj/ extern/ WaydroidHelper.qmod libWaydroidHelper.so
	qpm-rust clear || true

.PHONY: clean ndk all

sinclude $(CFILES:%=$(OBJDIR)/%.d)
