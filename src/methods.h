#pragma once
#include "helpers.h"

static const MethodInfo *OpenXRSettings_GetFeature_info_ = NULL;
static Il2CppObject *OpenXRSettings_GetFeature(Il2CppObject *const this, Il2CppClass *const featClass) {
	if(OpenXRSettings_GetFeature_info_ == NULL) {
		OpenXRSettings_GetFeature_info_ = Helper_GetMethod("UnityEngine.XR.OpenXR", "OpenXRSettings", "GetFeature", 0);
		assert(OpenXRSettings_GetFeature_info_ != NULL);
	}
	assert(featClass != NULL);
	const MethodInfo *const genInfo = Helper_GenericMethod(OpenXRSettings_GetFeature_info_, &featClass, 1);
	assert(genInfo != NULL);
	Il2CppException *error = NULL;
	Il2CppObject *const result = il2cpp_runtime_invoke(genInfo, this, NULL, &error);
	assert(error == NULL);
	return result;
}

static const MethodInfo *ScriptableObject_CreateInstance_info_ = NULL;
static Il2CppObject *ScriptableObject_CreateInstance(Il2CppClass *const soClass) {
	if(ScriptableObject_CreateInstance_info_ == NULL) {
		ScriptableObject_CreateInstance_info_ = Helper_GetMethod("UnityEngine", "ScriptableObject", "CreateInstance", 0);
		assert(ScriptableObject_CreateInstance_info_ != NULL);
	}
	assert(soClass != NULL);
	const MethodInfo *const genInfo = Helper_GenericMethod(ScriptableObject_CreateInstance_info_, &soClass, 1);
	assert(genInfo != NULL);
	Il2CppException *error = NULL;
	Il2CppObject *const result = il2cpp_runtime_invoke(genInfo, NULL, NULL, &error);
	assert(error == NULL);
	return result;
}

static const MethodInfo *OpenXRSettings_GetInstance_info_ = NULL;
static Il2CppObject *OpenXRSettings_GetInstance(bool useActiveBuildTarget) {
	if(OpenXRSettings_GetInstance_info_ == NULL) {
		OpenXRSettings_GetInstance_info_ = Helper_GetMethod("UnityEngine.XR.OpenXR", "OpenXRSettings", "GetInstance", 1);
		assert(OpenXRSettings_GetInstance_info_ != NULL);
	}
	Il2CppException *error = NULL;
	Il2CppObject *const result = il2cpp_runtime_invoke(OpenXRSettings_GetInstance_info_, NULL, (void*[]){&useActiveBuildTarget}, &error);
	assert(error == NULL);
	return result;
}

static const MethodInfo *OpenXRFeature_set_enabled_info_ = NULL;
static void OpenXRFeature_set_enabled(Il2CppObject *const this, bool enabled) {
	if(OpenXRFeature_set_enabled_info_ == NULL) {
		OpenXRFeature_set_enabled_info_ = Helper_GetMethod("UnityEngine.XR.OpenXR.Features", "OpenXRFeature", "set_enabled", 1);
		assert(OpenXRFeature_set_enabled_info_ != NULL);
	}
	Il2CppException *error = NULL;
	il2cpp_runtime_invoke(OpenXRFeature_set_enabled_info_, this, (void*[]){&enabled}, &error);
	assert(error == NULL);
}

static const MethodInfo *XRManagerSettings_get_currentLoaders_info_ = NULL;
static Il2CppObject *XRManagerSettings_get_currentLoaders(Il2CppObject *const this)  {
	if(XRManagerSettings_get_currentLoaders_info_ == NULL) {
		XRManagerSettings_get_currentLoaders_info_ = Helper_GetMethod("UnityEngine.XR.Management", "XRManagerSettings", "get_currentLoaders", 0);
		assert(XRManagerSettings_get_currentLoaders_info_ != NULL);
	}
	Il2CppException *error = NULL;
	Il2CppObject *const result = il2cpp_runtime_invoke(XRManagerSettings_get_currentLoaders_info_, this, NULL, &error);
	assert(error == NULL);
	return result;
}
