#include "vfs/dol.h"

#include <algorithm>

#include "common/bytes.h"

namespace mvp::vfs {

std::optional<std::uint32_t> Dol::size_from_header(std::span<const std::uint8_t> h) {
  if (h.size() < kHeaderSize) return std::nullopt;
  std::uint64_t end = kHeaderSize;
  for (int i = 0; i < 18; ++i) {
    std::uint32_t off = be32(h.data() + 4 * i);
    std::uint32_t size = be32(h.data() + 0x90 + 4 * i);
    if (size) end = std::max<std::uint64_t>(end, std::uint64_t(off) + size);
  }
  if (end > 0xFFFFFFFFull) return std::nullopt;
  return static_cast<std::uint32_t>(end);
}

std::optional<Dol> Dol::parse(std::vector<std::uint8_t> bytes, std::string* error) {
  auto fail = [&](const std::string& why) -> std::optional<Dol> {
    if (error) *error = "DOL: " + why;
    return std::nullopt;
  };
  if (bytes.size() < kHeaderSize) return fail("shorter than its header");
  Dol d;
  const std::uint8_t* h = bytes.data();
  for (int i = 0; i < 18; ++i) {
    DolSection s;
    s.slot = i;
    s.text = i < 7;
    s.offset = be32(h + 4 * i);
    s.address = be32(h + 0x48 + 4 * i);
    s.size = be32(h + 0x90 + 4 * i);
    if (!s.size) continue;
    if (s.offset < kHeaderSize || std::uint64_t(s.offset) + s.size > bytes.size())
      return fail("section " + std::to_string(i) + " outside the file");
    if (std::uint64_t(s.address) + s.size > 0x100000000ull) return fail("section address wraps");
    d.sections_.push_back(s);
  }
  // Loaded sections must not overlap each other.
  auto sorted = d.sections_;
  std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) { return a.address < b.address; });
  for (std::size_t i = 1; i < sorted.size(); ++i)
    if (sorted[i - 1].address + sorted[i - 1].size > sorted[i].address) return fail("sections overlap");
  d.bss_addr_ = be32(h + 0xD8);
  d.bss_size_ = be32(h + 0xDC);
  d.entry_ = be32(h + 0xE0);
  d.bytes_ = std::move(bytes);
  return d;
}

const DolSection* Dol::section_at(std::uint32_t addr, std::uint32_t n) const {
  for (const auto& s : sections_)
    if (addr >= s.address && std::uint64_t(addr) + n <= std::uint64_t(s.address) + s.size) return &s;
  return nullptr;
}

const std::uint8_t* Dol::at(std::uint32_t addr, std::uint32_t n) const {
  const DolSection* s = section_at(addr, n);
  return s ? bytes_.data() + s->offset + (addr - s->address) : nullptr;
}

std::optional<std::vector<std::uint8_t>> read_main_dol(Source& disc, const Gcm& gcm, std::string* error) {
  bool ok = false;
  auto header = disc.read_vec(gcm.dol_offset(), Dol::kHeaderSize, &ok);
  if (!ok) {
    if (error) *error = "DOL header outside the disc";
    return std::nullopt;
  }
  auto size = Dol::size_from_header(header);
  if (!size) {
    if (error) *error = "bad DOL header";
    return std::nullopt;
  }
  auto dol = disc.read_vec(gcm.dol_offset(), *size, &ok);
  if (!ok) {
    if (error) *error = "DOL body outside the disc";
    return std::nullopt;
  }
  return dol;
}

std::optional<std::vector<ElfSection>> parse_elf_sections(std::span<const std::uint8_t> e, std::string* error) {
  auto fail = [&](const char* why) -> std::optional<std::vector<ElfSection>> {
    if (error) *error = std::string("ELF: ") + why;
    return std::nullopt;
  };
  if (e.size() < 52 || e[0] != 0x7F || e[1] != 'E' || e[2] != 'L' || e[3] != 'F') return fail("bad magic");
  if (e[4] != 1 || e[5] != 2) return fail("not a 32-bit big-endian ELF");
  std::uint32_t shoff = be32(&e[32]);
  std::uint16_t shentsize = be16(&e[46]), shnum = be16(&e[48]), shstrndx = be16(&e[50]);
  if (shentsize < 40 || shstrndx >= shnum) return fail("bad section header table");
  if (std::uint64_t(shoff) + std::uint64_t(shnum) * shentsize > e.size()) return fail("section headers outside the file");
  auto sh = [&](int i) { return &e[shoff + std::size_t(i) * shentsize]; };
  std::uint32_t str_off = be32(sh(shstrndx) + 16), str_size = be32(sh(shstrndx) + 20);
  if (std::uint64_t(str_off) + str_size > e.size()) return fail("string table outside the file");
  std::vector<ElfSection> out;
  for (int i = 0; i < shnum; ++i) {
    const std::uint8_t* p = sh(i);
    ElfSection s;
    std::uint32_t name = be32(p);
    if (name >= str_size) return fail("section name outside the string table");
    std::size_t n0 = str_off + name, n1 = n0;
    while (n1 < str_off + str_size && e[n1]) ++n1;
    s.name.assign(reinterpret_cast<const char*>(&e[n0]), n1 - n0);
    s.type = be32(p + 4);
    s.flags = be32(p + 8);
    s.addr = be32(p + 12);
    s.offset = be32(p + 16);
    s.size = be32(p + 20);
    out.push_back(std::move(s));
  }
  return out;
}

std::vector<std::string> dol_layout_lines(const Dol& dol, const std::vector<ElfSection>& elf) {
  std::vector<const ElfSection*> alloc;
  for (const auto& s : elf)
    if (s.alloc() && s.size) alloc.push_back(&s);
  std::sort(alloc.begin(), alloc.end(), [](auto* a, auto* b) { return a->addr < b->addr; });
  auto line = [&](const char* kind, std::uint32_t addr, std::uint32_t size) {
    std::string l = kind;
    for (auto* s : alloc)
      if (s->addr >= addr && std::uint64_t(s->addr) + s->size <= std::uint64_t(addr) + size) l += " " + s->name;
    return l;
  };
  std::vector<std::string> out;
  for (const auto& s : dol.sections()) out.push_back(line(s.text ? "text" : "data", s.address, s.size));
  if (dol.bss_size()) out.push_back(line("bss", dol.bss_address(), dol.bss_size()));
  return out;
}

}  // namespace mvp::vfs
