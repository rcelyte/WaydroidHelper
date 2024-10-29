#include "XRPolyfill.hpp"
using namespace std::literals::string_view_literals;

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
	"extend": "",
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
		{"name": "palmPose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 8, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["palmPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 20, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["palmRotation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "palmPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 8, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "palmRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 20, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::OculusTouchController_json = R"json({
	"name": "OculusTouchController",
	"extend": "",
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
		{"name": "thumbstick", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "Joystick"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "grip", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "gripPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "menu", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuButton"], "aliases": ["Primary", "menuButton", "systemButton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "primaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryButton"], "aliases": ["A", "X", "buttonA", "buttonX"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "primaryTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryTouch"], "aliases": ["ATouched", "XTouched", "ATouch", "XTouch", "buttonATouched", "buttonXTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "secondaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SecondaryButton"], "aliases": ["B", "Y", "buttonB", "buttonY"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "secondaryTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SecondaryTouch"], "aliases": ["BTouched", "YTouched", "BTouch", "YTouch", "buttonBTouched", "buttonYTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trigger", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Trigger"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerButton"], "aliases": ["indexButton", "indexTouched", "triggerbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerTouch"], "aliases": ["indexTouch", "indexNearTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickClicked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisClick"], "aliases": ["JoystickOrPadPressed", "thumbstickClick", "joystickClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisTouch"], "aliases": ["JoystickOrPadTouched", "thumbstickTouch", "joystickTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbrestTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["ThumbrestTouch"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 28, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["IsTracked"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 32, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TrackingState"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 36, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 48, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 96, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 108, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "haptic", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Haptic"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::WMRSpatialController_json = R"json({
	"name": "WMRSpatialController",
	"extend": "",
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
		{"name": "joystick", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "thumbstickaxes", "thumbstick"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "touchpad", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Secondary2DAxis"], "aliases": ["Secondary2DAxis", "touchpadaxes", "trackpad"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "grip", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "gripPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "menu", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trigger", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Trigger"], "aliases": ["triggeraxis"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerButton"], "aliases": ["triggerbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "joystickClicked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisClick"], "aliases": ["joystickClicked", "thumbstickpressed"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "touchpadClicked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Secondary2DAxisClick"], "aliases": ["joystickorpadpressed", "touchpadpressed", "trackpadClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "touchpadTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Secondary2DAxisTouch"], "aliases": ["joystickorpadtouched", "touchpadtouched", "trackpadTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 32, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 36, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 40, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 52, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 100, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 112, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "haptic", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Haptic"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::HoloLensHand_json = R"json({
	"name": "HoloLensHand",
	"extend": "",
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
		{"name": "select", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryAxis"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "selectPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryButton"], "aliases": ["Primary", "selectbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "squeeze", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Grip"], "aliases": ["Secondary"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "squeezePressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 132, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 136, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 20, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 32, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 80, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 92, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::QuestProTouchController_json = R"json({
	"name": "QuestProTouchController",
	"extend": "",
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
		{"name": "thumbstick", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "Joystick"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "grip", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "gripPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "menu", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuButton"], "aliases": ["Primary", "menuButton", "systemButton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "primaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryButton"], "aliases": ["A", "X", "buttonA", "buttonX"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "primaryTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryTouch"], "aliases": ["ATouched", "XTouched", "ATouch", "XTouch", "buttonATouched", "buttonXTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "secondaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SecondaryButton"], "aliases": ["B", "Y", "buttonB", "buttonY"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "secondaryTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SecondaryTouch"], "aliases": ["BTouched", "YTouched", "BTouch", "YTouch", "buttonBTouched", "buttonYTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trigger", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Trigger"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerButton"], "aliases": ["indexButton", "indexTouched", "triggerbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerTouch"], "aliases": ["indexTouch", "indexNearTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickClicked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisClick"], "aliases": ["JoystickOrPadPressed", "thumbstickClick", "joystickClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisTouch"], "aliases": ["JoystickOrPadTouched", "thumbstickTouch", "joystickTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbrestTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["ThumbrestTouch"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 28, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["IsTracked"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 32, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TrackingState"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 36, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 48, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 96, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 108, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "haptic", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Haptic"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbrestForce", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["ThumbrestForce"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "stylusForce", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["StylusForce"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerCurl", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerCurl"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerSlide", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerSlide"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerProximity", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerProximity"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbProximity", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["ThumbProximity"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "hapticTrigger", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["HapticTrigger"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "hapticThumb", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["HapticThumb"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::KHRSimpleController_json = R"json({
	"name": "KHRSimpleController",
	"extend": "",
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
		{"name": "select", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryButton"], "aliases": ["Secondary", "selectbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "menu", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 2, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 8, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 20, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 68, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 80, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "haptic", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Haptic"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::ViveController_json = R"json({
	"name": "ViveController",
	"extend": "",
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
		{"name": "select", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SystemButton"], "aliases": ["Secondary", "selectbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "grip", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "gripPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "menu", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trigger", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Trigger"], "aliases": ["triggeraxis"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerButton"], "aliases": ["triggerbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpad", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "touchpadaxes", "touchpad"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadClicked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisClick"], "aliases": ["joystickorpadpressed", "touchpadpressed"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisTouch"], "aliases": ["joystickorpadtouched", "touchpadtouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 26, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 28, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 32, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 44, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 92, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 104, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "haptic", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Haptic"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::ReverbG2Controller_json = R"json({
	"name": "ReverbG2Controller",
	"extend": "",
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
		{"name": "primaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryButton"], "aliases": ["A", "X", "buttonA", "buttonX"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "secondaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SecondaryButton"], "aliases": ["B", "Y", "buttonB", "buttonY"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "menu", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuButton"], "aliases": ["Primary", "menubutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "grip", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "gripPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trigger", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Trigger"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerButton"], "aliases": ["indexButton", "indexTouched", "triggerbutton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstick", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxis"], "aliases": ["Primary2DAxis", "Joystick"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickClicked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisClick"], "aliases": ["JoystickOrPadPressed", "thumbstickClick", "joystickClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 29, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 32, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 36, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 48, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 96, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 108, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "haptic", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Haptic"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::HandInteraction_json = R"json({
	"name": "HandInteraction",
	"extend": "",
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
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pokePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Poke"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pinchPose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pinch"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pinchValue", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PinchValue"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pinchReady", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PinchReady"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerActivateValue", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PointerActivateValue"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerActivateReady", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PointerActivateReady"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "graspValue", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GraspValue"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "graspReady", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GraspReady"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 2, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 8, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 20, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripRotation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 68, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 80, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pokePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 128, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pokeRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 140, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pinchPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 188, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pinchRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 200, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": true, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::DPad_json = R"json({
	"name": "DPad",
	"extend": "",
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
		{"name": "thumbstickDpadUp", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickDpadDown", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickDpadLeft", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickDpadRight", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadDpadUp", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadDpadDown", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadDpadLeft", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadDpadRight", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadDpadCenter", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;

const std::string_view XRPolyfill::OpenXRInteractionFeature::ValveIndexController_json = R"json({
	"name": "ValveIndexController",
	"extend": "",
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
		{"name": "system", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuButton"], "aliases": ["systemButton"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "systemTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["MenuTouch"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "primaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryButton"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "primaryTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["PrimaryTouch"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "secondaryButton", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SecondaryButton"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "secondaryTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["SecondaryTouch"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "grip", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Grip"], "aliases": ["GripAxis", "squeeze"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "gripPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripButton"], "aliases": ["GripButton", "squeezeClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "gripForce", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["GripForce"], "aliases": ["squeezeForce"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trigger", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Trigger"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerPressed", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerButton"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "triggerTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["TriggerTouch"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstick", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxis"], "aliases": ["joystick", "Primary2DAxis"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickClicked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisClick"], "aliases": ["joystickClicked"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "thumbstickTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Primary2DAxisTouch"], "aliases": ["joystickTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpad", "layout": "Vector2", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Secondary2DAxis"], "aliases": ["touchpad", "Secondary2DAxis"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadTouched", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Secondary2DAxisTouch"], "aliases": ["touchpadTouched"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackpadForce", "layout": "Axis", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Secondary2DAxisForce"], "aliases": ["touchpadForce"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePose", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Device"], "aliases": ["device", "gripPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointer", "layout": "Pose", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 0, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Pointer"], "aliases": ["aimPose"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "isTracked", "layout": "Button", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 53, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "trackingState", "layout": "Integer", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 56, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "devicePosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 60, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripPosition"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "deviceRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 72, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["gripOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerPosition", "layout": "Vector3", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 120, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "pointerRotation", "layout": "Quaternion", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 132, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": [], "aliases": ["pointerOrientation"], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""},
		{"name": "haptic", "layout": "Haptic", "variants": "", "usage": "", "alias": "", "useStateFrom": "", "offset": 4294967295, "bit": 4294967295, "sizeInBits": 0, "format": "", "arraySize": 0, "usages": ["Haptic"], "aliases": [], "parameters": "", "processors": "", "displayName": "", "shortDisplayName": "", "noisy": false, "dontReset": false, "synthetic": false, "defaultState": "", "minValue": "", "maxValue": ""}
	]
})json"sv;
