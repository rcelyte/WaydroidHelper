#pragma once
#include <stdint.h>

// Some of these probably have bad signatures; needs more research

#ifndef OPENXR_H_
typedef enum XrEnvironmentBlendMode {
	XR_ENVIRONMENT_BLEND_MODE_OPAQUE = 1,
	XR_ENVIRONMENT_BLEND_MODE_ADDITIVE = 2,
	XR_ENVIRONMENT_BLEND_MODE_ALPHA_BLEND = 3,
	XR_ENVIRONMENT_BLEND_MODE_MAX_ENUM = 0x7FFFFFFF,
} XrEnvironmentBlendMode;
typedef int32_t XrResult;
#endif

#ifdef __cplusplus
namespace UnityOpenXR {
extern "C" {
#endif

/* P/Invoke entrypoints:
	void DiagnosticReport_AddEventEntry(string eventName, string eventData);
	void DiagnosticReport_AddSectionBreak(ulong sectionHandle);
	void DiagnosticReport_AddSectionEntry(ulong sectionHandle, string sectionEntry, string sectionBody);
	void DiagnosticReport_DumpReport();
	void DiagnosticReport_DumpReportWithReason(string reason);
	IntPtr DiagnosticReport_GenerateReport();
	ulong DiagnosticReport_GetSection(string sectionName);
	void DiagnosticReport_ReleaseReport(IntPtr report);
	void DiagnosticReport_StartReport();
	bool Internal_GetCurrentInteractionProfile(ulong pathId, out ulong interactionProfile);
	bool Internal_PathToString(ulong pathId, out IntPtr path);
	bool Internal_StringToPath([MarshalAs(UnmanagedType.LPStr)] string str, out ulong pathId);
	bool main_LoadOpenXRLibrary(byte[] loaderPath);
	void main_UnloadOpenXRLibrary();
	void messagepump_PumpMessageLoop();
	bool NativeConfig_GetAllowRecentering();
	bool NativeConfig_GetAPIVersion(out ushort major, out ushort minor, out uint patch);
	DepthSubmissionMode NativeConfig_GetDepthSubmissionMode();
	XrEnvironmentBlendMode NativeConfig_GetEnvironmentBlendMode();
	float NativeConfig_GetFloorOffsetHeight();
	int NativeConfig_GetFormFactor();
	bool NativeConfig_GetPluginVersion(out IntPtr pluginVersionPtr);
	IntPtr NativeConfig_GetProcAddressPtr(bool loaderDefault);
	RenderMode NativeConfig_GetRenderMode();
	bool NativeConfig_GetRuntimeName(out IntPtr runtimeNamePtr);
	bool NativeConfig_GetRuntimeVersion(out ushort major, out ushort minor, out uint patch);
	uint NativeConfig_GetUnityVersion(string unityVersion);
	int NativeConfig_GetViewConfigurationType();
	int NativeConfig_GetViewTypeFromRenderIndex(int renderPassIndex);
	void NativeConfig_SetAllowRecentering(bool active, float height);
	void NativeConfig_SetApplicationInfo(string applicationName, string applicationVersion, uint applicationVersionHash, string engineVersion);
	void NativeConfig_SetCallbacks(OpenXRLoader.ReceiveNativeEventDelegate callback);
	void NativeConfig_SetDepthSubmissionMode(DepthSubmissionMode depthSubmissionMode);
	void NativeConfig_SetEnvironmentBlendMode(XrEnvironmentBlendMode xrEnvironmentBlendMode);
	void NativeConfig_SetProcAddressPtrAndLoadStage1(IntPtr func);
	void NativeConfig_SetRenderMode(RenderMode renderMode);
	void NativeConfig_SetSymmetricProjection(bool enabled);
	bool OpenXRInputProvider_AttachActionSets();
	ulong OpenXRInputProvider_CreateAction(ulong actionSetId, string name, string localizedName, uint actionType, SerializedGuid guid, string[] userPaths, uint userPathCount, bool isAdditive, string[] usages, uint usageCount);
	ulong OpenXRInputProvider_CreateActionSet(string name, string localizedName, SerializedGuid guid);
	ulong OpenXRInputProvider_GetActionIdByControl(uint deviceId, string name);
	bool OpenXRInputProvider_GetActionIsActive(uint deviceId, string name);
	bool OpenXRInputProvider_GetAppSpace(out ulong appSpace);
	ulong OpenXRInputProvider_RegisterDeviceDefinition(string userPath, string interactionProfile, bool isAdditive, uint characteristics, string name, string manufacturer, string serialNumber);
	__cdecl void OpenXRInputProvider_SendHapticImpulse(uint deviceId, ulong actionId, float amplitude, float frequency, float duration);
	__cdecl void OpenXRInputProvider_SetDpadBindingCustomValues(bool isLeft, float forceThreshold, float forceThresholdReleased, float centerRegion, float wedgeAngle, bool isSticky);
	__cdecl void OpenXRInputProvider_StopHaptics(uint deviceId, ulong actionId);
	bool OpenXRInputProvider_SuggestBindings(string interactionProfile, SerializedBinding[] serializedBindings, uint serializedBindingCount);
	bool OpenXRInputProvider_TryGetInputSourceName(uint deviceId, ulong actionId, uint index, uint flags, out IntPtr outName);
	bool OpenXRInputProvider_TrySetControllerLateLatchAction(uint deviceId, ulong actionId);
	void session_BeginSession();
	bool session_CreateSessionIfNeeded();
	void session_DestroySession();
	void session_EndSession();
	bool session_GetLastError(out IntPtr error);
	void session_GetSessionState(out int oldState, out int newState);
	bool session_GetSoftRestartLoopAtInitialization();
	bool session_InitializeSession();
	void session_RequestExitSession();
	void session_SetSoftRestartLoopAtInitialization(bool value);
	void session_SetSuccessfullyInitialized(bool value);
	uint unity_ext_GetAvailableExtensionCount();
	bool unity_ext_GetAvailableExtensionName(uint index, out IntPtr extensionName);
	uint unity_ext_GetEnabledExtensionCount();
	bool unity_ext_GetEnabledExtensionName(uint index, out IntPtr outName);
	uint unity_ext_GetExtensionVersion(string extensionName);
	bool unity_ext_IsExtensionEnabled(string extensionName);
	bool unity_ext_RequestEnableExtensionString(string extensionString);
*/

enum NativeEvent : uint32_t {
	// Setup
	NativeEvent_XrSetupConfigValues,
	NativeEvent_XrSystemIdChanged,
	NativeEvent_XrInstanceChanged,
	NativeEvent_XrSessionChanged,
	NativeEvent_XrBeginSession,

	// Runtime
	NativeEvent_XrSessionStateChanged,
	NativeEvent_XrChangedSpaceApp,

	// Shutdown
	NativeEvent_XrEndSession,
	NativeEvent_XrDestroySession,
	NativeEvent_XrDestroyInstance,

	// General Session Events
	NativeEvent_XrIdle,
	NativeEvent_XrReady,
	NativeEvent_XrSynchronized,
	NativeEvent_XrVisible,
	NativeEvent_XrFocused,
	NativeEvent_XrStopping,
	NativeEvent_XrExiting,
	NativeEvent_XrLossPending,
	NativeEvent_XrInstanceLossPending,
	NativeEvent_XrRestartRequested,
	NativeEvent_XrRequestRestartLoop,
	NativeEvent_XrRequestGetSystemLoop,
};
enum DepthSubmissionMode {
	DepthSubmissionMode_None, // No depth is submitted to the OpenXR compositor.
	DepthSubmissionMode_Depth16Bit, // 16-bit depth is submitted to the OpenXR compositor.
	DepthSubmissionMode_Depth24Bit, // 24-bit depth is submitted to the OpenXR compositor.
};
enum RenderMode {
	RenderMode_MultiPass, // Submit separate draw calls for each eye.
	RenderMode_SinglePassInstanced, // Submit one draw call for both eyes.
};
struct SerializedGuid {
	uint64_t data[2];
};
struct SerializedBinding {
	uint64_t actionId;
	const char *path;
};

typedef void ReceiveNativeEventDelegate(enum NativeEvent e, uint64_t payload);
typedef char STRING_MARSHAL_TYPE;
void DiagnosticReport_AddEventEntry(const STRING_MARSHAL_TYPE eventName[], const STRING_MARSHAL_TYPE eventData[]);
void DiagnosticReport_AddSectionBreak(uint64_t sectionHandle);
void DiagnosticReport_AddSectionEntry(uint64_t sectionHandle, const STRING_MARSHAL_TYPE sectionEntry[], const STRING_MARSHAL_TYPE sectionBody[]);
void DiagnosticReport_DumpReport();
void DiagnosticReport_DumpReportWithReason(const STRING_MARSHAL_TYPE reason[]);
intptr_t DiagnosticReport_GenerateReport();
uint64_t DiagnosticReport_GetSection(const STRING_MARSHAL_TYPE sectionName[]);
void DiagnosticReport_ReleaseReport(intptr_t report);
void DiagnosticReport_StartReport();
bool Internal_GetCurrentInteractionProfile(uint64_t pathId, uint64_t *interactionProfile);
bool Internal_PathToString(uint64_t pathId, intptr_t *path);
bool Internal_StringToPath(const char str[], uint64_t *pathId);
bool main_LoadOpenXRLibrary(const wchar_t loaderPath[]);
void main_UnloadOpenXRLibrary();
void messagepump_PumpMessageLoop();
bool NativeConfig_GetAllowRecentering();
bool NativeConfig_GetAPIVersion(uint16_t *major, uint16_t *minor, uint32_t *patch);
enum DepthSubmissionMode NativeConfig_GetDepthSubmissionMode();
XrEnvironmentBlendMode NativeConfig_GetEnvironmentBlendMode();
float NativeConfig_GetFloorOffsetHeight();
int32_t NativeConfig_GetFormFactor();
bool NativeConfig_GetPluginVersion(intptr_t *pluginVersionPtr);
int32_t (*NativeConfig_GetProcAddressPtr(bool loaderDefault))(struct XrInstance_T *instance, const char *name, void (**function)(void));
enum RenderMode NativeConfig_GetRenderMode();
bool NativeConfig_GetRuntimeName(intptr_t *runtimeNamePtr);
bool NativeConfig_GetRuntimeVersion(uint16_t *major, uint16_t *minor, uint32_t *patch);
uint32_t NativeConfig_GetUnityVersion(const STRING_MARSHAL_TYPE unityVersion[]);
int32_t NativeConfig_GetViewConfigurationType();
int32_t NativeConfig_GetViewTypeFromRenderIndex(int32_t renderPassIndex);
void NativeConfig_SetAllowRecentering(bool active, float height);
void NativeConfig_SetApplicationInfo(const STRING_MARSHAL_TYPE applicationName[], const STRING_MARSHAL_TYPE applicationVersion[], uint32_t applicationVersionHash, const STRING_MARSHAL_TYPE engineVersion[]);
void NativeConfig_SetCallbacks(ReceiveNativeEventDelegate callback);
void NativeConfig_SetDepthSubmissionMode(enum DepthSubmissionMode depthSubmissionMode);
void NativeConfig_SetEnvironmentBlendMode(XrEnvironmentBlendMode xrEnvironmentBlendMode);
void NativeConfig_SetProcAddressPtrAndLoadStage1(int32_t (*func)(struct XrInstance_T *instance, const char *name, void (**function)(void)));
void NativeConfig_SetRenderMode(enum RenderMode renderMode);
void NativeConfig_SetSymmetricProjection(bool enabled);
bool OpenXRInputProvider_AttachActionSets();
uint64_t OpenXRInputProvider_CreateAction(uint64_t actionSetId, const STRING_MARSHAL_TYPE name[], const STRING_MARSHAL_TYPE localizedName[], uint32_t actionType, struct SerializedGuid guid, const STRING_MARSHAL_TYPE userPaths[/*ARRAY TYPE*/], uint32_t userPathCount, bool isAdditive, const STRING_MARSHAL_TYPE usages[/*ARRAY TYPE*/], uint32_t usageCount);
uint64_t OpenXRInputProvider_CreateActionSet(const STRING_MARSHAL_TYPE name[], const STRING_MARSHAL_TYPE localizedName[], struct SerializedGuid guid);
uint64_t OpenXRInputProvider_GetActionIdByControl(uint32_t deviceId, const STRING_MARSHAL_TYPE name[]);
bool OpenXRInputProvider_GetActionIsActive(uint32_t deviceId, const STRING_MARSHAL_TYPE name[]);
bool OpenXRInputProvider_GetAppSpace(uint64_t *appSpace);
uint64_t OpenXRInputProvider_RegisterDeviceDefinition(const STRING_MARSHAL_TYPE userPath[], const STRING_MARSHAL_TYPE interactionProfile[], bool isAdditive, uint32_t characteristics, const STRING_MARSHAL_TYPE name[], const STRING_MARSHAL_TYPE manufacturer[], const STRING_MARSHAL_TYPE serialNumber[]);
// __cdecl void OpenXRInputProvider_SendHapticImpulse(uint32_t deviceId, uint64_t actionId, float amplitude, float frequency, float duration);
// __cdecl void OpenXRInputProvider_SetDpadBindingCustomValues(bool isLeft, float forceThreshold, float forceThresholdReleased, float centerRegion, float wedgeAngle, bool isSticky);
// __cdecl void OpenXRInputProvider_StopHaptics(uint32_t deviceId, uint64_t actionId);
bool OpenXRInputProvider_SuggestBindings(const STRING_MARSHAL_TYPE interactionProfile[], struct SerializedBinding serializedBindings[/*ARRAY TYPE*/], uint32_t serializedBindingCount);
bool OpenXRInputProvider_TryGetInputSourceName(uint32_t deviceId, uint64_t actionId, uint32_t index, uint32_t flags, intptr_t *outName);
bool OpenXRInputProvider_TrySetControllerLateLatchAction(uint32_t deviceId, uint64_t actionId);
void session_BeginSession();
bool session_CreateSessionIfNeeded();
void session_DestroySession();
void session_EndSession();
bool session_GetLastError(intptr_t *error);
void session_GetSessionState(int32_t *oldState, int32_t *newState);
bool session_GetSoftRestartLoopAtInitialization();
bool session_InitializeSession();
void session_RequestExitSession();
void session_SetSoftRestartLoopAtInitialization(bool value);
void session_SetSuccessfullyInitialized(bool value);
uint32_t unity_ext_GetAvailableExtensionCount();
bool unity_ext_GetAvailableExtensionName(uint32_t index, intptr_t *extensionName);
uint32_t unity_ext_GetEnabledExtensionCount();
bool unity_ext_GetEnabledExtensionName(uint32_t index, intptr_t *outName);
uint32_t unity_ext_GetExtensionVersion(const STRING_MARSHAL_TYPE extensionName[]);
bool unity_ext_IsExtensionEnabled(const STRING_MARSHAL_TYPE extensionName[]);
bool unity_ext_RequestEnableExtensionString(const STRING_MARSHAL_TYPE extensionString[]);

#ifdef __cplusplus
}}
#endif
