// Data-free tests of the engine's roster-pack implementation (docs/MODDING.md).
// Expected values come from the reference tool, tools/rosters/pack.py (run on the
// same inputs); engine/mods/tests/crosscheck.py compares the two on pack.py's own
// synthetic disc and test packs. Nothing here is game data.
#include <doctest/doctest.h>

#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#include "common/file.h"
#include "mods/apply.h"
#include "mods/json.h"
#include "mods/mount.h"
#include "mods/pack.h"
#include "mods/tables.h"
#include "mods/zip.h"
#include "vfs/big.h"
#include "vfs/refpack.h"

using namespace mvp;
using namespace mvp::mods;

namespace {

std::string parse_error(const std::string& text) {
  std::string err;
  auto v = parse_json(text, &err);
  return v ? "OK " + canonical_json(*v) : err;
}

std::string repo_root() {
  const char* r = std::getenv("MVP_REPO_ROOT");
  return r ? r : "";
}

}  // namespace

TEST_CASE("strict JSON: pack.py's messages and positions") {
  // Each expectation is pack.parse_json's message for the same bytes (Python 3.12).
  const std::vector<std::pair<std::string, std::string>> cases = {
      {R"({"ops": [], "ops": []})", "duplicate key 'ops'"},
      {R"({"ops": [1.5]})", "non-integer number 1.5 (only integers are allowed)"},
      {R"({"ops": [NaN]})", "NaN is not allowed"},
      {R"({"ops": [9999999999]})", "$.ops[0]: integer 9999999999 outside the signed 32-bit range"},
      {"{\"a\": \"\xff\"}", "not UTF-8 (invalid start byte)"},
      {"[1,]", "line 1 column 4: Expecting value"},
      {R"({"a" 1})", "line 1 column 6: Expecting ':' delimiter"},
      {R"({"a": 1,})", "line 1 column 9: Expecting property name enclosed in double quotes"},
      {"{a: 1}", "line 1 column 2: Expecting property name enclosed in double quotes"},
      {"[1 2]", "line 1 column 4: Expecting ',' delimiter"},
      {R"({"a": [1, 2)", "line 1 column 12: Expecting ',' delimiter"},
      {"\"abc", "line 1 column 1: Unterminated string starting at"},
      {R"("a\qb")", "line 1 column 3: Invalid \\escape"},
      {R"("\u12")", "line 1 column 3: Invalid \\uXXXX escape"},
      {R"("\u12g4")", "line 1 column 3: Invalid \\uXXXX escape"},
      {"\n\n  [tru]", "line 3 column 4: Expecting value"},
      {"01", "line 1 column 2: Extra data"},
      {"1e5", "non-integer number 1e5 (only integers are allowed)"},
      {"-", "line 1 column 1: Expecting value"},
      {"[-Infinity]", "-Infinity is not allowed"},
      {"\"\x01\"", "line 1 column 2: Invalid control character at"},
      {R"({"é": 1})", "$: object key '\xc3\xa9' must be printable ASCII"},
      {R"({"a": "\ud800"})", "$.a: string holds a lone surrogate"},
      {"\xef\xbb\xbf\xef\xbb\xbf{}", "line 1 column 1: Unexpected UTF-8 BOM (decode using utf-8-sig)"},
      {R"({"a":1} x)", "line 1 column 9: Extra data"},
      {"", "line 1 column 1: Expecting value"},
      {R"({"k": {"x": 1, "x": 2}})", "duplicate key 'x'"},
      {"\xe0\x80", "not UTF-8 (invalid continuation byte)"},
      {"\xed\xa0\x80", "not UTF-8 (invalid continuation byte)"},
      {"{\"a\": \"\xf0\x9f\x98\"}", "not UTF-8 (invalid continuation byte)"},
      {"[1, 2]   ", "OK [1,2]"},
      {R"({"a": "x\"y", "b'": 1, "c": [true, false, null, -0, 12]})",
       R"(OK {"a":"x\"y","b'":1,"c":[true,false,null,0,12]})"},
      {"1.0", "non-integer number 1.0 (only integers are allowed)"},
      {"[1.5e3]", "non-integer number 1.5e3 (only integers are allowed)"},
      {R"({"a":1e})", "line 1 column 7: Expecting ',' delimiter"},
      {R"({"t": "tab\there\u0001é😀", "z": {"b": 2, "a": 1}})",
       "OK {\"t\":\"tab\\there\\u0001\xc3\xa9\xf0\x9f\x98\x80\",\"z\":{\"a\":1,\"b\":2}}"},
      {R"("\ud83dx")", "$: string holds a lone surrogate"},
  };
  for (const auto& [in, want] : cases) {
    INFO(in);
    CHECK(parse_error(in) == want);
  }
  // A leading byte-order mark is ignored.
  CHECK(parse_error("\xef\xbb\xbf{\"a\": 1}") == "OK {\"a\":1}");
}

TEST_CASE("Python repr of values in messages") {
  CHECK(py_repr(std::string("Doe,Jane")) == "'Doe,Jane'");
  CHECK(py_repr(std::string("it's")) == "\"it's\"");
  CHECK(py_repr(std::string("a'b\"c")) == "'a\\'b\"c'");
  CHECK(py_repr(std::string("tab\there\n")) == "'tab\\there\\n'");
  std::string err;
  auto v = parse_json(R"([1, true, null, {"a": "b"}, "x"])", &err);
  REQUIRE(v);
  CHECK(py_repr(*v) == "[1, True, None, {'a': 'b'}, 'x']");
}

TEST_CASE("djb2 keys") {
  CHECK(djb2("Ana") == 0x0B87D5F5u);
  CHECK(key_of("Ana") == "00b87d5f5");
  CHECK(djb2("Smith,Ab") == djb2("Smith,BA"));  // the documented collision
}

TEST_CASE("RefPack round trip, and the compressor's stream form") {
  std::string text;
  for (int i = 0; i < 4000; ++i) text += "0 first_name,1 last_name," + std::to_string(i % 97) + ",;\r\n";
  std::vector<std::uint8_t> in(text.begin(), text.end());
  auto packed = vfs::refpack::compress(in);
  CHECK(packed.size() < in.size() / 4);
  CHECK(vfs::refpack::is_refpack(packed));
  auto back = vfs::refpack::decompress(packed);
  REQUIRE(back);
  CHECK(*back == in);
  // Short inputs: header, literals, stop.
  std::vector<std::uint8_t> abc = {'a', 'b', 'c'};
  CHECK(vfs::refpack::compress(abc) == std::vector<std::uint8_t>{0x10, 0xFB, 0, 0, 3, 0xFF, 'a', 'b', 'c'});
  CHECK(*vfs::refpack::decompress(vfs::refpack::compress({})) == std::vector<std::uint8_t>{});
  // Corrupt streams are refused, never read out of bounds.
  auto bad = packed;
  bad.resize(bad.size() / 2);
  CHECK(!vfs::refpack::decompress(bad));
}

TEST_CASE("BIG archives rebuild byte for byte and keep their alignment") {
  const std::vector<std::pair<std::string, std::vector<std::uint8_t>>> items = {
      {"a.dat", {1, 2, 3}}, {"B.gsh", {4, 5, 6, 7, 8}}, {"c.dat", {9}}};
  for (std::uint32_t align : {4u, 128u}) {
    auto bytes = vfs::build_big(items, 2, align);
    auto arc = vfs::BigArchive::parse(bytes);
    REQUIRE(arc);
    CHECK(arc->payload_alignment() == align);
    CHECK(arc->flag() == 2);
    CHECK(arc->rebuild({}, align) == bytes);
    const vfs::BigEntry* e = arc->find("b.GSH");
    REQUIRE(e);
    CHECK(arc->raw(*e) == items[1].second);
    auto changed = arc->rebuild({{"B.gsh", {42}}}, align);
    auto arc2 = vfs::BigArchive::parse(changed);
    REQUIRE(arc2);
    CHECK(arc2->raw(*arc2->find("B.gsh")) == std::vector<std::uint8_t>{42});
    CHECK(arc2->raw(*arc2->find("c.dat")) == items[2].second);
    CHECK(arc2->payload_alignment() == align);
  }
  CHECK(!vfs::BigArchive::parse(std::vector<std::uint8_t>{'B', 'I', 'G'}));
}

TEST_CASE("tables and LOC files re-serialize exactly") {
  const std::string text = "0 first_name,1 last_name,2 x,;\r\n000001505,0 Default,1 Default,2 -,;\r\n0abc,0 A,1 B,2 7,;\r\n";
  auto t = Table::parse("t", std::vector<std::uint8_t>(text.begin(), text.end()), nullptr);
  REQUIRE(t);
  CHECK(t->fields == std::vector<std::string>{"first_name", "last_name", "x"});
  CHECK(t->rows.size() == 2);
  CHECK(*t->serialize() == text);
  t->rows[1][3] = "a,b";
  CHECK(!t->serialize());
  CHECK(canon_int("12") == 12);
  CHECK(canon_int("-3") == -3);
  CHECK(!canon_int("012"));
  CHECK(!canon_int("-0"));
  CHECK(!canon_int("-"));

  Loc loc;
  using E = std::pair<std::uint16_t, std::string>;
  loc.entries = {E{std::uint16_t{2010}, "Lanterns"}, E{std::uint16_t{7}, "Caf\xc3\xa9 \xe2\x84\xa2"},
                 E{std::uint16_t{17618}, "Harbor City"}, E{std::uint16_t{9}, ""}};
  auto bytes = loc.serialize();
  auto back = Loc::parse(bytes, nullptr);
  REQUIRE(back);
  CHECK(back->entries == loc.entries);
  CHECK(back->serialize() == bytes);
  CHECK(bytes.size() % 4 == 0);
}

TEST_CASE("zip packs: deflate, one top folder, the same hash as pack.py") {
  // A zip written by Python's zipfile (deflated), holding zip-test/pack.json,
  // zip-test/patches/p.json and a README. pack.py: no issues, hash 9947a065...
  static const char kZip[] =
#include "zip_vector.inc"
      ;
  std::vector<std::uint8_t> bytes(kZip, kZip + sizeof kZip - 1);
  CHECK(ZipArchive::is_zip(bytes));
  std::string err;
  auto src = zip_source(bytes, &err);
  REQUIRE(src);
  Report r;
  Pack p = load_pack("z.zip", src.get(), r);
  CHECK(r.render() == "0 error(s), 0 warning(s)");
  CHECK(p.id == "zip-test");
  CHECK(p.hash == "9947a0650b8f6f3a7a3f1e22a3be21015cb68d25c08df12efda731acedf27173");
  CHECK(set_hash({p}) == "10a8369a1423503d070bcfaf8010652c7eec9317c7f353d805858d30bc7008ab");
  // A damaged entry is refused.
  bytes[60] ^= 0x55;
  auto src2 = zip_source(bytes, &err);
  REQUIRE(src2);
  Report r2;
  load_pack("z.zip", src2.get(), r2);
  CHECK(!r2.ok());
}

TEST_CASE("the example pack: static validation and the documented hashes") {
  const std::string root = repo_root();
  if (root.empty()) return;  // run by ctest with MVP_REPO_ROOT
  Report r;
  Pack p = load_pack_path(root + "/docs/examples/packs/fictional-league", r);
  CHECK(r.render() == "0 error(s), 0 warning(s)");
  CHECK(p.id == "fictional-league");
  CHECK(p.patches.size() == 3);
  // docs/MODDING.md §12.
  CHECK(p.hash == "e83c0341774a0363d2ce834624a8ca62bbc944a9e005806fd025f42bb2aab4f5");
  CHECK(set_hash({p}) == "b9a04e6578e789b4abe0f8a95d4c269ebda1881ace871e083c399f1d6023cafb");
  // The same files handed over by a browser (a picked folder: one top folder).
  std::map<std::string, std::vector<std::uint8_t>> files;
  for (const char* rel : {"pack.json", "patches/players.json", "patches/harbor-city.json", "patches/tweaks.json"})
    files[std::string("fictional-league/") + rel] = *read_file(root + "/docs/examples/packs/fictional-league/" + rel);
  files["fictional-league/notes.txt"] = {'x'};
  auto src = memory_source(files);
  Report r2;
  CHECK(load_pack("fictional-league", src.get(), r2).hash == p.hash);
}

TEST_CASE("the empty set and set order") {
  CHECK(empty_set_hash() == "f5e1298911db13adf522a1b34d4d4f9291b42fa7a77f63a5f6f07bc322dcc66e");
  auto mk = [](const std::string& id) {
    std::map<std::string, std::vector<std::uint8_t>> f;
    const std::string m = "{\"id\": \"" + id +
                          "\", \"name\": \"n\", \"version\": \"1.0.0\", \"game\": \"GV4E69-0\", \"engine_api\": \"1.0\", "
                          "\"patches\": []}";
    f["pack.json"] = std::vector<std::uint8_t>(m.begin(), m.end());
    auto src = memory_source(f);
    Report r;
    return load_pack(id, src.get(), r);
  };
  Pack a = mk("pack-a"), b = mk("pack-b");
  CHECK(set_hash({a, b}) != set_hash({b, a}));
  CHECK(set_hash({a, b}) == set_hash({a, b}));
}

TEST_CASE("version requirements") {
  auto v = [](const char* s) {
    std::string t(s);
    const auto d1 = t.find('.'), d2 = t.rfind('.');
    return Semver{t.substr(0, d1), t.substr(d1 + 1, d2 - d1 - 1), t.substr(d2 + 1)};
  };
  CHECK(version_matches("^1.2.0", v("1.4.0")));
  CHECK(!version_matches("^1.2.0", v("2.0.0")));
  CHECK(!version_matches("^1.2.0", v("1.1.9")));
  CHECK(version_matches("^0.2.1", v("0.2.5")));
  CHECK(!version_matches("^0.2.1", v("0.3.0")));
  CHECK(version_matches("1.2.3", v("1.2.3")));
  CHECK(!version_matches("1.2.3", v("1.2.4")));
  CHECK(version_matches("^1.9.0", v("1.10.0")));  // numeric, not lexical
}

TEST_CASE("static op checks: codes and places as pack.py reports them") {
  // test_pack.py test_op_errors_are_reported_with_their_location.
  const std::string ops = R"({"ops": [
    {"op": "player.fly", "player": "Doe,Jane"},
    {"op": "player.add", "player": "Doe,Jane", "set": {"attrib": {"playerattrib_speed": 120}}},
    {"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"first_name": "Jo"}}},
    {"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"no_such": 1}}},
    {"op": "player.add", "player": "Doe Jane"},
    {"op": "player.add", "player": "Doe,Jane", "set": {"pitcher": {}}},
    {"op": "roster.set", "team": "Aaa", "entries": [{"player": "Doe,Jane", "pos": "QB"}]},
    {"op": "team.edit", "team": "Aaa", "set": {"team": {"team_league": 3}}},
    {"op": "loc.set", "file": "FEENG.LOC", "strings": {"12": "badé"}}
  ]})";
  const std::string manifest =
      R"({"id": "bad-ops", "name": "bad-ops", "version": "1.0.0", "game": "GV4E69-0", "engine_api": "1.0", "patches": ["patches/p0.json"]})";
  std::map<std::string, std::vector<std::uint8_t>> f;
  f["pack.json"] = std::vector<std::uint8_t>(manifest.begin(), manifest.end());
  f["patches/p0.json"] = std::vector<std::uint8_t>(ops.begin(), ops.end());
  auto src = memory_source(f);
  Report r;
  load_pack("bad-ops", src.get(), r);
  std::vector<std::pair<std::string, std::string>> got;
  for (const auto& i : r.issues) {
    const auto at = i.where.find(":ops[");
    got.emplace_back(i.code, i.where.substr(at + 5, i.where.find(']', at) - at - 5));
  }
  const std::vector<std::pair<std::string, std::string>> want = {
      {"E-OP", "0"},    {"E-VALUE", "1"}, {"E-FIELD", "2"},  {"E-FIELD", "3"}, {"E-NAME", "4"},
      {"E-OP", "5"},    {"E-ROSTER", "6"}, {"E-FIELD", "7"}, {"E-LOC", "8"}};
  CHECK(got == want);
  CHECK(r.issues[0].message == "unknown op 'player.fly'");
  CHECK(r.issues[1].where == "bad-ops:patches/p0.json:ops[1] (player.add) set.attrib.playerattrib_speed");
  CHECK(r.issues[1].message == "120 is outside 0-99");
}
