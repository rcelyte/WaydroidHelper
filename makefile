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

CFLAGS := -std=c2x -fPIC -fvisibility=hidden -DVERSION=\"$(VERSION)\" -Wall -Wextra -Werror -pedantic-errors -Wno-error=unused-function
CXXFLAGS := -std=c++20 -fPIC -fvisibility=hidden -fdeclspec -DVERSION=\"$(VERSION)\" -isystem extern/includes \
	-isystem extern/includes/bs-cordl/include -isystem extern/includes/libil2cpp/il2cpp/libil2cpp -isystem extern/includes/fmt/fmt/include \
	-DUNITY_2021 -DHAS_CODEGEN -DFMT_HEADER_ONLY
LDFLAGS = -static-libstdc++ -shared -Wl,--no-undefined,--gc-sections,--fatal-warnings -Lextern/libs -L.obj -Lextern/libs \
	-l:$(notdir $(wildcard extern/libs/libbeatsaber-hook*.so)) -lpaperlog -lsl2 -llog

CXXFILES := $(wildcard src/*.c src/*.cpp) extern/includes/beatsaber-hook/src/inline-hook/And64InlineHook.cpp

all: WaydroidHelper.qmod

WaydroidHelper.qmod: cover.png $(wildcard overrides/arm64-v8a/*.so) libWaydroidHelper.so .obj/WaydroidHelper.qmod/mod.json
	@echo "[zip $@]"
	zip -j "$@" $^ extern/libs/libbeatsaber-hook*.so

libWaydroidHelper.so: $(CXXFILES:%=$(OBJDIR)/%.o) | ndk
	@echo "[cxx $@]"
	$(CXX) $(LDFLAGS) $(CXXFILES:%=$(OBJDIR)/%.o) -o "$@"

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
		\"packageVersion\": \"1.35.0_8016709773\",\n\
		\"description\": \"Questless any%%\",\n\
		\"coverImage\": \"cover.png\",\n\
		\"dependencies\": [\n\
			{\n\
				\"version\": \"^3.6.1\",\n\
				\"id\": \"paper\",\n\
				\"downloadIfMissing\": \"https://github.com/Fernthedev/paperlog/releases/download/v3.6.3/paperlog.qmod\"\n\
			}\n\
		],\n\
		\"modFiles\": [\"libWaydroidHelper.so\"],\n\
		\"libraryFiles\": [\"$(notdir $(wildcard extern/libs/libbeatsaber-hook*.so))\", \"libopenxr_loader.so\", \"libUnityOpenXR.so\"]\n\
	}" > $@

extern: qpm.json
	@echo "[qpm restore]"
	qpm-rust restore
	touch extern

clean:
	@echo "[cleaning]"
	$(RM) -r .obj/ extern/ WaydroidHelper.qmod libWaydroidHelper.so
	qpm-rust clear || true

.PHONY: clean ndk all

sinclude $(CXXFILES:%=$(OBJDIR)/%.d)
