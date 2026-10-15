// The host side of engine/mods (native tools and tests): packs and extracted discs
// in host directories. Not in the browser modules, which get their files from the
// page (wasm/packs_web.cpp), so they carry no std::filesystem or iostreams.
#include <algorithm>
#include <filesystem>
#include <fstream>

#include "mods/apply.h"
#include "mods/mount.h"
#include "mods/pack.h"
#include "mods/zip.h"

namespace mvp::mods {

namespace {

std::vector<std::string> split(const std::string& s, char sep) {
  std::vector<std::string> out;
  std::size_t at = 0;
  for (;;) {
    std::size_t k = s.find(sep, at);
    if (k == std::string::npos) {
      out.push_back(s.substr(at));
      return out;
    }
    out.push_back(s.substr(at, k - at));
    at = k + 1;
  }
}
std::string lower(std::string s) {
  for (char& c : s)
    if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
  return s;
}

std::filesystem::path host_path(const std::string& utf8) {
  return std::filesystem::path(std::u8string(reinterpret_cast<const char8_t*>(utf8.data()), utf8.size()));
}
std::string utf8_of(const std::filesystem::path& p) {
  const std::u8string u = p.u8string();
  return std::string(reinterpret_cast<const char*>(u.data()), u.size());
}

namespace fs = std::filesystem;

class DirSource final : public PackSource {
 public:
  explicit DirSource(const std::string& root) {
    std::error_code ec;
    root_ = fs::absolute(host_path(root), ec);
  }
  bool exists(const std::string& rel) override { return path(rel).has_value(); }
  std::uint64_t size(const std::string& rel) override {
    std::error_code ec;
    return fs::file_size(*path(rel), ec);
  }
  std::optional<std::vector<std::uint8_t>> read(const std::string& rel, std::string* error) override {
    auto p = path(rel);
    std::ifstream f(*p, std::ios::binary);
    if (!f) {
      if (error) *error = "cannot read " + rel;
      return std::nullopt;
    }
    return std::vector<std::uint8_t>((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
  }

 private:
  fs::path root_;
  // Exact-case match of every segment, and the result must stay inside the root.
  std::optional<fs::path> path(const std::string& rel) {
    fs::path cur = root_;
    std::error_code ec;
    for (const auto& seg : split(rel, '/')) {
      bool found = false;
      for (fs::directory_iterator it(cur, ec), end; !ec && it != end; it.increment(ec))
        if (utf8_of(it->path().filename()) == seg) {
          found = true;
          break;
        }
      if (!found) return std::nullopt;
      cur /= host_path(seg);
    }
    const fs::path real = fs::weakly_canonical(cur, ec), base = fs::weakly_canonical(root_, ec);
    auto r = real.begin(), b = base.begin();
    for (; b != base.end(); ++b, ++r)
      if (r == real.end() || *r != *b) return std::nullopt;
    if (!fs::is_regular_file(cur, ec)) return std::nullopt;
    return cur;
  }
};

namespace fs = std::filesystem;

class DirFiles final : public DiscFiles {
 public:
  explicit DirFiles(std::string root) : root_(std::move(root)) {}
  std::optional<std::vector<std::uint8_t>> read(const std::string& path) override {
    auto p = find(path);
    if (!p) return std::nullopt;
    std::ifstream f(*p, std::ios::binary);
    return std::vector<std::uint8_t>((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
  }
  std::optional<std::string> name_of(const std::string& lower_path) override {
    return find(lower_path) ? std::optional<std::string>(lower_path) : std::nullopt;
  }
  std::optional<std::vector<std::uint8_t>> dol() override {
    for (const char* rel : {"/sys/main.dol", "/main.dol"})
      if (auto d = read(rel)) return d;
    return std::nullopt;
  }
  std::string label() const override { return root_; }

 private:
  std::string root_;
  std::optional<fs::path> find(const std::string& path) {
    fs::path cur = fs::path(std::u8string(reinterpret_cast<const char8_t*>(root_.data()), root_.size()));
    std::string p = path;
    while (!p.empty() && p.front() == '/') p.erase(0, 1);
    while (!p.empty() && p.back() == '/') p.pop_back();
    std::size_t at = 0;
    std::error_code ec;
    for (;;) {
      const std::size_t k = p.find('/', at);
      const std::string seg = lower(p.substr(at, k == std::string::npos ? std::string::npos : k - at));
      std::optional<fs::path> hit;
      for (fs::directory_iterator it(cur, ec), end; !ec && it != end; it.increment(ec)) {
        const std::u8string u = it->path().filename().u8string();
        if (lower(std::string(reinterpret_cast<const char*>(u.data()), u.size())) == seg) hit = it->path();
      }
      if (!hit) return std::nullopt;
      cur = *hit;
      if (k == std::string::npos) break;
      at = k + 1;
    }
    if (!fs::is_regular_file(cur, ec)) return std::nullopt;
    return cur;
  }
};

}  // namespace

std::unique_ptr<PackSource> dir_source(const std::string& root) { return std::make_unique<DirSource>(root); }

std::unique_ptr<DiscFiles> dir_files(const std::string& root) { return std::make_unique<DirFiles>(root); }

Pack load_pack_path(const std::string& spec, Report& report) {
  namespace fs = std::filesystem;
  std::error_code ec;
  const fs::path p = host_path(spec);
  if (fs::is_directory(p, ec)) {
    auto src = dir_source(spec);
    return load_pack(spec, src.get(), report);
  }
  if (fs::is_regular_file(p, ec)) {
    std::ifstream f(p, std::ios::binary);
    std::vector<std::uint8_t> bytes((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    if (ZipArchive::is_zip(bytes)) {
      std::string err;
      auto src = zip_source(std::move(bytes), &err);
      if (!src) {
        Pack pack;
        pack.label = spec;
        report.error("E-PACK", spec, err);
        return pack;
      }
      return load_pack(spec, src.get(), report);
    }
  }
  return load_pack(spec, nullptr, report);
}

MountResult mount_pack_paths(vfs::Disc& disc, const std::vector<std::string>& paths, std::string* log,
                             std::string* hash) {
  PackSet set;
  for (const auto& p : paths) set.add(load_pack_path(p, set.report));
  set.check();
  if (hash) *hash = set.set_hash();
  MountResult r = mount_packs(disc, set);
  if (log) {
    *log = set.report.render() + "\n";
    if (!r.fatal.empty()) *log += "error: " + r.fatal + "\n";
    for (const auto& p : set.packs) *log += "pack " + p.where() + " " + p.version_text() + " " + p.hash + "\n";
    *log += "set hash " + set.set_hash() + "\n";
    if (r.ok && !set.packs.empty()) {
      *log += "result hash " + r.result_hash + "\n";
      *log += "changed tables:";
      for (const auto& t : r.changed_tables) *log += " " + t;
      *log += "\nmounted:";
      for (const auto& f : r.files) *log += " " + f;
      *log += " (" + std::to_string(r.bytes) + " bytes)\n";
    }
  }
  return r;
}

}  // namespace mvp::mods
