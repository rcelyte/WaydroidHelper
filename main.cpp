#pragma GCC diagnostic ignored "-Wconstant-conversion"
#define NO_CODEGEN_USE
#include <beatsaber-hook/shared/utils/hooking.hpp>
#include <modloader/shared/modloader.hpp>

static Logger *logger = NULL;

namespace UnityEngine::XR::OpenXR::Features {
	struct OpenXRFeature : public Il2CppObject {
		void set_enabled(bool enabled) {
			static auto *proc_ = THROW_UNLESS(il2cpp_utils::FindMethod("UnityEngine.XR.OpenXR.Features", "OpenXRFeature", "set_enabled", std::vector<Il2CppClass*>{},  ::std::vector<const Il2CppType*>{
				il2cpp_utils::il2cpp_type_check::il2cpp_no_arg_type<bool>::get(),
			}));
			return il2cpp_utils::RunMethodRethrow<void, false>(this, proc_, enabled);
		}
	};
}
NEED_NO_BOX(UnityEngine::XR::OpenXR::Features::OpenXRFeature);
DEFINE_IL2CPP_ARG_TYPE(UnityEngine::XR::OpenXR::Features::OpenXRFeature*, "UnityEngine.XR.OpenXR.Features", "OpenXRFeature");

static ListW<Il2CppObject*> XRManagerSettings_get_currentLoaders(Il2CppObject *const self)  {
	static auto *const proc_ = THROW_UNLESS((il2cpp_utils::FindMethod(self, "get_currentLoaders", std::vector<Il2CppClass*>{}, std::vector<const Il2CppType*>{})));
	return il2cpp_utils::RunMethodRethrow<Il2CppObject*, false>(self, proc_);
}

static UnityEngine::XR::OpenXR::Features::OpenXRFeature *OpenXRSettings_GetFeature(Il2CppObject *self, Il2CppClass *featClass) {
	auto *proc_ = THROW_UNLESS(il2cpp_utils::FindMethod("UnityEngine.XR.OpenXR", "OpenXRSettings", "GetFeature", std::vector<Il2CppClass*>{featClass}, ::std::vector<const Il2CppType*>{}));
	auto *genproc_ = THROW_UNLESS(il2cpp_utils::MakeGenericMethod(proc_, std::vector<Il2CppClass*>{featClass}));
	return static_cast<UnityEngine::XR::OpenXR::Features::OpenXRFeature*>(il2cpp_utils::RunMethodRethrow<Il2CppObject*, false>(self, genproc_));
}

static ArrayW<UnityEngine::XR::OpenXR::Features::OpenXRFeature*> OpenXRSettings_GetFeatures(Il2CppObject *self) {
	static auto *proc_ = THROW_UNLESS(il2cpp_utils::FindMethod(self, "GetFeatures", std::vector<Il2CppClass*>{}, ::std::vector<const Il2CppType*>{}));
	return il2cpp_utils::RunMethodRethrow<Il2CppObject*, false>(self, proc_);
}

static Il2CppObject *ScriptableObject_CreateInstance(Il2CppClass *soClass) {
	auto *proc_ = THROW_UNLESS(il2cpp_utils::FindMethod("UnityEngine", "ScriptableObject", "CreateInstance", std::vector<Il2CppClass*>{soClass}, ::std::vector<const Il2CppType*>{}));
	auto *genproc_ = THROW_UNLESS(il2cpp_utils::MakeGenericMethod(proc_, std::vector<Il2CppClass*>{soClass}));
	return il2cpp_utils::RunMethodRethrow<Il2CppObject*, false>(static_cast<Il2CppObject*>(nullptr), genproc_);
}

static Il2CppObject *OpenXRSettings_GetInstance(bool useActiveBuildTarget = false) {
	static auto *proc_ = THROW_UNLESS(il2cpp_utils::FindMethod("UnityEngine.XR.OpenXR", "OpenXRSettings", "GetInstance", std::vector<Il2CppClass*>{},  ::std::vector<const Il2CppType*>{
		il2cpp_utils::il2cpp_type_check::il2cpp_no_arg_type<bool>::get(),
	}));
	return il2cpp_utils::RunMethodRethrow<Il2CppObject*, false>(static_cast<Il2CppObject*>(nullptr), proc_, useActiveBuildTarget);
}

MAKE_HOOK_FIND_CLASS_UNSAFE_STATIC(OculusLoader_IsDeviceSupported, "Unity.XR.Oculus", "OculusLoader", "IsDeviceSupported", int,) {
	const int res = OculusLoader_IsDeviceSupported();
	return (res == 2 /*Unity::XR::Oculus::OculusLoader::DeviceSupportedResult::ExitApplication*/) ? 1 /*Unity::XR::Oculus::OculusLoader::DeviceSupportedResult::NotSupported*/ : res;
}

MAKE_HOOK_FIND_CLASS_UNSAFE_STATIC(OculusInit_NoDomainReloadInit, "", "OculusInit", "NoDomainReloadInit", void,) {
	OculusInit_NoDomainReloadInit();
	THROW_UNLESS(il2cpp_utils::SetFieldValue("", "OculusInit", "__enabled", false));
}

MAKE_HOOK_FIND_CLASS_UNSAFE_INSTANCE(XRManagerSettings_InitializeLoaderSync, "UnityEngine.XR.Management", "XRManagerSettings", "InitializeLoaderSync", void, Il2CppObject *const self) {
	using namespace std::literals;
	static constexpr auto Feature = [](std::string_view namespace_, std::string_view className, bool enabled) {
		Il2CppClass *const class_ = THROW_UNLESS(il2cpp_utils::GetClassFromName(namespace_, className));
		UnityEngine::XR::OpenXR::Features::OpenXRFeature *feature = OpenXRSettings_GetFeature(OpenXRSettings_GetInstance(), class_);
		if(feature == NULL)
			feature = static_cast<UnityEngine::XR::OpenXR::Features::OpenXRFeature*>(ScriptableObject_CreateInstance(class_));
		assert(feature != NULL);
		feature->set_enabled(enabled);
		return feature;
	};

	const auto _OpenXRSettings_features = THROW_UNLESS(il2cpp_utils::FindField(OpenXRSettings_GetInstance(), "features"))->offset;
	*(ArrayW<UnityEngine::XR::OpenXR::Features::OpenXRFeature*>*)((char*)OpenXRSettings_GetInstance() + _OpenXRSettings_features) = { // features seen on PC
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "EyeGazeInteraction"sv, false),
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "HTCViveControllerProfile"sv, true),
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "KHRSimpleControllerProfile"sv, true),
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "MetaQuestTouchProControllerProfile"sv, false),
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "MicrosoftHandInteraction"sv, false),
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "MicrosoftMotionControllerProfile"sv, true),
		Feature("UnityEngine.XR.OpenXR.Features.Mock"sv, "MockRuntime"sv, false),
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "OculusTouchControllerProfile"sv, true),
		Feature("UnityEngine.XR.OpenXR.Features.Interactions"sv, "ValveIndexControllerProfile"sv, true),
	};

	Il2CppObject *const xrLoader = ScriptableObject_CreateInstance(THROW_UNLESS(il2cpp_utils::GetClassFromName("UnityEngine.XR.OpenXR"sv, "OpenXRLoader"sv)));
	assert(xrLoader != NULL);
	ListW<Il2CppObject*> currentLoaders = XRManagerSettings_get_currentLoaders(self);
	assert(currentLoaders.size() >= 1);
	currentLoaders[0] = xrLoader;

	ArrayW<Il2CppObject*> allFeatures = OpenXRSettings_GetFeatures(OpenXRSettings_GetInstance());
	logger->info("Features[%zu]:", allFeatures.size());
	const auto _OpenXRFeature_m_enabled = THROW_UNLESS(il2cpp_utils::FindField(allFeatures[0], "m_enabled"))->offset;
	for(Il2CppObject *const feature : allFeatures) {
		const bool enabled = *reinterpret_cast<bool*>((char*)feature + _OpenXRFeature_m_enabled);
		logger->info("    %s - %s", il2cpp_functions::class_get_name(il2cpp_functions::object_get_class(feature)), enabled ? "enabled" : "disabled");
	}

	XRManagerSettings_InitializeLoaderSync(self);

	void *const libUnityOpenXR = dlopen("libUnityOpenXR.so", 0);
	assert(libUnityOpenXR != NULL);
	void (*NativeConfig_SetRenderMode)(int renderMode) = (decltype(NativeConfig_SetRenderMode))dlsym(libUnityOpenXR, "NativeConfig_SetRenderMode");
	assert(NativeConfig_SetRenderMode != NULL);
	NativeConfig_SetRenderMode(0 /*UnityEngine::XR::OpenXR::OpenXRSettings::RenderMode::MultiPass*/);
	// NativeConfig_SetRenderMode(1 /*UnityEngine::XR::OpenXR::OpenXRSettings::RenderMode::SinglePassInstanced*/);
	dlclose(libUnityOpenXR);
}

MAKE_HOOK_NO_CATCH(Data_GetValue, NULL, const char*, void *self, const char key[], uintptr_t num) {
	const char *const res = Data_GetValue(self, key, num);
	if(strcmp(key, "xr-meta-enabled") == 0)
		return "0";
	if(strcmp(key, "xrsdk-pre-init-library") == 0)
		return "UnityOpenXR";
	return res;
}

extern "C" [[gnu::visibility("default")]] void setup(ModInfo *const info) {
	info->id = "WaydroidHelper";
	info->version = VERSION;
	logger = new Logger(*info, LoggerOptions(false, true));
	logger->info("Completed setup");
}

#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
static void *ElfLoadedSymbol(const char libPath[], const char procName[]) {
	const int lib_fd = open(libPath, O_RDONLY);
	std::shared_ptr<void> _defer((void*)(uintptr_t)(unsigned)lib_fd, [](void *const fd) {close((int)(unsigned)(uintptr_t)fd);});
	struct stat lib_stat = {0};
	if(fstat(lib_fd, &lib_stat) != 0) {
		logger->critical("fstat(\"%s\") failed: %s", libPath, strerror(errno));
		return NULL;
	}
	const Elf64_Ehdr *const header = (const Elf64_Ehdr*)mmap(NULL, lib_stat.st_size, PROT_READ, MAP_SHARED, lib_fd, 0);
	if(header == MAP_FAILED) {
		logger->critical("mmap(\"%s\") failed: %s", libPath, strerror(errno));
		return NULL;
	}
	const Elf64_Shdr *const sections = (const Elf64_Shdr*)&header->e_ident[header->e_shoff];
	for(const Elf64_Shdr *section = sections, *const sections_end = &sections[header->e_shnum]; section < sections_end; ++section) {
		if(section->sh_type != SHT_SYMTAB)
			continue;
		assert(section->sh_entsize == sizeof(Elf64_Sym));
		const char *stringTable = (const char*)&header->e_ident[((const Elf64_Shdr*)&sections[section->sh_link])->sh_offset];
		for(const Elf64_Sym *symbol = (const Elf64_Sym*)&header->e_ident[section->sh_offset], *const symbols_end = &symbol[section->sh_size / sizeof(*symbol)]; symbol < symbols_end; ++symbol)
			if(strcmp(&stringTable[symbol->st_name], procName) == 0)
				return (void*)(baseAddr(libPath) + symbol->st_value);
		break;
	}
	return NULL;
}

extern "C" [[gnu::visibility("default")]] void load() {
	il2cpp_functions::Init();

	const std::string libunity_path = Modloader::getModloaderPath() + "/libunity.so";
	INSTALL_HOOK_DIRECT(*logger, Data_GetValue, THROW_UNLESS(ElfLoadedSymbol(libunity_path.c_str(), "_ZNK10BootConfig4Data8GetValueEPKcm")));
	// Unity implodes if libUnityOpenXR is loaded from a path outside the libs folder
	symlink("/data/user/0/com.beatgames.beatsaber/files/libUnityOpenXR.so", (Modloader::getModloaderPath() + "/libUnityOpenXR.so").c_str());

	INSTALL_HOOK(*logger, OculusLoader_IsDeviceSupported);
	INSTALL_HOOK(*logger, OculusInit_NoDomainReloadInit);
	INSTALL_HOOK(*logger, XRManagerSettings_InitializeLoaderSync);
	logger->info("loaded");
}
