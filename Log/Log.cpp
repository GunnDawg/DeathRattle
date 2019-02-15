#include "Log.h"

namespace Gunn
{
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("Gunngine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Client");
		s_ClientLogger->set_level(spdlog::level::trace);

		sFileLogger = spdlog::basic_logger_mt("Log Info", "log.txt");
		sFileLogger->set_level(spdlog::level::trace);
	}
}