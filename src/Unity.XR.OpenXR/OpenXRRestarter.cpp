#include "OpenXRRestarter.hpp"
#include "../log.hpp"

#include <UnityEngine/Application.hpp>

void OpenXRRestarter::ShutdownAndRestart() {
	logger.critical("TODO: OpenXRRestarter::ShutdownAndRestart()");
	UnityEngine::Application::Quit();
}

void OpenXRRestarter::PauseAndShutdownAndRestart() {
	logger.critical("TODO: OpenXRRestarter::PauseAndShutdownAndRestart()");
	UnityEngine::Application::Quit();
}

void OpenXRRestarter::PauseAndRetryInitialization() {
	logger.critical("TODO: OpenXRRestarter::PauseAndRetryInitialization()");
	UnityEngine::Application::Quit();
}

void OpenXRRestarter::Shutdown() {
	logger.critical("TODO: OpenXRRestarter::Shutdown()");
	UnityEngine::Application::Quit();
}
