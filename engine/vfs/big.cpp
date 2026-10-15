#include "vfs/big.h"

#include <cctype>
#include <cstring>

#include "common/bytes.h"
#include "vfs/refpack.h"

namespace mvp::vfs {

std::optional<BigArchive> BigArchive::parse(std::vector<std::uint8_t> bytes, std::string* error) {
  auto fail = [&](const std::string& why) -> std::optional<BigArchive> {
    if (error) *error = why;
    return std::nullopt;
  };
  BigArchive a;
  a.bytes_ = std::move(bytes);
  const auto& d = a.bytes_;
  if (d.size() < 16 || std::memcmp(d.data(), "BIGF", 4) != 0) return fail("not a BIGF archive");
  a.file_size_ = le32(d.data() + 4);
  const std::uint32_t count = be32(d.data() + 8);
  a.header_size_ = be32(d.data() + 12);
  if (a.file_size_ != d.size())
    return fail("size field " + std::to_string(a.file_size_) + " != file size " + std::to_string(d.size()));
  if (a.header_size_ > d.size()) return fail("truncated header");
  const std::size_t hs = a.header_size_;
  std::size_t p = 16;
  for (std::uint32_t i = 0; i < count; ++i) {
    if (p + 9 > hs) return fail("entry table runs past the header");
    BigEntry e;
    e.offset = be32(d.data() + p);
    e.size = be32(d.data() + p + 4);
    p += 8;
    std::size_t end = p;
    while (end < hs && d[end]) ++end;
    if (end >= hs) return fail("entry name runs past the header");
    e.name.assign(reinterpret_cast<const char*>(d.data() + p), end - p);
    p = end + 1;
    if (std::uint64_t(e.offset) + e.size > d.size()) return fail("entry " + e.name + " outside the archive");
    a.entries_.push_back(std::move(e));
  }
  if (hs - p != 8 || std::memcmp(d.data() + p, "L234", 4) != 0) return fail("unexpected trailer");
  a.flag_ = be32(d.data() + p + 4);
  return a;
}

const BigEntry* BigArchive::find(const std::string& name) const {
  for (const auto& e : entries_) {
    if (e.name.size() != name.size()) continue;
    bool same = true;
    for (std::size_t i = 0; i < name.size() && same; ++i)
      same = std::tolower(static_cast<unsigned char>(e.name[i])) == std::tolower(static_cast<unsigned char>(name[i]));
    if (same) return &e;
  }
  return nullptr;
}

std::vector<std::uint8_t> BigArchive::raw(const BigEntry& e) const {
  return std::vector<std::uint8_t>(bytes_.begin() + e.offset, bytes_.begin() + e.offset + e.size);
}

std::optional<std::vector<std::uint8_t>> BigArchive::read(const BigEntry& e, std::string* error) const {
  const std::uint8_t* p = bytes_.data() + e.offset;
  if (refpack::is_refpack(p, e.size)) return refpack::decompress(p, e.size, error);
  return raw(e);
}

std::uint32_t BigArchive::payload_alignment() const {
  for (std::uint32_t a = 4096; a >= 4; a >>= 1) {
    std::uint64_t pos = header_size_;
    bool ok = true;
    for (const auto& e : entries_) {
      if (e.offset != ((pos + a - 1) & ~std::uint64_t(a - 1))) {
        ok = false;
        break;
      }
      pos = std::uint64_t(e.offset) + e.size;
    }
    if (ok && pos == file_size_) return a;
  }
  return 0;
}

std::vector<std::uint8_t> BigArchive::rebuild(const std::map<std::string, std::vector<std::uint8_t>>& replace,
                                              std::uint32_t align) const {
  std::vector<std::pair<std::string, std::vector<std::uint8_t>>> items;
  items.reserve(entries_.size());
  for (const auto& e : entries_) {
    auto it = replace.find(e.name);
    items.emplace_back(e.name, it != replace.end() ? it->second : raw(e));
  }
  return build_big(items, flag_, align);
}

std::vector<std::uint8_t> build_big(const std::vector<std::pair<std::string, std::vector<std::uint8_t>>>& items,
                                    std::uint32_t flag, std::uint32_t align) {
  std::size_t table = 0;
  for (const auto& [name, data] : items) table += 8 + name.size() + 1;
  const std::uint64_t hs = 16 + table + 8;
  std::uint64_t pos = hs;
  std::vector<std::uint64_t> offs;
  for (const auto& [name, data] : items) {
    pos = (pos + align - 1) & ~std::uint64_t(align - 1);
    offs.push_back(pos);
    pos += data.size();
  }
  const std::uint64_t total = pos;
  std::vector<std::uint8_t> out(static_cast<std::size_t>(total), 0);
  std::memcpy(out.data(), "BIGF", 4);
  out[4] = std::uint8_t(total);
  out[5] = std::uint8_t(total >> 8);
  out[6] = std::uint8_t(total >> 16);
  out[7] = std::uint8_t(total >> 24);
  put_be32(out.data() + 8, static_cast<std::uint32_t>(items.size()));
  put_be32(out.data() + 12, static_cast<std::uint32_t>(hs));
  std::size_t p = 16;
  for (std::size_t i = 0; i < items.size(); ++i) {
    put_be32(out.data() + p, static_cast<std::uint32_t>(offs[i]));
    put_be32(out.data() + p + 4, static_cast<std::uint32_t>(items[i].second.size()));
    p += 8;
    std::memcpy(out.data() + p, items[i].first.data(), items[i].first.size());
    p += items[i].first.size() + 1;
  }
  std::memcpy(out.data() + p, "L234", 4);
  put_be32(out.data() + p + 4, flag);
  for (std::size_t i = 0; i < items.size(); ++i)
    if (!items[i].second.empty())
      std::memcpy(out.data() + offs[i], items[i].second.data(), items[i].second.size());
  return out;
}

}  // namespace mvp::vfs
