// Roster packs in the browser (E6): see packs_web.h. Exports, called in this order:
//   mvp_packs_reset()                         forget the packs given so far
//   mvp_pack_begin(label, len, kind)          a pack: kind 0 = files of a picked folder, 1 = a .zip
//   mvp_pack_file(path, len, data, n)         one file of it (folder: its path inside the
//                                             folder, '/'-separated; zip: the zip itself)
//   mvp_pack_end()                            reads and statically checks the pack
//   mvp_packs_json()                          the set as JSON (mods::set_json): ids, names,
//                                             versions, pack hashes, the set hash, the issues
//   mvp_packs_mount()                         (mvp-web) applies the set to the disc and mounts
//                                             it; 1 = ok; mvp_packs_json() then has the result
// Nothing here leaves the browser: the packs come from the player's own files,
// the patched tables live in the engine's memory only.
#include "web/wasm/packs_web.h"

#include <emscripten.h>

#include <map>
#include <optional>
#include <string>
#include <vector>

#include "mods/mount.h"
#include "mods/pack.h"

using namespace mvp;

namespace {

struct Pending {
  std::string label;
  int kind = 0;
  std::map<std::string, std::vector<std::uint8_t>> files;
};

struct State {
  vfs::Disc* disc = nullptr;
  mods::PackSet set;
  std::optional<Pending> pending;
  std::optional<mods::MountResult> mounted;
  std::string text;
} s;

}  // namespace

namespace mvp::web {

void packs_set_disc(vfs::Disc* disc) { s.disc = disc; }

std::array<std::uint8_t, 32> packs_set_hash() {
  const std::string hex = s.set.set_hash();
  std::array<std::uint8_t, 32> out{};
  auto nib = [](char c) { return static_cast<std::uint8_t>(c <= '9' ? c - '0' : c - 'a' + 10); };
  for (std::size_t i = 0; i < 32; ++i) out[i] = static_cast<std::uint8_t>(nib(hex[2 * i]) << 4 | nib(hex[2 * i + 1]));
  return out;
}

}  // namespace mvp::web

extern "C" {

EMSCRIPTEN_KEEPALIVE void mvp_packs_reset() {
  s.set = mods::PackSet{};
  s.pending.reset();
  s.mounted.reset();
}

EMSCRIPTEN_KEEPALIVE void mvp_pack_begin(const char* label, int len, int kind) {
  s.pending = Pending{std::string(label, static_cast<std::size_t>(len)), kind, {}};
}

EMSCRIPTEN_KEEPALIVE void mvp_pack_file(const char* path, int len, const std::uint8_t* data, double n) {
  if (!s.pending) return;
  s.pending->files[std::string(path, static_cast<std::size_t>(len))] =
      std::vector<std::uint8_t>(data, data + static_cast<std::size_t>(n));
}

EMSCRIPTEN_KEEPALIVE void mvp_pack_end() {
  if (!s.pending) return;
  Pending p = std::move(*s.pending);
  s.pending.reset();
  std::unique_ptr<mods::PackSource> src;
  std::string err;
  if (p.kind == 1) {
    if (!p.files.empty()) src = mods::zip_source(std::move(p.files.begin()->second), &err);
    if (!src) {
      mods::Pack bad;
      bad.label = p.label;
      s.set.report.error("E-PACK", p.label, err.empty() ? "not a pack directory or zip file" : err);
      s.set.add(std::move(bad));
      return;
    }
  } else {
    src = mods::memory_source(std::move(p.files));
  }
  s.set.add(mods::load_pack(p.label, src.get(), s.set.report));
  s.set.checked = false;
}

EMSCRIPTEN_KEEPALIVE const char* mvp_packs_json() {
  if (!s.set.checked) s.set.check();
  s.text = mods::canonical_json(mods::set_json(s.set, s.mounted ? &*s.mounted : nullptr));
  return s.text.c_str();
}

EMSCRIPTEN_KEEPALIVE int mvp_packs_mount() {
  if (!s.set.checked) s.set.check();
  if (!s.disc) {
    s.mounted = mods::MountResult{};
    s.mounted->fatal = "no disc";
    return 0;
  }
  s.mounted = mods::mount_packs(*s.disc, s.set);
  return s.mounted->ok ? 1 : 0;
}

}  // extern "C"
