#pragma once

#include "util/memory_size.h"

#include <memory>

namespace dsl
{
  namespace memory
  {

    class blob;

    // Similar design of string_view -> string.
    // A blob view has a const view over a blob
    // It doesn't own the blob but can provide an interface into
    // the data of a blob

    class blob_view
    {
    public:
      blob_view();
      explicit blob_view(const blob& blob);

      const std::byte* data() const;
      memory_size size() const;

      template <typename T>
      const T* data_as() const
      {
        return reinterpret_cast<T*>(data());
      }

    private:
      const std::byte* m_data;
      memory_size m_size;
    };
  } // namespace memory
} // namespace dsl