#pragma once
#include <Unity/XR/Oculus/OculusLoader.hpp>

namespace XRPolyfill::OpenXRLoader {
	void ProcessOpenXRMessageLoop();
	bool Initialize(Unity::XR::Oculus::OculusLoader *const self);
	bool Start(Unity::XR::Oculus::OculusLoader *const self);
	bool Stop(Unity::XR::Oculus::OculusLoader *const self);
	bool Deinitialize(Unity::XR::Oculus::OculusLoader *const self);
}
