#include "util/string_op.h"
#include "util/log.h"

namespace dsl
{
    namespace string_operations
    {
        std::string to_multibyte(const tchar* wide_character_buffer, size_t size)
        {
            std::string buffer;

            // Convert wide character string to multi byte character string.
            // size_t converted_chars => The amount of converted characters.
            // 0 terminate the string afterwards.
            size_t converted_chars = 0;
            auto result = wcstombs_s(&converted_chars, buffer.data(), size, wide_character_buffer, size);
            if (result != 0)
            {
                dsl::log::error("Failed to convert wide character string to multi byte character string.");
                return std::string("Invalid String");
            }

            // Add null terminator at the end
            buffer[converted_chars] = '\0';

            return std::string(buffer.data(), static_cast<size_t>(converted_chars));
        }
    }
}