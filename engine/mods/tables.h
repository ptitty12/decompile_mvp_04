// The game's data formats that roster packs patch (docs/ROSTERS.md; the reference
// tools are tools/rosters/dbtables.py and loc.py):
//
// - database.big's tables: RefPack-compressed text, a header line of numbered
//   field names, then one line per record, "<key9>,0 <v0>,1 <v1>,...,;\r\n".
//   Values are kept as the file's bytes (latin-1), so re-serializing an
//   unchanged table gives the same bytes.
// - LOC text files (FEENG.LOC, IGENG.LOC, MC_ENG.loc): string ids and UTF-16LE
//   strings. The engine keeps the text as UTF-8.
#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace mvp::mods {

// djb2 over the bytes (latin-1 text): h = h * 33 + c from 5381, 32 bit. The key of
// every player, manager and team record ("%09x").
std::uint32_t djb2(const std::string& text);
std::string key_of(const std::string& text);  // 9 lowercase hex digits

// Latin-1 table bytes as UTF-8 (for messages and LOC text).
std::string latin1_to_utf8(const std::string& s);

struct Table {
  std::string name;
  std::vector<std::string> fields;
  std::vector<std::vector<std::string>> rows;  // [key, v0, v1, ...]

  static std::optional<Table> parse(const std::string& name, const std::vector<std::uint8_t>& data,
                                    std::string* error);
  // The text, or nullopt when a value holds a separator (',' ';' CR LF).
  std::optional<std::string> serialize(std::string* error = nullptr) const;
};

// int(s) if s is a canonical decimal integer (no sign but '-', no leading zeros).
std::optional<std::int64_t> canon_int(const std::string& s);

struct Loc {
  std::vector<std::pair<std::uint16_t, std::string>> entries;  // (id, UTF-8 text) in file order

  static std::optional<Loc> parse(const std::vector<std::uint8_t>& data, std::string* error);
  std::vector<std::uint8_t> serialize() const;
};

}  // namespace mvp::mods
