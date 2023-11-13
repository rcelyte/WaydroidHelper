#pragma once
#include <il2cpp-config.h>
#include <il2cpp-api.h>
#include <il2cpp-object-internals.h>
#include <il2cpp-class-internals.h>
#include <assert.h>

static Il2CppClass *Helper_GetClass(const char namespace[], const char className[]) {
	Il2CppDomain *const domain = il2cpp_domain_get();
	if(domain == NULL)
		return NULL;
	size_t assemblies_len = 0;
	const Il2CppAssembly **const assemblies = il2cpp_domain_get_assemblies(domain, &assemblies_len);
	Il2CppClass *class = NULL;
	for(const Il2CppAssembly **assembly = assemblies; class == NULL && assembly < &assemblies[assemblies_len]; ++assembly) {
		const Il2CppImage *const image = il2cpp_assembly_get_image(*assembly);
		if(image == NULL)
			logLine_warn("il2cpp_assembly_get_image(%s) failed", (*assembly)->aname.name);
		else
			class = il2cpp_class_from_name(image, namespace, className);
	}
	return class;
}

static const MethodInfo *Helper_GetMethod(const char namespace[], const char className[], const char method[], uint32_t paramCount) {
	Il2CppClass *const class = Helper_GetClass(namespace, className);
	return (class != NULL) ? il2cpp_class_get_method_from_name(class, method, (int32_t)paramCount) : NULL;
}

static const MethodInfo *Helper_InstanceMethod(Il2CppObject *const object, const char method[], uint32_t paramCount) {
	Il2CppClass *const class = il2cpp_object_get_class(object);
	return (class != NULL) ? il2cpp_class_get_method_from_name(class, method, (int32_t)paramCount) : NULL;
}

static Il2CppMethodPointer Helper_MethodPointer(const char namespace[], const char className[], const char method[], uint32_t paramCount) {
	const MethodInfo *const info = Helper_GetMethod(namespace, className, method, paramCount);
	return (info != NULL) ? info->methodPointer : NULL;
}

static FieldInfo *Helper_GetField(const char namespace[], const char className[], const char field[]) {
	Il2CppClass *const class = Helper_GetClass(namespace, className);
	return (class != NULL) ? il2cpp_class_get_field_from_name(class, field) : NULL;
}

static FieldInfo *Helper_InstanceField(Il2CppObject *const object, const char field[]) {
	Il2CppClass *const class = il2cpp_object_get_class(object);
	return (class != NULL) ? il2cpp_class_get_field_from_name(class, field) : NULL;
}

static void Helper_InstanceFieldValue(Il2CppObject *const object, const char field[], void *const value_out) {
	assert(object != NULL && value_out != NULL);
	il2cpp_field_get_value(object, Helper_InstanceField(object, field), value_out);
}

static void Helper_InstanceFieldSet_Object(Il2CppObject *const object, const char field[], Il2CppObject *const value) {
	assert(object != NULL && value != NULL);
	il2cpp_field_set_value_object(object, Helper_InstanceField(object, field), value);
}

static const MethodInfo *Helper_GenericMethod(const MethodInfo *const info, Il2CppClass *const types[], const uint32_t types_len) {
	Il2CppArray *genericArgs = il2cpp_array_new(il2cpp_class_from_type(&(Il2CppType){.type = IL2CPP_TYPE_IL2CPP_TYPE_INDEX}), types_len);
	Il2CppObject **genericArgs_values = &((Il2CppObject**)genericArgs)[il2cpp_array_object_header_size() / sizeof(Il2CppObject*)];
	for(uint32_t i = 0; i < types_len; ++i)
		genericArgs_values[i] = il2cpp_type_get_object(il2cpp_class_get_type(types[i]));
	assert(il2cpp_method_is_generic(info));
	Il2CppReflectionMethod *const infoObject = il2cpp_method_get_object(info, NULL);
	assert(infoObject != NULL);
	Il2CppException *error = NULL;
	Il2CppReflectionMethod *const genInfoObject = (Il2CppReflectionMethod*)il2cpp_runtime_invoke(Helper_InstanceMethod(&infoObject->object, "MakeGenericMethod", 1), &infoObject->object, (void**)&genericArgs, &error);
	return (error == NULL && genInfoObject != NULL) ? il2cpp_method_get_from_reflection(genInfoObject) : NULL;
}
