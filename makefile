#!/bin/make
.SILENT:

sinclude makefile.user
VERSION := 1.0.0

CC := $(NDK)/toolchains/llvm/prebuilt/linux-x86_64/bin/clang --target=aarch64-linux-android26
CXX := $(NDK)/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-linux-android26

ifdef NDK
OBJDIR := .obj/$(shell $(CXX) -dumpmachine)
else
OBJDIR := .obj/unknown
ndk:
	$(error Android NDK path not set)
endif

CXXFLAGS := -std=c++20 -fPIC -fvisibility=hidden -fdeclspec -Iextern/includes -Iextern/includes/libil2cpp/il2cpp/libil2cpp -DVERSION=\"$(VERSION)\" -DUNITY_2021 \
	 -Wall -Wno-dollar-in-identifier-extension -Wno-zero-length-array -Wno-gnu-statement-expression -Wno-format-pedantic -Wno-vla-extension -Wno-unused-function -Werror -pedantic-errors
LDFLAGS = -static-libstdc++ -shared -Wl,--no-undefined,--gc-sections,--fatal-warnings -L$(OBJDIR)/lib/beatsaber-hook -Lextern/libs -l:libbeatsaber-hook_1_2_3.so -llog -lmodloader

FILES := main.cpp extern/includes/beatsaber-hook/src/inline-hook/And64InlineHook.cpp
OBJS := $(FILES:%=$(OBJDIR)/%.o)

WaydroidHelper.qmod: cover.png extern/libs/libbeatsaber-hook_1_2_3.so overrides/libopenxr_loader.so overrides/libUnityOpenXR.so libWaydroidHelper.so .obj/mod.json
	@echo "[zip $@]"
	zip -j "$@" $^

libWaydroidHelper.so: $(OBJDIR)/main.cpp.o | ndk
	@echo "[cxx $@]"
	$(CXX) $(LDFLAGS) $(OBJDIR)/main.cpp.o -o "$@"

$(OBJDIR)/%.cpp.o: %.cpp extern extern/libs/libbeatsaber-hook_1_2_3.so makefile | ndk
	@echo "[cxx $(notdir $@)]"
	@mkdir -p "$(@D)"
	$(CXX) $(CXXFLAGS) -c "$<" -o "$@" -MMD -MP

.obj/mod.json: extern makefile
	@echo "[printf $(notdir $@)]"
	@mkdir -p "$(@D)"
	printf "{\n\
		\"\$$schema\": \"https://raw.githubusercontent.com/Lauriethefish/QuestPatcher.QMod/main/QuestPatcher.QMod/Resources/qmod.schema.json\",\n\
		\"_QPVersion\": \"0.1.1\",\n\
		\"name\": \"Waydroid Helper\",\n\
		\"id\": \"WaydroidHelper\",\n\
		\"author\": \"rcelyte\",\n\
		\"version\": \"1.0.0\",\n\
		\"packageId\": \"com.beatgames.beatsaber\",\n\
		\"packageVersion\": \"1.31.0_5257753291\",\n\
		\"description\": \"Questless any%%\",\n\
		\"coverImage\": \"cover.png\",\n\
		\"dependencies\": [],\n\
		\"modFiles\": [\"libWaydroidHelper.so\"],\n\
		\"libraryFiles\": [\"$(notdir $(wildcard extern/libs/libbeatsaber-hook*.so))\", \"libopenxr_loader.so\", \"libUnityOpenXR.so\"]\n\
	}" > .obj/mod.json

extern:
	@echo "[qpm restore]"
	qpm-rust restore
	touch extern

clean:
	@echo "[cleaning]"
	$(RM) -r .obj/ extern/ include/ WaydroidHelper.qmod libWaydroidHelper.so
	qpm-rust clear || true

.PHONY: clean ndk

sinclude $(FILES:%=$(OBJDIR)/%.d)
