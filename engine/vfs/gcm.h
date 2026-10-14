// GameCube disc (GCM) structure: disc header (boot.bin), BI2, FST, and file access.
#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "vfs/source.h"

namespace mvp::vfs {

struct FstEntry {
  std::string path;  // "/data/ovlay.big"; directories end without a slash
  bool is_dir = false;
  std::uint32_t offset = 0;  // file: disc offset
  std::uint32_t size = 0;    // file: byte size
};

class Gcm {
 public:
  // Parses the disc header and the FST. Returns nullopt with a reason on any
  // inconsistency (bad magic, FST outside the disc, malformed entries).
  static std::optional<Gcm> open(Source& disc, std::string* error = nullptr);

  static constexpr std::uint32_t kDiscMagic = 0xC2339F3D;  // at 0x1C
  static constexpr std::size_t kBootSize = 0x440;
  static constexpr std::size_t kBi2Size = 0x2000;

  std::string game_id() const;  // 6 characters, e.g. "GV4E69"
  std::uint8_t disc_number() const { return boot_[6]; }
  std::uint8_t revision() const { return boot_[7]; }
  std::string title() const;
  std::uint32_t dol_offset() const { return dol_off_; }
  std::uint32_t fst_offset() const { return fst_off_; }
  std::uint32_t fst_size() const { return fst_size_; }
  std::uint32_t fst_max_size() const { return fst_max_; }
  const std::vector<std::uint8_t>& boot() const { return boot_; }
  const std::vector<std::uint8_t>& bi2() const { return bi2_; }
  const std::vector<std::uint8_t>& fst_bytes() const { return fst_; }
  const std::vector<FstEntry>& entries() const { return entries_; }

  const FstEntry* find(const std::string& path) const;  // case-insensitive, like the SDK
  std::optional<std::vector<std::uint8_t>> read_file(Source& disc, const std::string& path) const;

 private:
  std::vector<std::uint8_t> boot_, bi2_, fst_;
  std::uint32_t dol_off_ = 0, fst_off_ = 0, fst_size_ = 0, fst_max_ = 0;
  std::vector<FstEntry> entries_;
};

}  // namespace mvp::vfs
