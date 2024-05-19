#pragma once

#include "util/blob.h"
#include "util/memory_size.h"

#include <memory>

namespace dsl
{
  namespace memory
  {
    class blob_reader
    {
    public:
      explicit blob_reader(const memory::blob& b);
      blob_reader(const memory::blob& b, const memory_size& offset);

      template <typename T>
      T read();

      std::byte* read(const memory_size& bytes_to_read);

    private:
      const memory::blob* m_blob;
      memory_size m_read_offset;
    };

    //-------------------------------------------------------------------------
    template <typename T>
    T memory::blob_reader::read()
    {
      T value = m_blob->read<T>(m_read_offset);
      m_read_offset += sizeof(T);
      return value;
    }

    namespace reader
    {
      //-------------------------------------------------------------------------
      template <typename T>
      T read(const memory::blob& b)
      {
        blob_reader reader(b);
        return reader.read<T>();
      }
      //-------------------------------------------------------------------------
      template <typename T>
      T read(const memory::blob& b, const memory_size& offset)
      {
        blob_reader reader(b, offset);
        return reader.read<T>();
      }

      //-------------------------------------------------------------------------
      std::byte* read(const memory::blob& b, const memory_size& bytes_to_read, const memory_size& offset);
    } // namespace reader
  }   // namespace memory
} // namespace dsl