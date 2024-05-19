#include "util/blob.h"
#include "util/blob_writer.h"
#include "util/assert.h"
#include "util/log.h"

#include <memory>

namespace dsl
{
  namespace memory
  {
    //-------------------------------------------------------------------------
    void blob::copy(const blob& src, blob& dst)
    {
      if(src.size() == 0)
      {
        log::warn("size of src == 0, nothing to copy ...");

        return;
      }

      DSL_ASSERT_X(dst.size() != 0, "dst blob size is 0");
      DSL_ASSERT_X(dst.size() >= src.size(), "dst size is smaller than src size");

      std::memcpy(dst.m_data.get(), src.m_data.get(), src.size());
      std::memcpy(&dst.m_data_size, &src.m_data_size, sizeof(memory_size));
    }
    //-------------------------------------------------------------------------
    void blob::copy(const blob& src, void* dst)
    {
      if(src.size() == 0)
      {
        log::warn("size of src == 0, nothing to copy ...");

        return;
      }

      DSL_ASSERT_X(dst != nullptr, "dst is nullptr");

      std::memcpy(dst, src.m_data.get(), src.size());
    }
    //-------------------------------------------------------------------------
    void blob::copy(void* src, const memory_size& size, blob& dst)
    {
      DSL_ASSERT_X(src != nullptr, "src is nullptr");
      DSL_ASSERT_X(size != 0, "size is 0");

      DSL_ASSERT_X(dst.size() != 0, "dst size is 0");
      DSL_ASSERT_X(dst.size() >= size, "dst size is not big enough to receive copy");

      std::memcpy(dst.m_data.get(), src, size);
      std::memcpy(&dst.m_data_size, &size, sizeof(memory_size));
    }

    //-------------------------------------------------------------------------
    blob::blob()
        : m_data(nullptr)
        , m_data_size(0_bytes)
    {
    }

    //-------------------------------------------------------------------------
    blob::blob(blob&& other) noexcept 
        : m_data(std::exchange(other.m_data, nullptr))
        , m_data_size(std::exchange(other.m_data_size, 0_bytes))
    {
    }
    //-------------------------------------------------------------------------
    blob::blob(std::unique_ptr<std::byte[]> data, const memory_size& size)
        : m_data(std::exchange(data, nullptr))
        , m_data_size(size)
    {
    }

    //-------------------------------------------------------------------------
    blob::~blob() = default;

    //-------------------------------------------------------------------------
    blob& blob::operator=(blob&& other) noexcept
    {
      // Guard self assignment
      DSL_ASSERT_X(this != &other, "can't move to yourself");

      m_data = std::exchange(other.m_data, nullptr);
      m_data_size = std::exchange(other.m_data_size, 0_bytes);

      return *this;
    }

    //-------------------------------------------------------------------------
    blob::operator bool() const
    {
      return m_data.get() != nullptr;
    }

    //-------------------------------------------------------------------------
    std::byte& blob::operator[](s32 index)
    {
      return m_data.get()[index];
    }
    //-------------------------------------------------------------------------
    const std::byte& blob::operator[](s32 index) const
    {
      return (static_cast<const std::byte*>(m_data.get()))[index];
    }

    //-------------------------------------------------------------------------
    void blob::allocate(const memory_size& in_size)
    {
      release();

      if(in_size == 0)
      {
        log::warn("allocation of size equal to 0");

        return;
      }

      m_data = std::make_unique<std::byte[]>(static_cast<s32>(in_size)); // NOLINT(modernize-avoid-c-arrays)
      m_data_size = in_size;
    }
    //-------------------------------------------------------------------------
    void blob::release()
    {
      m_data.reset();
      m_data_size = 0_bytes;
    }
    //-------------------------------------------------------------------------
    void blob::zero_initialize()
    {
      if(m_data)
      {
        std::memset(m_data.get(), 0, size());
      }
    }

    //-------------------------------------------------------------------------
    std::byte* blob::read_bytes(std::byte* dst, const memory_size& in_size, const memory_size& in_offset)
    {
      DSL_ASSERT_X(in_offset + in_size <= size(), "amount to read out of bounds");

      std::memcpy(dst, static_cast<std::byte*>(m_data.get()) + in_offset, in_size);
      return dst;
    }

    //-------------------------------------------------------------------------
    const std::byte* blob::read_bytes(std::byte* dst, const memory_size& in_size, const memory_size& in_offset) const
    {
      DSL_ASSERT_X(in_offset + in_size <= size(), "amount of read out of bounds");

      std::memcpy(dst, static_cast<const std::byte*>(m_data.get()) + in_offset, in_size);
      return dst;
    }

    //-------------------------------------------------------------------------
    void blob::write(const void* in_data, const memory_size& in_size, const memory_size& in_offset)
    {
      DSL_ASSERT_X(in_offset + in_size <= size(), "amount for write out of bounds");

      std::memcpy(static_cast<std::byte*>(m_data.get()) + in_offset, in_data, in_size);
    }

    //-------------------------------------------------------------------------
    std::byte* blob::data()
    {
      return m_data.get();
    }
    //-------------------------------------------------------------------------
    const std::byte* blob::data() const
    {
      return m_data.get();
    }

    //-------------------------------------------------------------------------
    memory_size blob::size() const
    {
      return m_data_size;
    }

    //-------------------------------------------------------------------------
    blob make_blob(const std::byte* in_data, const memory_size& in_size)
    {
      blob blob;

      blob.allocate(in_size);
      blob.zero_initialize();

      if(in_data != nullptr)
      {
        writer::write(blob, in_data, in_size);
      }

      return blob;
    }
  } // namespace memory
} // namespace dsl