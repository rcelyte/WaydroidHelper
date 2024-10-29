#pragma once
#include <Unity/XR/Oculus/OculusLoader.hpp>
#include <GlobalNamespace/UnityXRController.hpp>

namespace XRPolyfill {
	extern GlobalNamespace::UnityXRHelper *unityXRHelper;
	void UpdateUserPresence();
}

namespace XRPolyfill::OpenXRLoader {
	void ProcessOpenXRMessageLoop();
	bool Initialize(Unity::XR::Oculus::OculusLoader *const self);
	bool Start(Unity::XR::Oculus::OculusLoader *const self);
	bool Stop(Unity::XR::Oculus::OculusLoader *const self);
	bool Deinitialize(Unity::XR::Oculus::OculusLoader *const self);
}

namespace XRPolyfill::OpenXRInput {
	void AttachActionSets();
}

namespace XRPolyfill::OpenXRRestarter {
	void ShutdownAndRestart();
	void PauseAndShutdownAndRestart();
	void PauseAndRetryInitialization();
	void Shutdown();
}

namespace XRPolyfill::OpenXRInteractionFeature {
	extern const std::string_view Haptic_json;
	extern const std::string_view OpenXRDevice_json;
	extern const std::string_view PalmPose_json;
	extern const std::string_view OculusTouchController_json;
	extern const std::string_view WMRSpatialController_json;
	extern const std::string_view HoloLensHand_json;
	extern const std::string_view QuestProTouchController_json;
	extern const std::string_view KHRSimpleController_json;
	extern const std::string_view ViveController_json;
	extern const std::string_view ReverbG2Controller_json;
	extern const std::string_view HandInteraction_json;
	extern const std::string_view DPad_json;
	extern const std::string_view ValveIndexController_json;
}
