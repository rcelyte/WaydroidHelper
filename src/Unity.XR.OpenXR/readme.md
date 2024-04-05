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
