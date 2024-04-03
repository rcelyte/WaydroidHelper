#pragma once
#include <UnityEngine/IntegratedSubsystemDescriptor_1.hpp>
#include <UnityEngine/IntegratedSubsystem_1.hpp>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreserved-identifier"

namespace UnityEngine::XR {
	class XRInputSubsystemDescriptor;
	class XRDisplaySubsystem;
}
MARK_REF_PTR_T(::UnityEngine::XR::XRInputSubsystemDescriptor);
MARK_REF_PTR_T(::UnityEngine::XR::XRDisplaySubsystem);
namespace UnityEngine::XR {
	class CORDL_TYPE XRInputSubsystemDescriptor : public ::UnityEngine::IntegratedSubsystemDescriptor_1<Il2CppObject*> {
		public:
		XRInputSubsystemDescriptor(XRInputSubsystemDescriptor&&) = delete;
		XRInputSubsystemDescriptor(XRInputSubsystemDescriptor const&) = delete;
		static constexpr bool __IL2CPP_IS_VALUE_TYPE = false;
	};
	class CORDL_TYPE XRDisplaySubsystem : public ::UnityEngine::IntegratedSubsystem_1<Il2CppObject*> {
		public:
		XRDisplaySubsystem(XRDisplaySubsystem&&) = delete;
		XRDisplaySubsystem(XRDisplaySubsystem const&) = delete;
		static constexpr bool __IL2CPP_IS_VALUE_TYPE = false;
	};
}
NEED_NO_BOX(UnityEngine::XR::XRInputSubsystemDescriptor);
DEFINE_IL2CPP_ARG_TYPE(UnityEngine::XR::XRInputSubsystemDescriptor*, "UnityEngine.XR", "XRInputSubsystemDescriptor");
NEED_NO_BOX(::UnityEngine::XR::XRDisplaySubsystem);
DEFINE_IL2CPP_ARG_TYPE(::UnityEngine::XR::XRDisplaySubsystem*, "UnityEngine.XR", "XRDisplaySubsystem");

template <typename TDescriptor, typename TSubsystem>
inline void XRLoaderHelper_CreateSubsystem(UnityEngine::XR::Management::XRLoaderHelper *const self,
		System::Collections::Generic::List_1<TDescriptor> *const descriptors, StringW id) {
	static const MethodInfo *const ___internal_method_base = THROW_UNLESS(il2cpp_utils::FindMethodUnsafe(
		il2cpp_utils::il2cpp_type_check::il2cpp_no_arg_class<UnityEngine::XR::Management::XRLoaderHelper*>::get(), "CreateSubsystem", 2));
	static const MethodInfo *const ___internal_method = THROW_UNLESS(il2cpp_utils::MakeGenericMethod(___internal_method_base,
		std::array<Il2CppClass const*, 2>{
			il2cpp_utils::il2cpp_type_check::il2cpp_no_arg_class<TDescriptor>::get(),
			il2cpp_utils::il2cpp_type_check::il2cpp_no_arg_class<TSubsystem>::get(),
		}));
	return cordl_internals::RunMethodRethrow<void, false>(self, ___internal_method, descriptors, id);
}

#pragma GCC diagnostic pop
