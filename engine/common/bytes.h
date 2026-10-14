// Big-endian byte access. Guest memory and every disc structure are big-endian (D8).
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace mvp {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using s8 = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

inline u16 be16(const void* p) {
  const u8* b = static_cast<const u8*>(p);
  return static_cast<u16>((b[0] << 8) | b[1]);
}
inline u32 be32(const void* p) {
  const u8* b = static_cast<const u8*>(p);
  return (u32(b[0]) << 24) | (u32(b[1]) << 16) | (u32(b[2]) << 8) | u32(b[3]);
}
inline u64 be64(const void* p) {
  const u8* b = static_cast<const u8*>(p);
  return (u64(be32(b)) << 32) | be32(b + 4);
}
inline void put_be16(void* p, u16 v) {
  u8* b = static_cast<u8*>(p);
  b[0] = u8(v >> 8);
  b[1] = u8(v);
}
inline void put_be32(void* p, u32 v) {
  u8* b = static_cast<u8*>(p);
  b[0] = u8(v >> 24);
  b[1] = u8(v >> 16);
  b[2] = u8(v >> 8);
  b[3] = u8(v);
}
inline void put_be64(void* p, u64 v) {
  put_be32(p, u32(v >> 32));
  put_be32(static_cast<u8*>(p) + 4, u32(v));
}
inline u32 le32(const void* p) {
  const u8* b = static_cast<const u8*>(p);
  return (u32(b[3]) << 24) | (u32(b[2]) << 16) | (u32(b[1]) << 8) | u32(b[0]);
}

}  // namespace mvp
