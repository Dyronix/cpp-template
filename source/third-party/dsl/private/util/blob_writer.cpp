#include "util/blob_writer.h"

namespace dsl
{
  namespace memory
  {
    //-------------------------------------------------------------------------
    blob_writer::blob_writer(memory::blob& b)
        : blob_writer(b, 0_bytes)
    {
    }
    //-------------------------------------------------------------------------
    blob_writer::blob_writer(memory::blob& b, s64 offset)
        : m_blob(&b)
        , m_write_offset(offset)
    {
    }

    //-------------------------------------------------------------------------
    void blob_writer::write(const void* in_data, const memory_size& in_size)
    {
      m_blob->write(in_data, in_size, m_write_offset);
      m_write_offset += in_size;
    }

    //-------------------------------------------------------------------------
    s64 blob_writer::write_offset() const
    {
      return m_write_offset;
    }

    namespace writer
    {
      //-------------------------------------------------------------------------
      void write(memory::blob& b, const void* in_data, const memory_size& in_size)
      {
        blob_writer writer(b);
        writer.write(in_data, in_size);
      }

      //-------------------------------------------------------------------------
      void write(memory::blob& b, const void* in_data, const memory_size& in_size, const memory_size& in_offset)
      {
        blob_writer writer(b, in_offset);
        writer.write(in_data, in_size);
      }
    } // namespace writer
  }   // namespace memory
} // namespace dsl