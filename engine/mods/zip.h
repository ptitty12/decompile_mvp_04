// Reading a pack's .zip (docs/MODDING.md §2): the central directory, stored and
// deflated entries (RFC 1951 inflate, written here), CRC-32 checked. Enough for
// the zips every common tool writes; zip64, encryption and other methods are
// refused with a reason.
#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace mvp::mods {

std::uint32_t crc32(const std::uint8_t* data, std::size_t size, std::uint32_t crc = 0);

// Raw deflate data -> bytes (at most `limit` bytes of output).
std::optional<std::vector<std::uint8_t>> inflate(const std::uint8_t* data, std::size_t size, std::size_t limit,
                                                 std::string* error);

struct ZipEntry {
  std::string name;  // as stored ('/' separators)
  std::uint16_t method = 0;
  std::uint32_t crc = 0;
  std::uint64_t compressed = 0, size = 0;
  std::uint64_t local_offset = 0;
  bool is_dir() const { return !name.empty() && name.back() == '/'; }
};

class ZipArchive {
 public:
  // True if the bytes end with a zip end-of-central-directory record.
  static bool is_zip(const std::vector<std::uint8_t>& bytes);
  static std::optional<ZipArchive> open(std::vector<std::uint8_t> bytes, std::string* error);
  const std::vector<ZipEntry>& entries() const { return entries_; }
  std::optional<std::vector<std::uint8_t>> read(const ZipEntry& e, std::string* error) const;

 private:
  std::vector<std::uint8_t> bytes_;
  std::vector<ZipEntry> entries_;
  std::uint64_t concat_ = 0;  // bytes prepended to the archive
};

}  // namespace mvp::mods
