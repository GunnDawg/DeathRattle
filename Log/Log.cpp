#include "Log.h"

namespace Gunn
{
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		sCoreLogger = spdlog::stdout_color_mt("Gunngine");
		sCoreLogger->set_level(spdlog::level::trace);

		sFileLogger = spdlog::basic_logger_mt("Log Info", "log.txt");
		sFileLogger->set_level(spdlog::level::trace);
	}
}