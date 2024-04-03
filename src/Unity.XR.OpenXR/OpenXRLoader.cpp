#include "OpenXRLoader.hpp"
#include "OpenXRRestarter.hpp"
#include "UnityOpenXR.hpp"
#include "../log.hpp"
#include <scotland2/shared/modloader.h>
#include <beatsaber-hook/shared/utils/hooking.hpp>

#include <System/Array.hpp>
#include <System/BitConverter.hpp>
#include <System/Security/Cryptography/MD5.hpp>
#include <System/Text/Encoding.hpp>
#include <Unity/XR/Oculus/RegisterUpdateCallback.hpp>
#include <UnityEngine/XR/XR.hpp>
#include <UnityEngine/Application.hpp>
#include <UnityEngine/Events/UnityAction.hpp>
#include <UnityEngine/Time.hpp>
#include "codegen_broken_types.hpp"

using namespace std::literals::string_view_literals;

enum class LoaderState {
	Uninitialized = 0,
	InitializeAttempted,
	Initialized,
	StartAttempted,
	Started,
	StopAttempted,
	Stopped,
	DeinitializeAttempted,
} static currentLoaderState = {};

static UnityOpenXR::NativeEvent currentOpenXRState = {};

static bool isWaydroid() {
	JNIEnv *env = nullptr;
	assert(modloader_jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) == JNI_OK);
	const jclass android_os_Build = env->FindClass("android/os/Build");
	const jstring manufacturer_obj  = static_cast<jstring>(env->GetStaticObjectField(android_os_Build,
		env->GetStaticFieldID(android_os_Build, "MANUFACTURER", "Ljava/lang/String;")));
	const char *const value = env->GetStringUTFChars(manufacturer_obj, nullptr);
	const bool result = (strcmp(value, "Waydroid") == 0);
	env->ReleaseStringUTFChars(manufacturer_obj, value);
	return result;
}

static bool StartInternal(Unity::XR::Oculus::OculusLoader *const self) {
	if(!UnityOpenXR::session_CreateSessionIfNeeded())
		return false;
	if(currentOpenXRState != UnityOpenXR::NativeEvent_XrReady ||
			(currentLoaderState != LoaderState::StartAttempted && currentLoaderState != LoaderState::Started))
		return true;
	if(UnityEngine::IntegratedSubsystem *const displaySubsystem = static_cast<UnityEngine::XR::XRDisplaySubsystem*>(self->get_displaySubsystem())) // TODO: remove cast once XRDisplaySubsystem is defined properly in codegen
		displaySubsystem->Start();
	UnityOpenXR::session_BeginSession();
	// TODO: OpenXRInput.AttachActionSets()
	if(UnityEngine::IntegratedSubsystem *const inputSubsystem = self->get_inputSubsystem())
		inputSubsystem->Start();
	// OpenXRFeature.ReceiveLoaderEvent(this, OpenXRFeature.LoaderEvent.SubsystemStart);
	return true;
}

static void StopInternal() {
	UnityOpenXR::session_EndSession();
	XRPolyfill::OpenXRLoader::ProcessOpenXRMessageLoop();
}

static Unity::XR::Oculus::OculusLoader *OpenXRLoader_Instance = nullptr;
static void ReceiveNativeEvent(UnityOpenXR::NativeEvent event, uint64_t /*payload*/) {
	// logger.info("ReceiveNativeEvent(%u, %lx)", event, payload);
	currentOpenXRState = event;
	switch(+event) {
		case UnityOpenXR::NativeEvent_XrRestartRequested: OpenXRRestarter::ShutdownAndRestart(); break;
		case UnityOpenXR::NativeEvent_XrReady: StartInternal(OpenXRLoader_Instance); break;
		case UnityOpenXR::NativeEvent_XrFocused: logger.info("System Startup Completed"); break;
		case UnityOpenXR::NativeEvent_XrRequestRestartLoop: {
			logger.debug("XR Initialization failed, will try to restart xr periodically.");
			OpenXRRestarter::PauseAndShutdownAndRestart();
		} break;
		case UnityOpenXR::NativeEvent_XrRequestGetSystemLoop: OpenXRRestarter::PauseAndRetryInitialization(); break;
		case UnityOpenXR::NativeEvent_XrStopping: StopInternal(); break;
		default:;
	}
	// TODO: OpenXRFeature::ReceiveNativeEvent(event, payload);
	if(currentLoaderState != LoaderState::Initialized && currentLoaderState != LoaderState::StartAttempted &&
			currentLoaderState != LoaderState::Started && event != UnityOpenXR::NativeEvent_XrInstanceChanged)
		return;
	switch(+event) {
		case UnityOpenXR::NativeEvent_XrExiting: OpenXRRestarter::Shutdown(); break;
		case UnityOpenXR::NativeEvent_XrLossPending: OpenXRRestarter::ShutdownAndRestart(); break;
		case UnityOpenXR::NativeEvent_XrInstanceLossPending: OpenXRRestarter::Shutdown(); break;
		default:;
	}
}

void XRPolyfill::OpenXRLoader::ProcessOpenXRMessageLoop() {
	if(currentOpenXRState == UnityOpenXR::NativeEvent_XrIdle ||
			(currentOpenXRState >= UnityOpenXR::NativeEvent_XrStopping && currentOpenXRState <= UnityOpenXR::NativeEvent_XrInstanceLossPending)) {
		static double lastPollCheckTime = 0;
		const double time = static_cast<double>(UnityEngine::Time::get_realtimeSinceStartup());
		if((time - lastPollCheckTime) < .1)
			return;
		lastPollCheckTime = time;
	}
	UnityOpenXR::messagepump_PumpMessageLoop();
}

static bool InitializeInternal(Unity::XR::Oculus::OculusLoader *const self) {
	currentLoaderState = LoaderState::InitializeAttempted;
	// TODO: OpenXRInput.RegisterLayouts()
	UnityOpenXR::session_SetSuccessfullyInitialized(false);
	{ // LoadOpenXRSymbols()
		if(!UnityOpenXR::main_LoadOpenXRLibrary(L"openxr_loader")) {
			logger.error("OpenXRLoader - Failed to load openxr runtime loader.");
			return false;
		}
	}
	{ // OpenXRFeature.HookGetInstanceProcAddr()
		const auto getProc = UnityOpenXR::NativeConfig_GetProcAddressPtr(true);
		UnityOpenXR::NativeConfig_SetProcAddressPtrAndLoadStage1(getProc);
	}
	if(!UnityOpenXR::session_InitializeSession())
		return false;
	{ // SetApplicationInfo()
		SafePtr<Array<uint8_t>> data = static_cast<Array<uint8_t>*>(
			SafePtr<System::Security::Cryptography::MD5>(System::Security::Cryptography::MD5::Create())
				->ComputeHash(System::Text::Encoding::get_UTF8()->GetBytes(UnityEngine::Application::get_version())));
		// System::Array::Reverse(static_cast<ArrayW<uint8_t>>(data.ptr())); // TODO: CRASHES
		UnityOpenXR::NativeConfig_SetApplicationInfo(std::string(UnityEngine::Application::get_productName()).c_str(),
			std::string(UnityEngine::Application::get_version()).c_str(), System::BitConverter::ToUInt32(data.ptr(), 0),
			std::string(UnityEngine::Application::get_unityVersion()).c_str());
	}
	// TODO: RequestOpenXRFeatures()
	OpenXRLoader_Instance = self;
	UnityOpenXR::NativeConfig_SetCallbacks(ReceiveNativeEvent);
	{ // OpenXRSettings.ApplySettings() -> OpenXRSettings.ApplyRenderSettings()
		UnityOpenXR::NativeConfig_SetSymmetricProjection(false);
		UnityOpenXR::NativeConfig_SetRenderMode(isWaydroid() ? UnityOpenXR::RenderMode_MultiPass : UnityOpenXR::RenderMode_SinglePassInstanced); // TODO: investigate more
		UnityOpenXR::NativeConfig_SetDepthSubmissionMode(UnityOpenXR::DepthSubmissionMode_None);
	}
	{ // CreateSubsystems()
		if(self->get_displaySubsystem() == nullptr) {
			XRLoaderHelper_CreateSubsystem<UnityEngine::XR::XRDisplaySubsystemDescriptor*, UnityEngine::XR::XRDisplaySubsystem*>(
				self, Unity::XR::Oculus::OculusLoader::getStaticF_s_DisplaySubsystemDescriptors(), "OpenXR Display"sv);
			if(self->get_displaySubsystem() == nullptr)
				return false;
		}
		if(self->get_inputSubsystem() == nullptr) {
			XRLoaderHelper_CreateSubsystem<UnityEngine::XR::XRInputSubsystemDescriptor*, UnityEngine::XR::XRInputSubsystem*>(
				self, reinterpret_cast<System::Collections::Generic::List_1<UnityEngine::XR::XRInputSubsystemDescriptor*>*>(
					Unity::XR::Oculus::OculusLoader::getStaticF_s_InputSubsystemDescriptors()), // TODO: remove cast once XRInputSubsystemDescriptor is defined properly in codegen
				"OpenXR Input"sv);
			if(self->get_inputSubsystem() == nullptr)
				return false;
		}
	}
	logger.info("register loop");
	// OpenXRFeature.ReceiveLoaderEvent(this, OpenXRFeature.LoaderEvent.SubsystemCreate);
	Unity::XR::Oculus::RegisterUpdateCallback::Initialize(); // Application.onBeforeRender += ProcessOpenXRMessageLoop
	currentLoaderState = LoaderState::Initialized;
	return true;
}

bool XRPolyfill::OpenXRLoader::Initialize(Unity::XR::Oculus::OculusLoader *const self) {
	if(currentLoaderState >= LoaderState::Initialized)
		return currentLoaderState == LoaderState::Initialized;
	const bool initialized = InitializeInternal(self);
	if(!initialized)
		XRPolyfill::OpenXRLoader::Deinitialize(self);
	return initialized;
}

bool XRPolyfill::OpenXRLoader::Start(Unity::XR::Oculus::OculusLoader *const self) {
	if(currentLoaderState == LoaderState::Started)
		return true;
	if(currentLoaderState != LoaderState::Initialized && currentLoaderState != LoaderState::StartAttempted && currentLoaderState != LoaderState::Stopped)
		return false;
	currentLoaderState = LoaderState::StartAttempted;
	const bool started = StartInternal(self);
	if(started)
		currentLoaderState = LoaderState::Started;
	else
		XRPolyfill::OpenXRLoader::Stop(self);
	return started;
}

bool XRPolyfill::OpenXRLoader::Stop(Unity::XR::Oculus::OculusLoader *const self) {
	if(currentLoaderState == LoaderState::Stopped)
		return true;
	if(currentLoaderState != LoaderState::StartAttempted && currentLoaderState != LoaderState::Started && currentLoaderState != LoaderState::StopAttempted)
		return false;
	currentLoaderState = LoaderState::StopAttempted;
	UnityEngine::IntegratedSubsystem *const inputSubsystem = self->get_inputSubsystem(),
		*const displaySubsystem = static_cast<UnityEngine::XR::XRDisplaySubsystem*>(self->get_displaySubsystem()); // TODO: remove cast once XRDisplaySubsystem is defined properly in codegen
	const bool inputRunning = inputSubsystem != nullptr && inputSubsystem->get_running();
	const bool displayRunning = displaySubsystem != nullptr && displaySubsystem->get_running();
	/*if(inputRunning || displayRunning)
		OpenXRFeature.ReceiveLoaderEvent(this, OpenXRFeature.LoaderEvent.SubsystemStop);*/
	if(inputRunning)
		inputSubsystem->Stop();
	if(displayRunning)
		displaySubsystem->Stop();
	StopInternal();
	currentLoaderState = LoaderState::Stopped;
	return true;
}

bool XRPolyfill::OpenXRLoader::Deinitialize(Unity::XR::Oculus::OculusLoader *const self) {
	if(currentLoaderState <= LoaderState::Initialized)
		return currentLoaderState == LoaderState::Uninitialized;
	if(currentLoaderState != LoaderState::Stopped && currentLoaderState != LoaderState::DeinitializeAttempted)
		return false;
	currentLoaderState = LoaderState::DeinitializeAttempted;
	UnityOpenXR::session_RequestExitSession();
	Unity::XR::Oculus::RegisterUpdateCallback::Deinitialize(); // Application.onBeforeRender += ProcessOpenXRMessageLoop
	ProcessOpenXRMessageLoop();
	// OpenXRFeature.ReceiveLoaderEvent(this, OpenXRFeature.LoaderEvent.SubsystemDestroy);
	self->DestroySubsystem<UnityEngine::XR::XRInputSubsystem*>();
	self->DestroySubsystem<UnityEngine::XR::XRDisplaySubsystem*>();
	UnityOpenXR::session_DestroySession();
	ProcessOpenXRMessageLoop();
	UnityOpenXR::main_UnloadOpenXRLibrary();
	currentLoaderState = LoaderState::Uninitialized;
	// actionSetsAttached = false;
	// TODO: return base.Deinitialize();
	return true;
}
