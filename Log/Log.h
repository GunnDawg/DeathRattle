#pragma once
#include <memory>
#include <spdlog/spdlog.h>

namespace Gunn
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetFileLogger() { return sFileLogger; }

	private:
		inline static std::shared_ptr<spdlog::logger> sCoreLogger;
		inline static std::shared_ptr<spdlog::logger> sFileLogger;
	};
}

#ifdef GUNN_DEBUG
#define GUNN_CORE_TRACE(...)   Gunn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GUNN_CORE_INFO(...)    Gunn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GUNN_CORE_WARN(...)    Gunn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GUNN_CORE_ERROR(...)   Gunn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GUNN_CORE_FATAL(...)   Gunn::Log::GetCoreLogger()->critical(__VA_ARGS__)
#else
#define GUNN_CORE_TRACE(...)   //Gunn::Log::GetFileLogger()->trace(__VA_ARGS__)
#define GUNN_CORE_INFO(...)    //Gunn::Log::GetFileLogger()->info(__VA_ARGS__)
#define GUNN_CORE_WARN(...)    //Gunn::Log::GetFileLogger()->warn(__VA_ARGS__)
#define GUNN_CORE_ERROR(...)   //Gunn::Log::GetFileLogger()->error(__VA_ARGS__)
#define GUNN_CORE_FATAL(...)   //Gunn::Log::GetFileLogger()->critical(__VA_ARGS__)
#endif