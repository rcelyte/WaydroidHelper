#pragma once
#include <android/log.h>

[[gnu::format(printf, 2, 0)]] static inline void logLineV(int priority, const char format[], va_list args) {
	__android_log_vprint(priority, "WaydroidHelper|v" VERSION, format, args);
}
[[gnu::format(printf, 1, 2)]] static inline void logLine_crit(const char format[], ...) {va_list args; va_start(args, format); logLineV(ANDROID_LOG_FATAL, format, args); va_end(args);}
[[gnu::format(printf, 1, 2)]] static inline void logLine_err(const char format[], ...) {va_list args; va_start(args, format); logLineV(ANDROID_LOG_ERROR, format, args); va_end(args);}
[[gnu::format(printf, 1, 2)]] static inline void logLine_warn(const char format[], ...) {va_list args; va_start(args, format); logLineV(ANDROID_LOG_WARN, format, args); va_end(args);}
[[gnu::format(printf, 1, 2)]] static inline void logLine_info(const char format[], ...) {va_list args; va_start(args, format); logLineV(ANDROID_LOG_INFO, format, args); va_end(args);}
[[gnu::format(printf, 1, 2)]] static inline void logLine(const char format[], ...) {va_list args; va_start(args, format); logLineV(ANDROID_LOG_DEBUG, format, args); va_end(args);}
