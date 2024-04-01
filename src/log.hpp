#pragma once
#include <android/log.h>

constexpr struct {
	[[gnu::format(printf, 1, 2)]] static inline void critical(const char format[], ...) {
		va_list args;
		va_start(args, format);
		__android_log_vprint(ANDROID_LOG_FATAL, "WaydroidHelper", format, args);
		va_end(args);
	}
	[[gnu::format(printf, 1, 2)]] static inline void error(const char format[], ...) {
		va_list args;
		va_start(args, format);
		__android_log_vprint(ANDROID_LOG_ERROR, "WaydroidHelper", format, args);
		va_end(args);
	}
	[[gnu::format(printf, 1, 2)]] static inline void warn(const char format[], ...) {
		va_list args;
		va_start(args, format);
		__android_log_vprint(ANDROID_LOG_WARN, "WaydroidHelper", format, args);
		va_end(args);
	}
	[[gnu::format(printf, 1, 2)]] static inline void info(const char format[], ...) {
		va_list args;
		va_start(args, format);
		__android_log_vprint(ANDROID_LOG_INFO, "WaydroidHelper", format, args);
		va_end(args);
	}
	[[gnu::format(printf, 1, 2)]] static inline void debug(const char format[], ...) {
		va_list args;
		va_start(args, format);
		__android_log_vprint(ANDROID_LOG_DEBUG, "WaydroidHelper", format, args);
		va_end(args);
	}
} logger;
