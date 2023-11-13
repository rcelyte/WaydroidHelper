#include "elf_helper.h"
#include "log.h"
#include "methods.h"
#include <scotland2/shared/modloader.h>
#include <flamingo/shared/And64InlineHook.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dlfcn.h>
#define lengthof(...) (sizeof(__VA_ARGS__) / sizeof((__VA_ARGS__)[0]))

// for -Wmissing-prototypes
[[gnu::visibility("default")]] void setup(CModInfo *const modInfo);
[[gnu::visibility("default")]] void load();

#define InstallHook(hook, ...) InstallHook_((void*)(__VA_ARGS__), (void*)(hook), (void**)&hook##_base, #__VA_ARGS__)
static bool InstallHook_(void *const original, void *const hook, void **const base_out, const char name[]) {
	assert(hook != NULL && base_out != NULL);
	if(original == NULL || *base_out != NULL)
		return false;
	A64HookFunction(original, hook, base_out);
	if(base_out == NULL)
		logLine_err("A64HookFunction(%s) failed", name);
	return *base_out != NULL;
}

static const char *(*BootConfig_Data_GetValue_base)(void*, const char[], uintptr_t) = NULL;
static const char *BootConfig_Data_GetValue(void *const self, const char key[], const uintptr_t _arg2) {
	const char *const result = BootConfig_Data_GetValue_base(self, key, _arg2);
	logLine("BootConfig_Data_GetValue_base(\"%s\", %zu) -> %s", key, _arg2, result);
	if(strcmp(key, "xr-meta-enabled") == 0)
		return "0";
	if(strcmp(key, "xrsdk-pre-init-library") == 0)
		return "UnityOpenXR";
	return result;
}

static int32_t (*OculusLoader_IsDeviceSupported_base)() = NULL;
static int32_t OculusLoader_IsDeviceSupported() {
	const int32_t result = OculusLoader_IsDeviceSupported_base();
	return (result == 2 /*DeviceSupportedResult::ExitApplication*/) ? 1 /*DeviceSupportedResult::NotSupported*/ : result;
}

static void (*OculusInit_NoDomainReloadInit_base)() = NULL;
static void OculusInit_NoDomainReloadInit() {
	OculusInit_NoDomainReloadInit_base();
	il2cpp_field_static_set_value(Helper_GetField("", "OculusInit", "__enabled"), &(bool){false});
}

static Il2CppObject *GetOrContructOpenXRFeature(Il2CppObject *const xrSettings, Il2CppClass *const class, bool enabled) {
	assert(class != NULL);
	Il2CppObject *feature = OpenXRSettings_GetFeature(xrSettings, class);
	if(feature == NULL)
		feature = ScriptableObject_CreateInstance(class);
	assert(feature != NULL);
	OpenXRFeature_set_enabled(feature, enabled);
	return feature;
}

static void (*XRManagerSettings_InitializeLoaderSync_base)(Il2CppObject*) = NULL;
static void XRManagerSettings_InitializeLoaderSync(Il2CppObject *const self) {
	logLine("XRManagerSettings_InitializeLoaderSync() pre");
	const struct {Il2CppClass *class; bool enabled; uint64_t:56;} featureDescs[] = {
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "EyeGazeInteraction"), false},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "HTCViveControllerProfile"), true},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "KHRSimpleControllerProfile"), true},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "MetaQuestTouchProControllerProfile"), false},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "MicrosoftHandInteraction"), false},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "MicrosoftMotionControllerProfile"), true},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Mock", "MockRuntime"), false},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "OculusTouchControllerProfile"), true},
		{Helper_GetClass("UnityEngine.XR.OpenXR.Features.Interactions", "ValveIndexControllerProfile"), true},
	};
	Il2CppClass *const OpenXRFeature_class = Helper_GetClass("UnityEngine.XR.OpenXR.Features", "OpenXRFeature");
	Il2CppArray *const features = il2cpp_array_new(OpenXRFeature_class, lengthof(featureDescs));
	Il2CppObject *const xrSettings = OpenXRSettings_GetInstance(false);
	Helper_InstanceFieldSet_Object(xrSettings, "features", &features->obj);
	Il2CppObject **const xrSettings_values = &((Il2CppObject**)features)[il2cpp_array_object_header_size() / sizeof(Il2CppObject*)];
	for(uint32_t i = 0; i < lengthof(featureDescs); ++i)
		xrSettings_values[i] = GetOrContructOpenXRFeature(xrSettings, featureDescs[i].class, featureDescs[i].enabled);

	Il2CppObject *const xrLoader = ScriptableObject_CreateInstance(Helper_GetClass("UnityEngine.XR.OpenXR", "OpenXRLoader"));
	assert(xrLoader != NULL);
	Il2CppObject *const currentLoaders = XRManagerSettings_get_currentLoaders(self);
	uint32_t currentLoaders_size = 0;
	Helper_InstanceFieldValue(currentLoaders, "_size", &currentLoaders_size);
	assert(currentLoaders_size >= 1);
	Il2CppArray *currentLoaders_items = NULL;
	Helper_InstanceFieldValue(currentLoaders, "_items", &currentLoaders_items);
	assert(currentLoaders_items != NULL && il2cpp_array_length(currentLoaders_items) >= currentLoaders_size);
	((Il2CppObject**)currentLoaders_items)[il2cpp_array_object_header_size() / sizeof(void*)] = xrLoader;

	XRManagerSettings_InitializeLoaderSync_base(self);

	void *const libUnityOpenXR = dlopen("libUnityOpenXR.so", 0);
	assert(libUnityOpenXR != NULL);
	void (*NativeConfig_SetRenderMode)(int32_t renderMode) = (void(*)(int32_t))dlsym(libUnityOpenXR, "NativeConfig_SetRenderMode");
	assert(NativeConfig_SetRenderMode != NULL);
	NativeConfig_SetRenderMode(0 /*UnityEngine::XR::OpenXR::OpenXRSettings::RenderMode::MultiPass*/);
	// NativeConfig_SetRenderMode(1 /*UnityEngine::XR::OpenXR::OpenXRSettings::RenderMode::SinglePassInstanced*/);
	dlclose(libUnityOpenXR);
	logLine("XRManagerSettings_InitializeLoaderSync() post");
}

[[gnu::visibility("default")]] void setup(CModInfo *const modInfo) {
	*modInfo = (CModInfo){
		.id = "WaydroidHelper",
		.version = VERSION,
		// TODO: .version_long = ...
	};
}

[[gnu::visibility("default")]] void load() {
	logLine_info("load");

	const char *const libil2cpp_so = modloader_get_libil2cpp_path();
	const char *const libPathEnd = strrchr(libil2cpp_so, '/');
	if(libPathEnd == NULL) {
		logLine_err("Bad libil2cpp path");
		return;
	}
	char soPath[0x4000], libUnityOpenXR_so[0x4000];
	assert((uint32_t)snprintf(soPath, sizeof(soPath), "%.*s/libunity.so", (int)(libPathEnd - libil2cpp_so), libil2cpp_so) < sizeof(soPath));
	void *const BootConfigːːDataːːGetValue = ElfLoadedSymbol(soPath, "_ZNK10BootConfig4Data8GetValueEPKcm");
	if(BootConfigːːDataːːGetValue == NULL) {
		logLine_err("ElfLoadedSymbol(\"BootConfig::Data::GetValue\") failed");
		return;
	}

	// Unity implodes if libUnityOpenXR is loaded from a path outside the libs folder
	assert((uint32_t)snprintf(soPath, sizeof(soPath), "%.*s/libUnityOpenXR.so", (int)(libPathEnd - libil2cpp_so), libil2cpp_so) < sizeof(soPath));
	assert((uint32_t)snprintf(libUnityOpenXR_so, sizeof(libUnityOpenXR_so), "%s/libs/libUnityOpenXR.so", modloader_get_files_dir()) < sizeof(libUnityOpenXR_so));
	struct stat libUnityOpenXR_stat = {0};
	if(stat(soPath, &libUnityOpenXR_stat) == 0 && (libUnityOpenXR_stat.st_mode & S_IFMT) == S_IFREG) {
		logLine("libUnityOpenXR.so already exists; skipping symlink");
	} else if(symlink(libUnityOpenXR_so, soPath) != 0) {
		logLine_err("symlink(libUnityOpenXR.so) failed: %s", strerror(errno));
		return;
	}

	bool result = true;
	result &= InstallHook(BootConfig_Data_GetValue, BootConfigːːDataːːGetValue);
	result &= InstallHook(OculusLoader_IsDeviceSupported, Helper_MethodPointer("Unity.XR.Oculus", "OculusLoader", "IsDeviceSupported", 0));
	result &= InstallHook(OculusInit_NoDomainReloadInit, Helper_MethodPointer("", "OculusInit", "NoDomainReloadInit", 0));
	result &= InstallHook(XRManagerSettings_InitializeLoaderSync, Helper_MethodPointer("UnityEngine.XR.Management", "XRManagerSettings", "InitializeLoaderSync", 0));
	logLine_info("load %s", result ? "finished" : "failed");
}
