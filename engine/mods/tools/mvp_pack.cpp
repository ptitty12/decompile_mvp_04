// mvp-pack: the engine's roster-pack implementation on the command line, with
// pack.py's commands (docs/MODDING.md Appendix B), so the two can be compared on
// the same packs and the same disc (engine/mods/tests/crosscheck.py).
//
//   mvp-pack validate [--disc DISC] [--json] PACK...
//   mvp-pack apply --disc DISC --out DIR [--json] PACK...
//   mvp-pack hash PACK...
//   mvp-pack mount-check --disc IMAGE PACK...
//
// DISC is an ISO/CISO image or a directory holding an extracted disc (data/...,
// sys/main.dol). PACK is a pack directory or .zip. `apply` writes the changed files
// at their disc paths under DIR and pack-apply.json; DIR must be outside the
// repository or under its ignored build/ directory (patched game files are never
// committed). `mount-check` mounts the packs on the image's virtual disc and reads
// every file back through it: replaced files must equal the outputs, every other
// file the original.
//
// Tests on synthetic discs: --slot-sha1 HEX and --slot-count N stand in for the
// retail main.dol's SHA-1 and its 124 team slots (as pack.py's tests patch them).
//
// Exit status: 0 no errors (warnings allowed), 1 errors, 2 usage or I/O problem.
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#include "mods/apply.h"
#include "mods/json.h"
#include "mods/mount.h"
#include "mods/pack.h"
#include "vfs/disc_check.h"
#include "vfs/overlay.h"

using namespace mvp;
using namespace mvp::mods;
namespace fs = std::filesystem;

namespace {

fs::path host(const std::string& s) {
  return fs::path(std::u8string(reinterpret_cast<const char8_t*>(s.data()), s.size()));
}

int usage() {
  std::fprintf(stderr,
               "usage: mvp-pack validate [--disc DISC] [--json] PACK... | apply --disc DISC --out DIR [--json] PACK... "
               "| hash PACK... | mount-check --disc IMAGE PACK...  [--slot-sha1 HEX] [--slot-count N]\n");
  return 2;
}

// Patched files must never land where git could pick them up: outside any work
// tree, or under a work tree's build/ directory.
bool safe_out(const std::string& out) {
  std::error_code ec;
  fs::path p = fs::weakly_canonical(fs::absolute(host(out), ec), ec);
  for (fs::path cur = p;; cur = cur.parent_path()) {
    if (fs::exists(cur / ".git", ec)) {
      const fs::path build = cur / "build";
      auto b = build.begin();
      auto q = p.begin();
      for (; b != build.end(); ++b, ++q)
        if (q == p.end() || *q != *b) return false;
      return true;
    }
    if (cur == cur.parent_path()) return true;
  }
}

Json bool_json(bool v) {
  Json j;
  j.kind = Json::Kind::Bool;
  j.b = v;
  return j;
}

}  // namespace

int main(int argc, char** argv) {
  if (argc < 2) return usage();
  const std::string cmd = argv[1];
  std::string disc_path, out_dir;
  bool as_json = false;
  SlotConfig slots;
  std::vector<std::string> specs;
  for (int k = 2; k < argc; ++k) {
    const std::string a = argv[k];
    auto next = [&]() -> std::string { return k + 1 < argc ? argv[++k] : std::string(); };
    if (a == "--disc") disc_path = next();
    else if (a == "--out") out_dir = next();
    else if (a == "--json") as_json = true;
    else if (a == "--slot-sha1") slots.dol_sha1 = next();
    else if (a == "--slot-count") slots.count = static_cast<std::uint32_t>(std::stoul(next()));
    else if (a.rfind("--", 0) == 0) return usage();
    else specs.push_back(a);
  }
  if (specs.empty() || (cmd != "validate" && cmd != "apply" && cmd != "hash" && cmd != "mount-check")) return usage();
  if ((cmd == "apply" || cmd == "mount-check") && disc_path.empty()) return usage();
  if (cmd == "apply" && out_dir.empty()) return usage();
  if (cmd == "apply" && !safe_out(out_dir)) {
    std::fprintf(stderr,
                 "error: %s is inside a git work tree and not under its build/ directory; patched game files must "
                 "never be committed\n",
                 out_dir.c_str());
    return 2;
  }

  PackSet set;
  for (const auto& s : specs) set.add(load_pack_path(s, set.report));
  set.check();

  if (cmd == "hash") {
    if (!set.report.ok()) {
      std::printf("%s\n", set.report.render().c_str());
      return 1;
    }
    for (const auto& p : set.packs) std::printf("%s  %s %s\n", p.hash.c_str(), p.id.c_str(), p.version_text().c_str());
    std::printf("%s  (set of %zu, in this order)\n", set.set_hash().c_str(), set.packs.size());
    return 0;
  }

  // The disc: an image (vfs) or an extracted directory.
  std::optional<vfs::Disc> image;
  std::unique_ptr<DiscFiles> files;
  if (!disc_path.empty()) {
    std::error_code ec;
    if (fs::is_directory(host(disc_path), ec)) {
      files = dir_files(disc_path);
    } else {
      std::string err;
      image = vfs::open_disc(disc_path, false, &err);
      if (!image) {
        std::fprintf(stderr, "error: disc %s: %s\n", disc_path.c_str(), err.c_str());
        return 2;
      }
      files = image_files(*image);
    }
  }

  if (cmd == "mount-check") {
    if (!image) return usage();
    // The original bytes of every file, then the same reads through the mounted overlay.
    std::vector<std::pair<std::string, std::vector<std::uint8_t>>> before;
    for (const auto& e : image->gcm.entries())
      if (!e.is_dir) before.emplace_back(e.path, *image->gcm.read_file(*image->image, e.path));
    std::optional<ApplyOutput> expect;
    try {
      Report scratch;
      auto f2 = image_files(*image);
      expect = apply_packs(set.packs, set.deps, *f2, scratch, slots);
    } catch (const PackError& e) {
      std::fprintf(stderr, "error: %s\n", e.message.c_str());
      return 2;
    }
    MountResult r = mount_packs(*image, set, slots);
    if (!r.ok || !expect) {
      std::printf("%s\n%s\n", set.report.render().c_str(), r.fatal.c_str());
      return 1;
    }
    int bad = 0;
    for (const auto& [path, bytes] : before) {
      auto now = image->gcm.read_file(*image->image, path);
      auto it = expect->files.find(path);
      const std::vector<std::uint8_t>& want = it != expect->files.end() ? it->second : bytes;
      if (!now || *now != want) {
        std::printf("MISMATCH %s\n", path.c_str());
        ++bad;
      }
    }
    std::printf("mount-check: %zu files, %zu replaced (%llu bytes), %d mismatches; result hash %s\n", before.size(),
                r.files.size(), static_cast<unsigned long long>(r.bytes), bad, r.result_hash.c_str());
    return bad ? 1 : 0;
  }

  std::optional<ApplyOutput> out;
  if (files && set.report.ok()) {
    try {
      out = apply_packs(set.packs, set.deps, *files, set.report, slots);
    } catch (const PackError& e) {
      std::fprintf(stderr, "error: %s\n", e.message.c_str());
      return 2;
    }
  }

  Json result = Json::object();
  if (cmd == "validate") {
    result.set("ok", bool_json(set.report.ok()));
    result.set("issues", set.report.to_json());
    Json packs = Json::array();
    for (const auto& p : set.packs) {
      Json j = Json::object();
      j.set("id", p.id.empty() ? Json{} : Json::string(p.id));
      j.set("hash", p.hash.empty() ? Json{} : Json::string(p.hash));
      packs.arr.push_back(std::move(j));
    }
    result.set("packs", std::move(packs));
    if (as_json) std::printf("%s\n", canonical_json(result).c_str());
    else std::printf("%s\n", set.report.render().c_str());
    return set.report.ok() ? 0 : 1;
  }

  // apply
  Json extra = Json::object();
  if (out) {
    std::error_code ec;
    fs::create_directories(host(out_dir), ec);
    Json written = Json::array();
    for (const auto& [path, bytes] : out->files) {
      fs::path dst = host(out_dir);
      std::string rel = path;
      while (!rel.empty() && rel[0] == '/') rel.erase(0, 1);
      dst /= host(rel);
      fs::create_directories(dst.parent_path(), ec);
      std::ofstream f(dst, std::ios::binary);
      f.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
      written.arr.push_back(Json::string(path));
    }
    Json changed = Json::array(), packs = Json::array();
    for (const auto& t : out->changed_tables) changed.arr.push_back(Json::string(t));
    for (const auto& p : set.packs) {
      Json j = Json::object();
      j.set("id", Json::string(p.id));
      j.set("version", Json::string(p.version_text()));
      j.set("hash", Json::string(p.hash));
      packs.arr.push_back(std::move(j));
    }
    extra.set("set_hash", Json::string(set.set_hash()));
    extra.set("result_hash", Json::string(out->result_hash));
    extra.set("changed_tables", std::move(changed));
    extra.set("written", std::move(written));
    extra.set("packs", std::move(packs));
    Json file = extra;
    file.set("issues", set.report.to_json());
    std::ofstream f(host(out_dir) / "pack-apply.json", std::ios::binary);
    f << canonical_json(file);
  }
  result = extra;
  result.set("ok", bool_json(set.report.ok()));
  result.set("issues", set.report.to_json());
  if (as_json) {
    std::printf("%s\n", canonical_json(result).c_str());
  } else {
    std::printf("%s\n", set.report.render().c_str());
    if (out) {
      std::printf("set hash    %s\nresult hash %s\n", set.set_hash().c_str(), out->result_hash.c_str());
      std::printf("changed tables:");
      for (const auto& t : out->changed_tables) std::printf(" %s", t.c_str());
      std::printf("\nwrote:");
      for (const auto& [path, bytes] : out->files) std::printf(" %s", path.c_str());
      std::printf("\n");
    }
  }
  return set.report.ok() ? 0 : 1;
}
