#include "XRPolyfill.hpp"
#include "../log.hpp"

#include <UnityEngine/Application.hpp>

void XRPolyfill::OpenXRRestarter::ShutdownAndRestart() {
	logger.critical("TODO: XRPolyfill::OpenXRRestarter::ShutdownAndRestart()");
	UnityEngine::Application::Quit();
}

void XRPolyfill::OpenXRRestarter::PauseAndShutdownAndRestart() {
	logger.critical("TODO: XRPolyfill::OpenXRRestarter::PauseAndShutdownAndRestart()");
	UnityEngine::Application::Quit();
}

void XRPolyfill::OpenXRRestarter::PauseAndRetryInitialization() {
	logger.critical("TODO: XRPolyfill::OpenXRRestarter::PauseAndRetryInitialization()");
	UnityEngine::Application::Quit();
}

void XRPolyfill::OpenXRRestarter::Shutdown() {
	logger.critical("TODO: XRPolyfill::OpenXRRestarter::Shutdown()");
	UnityEngine::Application::Quit();
}
