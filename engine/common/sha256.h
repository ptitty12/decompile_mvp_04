// SHA-256 (FIPS 180-4). Identifies roster packs, pack sets and patched game data
// (docs/MODDING.md §10) and the netplay pack-set field; never used for security.
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>

namespace mvp {

class Sha256 {
 public:
  Sha256();
  void update(const void* data, std::size_t size);
  std::array<std::uint8_t, 32> finish();

  static std::string hex(std::span<const std::uint8_t> bytes);
  static std::string of(const void* data, std::size_t size);  // hex digest
  static std::string of(const std::string& s) { return of(s.data(), s.size()); }

 private:
  void block(const std::uint8_t* p);
  std::uint32_t h_[8];
  std::uint8_t buf_[64];
  std::size_t used_ = 0;
  std::uint64_t total_ = 0;
};

}  // namespace mvp
