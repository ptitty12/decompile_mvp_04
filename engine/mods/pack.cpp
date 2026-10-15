#include "mods/pack.h"

#include <algorithm>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <sstream>

#include "common/sha256.h"
#include "mods/zip.h"

namespace mvp::mods {

// ---------------------------------------------------------------- small helpers
std::string sha256_hex(const std::string& data) { return Sha256::of(data.data(), data.size()); }
std::string sha256_hex(const std::vector<std::uint8_t>& data) { return Sha256::of(data.data(), data.size()); }

namespace {

std::filesystem::path host_path(const std::string& utf8) {
  return std::filesystem::path(std::u8string(reinterpret_cast<const char8_t*>(utf8.data()), utf8.size()));
}
std::string utf8_of(const std::filesystem::path& p) {
  const std::u8string u = p.u8string();
  return std::string(reinterpret_cast<const char*>(u.data()), u.size());
}

bool lower_alnum(char c) { return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'); }
bool alpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
bool digit(char c) { return c >= '0' && c <= '9'; }
bool alnum(char c) { return alpha(c) || digit(c); }

// ^[a-z0-9]+(-[a-z0-9]+)*$
bool is_pack_id(const std::string& s) {
  if (s.empty() || s.front() == '-' || s.back() == '-') return false;
  for (std::size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '-') {
      if (s[i + 1] == '-') return false;
    } else if (!lower_alnum(s[i])) {
      return false;
    }
  }
  return true;
}

// (0|[1-9]\d*)
bool is_number(const std::string& s) {
  if (s.empty()) return false;
  for (char c : s)
    if (!digit(c)) return false;
  return s == "0" || s[0] != '0';
}

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

std::optional<Semver> parse_semver(const Json& v) {
  if (!v.is_str()) return std::nullopt;
  auto p = split(v.s, '.');
  if (p.size() != 3 || !is_number(p[0]) || !is_number(p[1]) || !is_number(p[2])) return std::nullopt;
  return Semver{p[0], p[1], p[2]};
}
std::optional<Semver> parse_semver(const std::string& s) { return parse_semver(Json::string(s)); }

int compare_num(const std::string& a, const std::string& b) {
  if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
  return a < b ? -1 : a > b ? 1 : 0;
}

// One path segment: [A-Za-z0-9_][A-Za-z0-9._-]*
bool is_segment(const std::string& s) {
  if (s.empty() || !(alnum(s[0]) || s[0] == '_')) return false;
  for (char c : s)
    if (!(alnum(c) || c == '.' || c == '_' || c == '-')) return false;
  return true;
}
bool is_rel_path(const std::string& s) {
  for (const auto& seg : split(s, '/'))
    if (!is_segment(seg)) return false;
  return true;
}
bool is_game_path(const std::string& s) { return !s.empty() && s[0] == '/' && is_rel_path(s.substr(1)); }

// ^[A-Za-z][A-Za-z '.\-]*$
bool is_name_part(const std::string& s) {
  if (s.empty() || !alpha(s[0])) return false;
  for (char c : s)
    if (!(alpha(c) || c == ' ' || c == '\'' || c == '.' || c == '-')) return false;
  return true;
}
// ^[A-Za-z0-9][A-Za-z0-9 '.\-/]*$
bool is_team_text(const std::string& s) {
  if (s.empty() || !alnum(s[0])) return false;
  for (char c : s)
    if (!(alnum(c) || c == ' ' || c == '\'' || c == '.' || c == '-' || c == '/')) return false;
  return true;
}
bool is_abbr(const std::string& s) {
  if (s.empty() || s.size() > 3) return false;
  for (char c : s)
    if (!((c >= 'A' && c <= 'Z') || digit(c))) return false;
  return true;
}
bool is_team_code(const std::string& s) {
  if (s.empty() || s.size() > 3) return false;
  for (char c : s)
    if (!alnum(c)) return false;
  return true;
}
std::string lower(std::string s) {
  for (char& c : s)
    if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
  return s;
}
std::string upper(std::string s) {
  for (char& c : s)
    if (c >= 'a' && c <= 'z') c = static_cast<char>(c - 'a' + 'A');
  return s;
}
bool starts_with(const std::string& s, const std::string& p) { return s.compare(0, p.size(), p) == 0; }
bool ends_with(const std::string& s, const std::string& p) {
  return s.size() >= p.size() && s.compare(s.size() - p.size(), p.size(), p) == 0;
}
std::string join(const std::vector<std::string>& v, const std::string& sep) {
  std::string out;
  for (std::size_t i = 0; i < v.size(); ++i) out += (i ? sep : "") + v[i];
  return out;
}
bool contains(const std::vector<std::string>& v, const std::string& s) {
  return std::find(v.begin(), v.end(), s) != v.end();
}

const std::vector<std::string> kAssetRoots = {"/data/frontend/", "/data/models.big", "/data/stadium/",
                                              "/data/audio/spch_pbp/", "/data/audio/spch_pa/"};
const std::vector<std::string> kManifestKeys = {"id",          "name",    "version", "game",    "engine_api",
                                                "description", "authors", "license", "depends", "patches",
                                                "assets",      "meta"};
const std::vector<std::string> kRequiredManifest = {"id", "name", "version", "game", "engine_api", "patches"};

// ---------------------------------------------------------------- schema text (pack.py _SCHEMA_TEXT)
std::string pitch(int n, bool null) {
  const std::string q = null ? "?" : "", p = "pitchattrib_pitch" + std::to_string(n);
  return p + "_type:1-14" + q + " " + p + "_movement:0-15" + q + " " + p + "_description:0-7" + q + " " + p +
         "_control:0-99" + q + " " + p + "_velocity:47-101" + q;
}

std::map<std::string, std::string> schema_text() {
  std::string lr_attrib = "lrattrib_contact:0-100 lrattrib_power:0-100";
  for (const char* z : {"ul", "um", "ur", "cl", "cm", "cr", "ll", "lm", "lr"})
    lr_attrib += std::string(" lrattrib_hit_") + z + ":0-2";
  for (const char* z : {"lf", "cf", "rf", "hr", "fb", "ld", "gb"}) lr_attrib += std::string(" lrattrib_") + z + "_pct:0-100";
  auto lr_disc = [](const std::string& extra) {
    return "lrattrib_chasefb:0-15 lrattrib_chaseslowbreak:0-15 " + extra +
           "lrattrib_takefb:0-15 lrattrib_takeslowbreak:0-15 lrattrib_takehardbreak:0-15 "
           "lrattrib_missfb:0-15 lrattrib_missslowbreak:0-15 lrattrib_misshardbreak:0-15";
  };
  const std::string lrbat =
      "lrbatstat_1b:0-255 lrbatstat_2b:0-63 lrbatstat_3b:0-15 lrbatstat_hr:0-63 "
      "lrbatstat_rbi:0-127 lrbatstat_so:0-255 lrbatstat_bb:0-127 lrbatstat_ibb:0-31 "
      "lrbatstat_sh:0-31 lrbatstat_sf:0-15 lrbatstat_hbp:0-31 lrbatstat_tpa:0-1023";
  const std::string lrpit =
      "lrpitchstat_so:0-255 lrpitchstat_bb:0-127 lrpitchstat_ibb:0-15 lrpitchstat_hbp:0-15 "
      "lrpitchstat_sf:0-15 lrpitchstat_sh:0-15 lrpitchstat_1b:0-255 lrpitchstat_2b:0-63 "
      "lrpitchstat_3b:0-15 lrpitchstat_hr:0-63 lrpitchstat_tpa:0-1023";
  const std::string names = "!first_name:name !last_name:name ";
  std::string vs, strategy;
  for (const char* v : {"ana", "oak", "sea", "tex", "cws", "cle", "det", "kc",  "min", "bal", "bos",
                        "nyy", "tam", "tor", "ari", "col", "la",  "sdp", "sfg", "cub", "cin", "hou",
                        "mil", "pit", "stl", "atl", "fla", "mon", "nym", "phi", "al",  "nl"})
    vs += std::string(vs.empty() ? "" : " ") + "team_vs_" + v + ":0-2";
  for (const char* s : {"pinchhitter", "pinchrunner", "pitchersub", "defensivesub", "defensivealign", "takepitch",
                        "sacbunt", "buntforhit", "pickoff", "int_walks", "hitandrun", "steals", "advancebases",
                        "suicidesqueeze"})
    strategy += std::string(strategy.empty() ? "" : " ") + "team_" + s + ":0-2";
  std::string roster = "!roster_teamid:roster !roster_playerid:roster";
  for (const char* hl : {"rh_al", "rh_nl", "lh_al", "lh_nl"}) {
    const std::string h(hl, 2), l(hl + 3, 2);
    roster += " !" + h + "_roster_" + l + "_position:roster !" + h + "_roster_" + l + "_battingorder:roster";
  }
  std::map<std::string, std::string> t;
  t["attrib"] = names +
                "playerattrib_jerseynum:0-99 playerattrib_bats:0-2 playerattrib_throws:0-1 "
                "playerattrib_primary_position:0-10 playerattrib_secondary_position:0-13 "
                "playerattrib_height:18-35 playerattrib_weight:50-190 playerattrib_boneprofile:25-37 "
                "playerattrib_face:1-915 playerattrib_face2004style:0-1 playerattrib_skin_tone:0-10 "
                "playerattrib_hairstyle:0-9 playerattrib_haircolour:0-6 playerattrib_facialhair:0-7 "
                "playerattrib_bodytype:1-2 playerattrib_audioid:0-2665 playerattrib_photo:1-2 "
                "playerattrib_platediscipline:0-15 playerattrib_bunting:0-15 "
                "playerattrib_stealing_aggressive:0-15 playerattrib_baserunning:0-15 "
                "playerattrib_speed:0-99 playerattrib_fielding:0-15 playerattrib_range:0-15 "
                "playerattrib_throwstrength:0-15 playerattrib_throwaccuracy:0-15 "
                "playerattrib_durability:0-15 playerattrib_battingstance:0-65 playerattrib_swingtype:0-6 "
                "playerattrib_batcolour:0-7 playerattrib_batglove:0-1 playerattrib_wristband:0-6 "
                "playerattrib_elbowguard:0-3 playerattrib_shinguard:0-4 playerattrib_socks:0-2 "
                "playerattrib_catchermask:0-1 playerattrib_fieldglovecolour:0-4 playerattrib_ditty:0-6 "
                "playerattrib_salary:0-255 playerattrib_contract_length:1-7 playerattrib_starpower:0-4 "
                "playerattrib_topprospect:0-1 playerattrib_hidden:0-1 playerattrib_birthday:0-32767";
  t["lhattrib"] = names + lr_attrib + " " + lr_disc("");
  t["rhattrib"] = names + lr_attrib + " " + lr_disc("lrattrib_chasehardbreak:0-15 ");
  t["bstats"] = names + "batstat_g:0-255 batstat_r:0-255 batstat_sb:0-127 batstat_cs:0-31";
  t["fbstats"] = names + "fieldstat_g:0-255 fieldstat_po:0-2047 fieldstat_a:0-1023 fieldstat_e:0-31";
  t["lhbstats"] = names + lrbat;
  t["rhbstats"] = names + lrbat;
  t["career"] = names +
                "batcareerstats_g:0-4095 batcareerstats_ab:0-16383 batcareerstats_h:0-8191 "
                "batcareerstats_hr:0-1023 batcareerstats_rbi:0-4095 batcareerstats_r:0-4095 "
                "batcareerstats_sb:0-1023";
  t["pitcher"] = names +
                 "pitchattrib_stamina:0-99 pitchattrib_pickoff:0-15 pitchattrib_fastball_movement:0-0 "
                 "pitchattrib_fastball_description:0-0 pitchattrib_fastball_control:0-99 "
                 "pitchattrib_fastball_velocity:47-101 " +
                 pitch(2, false) + " " + pitch(3, true) + " " + pitch(4, true) + " " + pitch(5, true) +
                 " pitchattrib_pitcher_delivery:0-58";
  t["pstats"] = names +
                "pitchstat_g:0-127 pitchstat_gs:0-63 pitchstat_r:0-255 pitchstat_er:0-255 pitchstat_w:0-31 "
                "pitchstat_l:0-31 pitchstat_sv:0-63 pitchstat_blsv:0-15 pitchstat_cg:0-15 pitchstat_sho:0-3 "
                "pitchstat_pk:0-31 pitchstat_ip:0-255 pitchstat_pip:0-2";
  t["lhpstats"] = names + lrpit;
  t["rhpstats"] = names + lrpit;
  t["careerp"] = names +
                 "pitchcareer_g:0-2047 pitchcareer_ip:0-8191 pitchcareer_pip:0-2 pitchcareer_er:0-4095 "
                 "pitchcareer_w:0-511 pitchcareer_l:0-511 pitchcareer_sv:0-511 pitchcareer_so:0-8191 "
                 "pitchcareer_bb:0-4095";
  t["team"] =
      "!unique_team:code team_location:text13 team_long_name:text12 team_short_name:abbr "
      "!team_league:0-10 !team_division:0-25 !team_artid:1-126 team_climatezone:0-2 "
      "team_homeintensity:0-2 " +
      vs + " " + strategy;
  t["tstat"] =
      "!unique_team:code team_wins_1sthalf:0-127? team_losses_1sthalf:0-127? "
      "team_wins_2ndhalf:0-127? team_losses_2ndhalf:0-127?";
  t["roster"] = roster;
  t["org"] =
      "!unique_team:code !org_team_mlb:key !org_team_aaa:key !org_team_aa:key !org_team_a:key "
      "!org_is_franchise:0-1 !org_spring:0-1 org_budget:0-100000 !org_penalty1:0-0 "
      "!org_penalty2:0-0 !org_penalty3:0-0 !org_penalty4:0-0 org_mlb_manager:mgr "
      "org_minors_manager:mgr";
  t["manager"] = names +
                 "manager_jerseynum:0-99 manager_audioid:5000-5048 manager_height:72-72 "
                 "manager_weight:200-200 manager_boneprofile:27-37 manager_face:1-915 "
                 "manager_face2004style:0-1 manager_skintone:0-9 manager_hairstyle:0-3 "
                 "manager_haircolour:0-4 manager_facialhair:0-0 manager_bodytype:1-2 manager_hitting:0-100 "
                 "manager_baserunning:0-100 manager_fielding:0-100 manager_pitching:0-100 "
                 "manager_salary:0-15 manager_reallife:0-1 manager_birthday:0-8191";
  return t;
}

Column parse_column(std::string tok) {
  Column c;
  c.editable = tok[0] != '!';
  if (!c.editable) tok = tok.substr(1);
  const std::size_t colon = tok.find(':');
  c.name = tok.substr(0, colon);
  std::string kind = tok.substr(colon + 1);
  c.null = !kind.empty() && kind.back() == '?';
  if (c.null) kind.pop_back();
  const std::size_t dash = kind.find('-');
  if (dash != std::string::npos && dash > 0 && digit(kind[0])) {
    c.kind = "int";
    c.lo = std::stoll(kind.substr(0, dash));
    c.hi = std::stoll(kind.substr(dash + 1));
  } else {
    c.kind = kind;
  }
  return c;
}

}  // namespace

const std::vector<std::string> kTableOrder = {"attrib",  "lhattrib", "rhattrib", "bstats", "fbstats", "lhbstats",
                                              "lhpstats", "pstats",  "rhbstats", "rhpstats", "pitcher", "team",
                                              "tstat",   "roster",   "career",   "careerp",  "org",     "manager"};
const std::vector<std::string> kBatterTables = {"attrib",   "lhattrib", "rhattrib", "bstats",
                                                "fbstats",  "lhbstats", "rhbstats", "career"};
const std::vector<std::string> kPitcherTables = {"pitcher", "pstats", "lhpstats", "rhpstats", "careerp"};
const std::vector<std::string> kPlayerTables = {"attrib",   "lhattrib", "rhattrib", "bstats",  "fbstats",
                                                "lhbstats", "rhbstats", "career",   "pitcher", "pstats",
                                                "lhpstats", "rhpstats", "careerp"};
const std::vector<std::string> kLineups = {"rh_al", "rh_nl", "lh_al", "lh_nl"};
const std::vector<std::string> kFielders = {"C", "1B", "2B", "3B", "SS", "LF", "CF", "RF"};
const std::vector<std::string> kStarters = {"SP1", "SP2", "SP3", "SP4", "SP5"};
const std::vector<std::string> kPitchRoles = {"SP1", "SP2", "SP3", "SP4", "SP5", "LR", "MR", "SU", "CP"};
const std::vector<std::string> kRosterCodes = {"C",   "1B",  "2B",  "3B",  "SS", "LF", "CF", "RF", "DH",
                                               "SP1", "SP2", "SP3", "SP4", "SP5", "LR", "MR", "SU", "CP", "B"};

const Schema& schema() {
  static const Schema s = [] {
    Schema sc;
    for (const auto& [table, text] : schema_text()) {
      std::istringstream in(text);
      std::string tok;
      while (in >> tok) sc.tables[table].push_back(parse_column(tok));
    }
    return sc;
  }();
  return s;
}

const Column* Schema::column(const std::string& table, const std::string& name) const {
  auto it = tables.find(table);
  if (it == tables.end()) return nullptr;
  for (const auto& c : it->second)
    if (c.name == name) return &c;
  return nullptr;
}

int Schema::index(const std::string& table, const std::string& name) const {
  auto it = tables.find(table);
  if (it == tables.end()) return -1;
  for (std::size_t i = 0; i < it->second.size(); ++i)
    if (it->second[i].name == name) return static_cast<int>(i);
  return -1;
}

// ---------------------------------------------------------------- report
std::size_t Report::errors() const {
  std::size_t n = 0;
  for (const auto& i : issues)
    if (i.severity == "error") ++n;
  return n;
}

std::string Report::render() const {
  std::string out;
  for (const auto& i : issues) out += i.severity + " " + i.code + " " + i.where + ": " + i.message + "\n";
  out += std::to_string(errors()) + " error(s), " + std::to_string(issues.size() - errors()) + " warning(s)";
  return out;
}

Json Report::to_json() const {
  Json a = Json::array();
  for (const auto& i : issues) {
    Json o = Json::object();
    o.set("severity", Json::string(i.severity));
    o.set("code", Json::string(i.code));
    o.set("where", Json::string(i.where));
    o.set("message", Json::string(i.message));
    a.arr.push_back(std::move(o));
  }
  return a;
}

// ---------------------------------------------------------------- sources
namespace {

class MemorySource final : public PackSource {
 public:
  explicit MemorySource(std::map<std::string, std::vector<std::uint8_t>> files) : files_(std::move(files)) {}
  bool exists(const std::string& rel) override { return files_.count(rel) != 0; }
  std::uint64_t size(const std::string& rel) override { return files_.at(rel).size(); }
  std::optional<std::vector<std::uint8_t>> read(const std::string& rel, std::string*) override {
    return files_.at(rel);
  }

 private:
  std::map<std::string, std::vector<std::uint8_t>> files_;
};

// The single top-level folder that holds pack.json, when pack.json is not at the top.
template <typename Names>
std::string single_top(const Names& names) {
  if (names.count("pack.json")) return "";
  std::set<std::string> tops;
  for (const auto& [n, _] : names) tops.insert(n.substr(0, n.find('/')));
  if (tops.size() == 1 && names.count(*tops.begin() + "/pack.json")) return *tops.begin() + "/";
  return "";
}

class ZipSource final : public PackSource {
 public:
  explicit ZipSource(ZipArchive z) : zip_(std::move(z)) {
    std::map<std::string, const ZipEntry*> infos;
    for (const auto& e : zip_.entries())
      if (!e.is_dir()) infos[e.name] = &e;  // the last of duplicate names, as zipfile's dict
    const std::string prefix = single_top(infos);
    for (const auto& [n, e] : infos)
      if (starts_with(n, prefix)) files_[n.substr(prefix.size())] = e;
  }
  bool exists(const std::string& rel) override { return files_.count(rel) != 0; }
  std::uint64_t size(const std::string& rel) override { return files_.at(rel)->size; }
  std::optional<std::vector<std::uint8_t>> read(const std::string& rel, std::string* error) override {
    return zip_.read(*files_.at(rel), error);
  }

 private:
  ZipArchive zip_;
  std::map<std::string, const ZipEntry*> files_;
};

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

}  // namespace

std::unique_ptr<PackSource> memory_source(std::map<std::string, std::vector<std::uint8_t>> files,
                                          bool strip_single_top) {
  if (strip_single_top) {
    const std::string prefix = single_top(files);
    if (!prefix.empty()) {
      std::map<std::string, std::vector<std::uint8_t>> inner;
      for (auto& [n, d] : files)
        if (starts_with(n, prefix)) inner[n.substr(prefix.size())] = std::move(d);
      files = std::move(inner);
    }
  }
  return std::make_unique<MemorySource>(std::move(files));
}

std::unique_ptr<PackSource> zip_source(std::vector<std::uint8_t> bytes, std::string* error) {
  auto z = ZipArchive::open(std::move(bytes), error);
  if (!z) return nullptr;
  return std::make_unique<ZipSource>(std::move(*z));
}

std::unique_ptr<PackSource> dir_source(const std::string& root) { return std::make_unique<DirSource>(root); }

// ---------------------------------------------------------------- versions
int compare(const Semver& a, const Semver& b) {
  if (int c = compare_num(a.major, b.major)) return c;
  if (int c = compare_num(a.minor, b.minor)) return c;
  return compare_num(a.patch, b.patch);
}

bool version_matches(const std::string& req, const Semver& ver) {
  if (starts_with(req, "^")) {
    auto base = parse_semver(req.substr(1));
    if (!base || compare(ver, *base) < 0) return false;
    if (base->major != "0") return ver.major == base->major;
    if (base->minor != "0") return ver.major == base->major && ver.minor == base->minor;
    return compare(ver, *base) == 0;
  }
  auto base = parse_semver(req);
  return base && compare(ver, *base) == 0;
}

namespace {
bool valid_requirement(const Json& req) {
  return req.is_str() && parse_semver(starts_with(req.s, "^") ? req.s.substr(1) : req.s).has_value();
}
}  // namespace

// ---------------------------------------------------------------- packs
std::string Pack::where(const std::string& path, int index) const {
  std::string s = id.empty() ? label : id;
  if (!path.empty()) s += ":" + path;
  if (index >= 0) s += ":ops[" + std::to_string(index) + "]";
  return s;
}

std::string Pack::name() const {
  const Json* n = manifest ? manifest->get("name") : nullptr;
  return n && n->is_str() ? n->s : "";
}

std::string Pack::version_text() const {
  const Json* n = manifest ? manifest->get("version") : nullptr;
  return n && n->is_str() ? n->s : "";
}

namespace {

bool check_rel(const Json& p) {
  if (!p.is_str() || utf8_length(p.s) > 200 || !is_rel_path(p.s)) return false;
  for (const auto& seg : split(p.s, '/'))
    if (seg == "." || seg == "..") return false;
  return true;
}

std::optional<AssetTarget> check_asset_target(const Json* path, const Json* entry, Report& report,
                                              const std::string& where) {
  if (!(path && path->is_str() && is_game_path(path->s))) {
    report.error("E-ASSET", where, "path must be an absolute disc path like \"/data/frontend/logos.big\"");
    return std::nullopt;
  }
  const std::string low = lower(path->s);
  bool rooted = false;
  for (const auto& r : kAssetRoots) rooted = rooted || starts_with(low, r);
  if (!rooted) {
    report.error("E-ASSET", where, "path " + py_repr(path->s) + " is outside the v1 asset roots " + join(kAssetRoots, ", "));
    return std::nullopt;
  }
  const bool is_big = ends_with(low, ".big");
  const bool has_entry = entry && !entry->is_null();
  if (is_big && !has_entry) {
    report.error("E-ASSET", where, "a .big archive is replaced entry by entry: give \"entry\"");
    return std::nullopt;
  }
  if (!is_big && has_entry) {
    report.error("E-ASSET", where, "\"entry\" is only valid for .big archives");
    return std::nullopt;
  }
  if (has_entry && !(entry->is_str() && is_segment(entry->s))) {
    report.error("E-ASSET", where, "entry must be an archive entry name like \"l000.gsh\"");
    return std::nullopt;
  }
  AssetTarget t;
  t.path = low;
  t.has_entry = has_entry;
  if (has_entry) t.entry = lower(entry->s);
  return t;
}

}  // namespace

Pack load_pack(const std::string& label, PackSource* src, Report& report) {
  Pack pack;
  pack.label = label;
  if (!src) {
    report.error("E-PACK", label, "not a pack directory or zip file");
    return pack;
  }
  if (!src->exists("pack.json")) {
    report.error("E-PACK", label, "no pack.json at the top level");
    return pack;
  }
  std::string err;
  auto bytes = src->read("pack.json", &err);
  if (!bytes) {
    report.error("E-PACK", label, err);
    return pack;
  }
  auto parsed = parse_json(bytes->data(), bytes->size(), &err);
  if (!parsed) {
    report.error("E-JSON", pack.where("pack.json"), err);
    return pack;
  }
  if (!parsed->is_obj()) {
    report.error("E-MANIFEST", pack.where("pack.json"), "the manifest must be a JSON object");
    return pack;
  }
  pack.manifest = std::move(*parsed);
  const Json& m = *pack.manifest;
  std::string w = pack.where("pack.json");
  {
    std::vector<std::string> unknown;
    for (const auto& [k, _] : m.obj)
      if (!contains(kManifestKeys, k)) unknown.push_back(k);
    std::sort(unknown.begin(), unknown.end());
    for (const auto& k : unknown) report.error("E-MANIFEST", w, "unknown field " + py_repr(k));
  }
  for (const auto& k : kRequiredManifest)
    if (!m.has(k)) report.error("E-MANIFEST", w, "missing required field " + py_repr(k));
  if (const Json* id = m.get("id")) {
    if (id->is_str() && is_pack_id(id->s) && utf8_length(id->s) >= 3 && utf8_length(id->s) <= 64) {
      pack.id = id->s;
      w = pack.where("pack.json");
    } else {
      report.error("E-MANIFEST", w, "id must be 3-64 characters of a-z 0-9 and single hyphens");
    }
  }
  if (const Json* v = m.get("name"); v && !(v->is_str() && utf8_length(v->s) >= 1 && utf8_length(v->s) <= 100))
    report.error("E-MANIFEST", w, "name must be a string of 1-100 characters");
  if (const Json* v = m.get("version")) {
    pack.version = parse_semver(*v);
    if (!pack.version) report.error("E-MANIFEST", w, "version must be MAJOR.MINOR.PATCH");
  }
  if (const Json* v = m.get("game"); v && !(v->is_str() && v->s == kGameId))
    report.error("E-GAME", w, "game must be " + py_repr(std::string(kGameId)) + ", not " + py_repr(*v));
  if (const Json* v = m.get("engine_api")) {
    std::vector<std::string> p = v->is_str() ? split(v->s, '.') : std::vector<std::string>{};
    if (p.size() != 2 || !is_number(p[0]) || !is_number(p[1])) {
      report.error("E-MANIFEST", w, "engine_api must be MAJOR.MINOR, e.g. \"1.0\"");
    } else if (p[0] != std::to_string(kApiMajor) || compare_num(p[1], std::to_string(kApiMinor)) > 0) {
      report.error("E-ENGINE-API", w,
                   "targets engine API " + v->s + "; this implementation is " + std::to_string(kApiMajor) + "." +
                       std::to_string(kApiMinor));
    }
  }
  if (const Json* v = m.get("description"); v && !(v->is_str() && utf8_length(v->s) <= 2000))
    report.error("E-MANIFEST", w, "description must be a string of at most 2000 characters");
  if (const Json* v = m.get("license"); v && !(v->is_str() && utf8_length(v->s) <= 100))
    report.error("E-MANIFEST", w, "license must be a short string (an SPDX id)");
  if (const Json* v = m.get("authors")) {
    bool good = v->is_arr();
    if (good)
      for (const auto& a : v->arr) good = good && a.is_str() && utf8_length(a.s) >= 1 && utf8_length(a.s) <= 100;
    if (!good) report.error("E-MANIFEST", w, "authors must be a list of strings");
  }
  if (const Json* v = m.get("meta"); v && !v->is_obj()) report.error("E-MANIFEST", w, "meta must be an object");
  {
    const Json* deps = m.get("depends");
    std::vector<const Json*> list;
    Json none;
    if (!deps) {
    } else if (deps->is_arr()) {
      for (const auto& d : deps->arr) list.push_back(&d);
    } else {
      list.push_back(&none);
    }
    for (std::size_t i = 0; i < list.size(); ++i) {
      const Json& d = *list[i];
      const Json* did = d.get("id");
      const Json* dv = d.get("version");
      const bool good = d.is_obj() && d.obj.size() == 2 && did && dv && did->is_str() && is_pack_id(did->s) &&
                        valid_requirement(*dv);
      if (!good)
        report.error("E-MANIFEST", w,
                     "depends[" + std::to_string(i) +
                         "] must be {\"id\": <pack id>, \"version\": \"^X.Y.Z\" or \"X.Y.Z\"}");
      else
        pack.depends.emplace_back(did->s, dv->s);
    }
  }
  std::uint64_t total = 0;
  std::map<std::string, std::vector<std::uint8_t>> files;
  auto take = [&](const Json& rel, const std::string& what, std::uint64_t limit) -> const std::vector<std::uint8_t>* {
    if (!check_rel(rel)) {
      report.error("E-PATH", w, what + " path " + py_repr(rel) + " is not a valid relative path");
      return nullptr;
    }
    if (rel.s == "pack.json" || !src->exists(rel.s)) {
      report.error("E-PATH", w, what + " file " + py_repr(rel) + " not found (paths are case-sensitive)");
      return nullptr;
    }
    if (auto it = files.find(rel.s); it != files.end()) return &it->second;
    const std::uint64_t size = src->size(rel.s);
    total += size;
    if (size > limit) {
      report.error("E-PATH", w, what + " file " + py_repr(rel) + " is larger than " + std::to_string(limit) + " bytes");
      return nullptr;
    }
    std::string rerr;
    auto data = src->read(rel.s, &rerr);
    if (!data) {
      report.error("E-PACK", w, rerr);
      return nullptr;
    }
    return &(files[rel.s] = std::move(*data));
  };

  std::vector<Json> patches;
  if (const Json* p = m.get("patches")) {
    bool good = p->is_arr();
    if (good)
      for (const auto& x : p->arr) good = good && x.is_str();
    if (!good) report.error("E-MANIFEST", w, "patches must be a list of file paths");
    else patches = p->arr;
  }
  {
    std::set<std::string> uniq;
    for (const auto& p : patches) uniq.insert(p.s);
    if (uniq.size() != patches.size()) report.error("E-MANIFEST", w, "a patch file is listed twice");
  }
  for (const auto& rel : patches) {
    const auto* data = take(rel, "patch", kMaxPatchBytes);
    if (!data) continue;
    std::string jerr;
    auto obj = parse_json(data->data(), data->size(), &jerr);
    if (!obj) {
      report.error("E-JSON", pack.where(rel.s), jerr);
      continue;
    }
    const Json* ops = obj->get("ops");
    if (!(obj->is_obj() && obj->obj.size() == 1 && ops && ops->is_arr())) {
      report.error("E-OP", pack.where(rel.s), "a patch file is an object {\"ops\": [...]}");
      continue;
    }
    pack.digests[rel.s] = sha256_hex(canonical_json(*obj));
    Pack::Patch patch;
    patch.path = rel.s;
    for (std::size_t i = 0; i < ops->arr.size(); ++i)
      if (check_op(ops->arr[i], report, pack.where(rel.s, static_cast<int>(i))))
        patch.ops.emplace_back(static_cast<int>(i), ops->arr[i]);
    pack.patches.push_back(std::move(patch));
  }

  std::vector<const Json*> assets;
  if (const Json* a = m.get("assets")) {
    if (!a->is_arr()) report.error("E-MANIFEST", w, "assets must be a list");
    else
      for (const auto& x : a->arr) assets.push_back(&x);
  }
  std::vector<AssetTarget> seen;
  for (std::size_t i = 0; i < assets.size(); ++i) {
    const Json& a = *assets[i];
    const std::string aw = pack.where("pack.json") + ":assets[" + std::to_string(i) + "]";
    bool shape = a.is_obj() && a.has("path") && a.has("file");
    if (shape)
      for (const auto& [k, _] : a.obj) shape = shape && (k == "path" || k == "entry" || k == "file");
    if (!shape) {
      report.error("E-ASSET", aw, "an asset is {\"path\", [\"entry\"], \"file\"}");
      continue;
    }
    auto target = check_asset_target(a.get("path"), a.get("entry"), report, aw);
    const Json& file = *a.get("file");
    const auto* data = file.is_str() ? take(file, "asset", kMaxAssetBytes) : nullptr;
    if (!data || !target) {
      if (!file.is_str()) report.error("E-ASSET", aw, "file must be a relative path");
      continue;
    }
    if (data->size() >= 4 && (std::equal(data->begin(), data->begin() + 4, "BIGF") ||
                              std::equal(data->begin(), data->begin() + 4, "LOCH"))) {
      report.error("E-ASSET", aw,
                   "asset files must be authored content, not archives or LOC files (replace single entries; use "
                   "loc.set for text)");
      continue;
    }
    if (std::find(seen.begin(), seen.end(), *target) != seen.end()) {
      report.error("E-ASSET", aw, "two assets map to " + target->label());
      continue;
    }
    seen.push_back(*target);
    pack.digests[file.s] = sha256_hex(*data);
    pack.assets.push_back({*target, file.s, *data, aw});
  }
  if (total > kMaxPackBytes)
    report.error("E-PACK", w, "pack content is larger than " + std::to_string(kMaxPackBytes) + " bytes");
  Json files_obj = Json::object();
  for (const auto& [k, v] : pack.digests) files_obj.set(k, Json::string(v));
  Json top = Json::object();
  top.set("manifest", *pack.manifest);
  top.set("files", std::move(files_obj));
  pack.hash = sha256_hex("mvp2005-pack-hash/1\n" + canonical_json(top));
  return pack;
}

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

// ---------------------------------------------------------------- static op checks
namespace {

struct OpFields {
  std::vector<std::string> required, optional;
};
const std::map<std::string, OpFields>& op_fields() {
  static const std::map<std::string, OpFields> m = {
      {"player.add", {{"op", "player"}, {"pitcher", "set"}}},
      {"player.edit", {{"op", "player"}, {"pitcher", "set"}}},
      {"player.remove", {{"op", "player"}, {}}},
      {"player.rename", {{"op", "player", "to"}, {}}},
      {"roster.set", {{"op", "team", "entries"}, {"release"}}},
      {"roster.replace", {{"op", "team", "out", "in"}, {"release"}}},
      {"roster.swap", {{"op", "a", "b"}, {}}},
      {"team.edit", {{"op", "team", "set"}, {}}},
      {"manager.edit", {{"op", "set"}, {"manager", "team"}}},
      {"manager.rename", {{"op", "to"}, {"manager", "team"}}},
      {"loc.set", {{"op", "file", "strings"}, {}}},
      {"team.names", {{"op", "team"}, {"location", "nickname", "abbreviation", "full_name"}}},
  };
  return m;
}

std::vector<std::string> set_groups(const std::string& kind) {
  if (kind == "player.add" || kind == "player.edit") return kPlayerTables;
  if (kind == "team.edit") return {"team", "tstat", "org"};
  if (kind == "manager.edit") return {"manager"};
  return {};
}

const char* const kLocExtra = "\xC2\xA0\xC2\xA9\xC2\xAE\xE2\x80\xA6\xE2\x84\xA2";  // U+00A0 U+00A9 U+00AE U+2026 U+2122

bool check_loc(const Json& file, const Json& strings, Report& report, const std::string& where) {
  bool ok = true;
  bool known = false;
  if (file.is_str())
    for (const char* f : kLocFiles) known = known || upper(file.s) == upper(f);
  if (!known) {
    report.error("E-LOC", where, "file must be one of FEENG.LOC, IGENG.LOC, MC_ENG.loc");
    ok = false;
  }
  if (!strings.is_obj() || strings.obj.empty()) {
    report.error("E-LOC", where, "strings must be a non-empty object {\"<id>\": \"text\"}");
    return false;
  }
  for (const auto& [k, v] : strings.obj) {
    bool id_ok = !k.empty() && k.size() <= 5 && (k == "0" || (k[0] >= '1' && k[0] <= '9'));
    for (char c : k) id_ok = id_ok && digit(c);
    if (id_ok && std::stol(k) > 65535) id_ok = false;
    if (!id_ok) {
      report.error("E-LOC", where, "string id " + py_repr(k) + " must be a decimal number 0-65535");
      ok = false;
    }
    bool text_ok = v.is_str() && utf8_length(v.s) <= 400;
    if (text_ok)
      for (std::uint32_t c : utf8_decode(v.s))
        text_ok = text_ok && ((c >= 0x20 && c < 0x7F) || c == 0xA0 || c == 0xA9 || c == 0xAE || c == 0x2026 ||
                              c == 0x2122);
    if (!text_ok) {
      report.error("E-LOC", where,
                   "string " + k +
                       ": text must be at most 400 characters of printable ASCII (plus U+00A0 U+00A9 U+00AE "
                       "U+2026 U+2122)");
      ok = false;
    }
  }
  (void)kLocExtra;
  return ok;
}

bool check_set(const Json& op, const std::string& kind, Report& report, const std::string& where) {
  const Json& groups = *op.get("set");
  const auto allowed = set_groups(kind);
  if (!groups.is_obj()) {
    report.error("E-OP", where, "set must be an object {table: {column: value}}");
    return false;
  }
  bool ok = true;
  const Json* pitcher = op.get("pitcher");
  for (const auto& [table, fields] : groups.obj) {
    if (!contains(allowed, table)) {
      report.error("E-FIELD", where,
                   "table " + py_repr(table) + " cannot be set by " + kind + " (allowed: " + join(allowed, ", ") + ")");
      ok = false;
      continue;
    }
    if (kind == "player.add" && contains(kPitcherTables, table) && !(pitcher && pitcher->truthy())) {
      report.error("E-OP", where, "set." + table + " needs \"pitcher\": true");
      ok = false;
    }
    if (!fields.is_obj()) {
      report.error("E-OP", where, "set." + table + " must be an object {column: value}");
      ok = false;
      continue;
    }
    for (const auto& [name, value] : fields.obj) {
      const Column* col = schema().column(table, name);
      if (!col) {
        report.error("E-FIELD", where, table + " has no column " + py_repr(name));
        ok = false;
      } else if (!col->editable) {
        const std::string hint = col->kind == "name" ? " (use player.rename / manager.rename)" : "";
        report.error("E-FIELD", where, table + "." + name + " cannot be set by a pack" + hint);
        ok = false;
      } else if (!check_value(*col, value, report, where + " set." + table + "." + name)) {
        ok = false;
      }
    }
  }
  return ok;
}

bool check_names_op(const Json& op, Report& report, const std::string& where) {
  if (op.obj.size() == 2) {
    report.error("E-OP", where, "team.names needs at least one of location, nickname, abbreviation, full_name");
    return false;
  }
  bool ok = true;
  const std::pair<const char*, const char*> fields[] = {
      {"location", "team_location"}, {"nickname", "team_long_name"}, {"abbreviation", "team_short_name"}};
  for (const auto& [field, col] : fields)
    if (const Json* v = op.get(field))
      ok = check_value(*schema().column("team", col), *v, report, where + " " + field) && ok;
  if (const Json* full = op.get("full_name")) {
    Json strings = Json::object();
    strings.set("0", *full);
    ok = check_loc(Json::string("FEENG.LOC"), strings, report, where) && ok;
  }
  return ok;
}

std::optional<std::pair<std::string, std::string>> parse_slot(const Json& text) {
  if (!text.is_str()) return std::nullopt;
  const std::string& s = text.s;
  const std::size_t colon = s.find(':');
  const std::string code = s.substr(0, colon);
  if (code.empty()) return std::nullopt;
  for (char c : code)
    if (!((c >= 'A' && c <= 'Z') || digit(c))) return std::nullopt;
  std::string order = "-1";
  if (colon != std::string::npos) {
    const std::string n = s.substr(colon + 1);
    if (n.size() != 1 || n[0] < '1' || n[0] > '9') return std::nullopt;
    order = n;
  }
  if (!contains(kRosterCodes, code)) return std::nullopt;
  return std::make_pair(code, order);
}

}  // namespace

std::optional<std::pair<std::string, std::string>> check_name(const Json& name, Report& report,
                                                              const std::string& where, const std::string& what) {
  if (!name.is_str()) {
    report.error("E-NAME", where, what + " name must be a string \"Last,First\"");
    return std::nullopt;
  }
  auto parts = split(name.s, ',');
  if (parts.size() != 2) {
    report.error("E-NAME", where, what + " name " + py_repr(name.s) + " must be \"Last,First\" with one comma");
    return std::nullopt;
  }
  const std::pair<std::size_t, const char*> lims[2] = {{14, "last"}, {13, "first"}};
  for (int k = 0; k < 2; ++k) {
    const std::string& part = parts[static_cast<std::size_t>(k)];
    if (!is_name_part(part) || part.back() == ' ' || part.find("  ") != std::string::npos) {
      report.error("E-NAME", where,
                   what + " name " + py_repr(name.s) + ": " + lims[k].second +
                       " name may use letters, space, ' - . and must start with a letter");
      return std::nullopt;
    }
    if (part.size() > lims[k].first) {
      report.error("E-NAME", where,
                   what + " name " + py_repr(name.s) + ": " + lims[k].second + " name longer than " +
                       std::to_string(lims[k].first) + " characters");
      return std::nullopt;
    }
  }
  return std::make_pair(parts[0], parts[1]);
}

bool check_value(const Column& col, const Json& v, Report& report, const std::string& where) {
  if (col.kind == "int") {
    if (col.null && v.is_str() && v.s == "-") return true;
    if (!v.is_int()) {
      report.error("E-VALUE", where, std::string("must be an integer") + (col.null ? " or \"-\"" : ""));
      return false;
    }
    if (v.i < col.lo || v.i > col.hi) {
      report.error("E-VALUE", where,
                   std::to_string(v.i) + " is outside " + std::to_string(col.lo) + "-" + std::to_string(col.hi));
      return false;
    }
    return true;
  }
  if (starts_with(col.kind, "text")) {
    const std::size_t lim = static_cast<std::size_t>(std::stoi(col.kind.substr(4)));
    if (!(v.is_str() && is_team_text(v.s) && v.s.back() != ' ' && v.s.size() <= lim)) {
      report.error("E-VALUE", where,
                   "must be 1-" + std::to_string(lim) +
                       " characters of A-Z a-z 0-9 space ' . - / starting with a letter or digit");
      return false;
    }
    return true;
  }
  if (col.kind == "abbr") {
    if (!(v.is_str() && is_abbr(v.s))) {
      report.error("E-VALUE", where, "must be 1-3 characters of A-Z 0-9");
      return false;
    }
    return true;
  }
  if (col.kind == "mgr") return check_name(v, report, where, "manager").has_value();
  report.error("E-FIELD", where, "column cannot be set");
  return false;
}

std::optional<std::vector<std::vector<std::string>>> check_entries(const Json& entries, Report& report,
                                                                   const std::string& where) {
  if (!entries.is_arr() || entries.arr.empty()) {
    report.error("E-ROSTER", where, "entries must be a non-empty list");
    return std::nullopt;
  }
  std::vector<std::vector<std::string>> out;
  bool ok = true;
  for (std::size_t i = 0; i < entries.arr.size(); ++i) {
    const Json& e = entries.arr[i];
    const std::string ew = where + " entries[" + std::to_string(i) + "]";
    bool shape = e.is_obj() && e.has("player");
    if (shape)
      for (const auto& [k, _] : e.obj) shape = shape && (k == "player" || k == "pos" || contains(kLineups, k));
    if (!shape) {
      report.error("E-ROSTER", ew, "an entry is {\"player\", \"pos\", \"rh_al\", \"rh_nl\", \"lh_al\", \"lh_nl\"}");
      ok = false;
      continue;
    }
    if (!check_name(*e.get("player"), report, ew)) {
      ok = false;
      continue;
    }
    std::vector<std::string> row{e.get("player")->s};
    bool good = true;
    for (const auto& ln : kLineups) {
      const Json* t = e.get(ln);
      if (!t) t = e.get("pos");
      if (!t || t->is_null()) {
        report.error("E-ROSTER", ew, "no position for lineup " + ln + " (give \"pos\" or \"" + ln + "\")");
        good = false;
        break;
      }
      auto slot = parse_slot(*t);
      if (!slot) {
        report.error("E-ROSTER", ew,
                     ln + ": " + py_repr(*t) + " is not CODE or CODE:N (codes " + join(kRosterCodes, " ") + "; N 1-9)");
        good = false;
        break;
      }
      row.push_back(slot->first);
      row.push_back(slot->second);
    }
    if (good) out.push_back(std::move(row));
    else ok = false;
  }
  if (!ok) return std::nullopt;
  return out;
}

bool check_op(const Json& op, Report& report, const std::string& where_in) {
  const Json* kindv = op.get("op");
  if (!op.is_obj() || !kindv || !kindv->is_str()) {
    report.error("E-OP", where_in, "an op is an object with an \"op\" field");
    return false;
  }
  const std::string kind = kindv->s;
  auto it = op_fields().find(kind);
  if (it == op_fields().end()) {
    report.error("E-OP", where_in, "unknown op " + py_repr(kind));
    return false;
  }
  const auto& [req, opt] = it->second;
  bool ok = true;
  std::vector<std::string> missing, unknown;
  for (const auto& k : req)
    if (!op.has(k)) missing.push_back(k);
  for (const auto& [k, _] : op.obj)
    if (!contains(req, k) && !contains(opt, k)) unknown.push_back(k);
  std::sort(missing.begin(), missing.end());
  std::sort(unknown.begin(), unknown.end());
  for (const auto& k : missing) {
    report.error("E-OP", where_in, kind + ": missing field " + py_repr(k));
    ok = false;
  }
  for (const auto& k : unknown) {
    report.error("E-OP", where_in, kind + ": unknown field " + py_repr(k));
    ok = false;
  }
  if (!ok) return false;
  const std::string where = where_in + " (" + kind + ")";
  const std::string what = starts_with(kind, "manager.") ? "manager" : "player";
  for (const char* k : {"player", "to", "out", "in", "a", "b", "manager"})
    if (const Json* v = op.get(k); v && !check_name(*v, report, where, what)) ok = false;
  if (const Json* v = op.get("pitcher"); v && !v->is_bool()) {
    report.error("E-OP", where, "pitcher must be true or false");
    ok = false;
  }
  if (const Json* v = op.get("release"); v && !(v->is_str() && (v->s == "keep" || v->s == "remove"))) {
    report.error("E-OP", where, "release must be \"keep\" or \"remove\"");
    ok = false;
  }
  if (const Json* v = op.get("team"); v && !(v->is_str() && is_team_code(v->s))) {
    report.error("E-OP", where, "team must be a unique_team code such as \"Ana\"");
    ok = false;
  }
  if (starts_with(kind, "manager.") && op.has("manager") == op.has("team")) {
    report.error("E-OP", where, "give either \"manager\" (a name) or \"team\" (the club whose MLB manager is meant)");
    ok = false;
  }
  if (kind == "player.edit" && !op.has("set") && !op.has("pitcher")) {
    report.error("E-OP", where, "player.edit needs \"set\" or \"pitcher\"");
    ok = false;
  }
  if (op.has("set")) ok = check_set(op, kind, report, where) && ok;
  if (kind == "roster.set") ok = check_entries(*op.get("entries"), report, where).has_value() && ok;
  if (kind == "loc.set") ok = check_loc(*op.get("file"), *op.get("strings"), report, where) && ok;
  if (kind == "team.names") ok = check_names_op(op, report, where) && ok;
  return ok;
}

// ---------------------------------------------------------------- composition and hashes
std::map<std::string, std::set<std::string>> check_set_order(const std::vector<Pack>& packs, Report& report) {
  std::map<std::string, std::set<std::string>> deps;
  std::map<std::string, const Pack*> seen;
  for (const auto& p : packs) {
    if (p.id.empty()) continue;
    if (seen.count(p.id)) {
      report.error("E-DUPLICATE", p.where(), "pack id " + py_repr(p.id) + " appears twice in the set");
      continue;
    }
    std::set<std::string> closure;
    for (const auto& [did, req] : p.depends) {
      if (did == p.id) {
        report.error("E-DEPENDENCY", p.where(), "a pack cannot depend on itself");
      } else if (!seen.count(did)) {
        bool later = false;
        for (const auto& q : packs) later = later || q.id == did;
        report.error("E-DEPENDENCY", p.where(),
                     "depends on " + py_repr(did) + ", which " +
                         (later ? "must come earlier in the set" : "is not in the set"));
      } else if (!version_matches(req, seen[did]->version.value_or(Semver{"0", "0", "0"}))) {
        const std::string have = seen[did]->version ? seen[did]->version->text() : "None";
        report.error("E-DEPENDENCY", p.where(), "depends on " + did + " " + req + ", the set has " + have);
      } else {
        closure.insert(did);
        closure.insert(deps[did].begin(), deps[did].end());
      }
    }
    deps[p.id] = closure;
    seen[p.id] = &p;
  }
  return deps;
}

std::string set_hash(const std::vector<Pack>& packs) {
  Json list = Json::array();
  for (const auto& p : packs) {
    Json o = Json::object();
    o.set("id", p.id.empty() ? Json{} : Json::string(p.id));
    const Json* v = p.manifest ? p.manifest->get("version") : nullptr;
    o.set("version", v ? *v : Json{});
    o.set("hash", p.hash.empty() ? Json{} : Json::string(p.hash));
    list.arr.push_back(std::move(o));
  }
  Json top = Json::object();
  top.set("packs", std::move(list));
  return sha256_hex("mvp2005-packset-hash/1\n" + canonical_json(top));
}

std::string empty_set_hash() { return set_hash({}); }

}  // namespace mvp::mods
