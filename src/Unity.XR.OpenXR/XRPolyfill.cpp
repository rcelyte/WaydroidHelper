#include "XRPolyfill.hpp"
#include "UnityOpenXR.hpp"
#include "../log.hpp"

GlobalNamespace::UnityXRHelper *XRPolyfill::unityXRHelper = nullptr;
void XRPolyfill::UpdateUserPresence() {
	int32_t oldState = 0, newState = 0;
	UnityOpenXR::session_GetSessionState(&oldState, &newState);
	if(XRPolyfill::unityXRHelper != nullptr) {
		logger.info("UpdateUserPresence(%d) -> %s", newState, (newState >= 3 && newState <= 5) ? "true" : "false");
		XRPolyfill::unityXRHelper->set_userPresence(newState >= 3 && newState <= 5);
	}
}
