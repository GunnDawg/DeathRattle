#pragma once
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Gunn
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		inline static std::shared_ptr<spdlog::logger> s_CoreLogger;
		inline static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#ifdef GUNN_DEBUG
#define GUNN_CORE_TRACE(...)   Gunn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GUNN_CORE_INFO(...)    Gunn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GUNN_CORE_WARN(...)    Gunn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GUNN_CORE_ERROR(...)   Gunn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GUNN_CORE_FATAL(...)   Gunn::Log::GetCoreLogger()->critical(__VA_ARGS__)
#else
#define GUNN_CORE_TRACE(...)
#define GUNN_CORE_INFO(...) 
#define GUNN_CORE_WARN(...) 
#define GUNN_CORE_ERROR(...)
#define GUNN_CORE_FATAL(...)
#endif