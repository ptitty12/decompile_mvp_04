// Roster packs in the engine (E6): the pack set a player chose, checked,
// composed, applied to the tables of the player's own disc and mounted on the
// virtual disc (vfs/overlay.h) before the machine boots.
//
//   PackSet set;
//   set.add(load_pack(...)) ...           // in the player's order
//   set.check();                         // static validation and composition (no disc)
//   mount_packs(disc, set)               // full validation; patched files on the virtual disc
//
// Determinism: the same disc and the same packs in the same order give the same
// virtual disc, byte for byte, on every machine (MODDING.md §9). The netplay
// handshake compares the set hash; peers may compare result hashes too.
#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

#include "mods/apply.h"
#include "mods/json.h"
#include "mods/pack.h"

namespace mvp::vfs {
struct Disc;
}

namespace mvp::mods {

struct PackSet {
  std::vector<Pack> packs;
  Report report;  // static issues, then those of applying
  std::map<std::string, std::set<std::string>> deps;
  bool checked = false;

  void add(Pack p) { packs.push_back(std::move(p)); }
  // Static validation is done as packs load; this adds the set rules (unique ids,
  // dependencies). Returns report.ok().
  bool check();
  std::string set_hash() const;  // of the packs as listed (MODDING.md §10)
};

struct MountResult {
  bool ok = false;
  std::string fatal;                 // a PackError: unreadable tables, a non-retail main.dol
  std::string result_hash;
  std::vector<std::string> changed_tables;
  std::vector<std::string> files;    // disc paths now served from memory
  std::uint64_t bytes = 0;           // their total size
};

// Applies the (checked, error-free) set to `disc` and mounts the patched files.
// On any error nothing is mounted and the disc is unchanged. An empty set
// mounts nothing and succeeds.
MountResult mount_packs(vfs::Disc& disc, PackSet& set, const SlotConfig& slots = {});

// Loads packs from host paths (directories or .zip files), checks the set and
// mounts it: the native tools' --pack option. Prints the issues to `log`
// (engine_mods_host).
MountResult mount_pack_paths(vfs::Disc& disc, const std::vector<std::string>& paths, std::string* log,
                             std::string* set_hash = nullptr);

// The set as JSON for the page: {ok, set_hash, packs: [{id, name, version, hash,
// label}], issues: [...]} plus, after mounting, result_hash, changed_tables, files.
Json set_json(const PackSet& set, const MountResult* mounted = nullptr);

}  // namespace mvp::mods
