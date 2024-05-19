#pragma once

#include "util/types.h"

#include <string>

namespace dsl
{
    namespace string_operations
    {
        std::string to_multibyte(const tchar* wide_character_buffer, size_t size);
    }
}