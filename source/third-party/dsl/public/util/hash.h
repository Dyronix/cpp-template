#pragma once

#include <string>

// Hashers for view descriptions.
namespace std
{
    // Source: https://stackoverflow.com/questions/2590677/how-do-i-combine-hash-values-in-c0x
    template <typename T> inline void hash_combine(size_t& seed, const T& v)
    {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
} // namespace std