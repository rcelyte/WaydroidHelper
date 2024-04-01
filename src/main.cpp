#include <scotland2/shared/modloader.h>
#include <beatsaber-hook/shared/utils/hooking.hpp>
#include "elf_helper.h"
#include "log.hpp"
#include <sys/stat.h>

#include <Unity/XR/Oculus/OculusLoader.hpp>
#include <GlobalNamespace/BasePlatformInit.hpp>

MAKE_HOOK_NO_CATCH(Data_GetValue, nullptr, const char*, const void *self, const char key[], unsigned long _unused) {
	const char *const result = Data_GetValue(self, key, _unused);
	return (std::string_view(key) == "xrsdk-pre-init-library") ? "UnityOpenXR" : result;
}

MAKE_HOOK_MATCH(OculusLoader_RuntimeLoadOVRPlugin, &Unity::XR::Oculus::OculusLoader::RuntimeLoadOVRPlugin, void) {}

MAKE_HOOK_MATCH(BasePlatformInit_Initialize, &GlobalNamespace::BasePlatformInit::Initialize, void, GlobalNamespace::BasePlatformInit *const self) {
	self->set_IsInitialized(true);
	BasePlatformInit_Initialize(self);
}

extern "C" void setup(CModInfo*);
extern "C" [[gnu::visibility("default")]] void setup(CModInfo *const modInfo) {
	*modInfo = (CModInfo){
		.id = "WaydroidHelper",
		.version = VERSION,
		.version_long = 2,
	};
}

extern "C" void load();
extern "C" [[gnu::visibility("default")]] void load() {
	logger.info("load [7]");

	// Unity implodes if libUnityOpenXR is loaded from a path outside the libs folder
	const auto soPath = std::filesystem::path{modloader::get_libil2cpp_path()}.replace_filename("libUnityOpenXR.so");
	struct stat libUnityOpenXR_stat = {0};
	if(stat(soPath.c_str(), &libUnityOpenXR_stat) == 0 && (libUnityOpenXR_stat.st_mode & S_IFMT) == S_IFREG) {
		logger.debug("libUnityOpenXR.so already exists; skipping symlink");
	} else if(symlink((modloader::get_files_dir() / "libs" / "libUnityOpenXR.so").c_str(), soPath.c_str()) != 0) {
		logger.error("symlink(libUnityOpenXR.so) failed: %s", strerror(errno));
		return;
	}

	Hooking::InstallHookDirect<Hook_Data_GetValue>(logger, ElfLoadedSymbol(
		std::filesystem::path{modloader::get_libil2cpp_path()}.replace_filename("libunity.so").c_str(), "_ZNK10BootConfig4Data8GetValueEPKcm"));
	Hooking::InstallHook<Hook_OculusLoader_RuntimeLoadOVRPlugin>(logger);
	Hooking::InstallHook<Hook_BasePlatformInit_Initialize>(logger);
	logger.info("load finished");
}
