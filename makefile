#!/bin/make
MAKEFLAGS += --no-print-directory -j
.SILENT:
.SUFFIXES:
.SECONDARY:

sinclude makefile.user
VERSION := 1.2.0

CC := $(NDK)/toolchains/llvm/prebuilt/linux-x86_64/bin/clang --target=aarch64-linux-android26
CXX := $(NDK)/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-linux-android26

ifdef NDK
OBJDIR := .obj/$(shell $(CXX) -dumpmachine)
else
OBJDIR := .obj/unknown
ndk:
	$(error Android NDK path not set)
endif

CFLAGS := -std=c2x -fPIC -fvisibility=hidden -DVERSION=\"$(VERSION)\" -Weverything \
	-Wno-declaration-after-statement -Wno-unsafe-buffer-usage -Werror -pedantic-errors
CXXFLAGS := -std=c++20 -fPIC -fvisibility=hidden -fdeclspec -DVERSION=\"$(VERSION)\" -isystem .obj/include -isystem extern/includes \
	-isystem extern/includes/bs-cordl/include -isystem extern/includes/libil2cpp/il2cpp/external/baselib/Include \
	-isystem extern/includes/libil2cpp/il2cpp/external/baselib/Platforms/Android/Include -isystem extern/includes/libil2cpp/il2cpp/libil2cpp \
	-isystem extern/includes/fmt/fmt/include -DUNITY_2021 -DHAS_CODEGEN -DFMT_HEADER_ONLY -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Werror -pedantic-errors
LDFLAGS = -static-libstdc++ -shared -Wl,--no-undefined,--gc-sections,--fatal-warnings -Lextern/libs -Lthirdparty \
	-l:$(notdir $(wildcard extern/libs/libbeatsaber-hook*.so)) -lpaper2_scotland2 -lsl2 -llog -l:libUnityOpenXR.so

CXXFILES := $(wildcard src/*.c src/*.cpp src/*/*.cpp) extern/includes/beatsaber-hook/shared/inline-hook/And64InlineHook.cpp

all: WaydroidHelper.qmod

WaydroidHelper.qmod: cover.png thirdparty/libUnityOpenXR.so thirdparty/libopenxr_loader.so thirdparty/UnitySubsystemsManifest.json libWaydroidHelper.so .obj/WaydroidHelper.qmod/mod.json
	@echo "[zip $@]"
	zip -j "$@" $^ extern/libs/libbeatsaber-hook*.so

libWaydroidHelper.so: $(CXXFILES:%=$(OBJDIR)/%.o) | ndk
	@echo "[cxx $@]"
	$(CXX) $(LDFLAGS) $(CXXFILES:%=$(OBJDIR)/%.o) -o "$@"

$(OBJDIR)/%.c.o: %.c extern makefile | ndk
	@echo "[cc $(notdir $@)]"
	@mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c "$<" -o "$@" -MMD -MP

$(OBJDIR)/extern/includes/beatsaber-hook/shared/inline-hook/And64InlineHook.cpp.o: CXXFLAGS += -w
$(OBJDIR)/%.cpp.o: %.cpp extern makefile | ndk
	@echo "[cxx $(notdir $@)]"
	@mkdir -p "$(@D)"
	$(CXX) $(CXXFLAGS) -c "$<" -o "$@" -MMD -MP

.obj/WaydroidHelper.qmod/mod.json: extern makefile
	@echo "[printf $(notdir $@)]"
	@mkdir -p "$(@D)"
	printf "{\n\
		\"\$$schema\": \"https://raw.githubusercontent.com/Lauriethefish/QuestPatcher.QMod/main/QuestPatcher.QMod/Resources/qmod.schema.json\",\n\
		\"_QPVersion\": \"1.2.0\",\n\
		\"modloader\": \"Scotland2\",\n\
		\"name\": \"Waydroid Helper (scotland2 test)\",\n\
		\"id\": \"WaydroidHelper\",\n\
		\"author\": \"rcelyte\",\n\
		\"version\": \"$(VERSION)\",\n\
		\"packageId\": \"com.beatgames.beatsaber\",\n\
		\"packageVersion\": \"1.40.4_5283\",\n\
		\"description\": \"Questless any%%\",\n\
		\"coverImage\": \"cover.png\",\n\
		\"dependencies\": [\n\
			{\n\
				\"version\": \"^4.6.2\",\n\
				\"id\": \"paper2_scotland2\",\n\
				\"downloadIfMissing\": \"https://github.com/Fernthedev/paperlog/releases/download/v4.6.2/paper2_scotland2.qmod\"\n\
			}\n\
		],\n\
		\"modFiles\": [\"libWaydroidHelper.so\"],\n\
		\"libraryFiles\": [\"$(notdir $(wildcard extern/libs/libbeatsaber-hook*.so))\", \"libopenxr_loader.so\", \"libUnityOpenXR.so\"],\n\
		\"fileCopies\": [{\"name\": \"UnitySubsystemsManifest.json\", \"destination\": \"/sdcard/ModData/com.beatgames.beatsaber/Mods/WaydroidHelper/UnityOpenXR/UnitySubsystemsManifest.json\"}]\n\
	}" > $@

thirdparty/libopenxr_loader.so:
	@echo "[curl $(notdir $@)]"
	@mkdir -p .obj/
	curl https://github.com/KhronosGroup/OpenXR-SDK-Source/releases/download/release-1.1.42/openxr_loader_for_android-1.1.42.aar -Lo .obj/openxr_loader.aar
	echo "4e80dcce0f08bbbf153df94d88032ed728a6cf16750733aebe7e6bb5c5814472 .obj/openxr_loader.aar" | \
		sha256sum -c || (rm .obj/openxr_loader.aar; false)
	unzip -ojd $(@D) .obj/openxr_loader.aar prefab/modules/openxr_loader/libs/android.arm64-v8a/libopenxr_loader.so
	rm .obj/openxr_loader.aar
	touch $@

extern/includes/beatsaber-hook/shared/inline-hook/And64InlineHook.cpp: extern

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
