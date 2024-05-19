#include "util/blob_reader.h"

namespace dsl
{
  namespace memory
  {
    //-------------------------------------------------------------------------
    blob_reader::blob_reader(const memory::blob& b)
        : blob_reader(b, 0_bytes)
    {
    }
    //-------------------------------------------------------------------------
    blob_reader::blob_reader(const memory::blob& b, const memory_size& offset)
        : m_blob(&b)
        , m_read_offset(offset)
    {
    }

    //-------------------------------------------------------------------------
    std::byte* blob_reader::read(const memory_size& bytes_to_read)
    {
      std::byte* dst = new std::byte[bytes_to_read];

      m_blob->read_bytes(dst, bytes_to_read, m_read_offset);
      m_read_offset += bytes_to_read;

      return dst;
    }

    namespace reader
    {
      //-------------------------------------------------------------------------
      std::byte* read(const memory::blob& b, const memory_size& bytes_to_read, const memory_size& offset)
      {
        blob_reader reader(b, offset);
        return reader.read(bytes_to_read);
      }
    } // namespace reader
  }   // namespace memory
} // namespace dsl