#pragma once

#define SPDLOG_DEBUG_ON
#include <SDL.h>
#include <SpdLog\spdlog.h>
#include "ErrorContext.h"

#define ERRASSERT(condition, msg, ...) \
	 do { if (!(condition)) Blz::Err::ErrorReport(#condition, __func__, __FILE__, __LINE__, msg, __VA_ARGS__); } while (0)

namespace Blz
{
	namespace Err
	{
		template<typename... ArgTypes>
		inline void ErrorReport(const char* condition, const char* functionName, const char* file, int32 lineNumber, const Blz::string& c_errMessage, ArgTypes... args)
		{
			//Create console object with spdlog
			auto console = spdlog::stdout_color_mt("console");
			//Controls how message is displayed. Different formatters % display different things. https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
			console->set_pattern("  %l: %v");

			Blz::string combinedErrMessages("Assertion failed: " + Blz::string(condition) + " \n         " + c_errMessage);

			ErrorContext::LogContext();

			console->error(combinedErrMessages.c_str(), args...);
			console->info("In function {}() \n        {}: {}", functionName, file, lineNumber);
			SDL_Quit();
			exit(0);
		}
	}
}