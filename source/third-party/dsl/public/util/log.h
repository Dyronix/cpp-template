#pragma once

#define FMT_HEADER_ONLY
#include <fmt/core.h>

namespace dsl
{
	namespace log
	{
		constexpr auto green = "\033[32m";
		constexpr auto magenta = "\033[35m";
		constexpr auto red = "\033[31m";
		constexpr auto yellow = "\033[33m";
		constexpr auto reset = "\033[0m";

		template<typename FormatString, typename... Args>
		inline void info(const FormatString& format, const Args&... args)
		{
			printf("[%sinfo%s] ", green, reset);
			fmt::print(fmt::runtime(format), args...);
			printf("\n");
		}

		template<typename FormatString, typename... Args>
		void warn(const FormatString& format, const Args&... args)
		{
			printf("[%swarn%s] ", magenta, reset);
			fmt::print(fmt::runtime(format), args...);
			printf("\n");
		}

		template<typename FormatString, typename... Args>
		void error(const FormatString& format, const Args&... args)
		{
			printf("[%serror%s] ", red, reset);
			fmt::print(fmt::runtime(format), args...);
			printf("\n");
		}

		template<typename FormatString, typename... Args>
		void critical(const FormatString& format, const Args&... args)
		{
			printf("[%serror%s] ", red, reset);
			fmt::print(fmt::runtime(format), args...);
			printf("\n");
		}
	}
}
