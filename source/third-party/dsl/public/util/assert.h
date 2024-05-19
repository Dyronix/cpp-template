#pragma once

#include "util/log.h"

namespace dsl
{
		template<typename FormatString, typename... Args>
		void dsl_assert(const FormatString& format, const Args&... args)
		{
      log::critical(format, std::forward<Args>(args));
    }
} // namespace dsl

#ifdef DSL_ENABLE_ASSERTS
  #define DSL_ASSERT(...)          \
    dsl::dsl_assert(__VA_ARGS__); \
    while(true)                     \
    {                               \
      DEBUG_BREAK();                \
    }
  #define DSL_ASSERT_X(cond, ...)  \
    if(!(cond))                     \
    {                               \
      DSL_ASSERT(__VA_ARGS__);     \
    }
#else
  #define DSL_ASSERT(...)
  #define DSL_ASSERT_X(cond, ...)
#endif