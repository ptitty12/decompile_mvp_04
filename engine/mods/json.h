// The JSON of roster packs (docs/MODDING.md §2, §10): a strict reader, the
// canonical form the hashes are computed over, and Python's repr() of values
// for report messages, all as the reference tool (tools/rosters/pack.py) does
// them, so the engine and the tool agree on every hash and every message.
//
// Strict: UTF-8 (a leading byte-order mark is ignored), no duplicate keys,
// integers only (in the signed 32-bit range), printable ASCII object keys. Error
// positions are Python's json module's (line and column in characters).
#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace mvp::mods {

struct Json {
  enum class Kind { Null, Bool, Int, Str, Arr, Obj };
  Kind kind = Kind::Null;
  bool b = false;
  std::int64_t i = 0;
  std::string big;  // an integer outside the 64-bit range: its decimal digits (only for error messages)
  std::string s;    // UTF-8
  std::vector<Json> arr;
  std::vector<std::pair<std::string, Json>> obj;  // in document order

  bool is_null() const { return kind == Kind::Null; }
  bool is_bool() const { return kind == Kind::Bool; }
  bool is_int() const { return kind == Kind::Int; }  // never a bool (unlike Python's isinstance)
  bool is_str() const { return kind == Kind::Str; }
  bool is_arr() const { return kind == Kind::Arr; }
  bool is_obj() const { return kind == Kind::Obj; }

  // Object member, or null when absent (or not an object).
  const Json* get(const std::string& key) const;
  bool has(const std::string& key) const { return get(key) != nullptr; }
  // Python truthiness.
  bool truthy() const;

  static Json string(std::string v) {
    Json j;
    j.kind = Kind::Str;
    j.s = std::move(v);
    return j;
  }
  static Json integer(std::int64_t v) {
    Json j;
    j.kind = Kind::Int;
    j.i = v;
    return j;
  }
  static Json object() {
    Json j;
    j.kind = Kind::Obj;
    return j;
  }
  static Json array() {
    Json j;
    j.kind = Kind::Arr;
    return j;
  }
  Json& set(const std::string& key, Json v);  // appends or replaces
};

bool operator==(const Json& a, const Json& b);  // Python ==: objects ignore order

// Parses `data` as pack.py's parse_json does. On error returns nullopt and the
// message pack.py reports (after "E-JSON <where>: ").
std::optional<Json> parse_json(const std::uint8_t* data, std::size_t size, std::string* error);
inline std::optional<Json> parse_json(const std::string& s, std::string* error) {
  return parse_json(reinterpret_cast<const std::uint8_t*>(s.data()), s.size(), error);
}

// Canonical JSON (RFC 8785 for this format's JSON): keys sorted, no whitespace,
// minimal escapes, UTF-8. Python's json.dumps(sort_keys=True, separators=(",",
// ":"), ensure_ascii=False).
std::string canonical_json(const Json& v);

// Python's repr() of the value the JSON parses to ('text', 12, [1, 2],
// {'a': True}, None).
std::string py_repr(const Json& v);
std::string py_repr(const std::string& utf8);

// Characters (code points) in a UTF-8 string; Python's len().
std::size_t utf8_length(const std::string& s);
// Decodes UTF-8 into code points (the input is valid: it came from the parser).
std::vector<std::uint32_t> utf8_decode(const std::string& s);

}  // namespace mvp::mods
