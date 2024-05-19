#pragma once

#include "util/memory_size.h"
#include "util/types.h"

#include <memory>

namespace dsl
{
  namespace memory
  {
    class blob
    {
    public:
      static void copy(const blob& src, blob& dst);
      static void copy(const blob& src, void* dst);
      static void copy(void* src, const memory_size& size, blob& dst);

      blob();
      blob(const blob& other) = delete;
      blob(blob&& other) noexcept;
      explicit blob(std::unique_ptr<std::byte[]> data, const memory_size& size);
      ~blob();

      blob& operator=(const blob& other) = delete;
      blob& operator=(blob&& other) noexcept;

      explicit operator bool() const;

      std::byte& operator[](s32 index);
      const std::byte& operator[](s32 index) const;

      void allocate(const memory_size& in_size);
      void release();
      void zero_initialize();

      std::byte* data();
      const std::byte* data() const;

      memory_size size() const;

      template <typename T>
      T* data_as();
      template <typename T>
      const T* data_as() const;

      template <typename T>
      T& read(const memory_size& offset = 0_bytes);
      template <typename T>
      const T& read(const memory_size& offset = 0_bytes) const;

    private:
      friend class blob_writer;
      friend class blob_reader;

      std::byte* read_bytes(std::byte* dst, const memory_size& in_size, const memory_size& in_offset);
      const std::byte* read_bytes(std::byte* dst, const memory_size& in_size, const memory_size& in_offset) const;

      void write(const void* in_data, const memory_size& in_size, const memory_size& in_offset = 0_bytes);

      std::unique_ptr<std::byte[]> m_data;
      memory_size m_data_size;
    };

    //-------------------------------------------------------------------------
    blob make_blob(const std::byte* in_data, const memory_size& in_size);
    //-------------------------------------------------------------------------
    template <typename T>
    blob make_blob(const T* data, s32 num)
    {
      return make_blob(reinterpret_cast<const std::byte*>(data), memory_size(sizeof(T) * num));
    }

    //-------------------------------------------------------------------------
    template <typename T>
    T& blob::read(const memory_size& offset /*= 0*/)
    {
      T* data = reinterpret_cast<T*>(m_data.get() + offset);
      return *data;
    }

    //-------------------------------------------------------------------------
    template <typename T>
    const T& blob::read(const memory_size& offset) const
    {
      return *(T*)(m_data.get() + offset);
    }

    //-------------------------------------------------------------------------
    template <typename T>
    T* blob::data_as()
    {
      return reinterpret_cast<T*>(m_data.get());
    }
    //-------------------------------------------------------------------------
    template <typename T>
    const T* blob::data_as() const
    {
      return reinterpret_cast<const T*>(m_data.get());
    }
  } // namespace memory
} // namespace dsl