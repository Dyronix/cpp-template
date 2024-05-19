#pragma once

#include "util/types.h"

namespace dsl
{
    constexpr s64 KiloByteMultiple = 1000;
    constexpr s64 MegaByteMultiple = KiloByteMultiple * 1000;
    constexpr s64 GigaByteMultiple = MegaByteMultiple * 1000;

    constexpr s64 KibiByteMultiple = 1024;
    constexpr s64 MibiByteMultiple = KibiByteMultiple * 1024;
    constexpr s64 GibiByteMultiple = MibiByteMultiple * 1024;

    class memory_size
    {
      public:
        constexpr memory_size() : m_size_in_bytes(0)
        {
        }

        constexpr memory_size(s64 size_in_bytes) : m_size_in_bytes(size_in_bytes)
        {
        }

        constexpr operator s64() const
        {
            return size_in_bytes();
        }
        constexpr s64 size_in_bytes() const
        {
            return m_size_in_bytes;
        }

        constexpr memory_size operator+(s64 bytes) const
        {
            return memory_size(m_size_in_bytes + bytes);
        }
        constexpr memory_size& operator+=(s64 bytes)
        {
            m_size_in_bytes += bytes;
            return *this;
        }

        constexpr memory_size operator-(s64 bytes) const
        {
            return memory_size(m_size_in_bytes - bytes);
        }
        constexpr memory_size operator-=(s64 bytes)
        {
            m_size_in_bytes -= bytes;
            return *this;
        }

        constexpr s64 size_in_kb() const
        {
            return size_in_bytes() / KiloByteMultiple;
        }
        constexpr s64 size_in_mb() const
        {
            return size_in_bytes() / MegaByteMultiple;
        }
        constexpr s64 size_in_gb() const
        {
            return size_in_bytes() / GigaByteMultiple;
        }
        constexpr s64 size_in_kib() const
        {
            return size_in_bytes() / KibiByteMultiple;
        }
        constexpr s64 size_in_mib() const
        {
            return size_in_bytes() / MibiByteMultiple;
        }
        constexpr s64 size_in_gib() const
        {
            return size_in_bytes() / GibiByteMultiple;
        }

      private:
        s64 m_size_in_bytes;
    };
} // namespace dsl

constexpr dsl::memory_size operator"" _bytes(unsigned long long bytes)
{
    return dsl::memory_size((s64)bytes);
}
constexpr dsl::memory_size operator"" _kb(unsigned long long bytes)
{
    return dsl::memory_size((s64)bytes * dsl::KiloByteMultiple);
}
constexpr dsl::memory_size operator"" _mb(unsigned long long bytes)
{
    return dsl::memory_size((s64)bytes * dsl::MegaByteMultiple);
}
constexpr dsl::memory_size operator"" _gb(unsigned long long bytes)
{
    return dsl::memory_size((s64)bytes * dsl::GigaByteMultiple);
}

constexpr dsl::memory_size operator"" _kib(unsigned long long bytes)
{
    return dsl::memory_size((s64)bytes * dsl::KibiByteMultiple);
}
constexpr dsl::memory_size operator"" _mib(unsigned long long bytes)
{
    return dsl::memory_size((s64)bytes * dsl::MibiByteMultiple);
}
constexpr dsl::memory_size operator"" _gib(unsigned long long bytes)
{
    return dsl::memory_size((s64)bytes * dsl::GibiByteMultiple);
}