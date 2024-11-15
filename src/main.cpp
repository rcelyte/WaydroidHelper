#include <scotland2/shared/modloader.h>
#include <beatsaber-hook/shared/utils/hooking.hpp>
#include "Unity.XR.OpenXR/XRPolyfill.hpp"
#include "elf_helper.h"
#include "log.hpp"
#include <dlfcn.h>
#include <sys/stat.h>

#include <GlobalNamespace/BasePlatformInit.hpp>
#include <GlobalNamespace/UnityXRController.hpp>
#include <GlobalNamespace/VRController.hpp>
#include <UnityEngine/InputSystem/XR/XRController.hpp>
#include <Unity/XR/Oculus/Oculus.hpp>
#include <UnityEngine/InputSystem/InputAction.hpp>
#include <UnityEngine/XR/InputDevices.hpp>
#include <UnityEngine/XR/InputDevice.hpp>
#include <UnityEngine/XR/WindowsMR/Input/WMRHMD.hpp>

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
#pragma GCC diagnostic ignored "-Wunsafe-buffer-usage"
MAKE_HOOK_MATCH(WMRHMD_FinishSetup, &UnityEngine::XR::WindowsMR::Input::WMRHMD::FinishSetup, void, UnityEngine::XR::WindowsMR::Input::WMRHMD *const self) {
	logger.info("WMRHMD::FinishSetup() pre");
	const UnityEngine::InputSystem::Layouts::InputDeviceDescription desc = self->get_description();
	logger.info("    InterfaceName=\"%s\"", static_cast<std::string>(desc.m_InterfaceName).c_str());
	logger.info("    DeviceClass=\"%s\"", static_cast<std::string>(desc.m_DeviceClass).c_str());
	logger.info("    Manufacturer=\"%s\"", static_cast<std::string>(desc.m_Manufacturer).c_str());
	logger.info("    Product=\"%s\"", static_cast<std::string>(desc.m_Product).c_str());
	logger.info("    Serial=\"%s\"", static_cast<std::string>(desc.m_Serial).c_str());
	logger.info("    Version=\"%s\"", static_cast<std::string>(desc.m_Version).c_str());
	/*logger.info("    Capabilities=<<<");
	auto caps = static_cast<std::string>(desc.m_Capabilities);
	char *start = caps.data();
	for(char &ch : caps) {
		if(ch == ',') {
			logger.info("        %.*s", int(&ch + 1 - start), start);
			start = &ch + 1;
		}
	}
	logger.info("        %.*s", int(&*caps.end() - start), start);
	logger.info("    >>>");*/
	WMRHMD_FinishSetup(self);
	logger.info("WMRHMD::FinishSetup() post");
}
MAKE_HOOK_MATCH(XRController_FinishSetup, &UnityEngine::InputSystem::XR::XRController::FinishSetup, void, UnityEngine::InputSystem::XR::XRController *const self) {
	logger.info("XRController::FinishSetup() pre");
	const UnityEngine::InputSystem::Layouts::InputDeviceDescription desc = self->get_description();
	logger.info("    InterfaceName=\"%s\"", static_cast<std::string>(desc.m_InterfaceName).c_str());
	logger.info("    DeviceClass=\"%s\"", static_cast<std::string>(desc.m_DeviceClass).c_str());
	logger.info("    Manufacturer=\"%s\"", static_cast<std::string>(desc.m_Manufacturer).c_str());
	logger.info("    Product=\"%s\"", static_cast<std::string>(desc.m_Product).c_str());
	logger.info("    Serial=\"%s\"", static_cast<std::string>(desc.m_Serial).c_str());
	logger.info("    Version=\"%s\"", static_cast<std::string>(desc.m_Version).c_str());
	/*logger.info("    Capabilities=<<<");
	auto caps = static_cast<std::string>(desc.m_Capabilities);
	char *start = caps.data();
	for(char &ch : caps) {
		if(ch == ',') {
			logger.info("        %.*s", int(&ch + 1 - start), start);
			start = &ch + 1;
		}
	}
	logger.info("        %.*s", int(&*caps.end() - start), start);
	logger.info("    >>>");*/
	XRController_FinishSetup(self);
	logger.info("XRController::FinishSetup() post");
}
MAKE_HOOK_MATCH(UnityXRController_TryToUpdateManufacturerName, &GlobalNamespace::UnityXRController::TryToUpdateManufacturerName, bool, GlobalNamespace::UnityXRController *const self, UnityEngine::XR::InputDevice device) {
	logger.info("UnityXRController::TryToUpdateManufacturerName(node=%d)", self->node.value__);
	if(device.IsValidId()) {
		logger.info("    name=\"%s\"", static_cast<std::string>(il2cpp_utils::resolve_icall<StringW, uint64_t>("UnityEngine.XR.InputDevices::GetDeviceName")(device.m_DeviceId)).c_str());
		logger.info("    manufacturer=\"%s\"", static_cast<std::string>(UnityEngine::XR::InputDevices::GetDeviceManufacturer(device.m_DeviceId)).c_str());
		logger.info("    serialNumber=\"%s\"", static_cast<std::string>(il2cpp_utils::resolve_icall<StringW, uint64_t>("UnityEngine.XR.InputDevices::GetDeviceSerialNumber")(device.m_DeviceId)).c_str());
		logger.info("    characteristics=\"%u\"", il2cpp_utils::resolve_icall<uint32_t, uint64_t>("UnityEngine.XR.InputDevices::GetDeviceCharacteristics")(device.m_DeviceId));
	}
	return UnityXRController_TryToUpdateManufacturerName(self, device);
}
#if 0
MAKE_HOOK_MATCH(UnityXRHelper_GetNodePose, &GlobalNamespace::UnityXRHelper::GetNodePose, bool, GlobalNamespace::UnityXRHelper *const self, const UnityEngine::XR::XRNode nodeType, const int32_t idx, ByRef<UnityEngine::Vector3> pos, ByRef<UnityEngine::Quaternion> rot) {
	const bool result = UnityXRHelper_GetNodePose(self, nodeType, idx, pos, rot);
	if(result) {
		/*logger.info("UnityXRHelper::GetNodePose(nodeType=%d) -> {{%f, %f, %f}, {%f, %f, %f, %f}}]", nodeType.value__,
			double(pos->x), double(pos->y), double(pos->z), double(rot->x), double(rot->y), double(rot->z), double(rot->z));*/
		auto *const action = self->ControllerFromNode(nodeType)->positionAction;
		logger.info("UnityXRHelper::GetNodePose(nodeType=%d) -> [type=%d] \"%s\"", nodeType.value__,
			action->get_type().value__, static_cast<std::string>(action->ToString()).c_str());
	}
	return result;
}
#endif
MAKE_HOOK_MATCH(UnityXRHelper_Start, &GlobalNamespace::UnityXRHelper::Start, void, GlobalNamespace::UnityXRHelper *const self) {
	UnityXRHelper_Start(self);
	XRPolyfill::unityXRHelper = self;
	XRPolyfill::UpdateUserPresence();
	self->RefreshControllersReference(); // TODO: does this fix the controllers?
}

MAKE_HOOK_MATCH(UnityXRHelper_OnDestroy, &GlobalNamespace::UnityXRHelper::OnDestroy, void, GlobalNamespace::UnityXRHelper *const self) {
	XRPolyfill::unityXRHelper = nullptr;
	UnityXRHelper_OnDestroy(self);
}

extern "C" void setup(CModInfo*);
extern "C" [[gnu::visibility("default")]] void setup(CModInfo *const modInfo) {
	*modInfo = {
		.id = "WaydroidHelper",
		.version = VERSION,
		.version_long = 3,
	};
}

extern "C" void load();
extern "C" [[gnu::visibility("default")]] void load() {
	logger.info("load [1]");

	// TEMP TEST
	// il2cpp_utils::exceptions::StackTraceException(fmt::format("Throwing in {} at {}:{}", "undefined_function", "undefined_file", 23));

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
	// Hooking::InstallHook<Hook_WMRHMD_FinishSetup>(logger);
	// Hooking::InstallHook<Hook_XRController_FinishSetup>(logger);
	// Hooking::InstallHook<Hook_UnityXRController_TryToUpdateManufacturerName>(logger);
	// Hooking::InstallHook<Hook_UnityXRHelper_GetNodePose>(logger);
	Hooking::InstallHook<Hook_UnityXRHelper_Start>(logger);
	Hooking::InstallHook<Hook_UnityXRHelper_OnDestroy>(logger);

	logger.info("load finished 2");

	// TODO: would `late_load()` be a better place for this?
	void UnityOpenXR_JNI_OnLoad(void*, void*) __asm__("JNI_OnLoad");
	UnityOpenXR_JNI_OnLoad(modloader_jvm, nullptr);
	logger.info("JNI_OnLoad() finished");
}
