// DOL executables and the minimal ELF section reader used to name DOL sections.
#pragma once

#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <vector>

#include "vfs/gcm.h"
#include "vfs/source.h"

namespace mvp::vfs {

// Identity of the one binary this engine runs: GV4E69 rev 0 main.dol (contract 1,
// ARCHITECTURE §2). Same value as config/GV4E69/build.sha1.
inline constexpr const char* kRetailDolSha1 = "da6becdbea614d03c4b5eae9f8a0fb08e0a184dd";
inline constexpr const char* kGameId = "GV4E69";

struct DolSection {
  int slot = 0;          // 0-6 text, 7-17 data
  bool text = false;
  std::uint32_t offset = 0;
  std::uint32_t address = 0;
  std::uint32_t size = 0;
};

class Dol {
 public:
  static constexpr std::size_t kHeaderSize = 0x100;
  static std::optional<Dol> parse(std::vector<std::uint8_t> bytes, std::string* error = nullptr);
  // File size implied by a DOL header: the furthest section end.
  static std::optional<std::uint32_t> size_from_header(std::span<const std::uint8_t> header);

  const std::vector<DolSection>& sections() const { return sections_; }  // non-empty, slot order
  std::uint32_t bss_address() const { return bss_addr_; }
  std::uint32_t bss_size() const { return bss_size_; }
  std::uint32_t entry() const { return entry_; }
  const std::vector<std::uint8_t>& bytes() const { return bytes_; }

  // The section containing [addr, addr+n), or null.
  const DolSection* section_at(std::uint32_t addr, std::uint32_t n = 1) const;
  // Pointer to the file bytes behind a loaded address range, or null.
  const std::uint8_t* at(std::uint32_t addr, std::uint32_t n = 1) const;

 private:
  std::vector<std::uint8_t> bytes_;
  std::vector<DolSection> sections_;
  std::uint32_t bss_addr_ = 0, bss_size_ = 0, entry_ = 0;
};

// Reads main.dol from a disc: the boot header's DOL offset, sized by the DOL header.
std::optional<std::vector<std::uint8_t>> read_main_dol(Source& disc, const Gcm& gcm, std::string* error = nullptr);

struct ElfSection {
  std::string name;
  std::uint32_t type = 0, flags = 0, addr = 0, offset = 0, size = 0;
  bool alloc() const { return (flags & 2) != 0; }
};

// Section headers of a 32-bit big-endian ELF (the disc's /mvp.elf).
std::optional<std::vector<ElfSection>> parse_elf_sections(std::span<const std::uint8_t> elf, std::string* error = nullptr);

// One line per non-empty DOL slot, then one bss line, in the format of
// config/GV4E69/dol_layout.txt: "<text|data|bss> <section> [<section> ...]". Each
// line lists the allocated, non-empty ELF sections inside that slot's address
// range, in address order.
std::vector<std::string> dol_layout_lines(const Dol& dol, const std::vector<ElfSection>& elf);

}  // namespace mvp::vfs
