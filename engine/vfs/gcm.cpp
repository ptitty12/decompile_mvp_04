#include "vfs/gcm.h"

#include <cctype>

#include "common/bytes.h"

namespace mvp::vfs {

std::optional<Gcm> Gcm::open(Source& disc, std::string* error) {
  auto fail = [&](const std::string& why) -> std::optional<Gcm> {
    if (error) *error = "GCM: " + why;
    return std::nullopt;
  };
  Gcm g;
  bool ok = false;
  g.boot_ = disc.read_vec(0, kBootSize, &ok);
  if (!ok) return fail("disc header read failed");
  if (be32(g.boot_.data() + 0x1C) != kDiscMagic) return fail("bad disc magic at 0x1C");
  g.bi2_ = disc.read_vec(kBootSize, kBi2Size, &ok);
  if (!ok) return fail("BI2 read failed");
  g.dol_off_ = be32(g.boot_.data() + 0x420);
  g.fst_off_ = be32(g.boot_.data() + 0x424);
  g.fst_size_ = be32(g.boot_.data() + 0x428);
  g.fst_max_ = be32(g.boot_.data() + 0x42C);
  if (g.fst_size_ < 12) return fail("FST too small");
  g.fst_ = disc.read_vec(g.fst_off_, g.fst_size_, &ok);
  if (!ok) return fail("FST outside the disc");

  const std::uint8_t* f = g.fst_.data();
  std::uint32_t count = be32(f + 8);  // root entry: number of entries
  if (f[0] != 1 || count == 0 || std::uint64_t(count) * 12 > g.fst_size_) return fail("bad FST root");
  std::size_t str_base = std::size_t(count) * 12;
  auto name_at = [&](std::uint32_t i, std::string* out) {
    std::uint32_t o = be32(f + i * 12) & 0xFFFFFFu;
    std::size_t p = str_base + o;
    if (p >= g.fst_size_) return false;
    std::size_t e = p;
    while (e < g.fst_size_ && f[e]) ++e;
    if (e >= g.fst_size_) return false;
    out->assign(reinterpret_cast<const char*>(f + p), e - p);
    return true;
  };
  // Walk the flat FST: a directory entry's second word is the index one past its
  // last descendant, so a stack of (end, path) pairs rebuilds the paths.
  std::vector<std::pair<std::uint32_t, std::string>> stack{{count, ""}};
  for (std::uint32_t i = 1; i < count; ++i) {
    while (stack.size() > 1 && i >= stack.back().first) stack.pop_back();
    FstEntry e;
    std::string name;
    if (!name_at(i, &name)) return fail("FST name outside the string table");
    e.path = stack.back().second + "/" + name;
    e.is_dir = f[i * 12] == 1;
    std::uint32_t a = be32(f + i * 12 + 4), b = be32(f + i * 12 + 8);
    if (e.is_dir) {
      if (b <= i || b > count) return fail("bad directory end index");
      stack.emplace_back(b, e.path);
    } else {
      if (f[i * 12] != 0) return fail("bad FST entry type");
      if (std::uint64_t(a) + b > disc.size()) return fail("file outside the disc: " + e.path);
      e.offset = a;
      e.size = b;
    }
    g.entries_.push_back(std::move(e));
  }
  return g;
}

std::string Gcm::game_id() const { return std::string(reinterpret_cast<const char*>(boot_.data()), 6); }

std::string Gcm::title() const {
  const char* t = reinterpret_cast<const char*>(boot_.data() + 0x20);
  std::size_t n = 0;
  while (n < 0x3E0 && t[n]) ++n;
  return std::string(t, n);
}

const FstEntry* Gcm::find(const std::string& path) const {
  auto eq = [](const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    for (std::size_t i = 0; i < a.size(); ++i)
      if (std::tolower(static_cast<unsigned char>(a[i])) != std::tolower(static_cast<unsigned char>(b[i])))
        return false;
    return true;
  };
  for (const auto& e : entries_)
    if (eq(e.path, path)) return &e;
  return nullptr;
}

std::optional<std::vector<std::uint8_t>> Gcm::read_file(Source& disc, const std::string& path) const {
  const FstEntry* e = find(path);
  if (!e || e->is_dir) return std::nullopt;
  bool ok = false;
  auto v = disc.read_vec(e->offset, e->size, &ok);
  if (!ok) return std::nullopt;
  return v;
}

}  // namespace mvp::vfs
