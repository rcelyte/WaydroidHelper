#include "XRPolyfill.hpp"
#include "UnityOpenXR.hpp"
#include "../log.hpp"
using namespace UnityOpenXR;

void XRPolyfill::OpenXRInput::AttachActionSets() {
	const auto common = InputDeviceCharacteristics_HeldInHand | InputDeviceCharacteristics_TrackedDevice | InputDeviceCharacteristics_Controller;
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/left", "/interaction_profiles/htc/vive_controller", false,
			common | InputDeviceCharacteristics_Left, "HTC Vive Controller OpenXR", "HTC", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/htc/vive_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/right", "/interaction_profiles/htc/vive_controller", false,
			common | InputDeviceCharacteristics_Right, "HTC Vive Controller OpenXR", "HTC", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/htc/vive_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/left", "/interaction_profiles/khr/simple_controller", false,
			common | InputDeviceCharacteristics_Left, "KHR Simple Controller OpenXR", "Khronos", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/khr/simple_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/right", "/interaction_profiles/khr/simple_controller", false,
			common | InputDeviceCharacteristics_Right, "KHR Simple Controller OpenXR", "Khronos", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/khr/simple_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/left", "/interaction_profiles/microsoft/motion_controller", false,
			common | InputDeviceCharacteristics_Left, "Windows MR Controller OpenXR", "Microsoft", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/microsoft/motion_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/right", "/interaction_profiles/microsoft/motion_controller", false,
			common | InputDeviceCharacteristics_Right, "Windows MR Controller OpenXR", "Microsoft", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/microsoft/motion_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/left", "/interaction_profiles/oculus/touch_controller", false,
			common | InputDeviceCharacteristics_Left, "Oculus Touch Controller OpenXR", "Oculus", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/oculus/touch_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/right", "/interaction_profiles/oculus/touch_controller", false,
			common | InputDeviceCharacteristics_Right, "Oculus Touch Controller OpenXR", "Oculus", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/oculus/touch_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/left", "/interaction_profiles/valve/index_controller", false,
			common | InputDeviceCharacteristics_Left, "Index Controller OpenXR", "Valve", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/valve/index_controller) failed");
		return;
	}
	if(OpenXRInputProvider_RegisterDeviceDefinition("/user/hand/right", "/interaction_profiles/valve/index_controller", false,
			common | InputDeviceCharacteristics_Right, "Index Controller OpenXR", "Valve", "") == 0) {
		logger.error("OpenXRInputProvider_RegisterDeviceDefinition(/interaction_profiles/valve/index_controller) failed");
		return;
	}
	if(const uint64_t set_htcvivecontroller = OpenXRInputProvider_CreateActionSet("htcvivecontroller", "htcvivecontrolleropenxr", {})) {
		const uint64_t action_grip = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "grip", "Grip", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Grip"}.data(), 1);
		const uint64_t action_grippressed = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "grippressed", "Grip Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"GripButton"}.data(), 1);
		const uint64_t action_menu = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "menu", "Menu", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"MenuButton"}.data(), 1);
		const uint64_t action_select = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "select", "Select", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"SystemButton"}.data(), 1);
		const uint64_t action_trigger = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "trigger", "Trigger", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Trigger"}.data(), 1);
		const uint64_t action_triggerpressed = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "triggerpressed", "Trigger Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"TriggerButton"}.data(), 1);
		const uint64_t action_trackpad = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "trackpad", "Trackpad", 2, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxis"}.data(), 1);
		const uint64_t action_trackpadtouched = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "trackpadtouched", "Trackpad Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxisTouch"}.data(), 1);
		const uint64_t action_trackpadclicked = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "trackpadclicked", "Trackpad Clicked", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxisClick"}.data(), 1);
		const uint64_t action_devicepose = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "devicepose", "Device Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Device"}.data(), 1);
		const uint64_t action_pointer = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "pointer", "Pointer Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Pointer"}.data(), 1);
		const uint64_t action_haptic = OpenXRInputProvider_CreateAction(set_htcvivecontroller, "haptic", "Haptic Output", 4, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Haptic"}.data(), 1);
		if(!OpenXRInputProvider_SuggestBindings("/interaction_profiles/htc/vive_controller", std::array{
			SerializedBinding{action_grip, "/user/hand/left/input/squeeze/click"},
			SerializedBinding{action_grip, "/user/hand/right/input/squeeze/click"},
			SerializedBinding{action_grippressed, "/user/hand/left/input/squeeze/click"},
			SerializedBinding{action_grippressed, "/user/hand/right/input/squeeze/click"},
			SerializedBinding{action_menu, "/user/hand/left/input/menu/click"},
			SerializedBinding{action_menu, "/user/hand/right/input/menu/click"},
			SerializedBinding{action_select, "/user/hand/left/input/system/click"},
			SerializedBinding{action_select, "/user/hand/right/input/system/click"},
			SerializedBinding{action_trigger, "/user/hand/left/input/trigger/value"},
			SerializedBinding{action_trigger, "/user/hand/right/input/trigger/value"},
			SerializedBinding{action_triggerpressed, "/user/hand/left/input/trigger/click"},
			SerializedBinding{action_triggerpressed, "/user/hand/right/input/trigger/click"},
			SerializedBinding{action_trackpad, "/user/hand/left/input/trackpad"},
			SerializedBinding{action_trackpad, "/user/hand/right/input/trackpad"},
			SerializedBinding{action_trackpadtouched, "/user/hand/left/input/trackpad/touch"},
			SerializedBinding{action_trackpadtouched, "/user/hand/right/input/trackpad/touch"},
			SerializedBinding{action_trackpadclicked, "/user/hand/left/input/trackpad/click"},
			SerializedBinding{action_trackpadclicked, "/user/hand/right/input/trackpad/click"},
			SerializedBinding{action_devicepose, "/user/hand/left/input/grip/pose"},
			SerializedBinding{action_devicepose, "/user/hand/right/input/grip/pose"},
			SerializedBinding{action_pointer, "/user/hand/left/input/aim/pose"},
			SerializedBinding{action_pointer, "/user/hand/right/input/aim/pose"},
			SerializedBinding{action_haptic, "/user/hand/left/output/haptic"},
			SerializedBinding{action_haptic, "/user/hand/right/output/haptic"},
		}.data(), 24)) {
			logger.error("OpenXRInputProvider_SuggestBindings(/interaction_profiles/htc/vive_controller) failed");
			return;
		}
	}
	if(const uint64_t set_khrsimplecontroller = OpenXRInputProvider_CreateActionSet("khrsimplecontroller", "khrsimplecontrolleropenxr", {})) {
		const uint64_t action_select = OpenXRInputProvider_CreateAction(set_khrsimplecontroller, "select", "Select", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"PrimaryButton"}.data(), 1);
		const uint64_t action_menu = OpenXRInputProvider_CreateAction(set_khrsimplecontroller, "menu", "Menu", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"MenuButton"}.data(), 1);
		const uint64_t action_devicepose = OpenXRInputProvider_CreateAction(set_khrsimplecontroller, "devicepose", "Device Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Device"}.data(), 1);
		const uint64_t action_pointer = OpenXRInputProvider_CreateAction(set_khrsimplecontroller, "pointer", "Pointer Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Pointer"}.data(), 1);
		const uint64_t action_haptic = OpenXRInputProvider_CreateAction(set_khrsimplecontroller, "haptic", "Haptic Output", 4, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Haptic"}.data(), 1);
		if(!OpenXRInputProvider_SuggestBindings("/interaction_profiles/khr/simple_controller", std::array{
			SerializedBinding{action_select, "/user/hand/left/input/select/click"},
			SerializedBinding{action_select, "/user/hand/right/input/select/click"},
			SerializedBinding{action_menu, "/user/hand/left/input/menu/click"},
			SerializedBinding{action_menu, "/user/hand/right/input/menu/click"},
			SerializedBinding{action_devicepose, "/user/hand/left/input/grip/pose"},
			SerializedBinding{action_devicepose, "/user/hand/right/input/grip/pose"},
			SerializedBinding{action_pointer, "/user/hand/left/input/aim/pose"},
			SerializedBinding{action_pointer, "/user/hand/right/input/aim/pose"},
			SerializedBinding{action_haptic, "/user/hand/left/output/haptic"},
			SerializedBinding{action_haptic, "/user/hand/right/output/haptic"},
		}.data(), 10)) {
			logger.error("OpenXRInputProvider_SuggestBindings(/interaction_profiles/khr/simple_controller) failed");
			return;
		}
	}
	if(const uint64_t set_microsoftmotioncontroller = OpenXRInputProvider_CreateActionSet("microsoftmotioncontroller", "windowsmrcontrolleropenxr", {})) {
		const uint64_t action_joystick = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "joystick", "Joystick", 2, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxis"}.data(), 1);
		const uint64_t action_touchpad = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "touchpad", "Touchpad", 2, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Secondary2DAxis"}.data(), 1);
		const uint64_t action_grip = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "grip", "Grip", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Grip"}.data(), 1);
		const uint64_t action_grippressed = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "grippressed", "Grip Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"GripButton"}.data(), 1);
		const uint64_t action_menu = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "menu", "Menu", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"MenuButton"}.data(), 1);
		const uint64_t action_trigger = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "trigger", "Trigger", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Trigger"}.data(), 1);
		const uint64_t action_triggerpressed = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "triggerpressed", "Trigger Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"TriggerButton"}.data(), 1);
		const uint64_t action_joystickclicked = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "joystickclicked", "JoystickClicked", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxisClick"}.data(), 1);
		const uint64_t action_touchpadclicked = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "touchpadclicked", "Touchpad Clicked", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Secondary2DAxisClick"}.data(), 1);
		const uint64_t action_touchpadtouched = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "touchpadtouched", "Touchpad Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Secondary2DAxisTouch"}.data(), 1);
		const uint64_t action_devicepose = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "devicepose", "Device Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Device"}.data(), 1);
		const uint64_t action_pointer = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "pointer", "Pointer Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Pointer"}.data(), 1);
		const uint64_t action_haptic = OpenXRInputProvider_CreateAction(set_microsoftmotioncontroller, "haptic", "Haptic Output", 4, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Haptic"}.data(), 1);
		if(!OpenXRInputProvider_SuggestBindings("/interaction_profiles/microsoft/motion_controller", std::array{
			SerializedBinding{action_joystick, "/user/hand/left/input/thumbstick"},
			SerializedBinding{action_joystick, "/user/hand/right/input/thumbstick"},
			SerializedBinding{action_touchpad, "/user/hand/left/input/trackpad"},
			SerializedBinding{action_touchpad, "/user/hand/right/input/trackpad"},
			SerializedBinding{action_grip, "/user/hand/left/input/squeeze/click"},
			SerializedBinding{action_grip, "/user/hand/right/input/squeeze/click"},
			SerializedBinding{action_grippressed, "/user/hand/left/input/squeeze/click"},
			SerializedBinding{action_grippressed, "/user/hand/right/input/squeeze/click"},
			SerializedBinding{action_menu, "/user/hand/left/input/menu/click"},
			SerializedBinding{action_menu, "/user/hand/right/input/menu/click"},
			SerializedBinding{action_trigger, "/user/hand/left/input/trigger/value"},
			SerializedBinding{action_trigger, "/user/hand/right/input/trigger/value"},
			SerializedBinding{action_triggerpressed, "/user/hand/left/input/trigger/value"},
			SerializedBinding{action_triggerpressed, "/user/hand/right/input/trigger/value"},
			SerializedBinding{action_joystickclicked, "/user/hand/left/input/thumbstick/click"},
			SerializedBinding{action_joystickclicked, "/user/hand/right/input/thumbstick/click"},
			SerializedBinding{action_touchpadclicked, "/user/hand/left/input/trackpad/click"},
			SerializedBinding{action_touchpadclicked, "/user/hand/right/input/trackpad/click"},
			SerializedBinding{action_touchpadtouched, "/user/hand/left/input/trackpad/touch"},
			SerializedBinding{action_touchpadtouched, "/user/hand/right/input/trackpad/touch"},
			SerializedBinding{action_devicepose, "/user/hand/left/input/grip/pose"},
			SerializedBinding{action_devicepose, "/user/hand/right/input/grip/pose"},
			SerializedBinding{action_pointer, "/user/hand/left/input/aim/pose"},
			SerializedBinding{action_pointer, "/user/hand/right/input/aim/pose"},
			SerializedBinding{action_haptic, "/user/hand/left/output/haptic"},
			SerializedBinding{action_haptic, "/user/hand/right/output/haptic"},
		}.data(), 26)) {
			logger.error("OpenXRInputProvider_SuggestBindings(/interaction_profiles/microsoft/motion_controller) failed");
			return;
		}
	}
	if(const uint64_t set_oculustouchcontroller = OpenXRInputProvider_CreateActionSet("oculustouchcontroller", "oculustouchcontrolleropenxr", {})) {
		const uint64_t action_thumbstick = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "thumbstick", "Thumbstick", 2, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxis"}.data(), 1);
		const uint64_t action_grip = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "grip", "Grip", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Grip"}.data(), 1);
		const uint64_t action_grippressed = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "grippressed", "Grip Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"GripButton"}.data(), 1);
		const uint64_t action_menu = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "menu", "Menu", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"MenuButton"}.data(), 1);
		const uint64_t action_primarybutton = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "primarybutton", "Primary Button", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"PrimaryButton"}.data(), 1);
		const uint64_t action_primarytouched = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "primarytouched", "Primary Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"PrimaryTouch"}.data(), 1);
		const uint64_t action_secondarybutton = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "secondarybutton", "Secondary Button", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"SecondaryButton"}.data(), 1);
		const uint64_t action_secondarytouched = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "secondarytouched", "Secondary Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"SecondaryTouch"}.data(), 1);
		const uint64_t action_trigger = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "trigger", "Trigger", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Trigger"}.data(), 1);
		const uint64_t action_triggerpressed = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "triggerpressed", "Trigger Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"TriggerButton"}.data(), 1);
		const uint64_t action_triggertouched = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "triggertouched", "Trigger Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"TriggerTouch"}.data(), 1);
		const uint64_t action_thumbstickclicked = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "thumbstickclicked", "Thumbstick Clicked", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxisClick"}.data(), 1);
		const uint64_t action_thumbsticktouched = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "thumbsticktouched", "Thumbstick Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxisTouch"}.data(), 1);
		const uint64_t action_thumbresttouched = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "thumbresttouched", "Thumbrest Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"ThumbrestTouch"}.data(), 1);
		const uint64_t action_devicepose = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "devicepose", "Device Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Device"}.data(), 1);
		const uint64_t action_pointer = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "pointer", "Pointer Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Pointer"}.data(), 1);
		const uint64_t action_haptic = OpenXRInputProvider_CreateAction(set_oculustouchcontroller, "haptic", "Haptic Output", 4, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Haptic"}.data(), 1);
		if(!OpenXRInputProvider_SuggestBindings("/interaction_profiles/oculus/touch_controller", std::array{
			SerializedBinding{action_thumbstick, "/user/hand/left/input/thumbstick"},
			SerializedBinding{action_thumbstick, "/user/hand/right/input/thumbstick"},
			SerializedBinding{action_grip, "/user/hand/left/input/squeeze/value"},
			SerializedBinding{action_grip, "/user/hand/right/input/squeeze/value"},
			SerializedBinding{action_grippressed, "/user/hand/left/input/squeeze/value"},
			SerializedBinding{action_grippressed, "/user/hand/right/input/squeeze/value"},
			SerializedBinding{action_menu, "/user/hand/left/input/menu/click"},
			SerializedBinding{action_menu, "/user/hand/right/input/system/click"},
			SerializedBinding{action_primarybutton, "/user/hand/left/input/x/click"},
			SerializedBinding{action_primarybutton, "/user/hand/right/input/a/click"},
			SerializedBinding{action_primarytouched, "/user/hand/left/input/x/touch"},
			SerializedBinding{action_primarytouched, "/user/hand/right/input/a/touch"},
			SerializedBinding{action_secondarybutton, "/user/hand/left/input/y/click"},
			SerializedBinding{action_secondarybutton, "/user/hand/right/input/b/click"},
			SerializedBinding{action_secondarytouched, "/user/hand/left/input/y/touch"},
			SerializedBinding{action_secondarytouched, "/user/hand/right/input/b/touch"},
			SerializedBinding{action_trigger, "/user/hand/left/input/trigger/value"},
			SerializedBinding{action_trigger, "/user/hand/right/input/trigger/value"},
			SerializedBinding{action_triggerpressed, "/user/hand/left/input/trigger/value"},
			SerializedBinding{action_triggerpressed, "/user/hand/right/input/trigger/value"},
			SerializedBinding{action_triggertouched, "/user/hand/left/input/trigger/touch"},
			SerializedBinding{action_triggertouched, "/user/hand/right/input/trigger/touch"},
			SerializedBinding{action_thumbstickclicked, "/user/hand/left/input/thumbstick/click"},
			SerializedBinding{action_thumbstickclicked, "/user/hand/right/input/thumbstick/click"},
			SerializedBinding{action_thumbsticktouched, "/user/hand/left/input/thumbstick/touch"},
			SerializedBinding{action_thumbsticktouched, "/user/hand/right/input/thumbstick/touch"},
			SerializedBinding{action_thumbresttouched, "/user/hand/left/input/thumbrest/touch"},
			SerializedBinding{action_thumbresttouched, "/user/hand/right/input/thumbrest/touch"},
			SerializedBinding{action_devicepose, "/user/hand/left/input/grip/pose"},
			SerializedBinding{action_devicepose, "/user/hand/right/input/grip/pose"},
			SerializedBinding{action_pointer, "/user/hand/left/input/aim/pose"},
			SerializedBinding{action_pointer, "/user/hand/right/input/aim/pose"},
			SerializedBinding{action_haptic, "/user/hand/left/output/haptic"},
			SerializedBinding{action_haptic, "/user/hand/right/output/haptic"},
		}.data(), 34)) {
			logger.error("OpenXRInputProvider_SuggestBindings(/interaction_profiles/oculus/touch_controller) failed");
			return;
		}
	}
	if(const uint64_t set_valveindexcontroller = OpenXRInputProvider_CreateActionSet("valveindexcontroller", "indexcontrolleropenxr", {})) {
		const uint64_t action_system = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "system", "System", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"MenuButton"}.data(), 1);
		const uint64_t action_systemtouched = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "systemtouched", "System Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"MenuTouch"}.data(), 1);
		const uint64_t action_primarybutton = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "primarybutton", "Primary Button", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"PrimaryButton"}.data(), 1);
		const uint64_t action_primarytouched = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "primarytouched", "Primary Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"PrimaryTouch"}.data(), 1);
		const uint64_t action_secondarybutton = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "secondarybutton", "Secondary Button", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"SecondaryButton"}.data(), 1);
		const uint64_t action_secondarytouched = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "secondarytouched", "Secondary Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"SecondaryTouch"}.data(), 1);
		const uint64_t action_grip = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "grip", "Grip", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Grip"}.data(), 1);
		const uint64_t action_grippressed = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "grippressed", "Grip Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"GripButton"}.data(), 1);
		const uint64_t action_gripforce = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "gripforce", "Grip Force", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"GripForce"}.data(), 1);
		const uint64_t action_trigger = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "trigger", "Trigger", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Trigger"}.data(), 1);
		const uint64_t action_triggerpressed = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "triggerpressed", "Triggger Pressed", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"TriggerButton"}.data(), 1);
		const uint64_t action_triggertouched = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "triggertouched", "Trigger Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"TriggerTouch"}.data(), 1);
		const uint64_t action_thumbstick = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "thumbstick", "Thumbstick", 2, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxis"}.data(), 1);
		const uint64_t action_thumbstickclicked = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "thumbstickclicked", "Thumbstick Clicked", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxisClick"}.data(), 1);
		const uint64_t action_thumbsticktouched = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "thumbsticktouched", "Thumbstick Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Primary2DAxisTouch"}.data(), 1);
		const uint64_t action_trackpad = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "trackpad", "Trackpad", 2, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Secondary2DAxis"}.data(), 1);
		const uint64_t action_trackpadforce = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "trackpadforce", "Trackpad Force", 1, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Secondary2DAxisForce"}.data(), 1);
		const uint64_t action_trackpadtouched = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "trackpadtouched", "Trackpad Touched", 0, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Secondary2DAxisTouch"}.data(), 1);
		const uint64_t action_devicepose = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "devicepose", "Device Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Device"}.data(), 1);
		const uint64_t action_pointer = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "pointer", "Pointer Pose", 3, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Pointer"}.data(), 1);
		const uint64_t action_haptic = OpenXRInputProvider_CreateAction(set_valveindexcontroller, "haptic", "Haptic Output", 4, {}, std::array{"/user/hand/left", "/user/hand/right"}.data(), 2, false, std::array{"Haptic"}.data(), 1);
		if(!OpenXRInputProvider_SuggestBindings("/interaction_profiles/valve/index_controller", std::array{
			SerializedBinding{action_system, "/user/hand/left/input/system/click"},
			SerializedBinding{action_system, "/user/hand/right/input/system/click"},
			SerializedBinding{action_systemtouched, "/user/hand/left/input/system/touch"},
			SerializedBinding{action_systemtouched, "/user/hand/right/input/system/touch"},
			SerializedBinding{action_primarybutton, "/user/hand/left/input/a/click"},
			SerializedBinding{action_primarybutton, "/user/hand/right/input/a/click"},
			SerializedBinding{action_primarytouched, "/user/hand/left/input/a/touch"},
			SerializedBinding{action_primarytouched, "/user/hand/right/input/a/touch"},
			SerializedBinding{action_secondarybutton, "/user/hand/left/input/b/click"},
			SerializedBinding{action_secondarybutton, "/user/hand/right/input/b/click"},
			SerializedBinding{action_secondarytouched, "/user/hand/left/input/b/touch"},
			SerializedBinding{action_secondarytouched, "/user/hand/right/input/b/touch"},
			SerializedBinding{action_grip, "/user/hand/left/input/squeeze/value"},
			SerializedBinding{action_grip, "/user/hand/right/input/squeeze/value"},
			SerializedBinding{action_grippressed, "/user/hand/left/input/squeeze/value"},
			SerializedBinding{action_grippressed, "/user/hand/right/input/squeeze/value"},
			SerializedBinding{action_gripforce, "/user/hand/left/input/squeeze/force"},
			SerializedBinding{action_gripforce, "/user/hand/right/input/squeeze/force"},
			SerializedBinding{action_trigger, "/user/hand/left/input/trigger/value"},
			SerializedBinding{action_trigger, "/user/hand/right/input/trigger/value"},
			SerializedBinding{action_triggerpressed, "/user/hand/left/input/trigger/click"},
			SerializedBinding{action_triggerpressed, "/user/hand/right/input/trigger/click"},
			SerializedBinding{action_triggertouched, "/user/hand/left/input/trigger/touch"},
			SerializedBinding{action_triggertouched, "/user/hand/right/input/trigger/touch"},
			SerializedBinding{action_thumbstick, "/user/hand/left/input/thumbstick"},
			SerializedBinding{action_thumbstick, "/user/hand/right/input/thumbstick"},
			SerializedBinding{action_thumbstickclicked, "/user/hand/left/input/thumbstick/click"},
			SerializedBinding{action_thumbstickclicked, "/user/hand/right/input/thumbstick/click"},
			SerializedBinding{action_thumbsticktouched, "/user/hand/left/input/thumbstick/touch"},
			SerializedBinding{action_thumbsticktouched, "/user/hand/right/input/thumbstick/touch"},
			SerializedBinding{action_trackpad, "/user/hand/left/input/trackpad"},
			SerializedBinding{action_trackpad, "/user/hand/right/input/trackpad"},
			SerializedBinding{action_trackpadforce, "/user/hand/left/input/trackpad/force"},
			SerializedBinding{action_trackpadforce, "/user/hand/right/input/trackpad/force"},
			SerializedBinding{action_trackpadtouched, "/user/hand/left/input/trackpad/touch"},
			SerializedBinding{action_trackpadtouched, "/user/hand/right/input/trackpad/touch"},
			SerializedBinding{action_devicepose, "/user/hand/left/input/grip/pose"},
			SerializedBinding{action_devicepose, "/user/hand/right/input/grip/pose"},
			SerializedBinding{action_pointer, "/user/hand/left/input/aim/pose"},
			SerializedBinding{action_pointer, "/user/hand/right/input/aim/pose"},
			SerializedBinding{action_haptic, "/user/hand/left/output/haptic"},
			SerializedBinding{action_haptic, "/user/hand/right/output/haptic"},
		}.data(), 42)) {
			logger.error("OpenXRInputProvider_SuggestBindings(/interaction_profiles/valve/index_controller) failed");
			return;
		}
	}
	if(!OpenXRInputProvider_AttachActionSets())
		logger.error("OpenXRInputProvider_AttachActionSets() failed");
	logger.info("action sets registered");
}
