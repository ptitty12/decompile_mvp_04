// Roster and team packs, format v1 (docs/MODDING.md, normative): reading a pack,
// its static validation, composition order and the hashes. The reference
// implementation is tools/rosters/pack.py; this is the engine's, and it must give
// the same issues (severity, code, place, message) and the same hashes for every
// pack (engine/mods/tests/crosscheck.py runs both).
//
// A pack never contains retail data and never names a decomp symbol or address:
// it depends only on the game's data formats and on this versioned format.
#pragma once

#include <cstdint>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <tuple>
#include <string>
#include <utility>
#include <vector>

#include "mods/json.h"

namespace mvp::mods {

inline constexpr int kApiMajor = 1, kApiMinor = 0;  // engine mod API = pack format version
inline constexpr const char* kGameId = "GV4E69-0";
inline constexpr const char* kDatabasePath = "/data/database/database.big";
inline constexpr const char* kLocFiles[3] = {"FEENG.LOC", "IGENG.LOC", "MC_ENG.loc"};  // in /data/, disc spelling
inline constexpr const char* kDefaultName = "Default,Default";
inline constexpr std::uint64_t kMaxPatchBytes = 16u << 20, kMaxAssetBytes = 16u << 20, kMaxPackBytes = 64u << 20;

// ---------------------------------------------------------------- report
struct Issue {
  std::string severity;  // "error" or "warning"
  std::string code;      // E-... / W-... (MODDING.md §7.4)
  std::string where;
  std::string message;
};

struct Report {
  std::vector<Issue> issues;
  void error(const std::string& code, const std::string& where, const std::string& msg) {
    issues.push_back({"error", code, where, msg});
  }
  void warn(const std::string& code, const std::string& where, const std::string& msg) {
    issues.push_back({"warning", code, where, msg});
  }
  std::size_t errors() const;
  bool ok() const { return errors() == 0; }
  std::string render() const;   // "<severity> <code> <where>: <message>" lines and the totals
  Json to_json() const;         // [{severity, code, where, message}]
};

// A problem that stops processing (an unreadable disc, a main.dol that is not
// GV4E69 rev 0); pack.py exits with status 2 for these.
struct PackError {
  std::string message;
};

// ---------------------------------------------------------------- schema (Appendix A)
struct Column {
  std::string name;
  std::string kind;  // "int", "name", "code", "text13", "text12", "abbr", "key", "mgr", "roster"
  std::int64_t lo = 0, hi = 0;
  bool null = false;      // also takes "-"
  bool editable = true;
};

struct Schema {
  std::map<std::string, std::vector<Column>> tables;
  const Column* column(const std::string& table, const std::string& name) const;
  int index(const std::string& table, const std::string& name) const;  // -1 if absent
};
const Schema& schema();

// Tables in database.big's archive order, and the player tables.
extern const std::vector<std::string> kTableOrder, kBatterTables, kPitcherTables, kPlayerTables;
extern const std::vector<std::string> kLineups, kFielders, kStarters, kPitchRoles, kRosterCodes;

// ---------------------------------------------------------------- pack sources
// Where a pack's files come from: a directory, a zip, or files the browser
// handed over. Paths are relative, '/'-separated and case-sensitive.
class PackSource {
 public:
  virtual ~PackSource() = default;
  virtual bool exists(const std::string& rel) = 0;
  virtual std::uint64_t size(const std::string& rel) = 0;
  virtual std::optional<std::vector<std::uint8_t>> read(const std::string& rel, std::string* error) = 0;
};

// Files in memory (a folder the browser read). With `strip_single_top` the
// files may sit in one top-level folder holding pack.json, as in a zip.
std::unique_ptr<PackSource> memory_source(std::map<std::string, std::vector<std::uint8_t>> files,
                                          bool strip_single_top = true);
// A zip's bytes; nullopt with the reason if they are not a readable zip.
std::unique_ptr<PackSource> zip_source(std::vector<std::uint8_t> bytes, std::string* error);
// A directory on the host (exact-case paths that stay inside it).
std::unique_ptr<PackSource> dir_source(const std::string& root);

// ---------------------------------------------------------------- packs
struct AssetTarget {
  std::string path;   // lower case
  std::string entry;  // lower case; empty: the whole file
  bool has_entry = false;
  bool operator<(const AssetTarget& o) const {
    return std::tie(path, has_entry, entry) < std::tie(o.path, o.has_entry, o.entry);
  }
  bool operator==(const AssetTarget& o) const {
    return path == o.path && has_entry == o.has_entry && entry == o.entry;
  }
  std::string label() const { return path + (has_entry ? " entry " + entry : ""); }
};

// A semantic version's parts as decimal strings (no leading zeros), so any size
// compares exactly.
struct Semver {
  std::string major, minor, patch;
  std::string text() const { return major + "." + minor + "." + patch; }
};
int compare(const Semver& a, const Semver& b);

struct Pack {
  std::string label;  // where it came from (a path, a file name)
  std::optional<Json> manifest;
  std::string id;     // empty: not valid (yet)
  std::optional<Semver> version;
  std::vector<std::pair<std::string, std::string>> depends;  // (id, requirement)
  struct Patch {
    std::string path;
    std::vector<std::pair<int, Json>> ops;  // (index in the file, op) of the ops that passed static checks
  };
  std::vector<Patch> patches;
  struct Asset {
    AssetTarget target;
    std::string file;
    std::vector<std::uint8_t> data;
    std::string where;
  };
  std::vector<Asset> assets;
  std::map<std::string, std::string> digests;  // file path -> SHA-256 hex of its canonical content
  std::string hash;                             // empty without a manifest

  std::string where(const std::string& path = "", int index = -1) const;
  std::string name() const;           // the manifest's display name, or ""
  std::string version_text() const;   // the manifest's "version" string, or ""
};

// Reads and statically validates one pack (MODDING.md §7.1). Check report.ok().
Pack load_pack(const std::string& label, PackSource* source, Report& report);
// A directory or a zip file on the host, as pack.py's load_pack(spec).
Pack load_pack_path(const std::string& spec, Report& report);

// Unique ids; every dependency earlier in the set with a matching version.
// Returns, per pack id, the ids it depends on (transitively).
std::map<std::string, std::set<std::string>> check_set_order(const std::vector<Pack>& packs, Report& report);

bool version_matches(const std::string& requirement, const Semver& version);

// The hashes of MODDING.md §10 (64 lowercase hex digits).
std::string set_hash(const std::vector<Pack>& packs);
std::string empty_set_hash();

// Static checks of one op (exposed for tests).
bool check_op(const Json& op, Report& report, const std::string& where);
// "Last,First" -> (last, first) or nullopt (an error is reported).
std::optional<std::pair<std::string, std::string>> check_name(const Json& name, Report& report,
                                                              const std::string& where,
                                                              const std::string& what = "player");
// roster.set entries -> rows [name, c0, o0, c1, o1, c2, o2, c3, o3], or nullopt.
std::optional<std::vector<std::vector<std::string>>> check_entries(const Json& entries, Report& report,
                                                                   const std::string& where);
bool check_value(const Column& col, const Json& v, Report& report, const std::string& where);

std::string sha256_hex(const std::string& data);
std::string sha256_hex(const std::vector<std::uint8_t>& data);

}  // namespace mvp::mods
