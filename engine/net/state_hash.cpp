#include "net/state_hash.h"

#include <algorithm>

namespace mvp::net {

namespace {

using u64 = std::uint64_t;
using u32 = std::uint32_t;

constexpr u64 P1 = 0x9E3779B185EBCA87ull;
constexpr u64 P2 = 0xC2B2AE3D27D4EB4Full;
constexpr u64 P3 = 0x165667B19E3779F9ull;
constexpr u64 P4 = 0x85EBCA77C2B2AE63ull;
constexpr u64 P5 = 0x27D4EB2F165667C5ull;

inline u64 rotl(u64 x, int r) { return (x << r) | (x >> (64 - r)); }
// Little-endian loads (the algorithm's definition), independent of the host.
inline u64 le64(const std::uint8_t* p) {
  u64 v = 0;
  for (int k = 7; k >= 0; --k) v = (v << 8) | p[k];
  return v;
}
inline u32 le32(const std::uint8_t* p) {
  return static_cast<u32>(p[0]) | static_cast<u32>(p[1]) << 8 | static_cast<u32>(p[2]) << 16 |
         static_cast<u32>(p[3]) << 24;
}
inline u64 round(u64 acc, u64 input) {
  acc += input * P2;
  acc = rotl(acc, 31);
  return acc * P1;
}
inline u64 merge(u64 acc, u64 v) {
  acc ^= round(0, v);
  return acc * P1 + P4;
}

}  // namespace

u64 xxh64(const void* data, std::size_t size, u64 seed) {
  const std::uint8_t* p = static_cast<const std::uint8_t*>(data);
  const std::uint8_t* end = p + size;
  u64 h;
  if (size >= 32) {
    u64 v1 = seed + P1 + P2, v2 = seed + P2, v3 = seed, v4 = seed - P1;
    const std::uint8_t* limit = end - 32;
    do {
      v1 = round(v1, le64(p));
      v2 = round(v2, le64(p + 8));
      v3 = round(v3, le64(p + 16));
      v4 = round(v4, le64(p + 24));
      p += 32;
    } while (p <= limit);
    h = rotl(v1, 1) + rotl(v2, 7) + rotl(v3, 12) + rotl(v4, 18);
    h = merge(h, v1);
    h = merge(h, v2);
    h = merge(h, v3);
    h = merge(h, v4);
  } else {
    h = seed + P5;
  }
  h += static_cast<u64>(size);
  while (end - p >= 8) {
    h ^= round(0, le64(p));
    h = rotl(h, 27) * P1 + P4;
    p += 8;
  }
  if (end - p >= 4) {
    h ^= static_cast<u64>(le32(p)) * P1;
    h = rotl(h, 23) * P2 + P3;
    p += 4;
  }
  while (p < end) {
    h ^= static_cast<u64>(*p) * P5;
    h = rotl(h, 11) * P1;
    ++p;
  }
  h ^= h >> 33;
  h *= P2;
  h ^= h >> 29;
  h *= P3;
  h ^= h >> 32;
  return h;
}

std::pair<std::size_t, std::size_t> StateHasher::slice(std::uint32_t s, std::size_t size) const {
  std::size_t per = (size + k_ - 1) / k_;
  per = (per + 63) & ~static_cast<std::size_t>(63);
  const std::size_t b = std::min(size, static_cast<std::size_t>(s) * per);
  const std::size_t e = std::min(size, b + per);
  return {b, e};
}

std::optional<u64> StateHasher::at_frame(u64 frame, const std::uint8_t* mem, std::size_t size, u64 ticks) {
  const u32 s = static_cast<u32>(frame % k_);
  if (s == 0) {
    h_ = 0;
    cur_.clear();
  }
  const auto [b, e] = slice(s, size);
  std::uint8_t t[16];
  for (int k = 0; k < 8; ++k) t[k] = static_cast<std::uint8_t>(frame >> (8 * k));
  for (int k = 0; k < 8; ++k) t[8 + k] = static_cast<std::uint8_t>(ticks >> (8 * k));
  const u64 sh = xxh64(mem + b, e - b, xxh64(t, sizeof t));
  cur_.push_back(sh);
  std::uint8_t c[16];  // chain: the window hash so far, then this slice's
  for (int k = 0; k < 8; ++k) c[k] = static_cast<std::uint8_t>(h_ >> (8 * k));
  for (int k = 0; k < 8; ++k) c[8 + k] = static_cast<std::uint8_t>(sh >> (8 * k));
  h_ = xxh64(c, sizeof c);
  if (s != k_ - 1) return std::nullopt;
  last_ = cur_;
  return h_;
}

}  // namespace mvp::net
