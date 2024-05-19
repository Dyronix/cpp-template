#pragma once

#include "util/blob.h"
#include "util/memory_size.h"
#include "util/types.h"

namespace dsl
{
  namespace memory
  {
    class blob_writer
    {
    public:
      explicit blob_writer(memory::blob& b);
      blob_writer(memory::blob& b, s64 offset);

      template <typename T>
      void write(const T& data);
      void write(const void* in_data, const memory_size& in_size);

      s64 write_offset() const;

    private:
      memory::blob* m_blob;
      memory_size m_write_offset;
    };

    //-------------------------------------------------------------------------
    template <typename T>
    void memory::blob_writer::write(const T& data)
    {
      m_blob->write(&data, sizeof(T), m_write_offset);
      m_write_offset += sizeof(T);
    }

    namespace writer
    {
      //-------------------------------------------------------------------------
      template <typename T>
      void write(memory::blob& b, const T& data)
      {
        blob_writer writer(b);

        writer.write<T>(data);
      }

      void write(memory::blob& b, const void* in_data, const memory_size& in_size);
      void write(memory::blob& b, const void* in_data, const memory_size& in_size, const memory_size& in_offset);
    } // namespace writer
  }   // namespace memory
} // namespace dsl