// Applying an ordered pack set to the tables of the player's disc (docs/MODDING.md
// §5-§10): the ops, the cell ownership that turns overlapping packs into
// E-CONFLICT, the final-state rules, the patched files and the result hash.
// A port of tools/rosters/pack.py (Model, Applier, validate_model,
// build_outputs, apply_assets); the same packs on the same disc give the same
// files, byte for byte, in both.
#pragma once

#include <cstdint>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "mods/pack.h"

namespace mvp::vfs {
struct Disc;
}

namespace mvp::mods {

// The team-slot tables of main.dol (ROSTERS.md §12.3, §12.6): the tid of each
// team.dat row and the LOC string ids of its names. Read from the player's own
// main.dol, whose SHA-1 must be the retail one. Retail addresses are contract 1
// (ARCHITECTURE.md §2). Tests on synthetic discs change the hash and the count.
struct SlotConfig {
  std::string dol_sha1 = "da6becdbea614d03c4b5eae9f8a0fb08e0a184dd";
  std::uint32_t count = 124;
  std::uint32_t tid_names = 0x80619D34, tid_row = 0x805C36C0;
  std::uint32_t full = 0x805C2F00, nickname = 0x805C30F0, abbreviation = 0x805C32E0, city = 0x805C34D0;
};

// The disc's files, as the applier reads them.
class DiscFiles {
 public:
  virtual ~DiscFiles() = default;
  // A file's bytes (path matched ignoring ASCII case), or nullopt.
  virtual std::optional<std::vector<std::uint8_t>> read(const std::string& path) = 0;
  // The disc's own spelling of a lower-case path, or nullopt if there is no such file.
  virtual std::optional<std::string> name_of(const std::string& lower_path) = 0;
  virtual std::optional<std::vector<std::uint8_t>> dol() = 0;
  virtual std::string label() const = 0;
};

// The files of a checked disc image (vfs).
std::unique_ptr<DiscFiles> image_files(vfs::Disc& disc);
// An extracted disc in a host directory (data/..., sys/main.dol), as pack.py's Disc.
std::unique_ptr<DiscFiles> dir_files(const std::string& root);

struct ApplyOutput {
  // The changed files at their disc paths: data/database/database.big, the LOC
  // files, rebuilt asset archives and whole-file assets.
  std::map<std::string, std::vector<std::uint8_t>> files;
  // What the result hash covers: every table's text, the three LOC files and
  // every replaced asset, keyed "<path>[:<entry>]" in lower case.
  std::map<std::string, std::vector<std::uint8_t>> texts;
  std::vector<std::string> changed_tables;
  std::string result_hash;
};

// Applies `packs` (loaded and statically valid, in set order) to `disc`.
// Problems go to `report`; nullopt when an op or a final-state rule failed. Asset
// problems are reported after the tables were built, so with them the output is
// returned and report.ok() is false (as pack.py does). Throws PackError when the
// disc's tables cannot be read or main.dol is not the retail one.
std::optional<ApplyOutput> apply_packs(const std::vector<Pack>& packs,
                                       const std::map<std::string, std::set<std::string>>& deps, DiscFiles& disc,
                                       Report& report, const SlotConfig& slots = {});

std::string result_hash(const std::map<std::string, std::vector<std::uint8_t>>& texts);

}  // namespace mvp::mods
