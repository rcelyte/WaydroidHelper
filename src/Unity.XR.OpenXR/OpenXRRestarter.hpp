#pragma once

namespace OpenXRRestarter {
	void ShutdownAndRestart();
	void PauseAndShutdownAndRestart();
	void PauseAndRetryInitialization();
	void Shutdown();
}
