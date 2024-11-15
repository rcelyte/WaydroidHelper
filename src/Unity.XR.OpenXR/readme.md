# XRPolyfill
This is an IL2CPP substitute for the [C# support code](https://download.packages.unity.com/com.unity.xr.openxr/-/com.unity.xr.openxr-1.9.1.tgz) portion of libUnityOpenXR


### How to build com.unity.xr.openxr (for comparison/validation):
```make
Unity.XR.OpenXR.dll: $(shell find Runtime/ -name "*.cs")
	$(CSC) -nologo -t:library -nostdlib -o+ -debug- -unsafe+ -langversion:7 $^ -out:$@ $(ASMREFS:%=-r:%) \
		-define:USE_INPUT_SYSTEM_POSE_CONTROL,UNITY_2019_3_OR_NEWER,UNITY_2021_3_OR_NEWER \
		-r:$(BSINSTALL)/Beat\ Saber_Data/Managed/mscorlib.dll \
		-r:$(BSINSTALL)/Beat\ Saber_Data/Managed/System.Core.dll \
		-r:$(BSINSTALL)/Beat\ Saber_Data/Managed/UnityEngine.CoreModule.dll \
		-r:$(BSINSTALL)/Beat\ Saber_Data/Managed/UnityEngine.SubsystemsModule.dll \
		-r:$(BSINSTALL)/Beat\ Saber_Data/Managed/UnityEngine.XRModule.dll \
		-r:$(BSINSTALL)/Beat\ Saber_Data/Managed/Unity.InputSystem.dll \
		-r:$(BSINSTALL)/Beat\ Saber_Data/Managed/Unity.XR.Management.dll
```
`OpenXRSettings.Instance.features` needs to be manually initialized in `OpenXRLoaderBase.Initialize()` due to the `[SerializeField]` not matching properly:
```cs
OpenXRSettings.Instance.features = new UnityEngine.XR.OpenXR.Features.OpenXRFeature[] {
	new BeatSaberXRFeature {enabled=true, nameUi="Beat Saber XR Feature", version="1.0.0", featureIdInternal="com.beatgames.beatsaber.feature.beatsaberxr", openxrExtensionStrings="", company="Beat Saber", priority=0, required=false},
	// new UnityEngine.XR.OpenXR.Features.ConformanceAutomation.ConformanceAutomationFeature {enabled=false, nameUi="Conformance Automation", version="0.0.1", featureIdInternal="com.unity.openxr.feature.conformance", openxrExtensionStrings="XR_EXT_conformance_automation", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.DPadInteraction {enabled=false, nameUi="D-Pad Binding", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.dpadinteraction", openxrExtensionStrings="XR_KHR_binding_modification XR_EXT_dpad_binding", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.EyeGazeInteraction {enabled=false, nameUi="Eye Gaze Interaction Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.eyetracking", openxrExtensionStrings="XR_EXT_eye_gaze_interaction", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.HandCommonPosesInteraction {enabled=false, nameUi="Hand Interaction Poses", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.handinteractionposes", openxrExtensionStrings="XR_EXT_hand_interaction", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.HandInteractionProfile {enabled=false, nameUi="Hand Interaction Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.handinteraction", openxrExtensionStrings="XR_EXT_hand_interaction", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.HPReverbG2ControllerProfile {enabled=false, nameUi="HP Reverb G2 Controller Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.hpreverb", openxrExtensionStrings="XR_EXT_hp_mixed_reality_controller", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.HTCViveControllerProfile {enabled=true, nameUi="HTC Vive Controller Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.htcvive", openxrExtensionStrings="", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.KHRSimpleControllerProfile {enabled=true, nameUi="Khronos Simple Controller Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.khrsimpleprofile", openxrExtensionStrings="", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.MetaQuestTouchProControllerProfile {enabled=false, nameUi="Meta Quest Touch Pro Controller Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.metaquestpro", openxrExtensionStrings="XR_FB_touch_controller_pro", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.MicrosoftHandInteraction {enabled=false, nameUi="Microsoft Hand Interaction Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.handtracking", openxrExtensionStrings="XR_MSFT_hand_interaction", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.MicrosoftMotionControllerProfile {enabled=true, nameUi="Microsoft Motion Controller Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.microsoftmotioncontroller", openxrExtensionStrings="", company="Unity", priority=0, required=false},
	// new UnityEngine.XR.OpenXR.Features.Mock.MockRuntime {enabled=false, nameUi="Mock Runtime", version="0.0.2", featureIdInternal="com.unity.openxr.feature.mockruntime", openxrExtensionStrings="XR_UNITY_null_gfx XR_UNITY_android_present", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.OculusTouchControllerProfile {enabled=true, nameUi="Oculus Touch Controller Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.oculustouch", openxrExtensionStrings="", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.PalmPoseInteraction {enabled=false, nameUi="Palm Pose", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.palmpose", openxrExtensionStrings="XR_EXT_palm_pose", company="Unity", priority=0, required=false},
	// new UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature {enabled=false, nameUi="Runtime Debugger", version="1", featureIdInternal="com.unity.openxr.features.runtimedebugger", openxrExtensionStrings="", company="Unity", priority=0, required=false},
	new UnityEngine.XR.OpenXR.Features.Interactions.ValveIndexControllerProfile {enabled=true, nameUi="Valve Index Controller Profile", version="0.0.1", featureIdInternal="com.unity.openxr.feature.input.valveindex", openxrExtensionStrings="", company="Unity", priority=0, required=false,
	},
};
```
