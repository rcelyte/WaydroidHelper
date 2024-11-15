#include "XRPolyfill.hpp"
using namespace std::literals::string_view_literals;

// "extend": "XRController"
// remove isTracked, trackingState, devicePosition, deviceRotation

const std::string_view XRPolyfill::OpenXRInteractionFeature::Haptic_json = R"json({
	"name": "Haptic",
	"extend": "",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [],
	"displayName": "",
	"description": "",
	"type": "UnityEngine.InputSystem.Controls.AnyKeyControl, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": []
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::OpenXRDevice_json = R"json({
	"name": "OpenXRDevice",
	"extend": "",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [],
	"displayName": "OpenXR Action Map",
	"description": "",
	"type": "UnityEngine.InputSystem.InputDevice, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": []
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::PalmPose_json = R"json({
	"name": "PalmPose",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Palm Pose (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRController, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "palmPose", "layout": "Pose", "offset": 0},
		{"name": "isTracked", "layout": "Button", "offset": 0},
		{"name": "trackingState", "layout": "Integer", "offset": 4},
		{"name": "devicePosition", "layout": "Vector3", "offset": 8, "aliases": ["palmPosition"], "noisy": true},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 20, "aliases": ["palmRotation"], "noisy": true},
		{"name": "palmPosition", "layout": "Vector3", "offset": 8, "noisy": true},
		{"name": "palmRotation", "layout": "Quaternion", "offset": 20, "noisy": true}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::OculusTouchController_json = R"json({
	"name": "OculusTouchController",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Oculus Touch Controller (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRControllerWithRumble, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "thumbstick", "layout": "Vector2", "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "Joystick"]},
		{"name": "grip", "layout": "Axis", "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"]},
		{"name": "gripPressed", "layout": "Button", "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"]},
		{"name": "menu", "layout": "Button", "usages": ["MenuButton"], "aliases": ["Primary", "menuButton", "systemButton"]},
		{"name": "primaryButton", "layout": "Button", "usages": ["PrimaryButton"], "aliases": ["A", "X", "buttonA", "buttonX"]},
		{"name": "primaryTouched", "layout": "Button", "usages": ["PrimaryTouch"], "aliases": ["ATouched", "XTouched", "ATouch", "XTouch", "buttonATouched", "buttonXTouched"]},
		{"name": "secondaryButton", "layout": "Button", "usages": ["SecondaryButton"], "aliases": ["B", "Y", "buttonB", "buttonY"]},
		{"name": "secondaryTouched", "layout": "Button", "usages": ["SecondaryTouch"], "aliases": ["BTouched", "YTouched", "BTouch", "YTouch", "buttonBTouched", "buttonYTouched"]},
		{"name": "trigger", "layout": "Axis", "usages": ["Trigger"]},
		{"name": "triggerPressed", "layout": "Button", "usages": ["TriggerButton"], "aliases": ["indexButton", "indexTouched", "triggerbutton"]},
		{"name": "triggerTouched", "layout": "Button", "usages": ["TriggerTouch"], "aliases": ["indexTouch", "indexNearTouched"]},
		{"name": "thumbstickClicked", "layout": "Button", "usages": ["Primary2DAxisClick"], "aliases": ["JoystickOrPadPressed", "thumbstickClick", "joystickClicked"]},
		{"name": "thumbstickTouched", "layout": "Button", "usages": ["Primary2DAxisTouch"], "aliases": ["JoystickOrPadTouched", "thumbstickTouch", "joystickTouched"]},
		{"name": "thumbrestTouched", "layout": "Button", "usages": ["ThumbrestTouch"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "isTracked", "layout": "Button", "offset": 28, "usages": ["IsTracked"]},
		{"name": "trackingState", "layout": "Integer", "offset": 32, "usages": ["TrackingState"]},
		{"name": "devicePosition", "layout": "Vector3", "offset": 36, "aliases": ["gripPosition"], "noisy": true},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 48, "aliases": ["gripOrientation"], "noisy": true},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 96},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 108, "aliases": ["pointerOrientation"]},
		{"name": "haptic", "layout": "Haptic", "usages": ["Haptic"]}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::WMRSpatialController_json = R"json({
	"name": "WMRSpatialController",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Windows MR Controller (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRControllerWithRumble, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "joystick", "layout": "Vector2", "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "thumbstickaxes", "thumbstick"]},
		{"name": "touchpad", "layout": "Vector2", "usages": ["Secondary2DAxis"], "aliases": ["Secondary2DAxis", "touchpadaxes", "trackpad"]},
		{"name": "grip", "layout": "Axis", "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"]},
		{"name": "gripPressed", "layout": "Button", "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"]},
		{"name": "menu", "layout": "Button", "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"]},
		{"name": "trigger", "layout": "Axis", "usages": ["Trigger"], "aliases": ["triggeraxis"]},
		{"name": "triggerPressed", "layout": "Button", "usages": ["TriggerButton"], "aliases": ["triggerbutton"]},
		{"name": "joystickClicked", "layout": "Button", "usages": ["Primary2DAxisClick"], "aliases": ["joystickClicked", "thumbstickpressed"]},
		{"name": "touchpadClicked", "layout": "Button", "usages": ["Secondary2DAxisClick"], "aliases": ["joystickorpadpressed", "touchpadpressed", "trackpadClicked"]},
		{"name": "touchpadTouched", "layout": "Button", "usages": ["Secondary2DAxisTouch"], "aliases": ["joystickorpadtouched", "touchpadtouched", "trackpadTouched"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "isTracked", "layout": "Button", "offset": 32},
		{"name": "trackingState", "layout": "Integer", "offset": 36},
		{"name": "devicePosition", "layout": "Vector3", "offset": 40, "aliases": ["gripPosition"]},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 52, "aliases": ["gripOrientation"]},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 100},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 112, "aliases": ["pointerOrientation"]},
		{"name": "haptic", "layout": "Haptic", "usages": ["Haptic"]}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::HoloLensHand_json = R"json({
	"name": "HoloLensHand",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Hololens Hand (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRController, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "select", "layout": "Axis", "usages": ["PrimaryAxis"]},
		{"name": "selectPressed", "layout": "Button", "usages": ["PrimaryButton"], "aliases": ["Primary", "selectbutton"]},
		{"name": "squeeze", "layout": "Axis", "usages": ["Grip"], "aliases": ["Secondary"]},
		{"name": "squeezePressed", "layout": "Button", "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"]},
		{"name": "isTracked", "layout": "Button", "offset": 132},
		{"name": "trackingState", "layout": "Integer", "offset": 136},
		{"name": "devicePosition", "layout": "Vector3", "offset": 20, "aliases": ["gripPosition"]},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 32, "aliases": ["gripOrientation"]},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 80},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 92, "aliases": ["pointerOrientation"]}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::QuestProTouchController_json = R"json({
	"name": "QuestProTouchController",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Meta Quest Pro Touch Controller(OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRControllerWithRumble, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "thumbstick", "layout": "Vector2", "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "Joystick"]},
		{"name": "grip", "layout": "Axis", "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"]},
		{"name": "gripPressed", "layout": "Button", "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"]},
		{"name": "menu", "layout": "Button", "usages": ["MenuButton"], "aliases": ["Primary", "menuButton", "systemButton"]},
		{"name": "primaryButton", "layout": "Button", "usages": ["PrimaryButton"], "aliases": ["A", "X", "buttonA", "buttonX"]},
		{"name": "primaryTouched", "layout": "Button", "usages": ["PrimaryTouch"], "aliases": ["ATouched", "XTouched", "ATouch", "XTouch", "buttonATouched", "buttonXTouched"]},
		{"name": "secondaryButton", "layout": "Button", "usages": ["SecondaryButton"], "aliases": ["B", "Y", "buttonB", "buttonY"]},
		{"name": "secondaryTouched", "layout": "Button", "usages": ["SecondaryTouch"], "aliases": ["BTouched", "YTouched", "BTouch", "YTouch", "buttonBTouched", "buttonYTouched"]},
		{"name": "trigger", "layout": "Axis", "usages": ["Trigger"]},
		{"name": "triggerPressed", "layout": "Button", "usages": ["TriggerButton"], "aliases": ["indexButton", "indexTouched", "triggerbutton"]},
		{"name": "triggerTouched", "layout": "Button", "usages": ["TriggerTouch"], "aliases": ["indexTouch", "indexNearTouched"]},
		{"name": "thumbstickClicked", "layout": "Button", "usages": ["Primary2DAxisClick"], "aliases": ["JoystickOrPadPressed", "thumbstickClick", "joystickClicked"]},
		{"name": "thumbstickTouched", "layout": "Button", "usages": ["Primary2DAxisTouch"], "aliases": ["JoystickOrPadTouched", "thumbstickTouch", "joystickTouched"]},
		{"name": "thumbrestTouched", "layout": "Button", "usages": ["ThumbrestTouch"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "isTracked", "layout": "Button", "offset": 28, "usages": ["IsTracked"]},
		{"name": "trackingState", "layout": "Integer", "offset": 32, "usages": ["TrackingState"]},
		{"name": "devicePosition", "layout": "Vector3", "offset": 36, "aliases": ["gripPosition"], "noisy": true},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 48, "aliases": ["gripOrientation"], "noisy": true},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 96},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 108, "aliases": ["pointerOrientation"]},
		{"name": "haptic", "layout": "Haptic", "usages": ["Haptic"]},
		{"name": "thumbrestForce", "layout": "Axis", "usages": ["ThumbrestForce"]},
		{"name": "stylusForce", "layout": "Axis", "usages": ["StylusForce"]},
		{"name": "triggerCurl", "layout": "Axis", "usages": ["TriggerCurl"]},
		{"name": "triggerSlide", "layout": "Axis", "usages": ["TriggerSlide"]},
		{"name": "triggerProximity", "layout": "Button", "usages": ["TriggerProximity"]},
		{"name": "thumbProximity", "layout": "Button", "usages": ["ThumbProximity"]},
		{"name": "hapticTrigger", "layout": "Haptic", "usages": ["HapticTrigger"]},
		{"name": "hapticThumb", "layout": "Haptic", "usages": ["HapticThumb"]}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::KHRSimpleController_json = R"json({
	"name": "KHRSimpleController",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Khronos Simple Controller (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRControllerWithRumble, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "select", "layout": "Button", "usages": ["PrimaryButton"], "aliases": ["Secondary", "selectbutton"]},
		{"name": "menu", "layout": "Button", "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "isTracked", "layout": "Button", "offset": 2},
		{"name": "trackingState", "layout": "Integer", "offset": 4},
		{"name": "devicePosition", "layout": "Vector3", "offset": 8, "aliases": ["gripPosition"]},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 20, "aliases": ["gripOrientation"]},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 68},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 80, "aliases": ["pointerOrientation"]},
		{"name": "haptic", "layout": "Haptic", "usages": ["Haptic"]}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::ViveController_json = R"json({
	"name": "ViveController",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "HTC Vive Controller (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRControllerWithRumble, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "select", "layout": "Button", "usages": ["SystemButton"], "aliases": ["Secondary", "selectbutton"]},
		{"name": "grip", "layout": "Axis", "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"]},
		{"name": "gripPressed", "layout": "Button", "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"]},
		{"name": "menu", "layout": "Button", "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"]},
		{"name": "trigger", "layout": "Axis", "usages": ["Trigger"], "aliases": ["triggeraxis"]},
		{"name": "triggerPressed", "layout": "Button", "usages": ["TriggerButton"], "aliases": ["triggerbutton"]},
		{"name": "trackpad", "layout": "Vector2", "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "touchpadaxes", "touchpad"]},
		{"name": "trackpadClicked", "layout": "Button", "usages": ["Primary2DAxisClick"], "aliases": ["joystickorpadpressed", "touchpadpressed"]},
		{"name": "trackpadTouched", "layout": "Button", "usages": ["Primary2DAxisTouch"], "aliases": ["joystickorpadtouched", "touchpadtouched"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "isTracked", "layout": "Button", "offset": 26},
		{"name": "trackingState", "layout": "Integer", "offset": 28},
		{"name": "devicePosition", "layout": "Vector3", "offset": 32, "aliases": ["gripPosition"]},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 44, "aliases": ["gripOrientation"]},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 92},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 104, "aliases": ["pointerOrientation"]},
		{"name": "haptic", "layout": "Haptic", "usages": ["Haptic"]}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::ReverbG2Controller_json = R"json({
	"name": "ReverbG2Controller",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "HP Reverb G2 Controller (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRControllerWithRumble, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "primaryButton", "layout": "Button", "usages": ["PrimaryButton"], "aliases": ["A", "X", "buttonA", "buttonX"]},
		{"name": "secondaryButton", "layout": "Button", "usages": ["SecondaryButton"], "aliases": ["B", "Y", "buttonB", "buttonY"]},
		{"name": "menu", "layout": "Button", "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"]},
		{"name": "grip", "layout": "Axis", "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"]},
		{"name": "gripPressed", "layout": "Button", "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"]},
		{"name": "trigger", "layout": "Axis", "usages": ["Trigger"]},
		{"name": "triggerPressed", "layout": "Button", "usages": ["TriggerButton"], "aliases": ["indexButton", "indexTouched", "triggerbutton"]},
		{"name": "thumbstick", "layout": "Vector2", "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "Joystick"]},
		{"name": "thumbstickClicked", "layout": "Button", "usages": ["Primary2DAxisClick"], "aliases": ["JoystickOrPadPressed", "thumbstickClick", "joystickClicked"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "isTracked", "layout": "Button", "offset": 29},
		{"name": "trackingState", "layout": "Integer", "offset": 32},
		{"name": "devicePosition", "layout": "Vector3", "offset": 36, "aliases": ["gripPosition"]},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 48, "aliases": ["gripOrientation"]},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 96},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 108, "aliases": ["pointerOrientation"]},
		{"name": "haptic", "layout": "Haptic", "usages": ["Haptic"]}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::HandInteraction_json = R"json({
	"name": "HandInteraction",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Hand Interaction (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRController, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "pokePose", "layout": "Pose", "offset": 0, "usages": ["Poke"]},
		{"name": "pinchPose", "layout": "Pose", "offset": 0, "usages": ["Pinch"]},
		{"name": "pinchValue", "layout": "Axis", "usages": ["PinchValue"]},
		{"name": "pinchReady", "layout": "Button", "usages": ["PinchReady"]},
		{"name": "pointerActivateValue", "layout": "Axis", "usages": ["PointerActivateValue"]},
		{"name": "pointerActivateReady", "layout": "Button", "usages": ["PointerActivateReady"]},
		{"name": "graspValue", "layout": "Axis", "usages": ["GraspValue"]},
		{"name": "graspReady", "layout": "Button", "usages": ["GraspReady"]},
		{"name": "isTracked", "layout": "Button", "offset": 2},
		{"name": "trackingState", "layout": "Integer", "offset": 4},
		{"name": "devicePosition", "layout": "Vector3", "offset": 8, "aliases": ["gripPosition"], "noisy": true},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 20, "aliases": ["gripRotation"], "noisy": true},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 68, "noisy": true},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 80, "noisy": true},
		{"name": "pokePosition", "layout": "Vector3", "offset": 128, "noisy": true},
		{"name": "pokeRotation", "layout": "Quaternion", "offset": 140, "noisy": true},
		{"name": "pinchPosition", "layout": "Vector3", "offset": 188, "noisy": true},
		{"name": "pinchRotation", "layout": "Quaternion", "offset": 200, "noisy": true}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::DPad_json = R"json({
	"name": "DPad",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "D-Pad Binding (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRController, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "thumbstickDpadUp", "layout": "Button"},
		{"name": "thumbstickDpadDown", "layout": "Button"},
		{"name": "thumbstickDpadLeft", "layout": "Button"},
		{"name": "thumbstickDpadRight", "layout": "Button"},
		{"name": "trackpadDpadUp", "layout": "Button"},
		{"name": "trackpadDpadDown", "layout": "Button"},
		{"name": "trackpadDpadLeft", "layout": "Button"},
		{"name": "trackpadDpadRight", "layout": "Button"},
		{"name": "trackpadDpadCenter", "layout": "Button"}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::ValveIndexController_json = R"json({
	"name": "ValveIndexController",
	"extend": "XRController",
	"extendMultiple": [],
	"format": "",
	"beforeRender": "",
	"runInBackground": "",
	"commonUsages": [
		"LeftHand",
		"RightHand"
	],
	"displayName": "Index Controller (OpenXR)",
	"description": "",
	"type": "UnityEngine.InputSystem.XR.XRControllerWithRumble, Unity.InputSystem, Version=1.6.3.0, Culture=neutral, PublicKeyToken=null",
	"variant": "",
	"isGenericTypeOfDevice": false,
	"hideInUI": false,
	"controls": [
		{"name": "system", "layout": "Button", "usages": ["MenuButton"], "aliases": ["systemButton"]},
		{"name": "systemTouched", "layout": "Button", "usages": ["MenuTouch"]},
		{"name": "primaryButton", "layout": "Button", "usages": ["PrimaryButton"]},
		{"name": "primaryTouched", "layout": "Button", "usages": ["PrimaryTouch"]},
		{"name": "secondaryButton", "layout": "Button", "usages": ["SecondaryButton"]},
		{"name": "secondaryTouched", "layout": "Button", "usages": ["SecondaryTouch"]},
		{"name": "grip", "layout": "Axis", "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"]},
		{"name": "gripPressed", "layout": "Button", "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"]},
		{"name": "gripForce", "layout": "Axis", "usages": ["GripForce"], "aliases": ["squeezeForce"]},
		{"name": "trigger", "layout": "Axis", "usages": ["Trigger"]},
		{"name": "triggerPressed", "layout": "Button", "usages": ["TriggerButton"]},
		{"name": "triggerTouched", "layout": "Button", "usages": ["TriggerTouch"]},
		{"name": "thumbstick", "layout": "Vector2", "usages": ["Primary2DAxis"], "aliases": ["joystick", "Primary2DAxis"]},
		{"name": "thumbstickClicked", "layout": "Button", "usages": ["Primary2DAxisClick"], "aliases": ["joystickClicked"]},
		{"name": "thumbstickTouched", "layout": "Button", "usages": ["Primary2DAxisTouch"], "aliases": ["joystickTouched"]},
		{"name": "trackpad", "layout": "Vector2", "usages": ["Secondary2DAxis"], "aliases": ["touchpad", "Secondary2DAxis"]},
		{"name": "trackpadTouched", "layout": "Button", "usages": ["Secondary2DAxisTouch"], "aliases": ["touchpadTouched"]},
		{"name": "trackpadForce", "layout": "Axis", "usages": ["Secondary2DAxisForce"], "aliases": ["touchpadForce"]},
		{"name": "devicePose", "layout": "Pose", "offset": 0, "usages": ["Device"], "aliases": ["device", "gripPose"]},
		{"name": "pointer", "layout": "Pose", "offset": 0, "usages": ["Pointer"], "aliases": ["aimPose"]},
		{"name": "isTracked", "layout": "Button", "offset": 53},
		{"name": "trackingState", "layout": "Integer", "offset": 56},
		{"name": "devicePosition", "layout": "Vector3", "offset": 60, "aliases": ["gripPosition"]},
		{"name": "deviceRotation", "layout": "Quaternion", "offset": 72, "aliases": ["gripOrientation"]},
		{"name": "pointerPosition", "layout": "Vector3", "offset": 120},
		{"name": "pointerRotation", "layout": "Quaternion", "offset": 132, "aliases": ["pointerOrientation"]},
		{"name": "haptic", "layout": "Haptic", "usages": ["Haptic"]}
	]
})json"sv;
