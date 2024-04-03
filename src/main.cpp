#include <scotland2/shared/modloader.h>
#include <beatsaber-hook/shared/utils/hooking.hpp>
#include "Unity.XR.OpenXR/OpenXRLoader.hpp"
#include "elf_helper.h"
#include "log.hpp"
#include <dlfcn.h>
#include <sys/stat.h>

#include <Unity/XR/Oculus/Oculus.hpp>
#include <GlobalNamespace/BasePlatformInit.hpp>

#pragma GCC diagnostic ignored "-Wexit-time-destructors"

constexpr static bool USE_SYMLINK = true;

static struct IUnityInterfaces *unityInterfaces = nullptr;
MAKE_HOOK_NO_CATCH(OVRPlugin_UnityPluginLoad, nullptr, void, struct IUnityInterfaces *const interfaces) {
	unityInterfaces = interfaces;
	OVRPlugin_UnityPluginLoad(interfaces);
}

MAKE_HOOK_NO_CATCH(Data_GetValue, nullptr, const char*, const void *self, const char key[], unsigned long _unused) {
	const char *const result = Data_GetValue(self, key, _unused);
	if constexpr(USE_SYMLINK) {
		return (std::string_view(key) == "xrsdk-pre-init-library") ? "UnityOpenXR" : result;
	} else {
		static const std::filesystem::path libUnityOpenXR = modloader::get_files_dir() / "libs" / "libUnityOpenXR.so";
		return (std::string_view(key) == "xrsdk-pre-init-library") ? libUnityOpenXR.c_str() : result;
	}
}
static void *(*dynamic_array_emplace_back)(void *self, const char *const &str) = nullptr;
MAKE_HOOK_NO_CATCH(GetSubsystemPluginSearchPaths, nullptr, void, uintptr_t *const paths_out, const void *const packageInfo) {
	GetSubsystemPluginSearchPaths(paths_out, packageInfo);
	dynamic_array_emplace_back(paths_out,
		(std::filesystem::path{modloader::get_modloader_root_load_path()}.replace_filename("Mods") / "WaydroidHelper").c_str());
}
MAKE_HOOK_MATCH(OculusLoader_RuntimeLoadOVRPlugin, &Unity::XR::Oculus::OculusLoader::RuntimeLoadOVRPlugin, void) {}
MAKE_HOOK_MATCH(BasePlatformInit_Initialize, &GlobalNamespace::BasePlatformInit::Initialize, void, GlobalNamespace::BasePlatformInit *const self) {
	self->set_IsInitialized(true);
	BasePlatformInit_Initialize(self);
}

MAKE_HOOK_MATCH(OculusLoader_Initialize, &Unity::XR::Oculus::OculusLoader::Initialize, bool, Unity::XR::Oculus::OculusLoader *const self) {
	[[maybe_unused]] static bool _once = [] {
		void UnityOpenXR_UnityPluginLoad(struct IUnityInterfaces*) __asm__("UnityPluginLoad");
		UnityOpenXR_UnityPluginLoad(unityInterfaces);
		return true;
	}();
	logger.info("XRPolyfill::OpenXRLoader::Initialize()");
	return XRPolyfill::OpenXRLoader::Initialize(self);
}
MAKE_HOOK_MATCH(OculusLoader_Start, &Unity::XR::Oculus::OculusLoader::Start, bool, Unity::XR::Oculus::OculusLoader *const self) {
	logger.info("XRPolyfill::OpenXRLoader::Start()");
	return XRPolyfill::OpenXRLoader::Start(self);
}
MAKE_HOOK_MATCH(OculusLoader_Stop, &Unity::XR::Oculus::OculusLoader::Stop, bool, Unity::XR::Oculus::OculusLoader *const self) {
	logger.info("XRPolyfill::OpenXRLoader::Stop()");
	return XRPolyfill::OpenXRLoader::Stop(self);
}
MAKE_HOOK_MATCH(OculusLoader_Deinitialize, &Unity::XR::Oculus::OculusLoader::Deinitialize, bool, Unity::XR::Oculus::OculusLoader *const self) {
	logger.info("XRPolyfill::OpenXRLoader::Deinitialize()");
	return XRPolyfill::OpenXRLoader::Deinitialize(self);
}
MAKE_HOOK_MATCH(InputFocus_Update, &Unity::XR::Oculus::InputFocus::Update, void) {
	XRPolyfill::OpenXRLoader::ProcessOpenXRMessageLoop();
}
MAKE_HOOK_MATCH(OculusSession_Update, &Unity::XR::Oculus::OculusSession::Update, void) {}

extern "C" void setup(CModInfo*);
extern "C" [[gnu::visibility("default")]] void setup(CModInfo *const modInfo) {
	*modInfo = {
		.id = "WaydroidHelper",
		.version = VERSION,
		.version_long = 2,
	};
}

extern "C" void load();
extern "C" [[gnu::visibility("default")]] void load() {
	logger.info("load [1]");

	// Unity implodes if libUnityOpenXR is loaded from a path outside the libs folder
	if constexpr(USE_SYMLINK) {
		const auto soPath = std::filesystem::path{modloader::get_libil2cpp_path()}.replace_filename("libUnityOpenXR.so");
		struct stat libUnityOpenXR_stat = {};
		if(stat(soPath.c_str(), &libUnityOpenXR_stat) == 0 && (libUnityOpenXR_stat.st_mode & S_IFMT) == S_IFREG) {
			logger.debug("libUnityOpenXR.so already exists; skipping symlink");
		} else if(symlink((modloader::get_files_dir() / "libs" / "libUnityOpenXR.so").c_str(), soPath.c_str()) != 0) {
			logger.error("symlink(libUnityOpenXR.so) failed: %s", strerror(errno));
			return;
		}
	}

	const std::filesystem::path libunity_so = std::filesystem::path{modloader::get_libil2cpp_path()}.replace_filename("libunity.so");
	dynamic_array_emplace_back = reinterpret_cast<decltype(dynamic_array_emplace_back)>(ElfLoadedSymbol(libunity_so.c_str(),
		"_ZN13dynamic_arrayIN4core12basic_stringIcNS0_20StringStorageDefaultIcEEEELm0EE12emplace_backIJRKPKcEEERS4_DpOT_"));
	assert(dynamic_array_emplace_back != nullptr);

	logger.info("installing native hooks");
	Hooking::InstallHookDirect<Hook_OVRPlugin_UnityPluginLoad>(logger, dlsym(dlopen("libOVRPlugin.so", RTLD_NOW), "UnityPluginLoad"));
	Hooking::InstallHookDirect<Hook_Data_GetValue>(logger, ElfLoadedSymbol(libunity_so.c_str(), "_ZNK10BootConfig4Data8GetValueEPKcm"));
	Hooking::InstallHookDirect<Hook_GetSubsystemPluginSearchPaths>(logger, ElfLoadedSymbol(libunity_so.c_str(),
		"_Z29GetSubsystemPluginSearchPathsR13dynamic_arrayIN4core12basic_stringIcNS0_20StringStorageDefaultIcEEEELm0EEPK28SubsystemUpmPackageInfoArray"));

	logger.info("installing managed hooks");
	Hooking::InstallHook<Hook_OculusLoader_RuntimeLoadOVRPlugin>(logger);
	Hooking::InstallHook<Hook_BasePlatformInit_Initialize>(logger);

	Hooking::InstallHook<Hook_OculusLoader_Initialize>(logger);
	Hooking::InstallHook<Hook_OculusLoader_Start>(logger);
	Hooking::InstallHook<Hook_OculusLoader_Stop>(logger);
	Hooking::InstallHook<Hook_OculusLoader_Deinitialize>(logger);
	Hooking::InstallHook<Hook_InputFocus_Update>(logger);
	Hooking::InstallHook<Hook_OculusSession_Update>(logger);
	logger.info("load finished");

	void UnityOpenXR_JNI_OnLoad(void*, void*) __asm__("JNI_OnLoad");
	UnityOpenXR_JNI_OnLoad(modloader_jvm, nullptr);
}
