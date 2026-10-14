#include "common/sha1.h"

#include <cstring>

namespace mvp {

namespace {
inline std::uint32_t rol(std::uint32_t v, int n) { return (v << n) | (v >> (32 - n)); }
}  // namespace

Sha1::Sha1() : h_{0x67452301u, 0xEFCDAB89u, 0x98BADCFEu, 0x10325476u, 0xC3D2E1F0u} {}

void Sha1::block(const std::uint8_t* p) {
  std::uint32_t w[80];
  for (int i = 0; i < 16; ++i)
    w[i] = (std::uint32_t(p[4 * i]) << 24) | (std::uint32_t(p[4 * i + 1]) << 16) |
           (std::uint32_t(p[4 * i + 2]) << 8) | std::uint32_t(p[4 * i + 3]);
  for (int i = 16; i < 80; ++i) w[i] = rol(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
  std::uint32_t a = h_[0], b = h_[1], c = h_[2], d = h_[3], e = h_[4];
  for (int i = 0; i < 80; ++i) {
    std::uint32_t f, k;
    if (i < 20) {
      f = (b & c) | (~b & d);
      k = 0x5A827999u;
    } else if (i < 40) {
      f = b ^ c ^ d;
      k = 0x6ED9EBA1u;
    } else if (i < 60) {
      f = (b & c) | (b & d) | (c & d);
      k = 0x8F1BBCDCu;
    } else {
      f = b ^ c ^ d;
      k = 0xCA62C1D6u;
    }
    std::uint32_t t = rol(a, 5) + f + e + k + w[i];
    e = d;
    d = c;
    c = rol(b, 30);
    b = a;
    a = t;
  }
  h_[0] += a;
  h_[1] += b;
  h_[2] += c;
  h_[3] += d;
  h_[4] += e;
}

void Sha1::update(const void* data, std::size_t size) {
  const std::uint8_t* p = static_cast<const std::uint8_t*>(data);
  total_ += size;
  if (used_) {
    std::size_t take = 64 - used_ < size ? 64 - used_ : size;
    std::memcpy(buf_ + used_, p, take);
    used_ += take;
    p += take;
    size -= take;
    if (used_ == 64) {
      block(buf_);
      used_ = 0;
    }
  }
  while (size >= 64) {
    block(p);
    p += 64;
    size -= 64;
  }
  if (size) {
    std::memcpy(buf_, p, size);
    used_ = size;
  }
}

std::array<std::uint8_t, 20> Sha1::finish() {
  std::uint64_t bits = total_ * 8;
  std::uint8_t pad = 0x80;
  update(&pad, 1);
  std::uint8_t zero = 0;
  while (used_ != 56) update(&zero, 1);
  std::uint8_t len[8];
  for (int i = 0; i < 8; ++i) len[i] = std::uint8_t(bits >> (56 - 8 * i));
  update(len, 8);
  std::array<std::uint8_t, 20> out{};
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 4; ++j) out[4 * i + j] = std::uint8_t(h_[i] >> (24 - 8 * j));
  return out;
}

std::string Sha1::hex(std::span<const std::uint8_t> bytes) {
  static const char digits[] = "0123456789abcdef";
  std::string s;
  s.reserve(bytes.size() * 2);
  for (std::uint8_t b : bytes) {
    s.push_back(digits[b >> 4]);
    s.push_back(digits[b & 15]);
  }
  return s;
}

std::string Sha1::of(const void* data, std::size_t size) {
  Sha1 s;
  s.update(data, size);
  auto d = s.finish();
  return hex(d);
}

}  // namespace mvp
