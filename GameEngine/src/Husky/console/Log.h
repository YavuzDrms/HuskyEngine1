#ifndef LOG_H
#define LOG_H

#include <vector>
#include <chrono>
#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Husky
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define HUSKY_CORE_TRACE(...)    ::Husky::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HUSKY_CORE_INFO(...)     ::Husky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HUSKY_CORE_WARN(...)     ::Husky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HUSKY_CORE_ERROR(...)    ::Husky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HUSKY_CORE_CRITICAL(...) ::Husky::Log::GetCoreLogger()->critical(__VA_ARGS__)
// Client log macros
#define HUSKY_TRACE(...)         ::Husky::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HUSKY_INFO(...)          ::Husky::Log::GetClientLogger()->info(__VA_ARGS__)
#define HUSKY_WARN(...)          ::Husky::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HUSKY_ERROR(...)         ::Husky::Log::GetClientLogger()->error(__VA_ARGS__)
#define HUSKY_CRITICAL(...)      ::Husky::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif // LOG_H