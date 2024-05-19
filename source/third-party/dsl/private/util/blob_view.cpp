#include "util/blob_view.h"
#include "util/blob.h"

namespace dsl
{
  namespace memory
  {
    blob_view::blob_view()
        : m_data(nullptr)
        , m_size(0)
    {
    }

    blob_view::blob_view(const blob& blob)
        : m_data(blob.data())
        , m_size(blob.size())
    {
    }

    const std::byte* blob_view::data() const
    {
      return m_data;
    }

    memory_size blob_view::size() const
    {
      return m_size;
    }
  } // namespace memory
} // namespace dsl