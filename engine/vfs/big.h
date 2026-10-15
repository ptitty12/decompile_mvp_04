// EA BIGF archives (docs/ROSTERS.md §2.1): the containers of database.big, the
// logos, uniforms, announcer clips and most other game files. The layout is the
// reference tool's (tools/rosters/big.py):
//
//   0x00 "BIGF", u32 LITTLE-endian file size, u32 BE entry count, u32 BE header size
//   0x10 entries: u32 BE payload offset, u32 BE payload size, NUL-terminated name
//   .... "L234" + u32 BE flag (0 raw, 1 RefPack, 2 anims.big, 3 fonts.big)
//   payloads, each on a multiple of the archive's alignment (4, or 64/128 for the
//   announcer archives), zero padded; the last one ends at the end of the file.
//
// Roster packs rebuild an archive with some payloads replaced (assets, patched
// tables); an archive rebuilt with no changes equals the original.
#pragma once

#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace mvp::vfs {

struct BigEntry {
  std::string name;  // as stored (latin-1 bytes)
  std::uint32_t offset = 0;
  std::uint32_t size = 0;
};

class BigArchive {
 public:
  // Parses `bytes` (kept by the archive). Returns nullopt with the reason.
  static std::optional<BigArchive> parse(std::vector<std::uint8_t> bytes, std::string* error = nullptr);

  const std::vector<BigEntry>& entries() const { return entries_; }
  std::uint32_t flag() const { return flag_; }
  std::uint32_t header_size() const { return header_size_; }
  std::uint32_t file_size() const { return file_size_; }
  const std::vector<std::uint8_t>& bytes() const { return bytes_; }

  // The first entry whose name equals `name` ignoring ASCII case, or null.
  const BigEntry* find(const std::string& name) const;
  // The payload as stored.
  std::vector<std::uint8_t> raw(const BigEntry& e) const;
  // The payload, RefPack-decompressed when it carries a RefPack header.
  std::optional<std::vector<std::uint8_t>> read(const BigEntry& e, std::string* error = nullptr) const;

  // The largest power of two A (4..4096) for which the archive is laid out
  // canonically with payloads aligned to A, or 0.
  std::uint32_t payload_alignment() const;

  // Rebuilds the archive with the payloads of the named entries (exact names)
  // replaced, payloads aligned to `align`.
  std::vector<std::uint8_t> rebuild(const std::map<std::string, std::vector<std::uint8_t>>& replace,
                                    std::uint32_t align = 4) const;

 private:
  std::vector<std::uint8_t> bytes_;
  std::vector<BigEntry> entries_;
  std::uint32_t flag_ = 0, header_size_ = 0, file_size_ = 0;
};

// Builds an archive from (name, payload) pairs with the game's layout.
std::vector<std::uint8_t> build_big(const std::vector<std::pair<std::string, std::vector<std::uint8_t>>>& items,
                                    std::uint32_t flag = 1, std::uint32_t align = 4);

}  // namespace mvp::vfs
