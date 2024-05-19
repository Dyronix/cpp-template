#pragma once

#include "util/types.h"

#include <cstddef>

namespace dsl
{
  constexpr void* jump_forward(void* mem, size_t count)
  {
    std::byte* mem_as_bytes = static_cast<std::byte*>(mem);
    mem_as_bytes += count;
    return mem_as_bytes;
  }
  constexpr void* jump_backward(void* mem, size_t count)
  {
    std::byte* mem_as_bytes = static_cast<std::byte*>(mem);
    mem_as_bytes -= count;
    return mem_as_bytes;
  }

  // Example:
  //
  // round up to nearest multiple of 256.
  // We do this by adding 255 and then masking off
  // the lower 2 bytes which store all bits < 256.
  //
  // Suppose byteSize = 300.
  //
  // (300 + 255) & ~255
  // 555 & ~255
  // 0x022B & ~0x00ff
  // 0x022B & 0xff00
  // 0x0200
  // 512

  template <typename T, typename U>
  constexpr T align_up(T addr, U alignment)
  {
    const U mask = alignment - 1;
    return (addr + mask) & ~mask;                                            // NOLINT(hicpp-signed-bitwise)
  }

  template <typename T, typename U>
  constexpr T align_down(T addr, U alignment)
  {
    const U mask = alignment - 1;
    return addr & ~mask;                                                     // NOLINT(hicpp-signed-bitwise)
  }
} // namespace dsl