// SHA-1 (FIPS 180-4). Used to identify the player's disc and DOL, never for security.
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>

namespace mvp {

class Sha1 {
 public:
  Sha1();
  void update(const void* data, std::size_t size);
  std::array<std::uint8_t, 20> finish();

  static std::string hex(std::span<const std::uint8_t> bytes);
  static std::string of(const void* data, std::size_t size);  // hex digest

 private:
  void block(const std::uint8_t* p);
  std::uint32_t h_[5];
  std::uint8_t buf_[64];
  std::size_t used_ = 0;
  std::uint64_t total_ = 0;
};

}  // namespace mvp
