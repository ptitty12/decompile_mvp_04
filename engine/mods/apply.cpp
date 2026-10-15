#include "mods/apply.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <cstdio>
#include <set>
#include <unordered_map>

#include "common/bytes.h"
#include "common/sha1.h"
#include "mods/tables.h"
#include "vfs/big.h"
#include "vfs/disc_check.h"
#include "vfs/refpack.h"

namespace mvp::mods {

namespace {

using Cell = std::vector<std::string>;
using Row = std::vector<std::string>;

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
std::string join(const std::vector<std::string>& v, const std::string& sep) {
  std::string out;
  for (std::size_t i = 0; i < v.size(); ++i) out += (i ? sep : "") + v[i];
  return out;
}
bool contains(const std::vector<std::string>& v, const std::string& s) {
  return std::find(v.begin(), v.end(), s) != v.end();
}
std::size_t table_index(const std::string& t) {
  return static_cast<std::size_t>(std::find(kPlayerTables.begin(), kPlayerTables.end(), t) - kPlayerTables.begin());
}
int col(const std::string& table, const std::string& name) { return schema().index(table, name); }
std::string u8(const std::string& latin1) { return latin1_to_utf8(latin1); }

// Python's _to_text: strings as they are, integers in decimal.
std::string to_text(const Json& v) { return v.is_str() ? v.s : v.big.empty() ? std::to_string(v.i) : v.big; }

std::string signed_text(const std::string& key9) {
  const std::uint32_t v = static_cast<std::uint32_t>(std::stoul(key9, nullptr, 16));
  return std::to_string(static_cast<std::int64_t>(static_cast<std::int32_t>(v)));
}

std::int64_t to_int(const std::string& s) {
  auto v = canon_int(s);
  if (v) return *v;
  try {
    return std::stoll(s);
  } catch (...) {
    return -1;
  }
}

std::string cell_label(const Cell& c) {
  const std::string& kind = c[0];
  auto rest = [&](std::size_t from) {
    std::vector<std::string> r(c.begin() + static_cast<std::ptrdiff_t>(from), c.end());
    return join(r, ".");
  };
  if (kind == "P") return "player " + c[1] + (c.size() == 2 ? "" : " " + rest(2));
  if (kind == "R") return "the roster of " + c[1];
  if (kind == "T") return "team " + c[1] + (c.size() == 2 ? "" : " " + rest(2));
  if (kind == "M") return "manager " + c[1] + (c.size() == 2 ? "" : " " + c[2]);
  if (kind == "L") return c[1] + " string " + c[2];
  return "asset " + c[1] + (c.size() > 2 ? " entry " + c[2] : "");
}

// ---------------------------------------------------------------- the model
struct Player {
  std::string key, name;  // latin-1, "Last,First"
  std::array<std::optional<Row>, 13> vals;  // kPlayerTables order
  bool pitcher() const { return vals[8].has_value(); }
};

struct SlotTables {
  std::map<std::string, std::vector<std::uint32_t>> ids;
  std::map<std::size_t, std::size_t> tid_of_row;
  std::vector<std::uint32_t> row_of_tid;

  std::vector<std::size_t> sharers(const std::string& kind, std::size_t tid) const {
    const auto& v = ids.at(kind);
    std::vector<std::size_t> out;
    for (std::size_t t = 0; t < v.size(); ++t)
      if (v[t] == v[tid] && t != tid) out.push_back(t);
    return out;
  }
};

SlotTables read_slots(const std::vector<std::uint8_t>& dol, const std::vector<std::string>& team_codes,
                      const SlotConfig& cfg) {
  if (Sha1::of(dol.data(), dol.size()) != cfg.dol_sha1)
    throw PackError{"main.dol is not GV4E69 rev 0 (SHA-1 mismatch)"};
  if (dol.size() < 0xD8) throw PackError{"main.dol is too short"};
  std::array<std::uint32_t, 18> offs{}, addrs{}, sizes{};
  for (int i = 0; i < 18; ++i) {
    offs[i] = be32(dol.data() + 4 * i);
    addrs[i] = be32(dol.data() + 0x48 + 4 * i);
    sizes[i] = be32(dol.data() + 0x90 + 4 * i);
  }
  auto read = [&](std::uint32_t addr, std::uint32_t n) -> const std::uint8_t* {
    for (int i = 0; i < 18; ++i)
      if (sizes[i] && addrs[i] <= addr && std::uint64_t(addr) + n <= std::uint64_t(addrs[i]) + sizes[i]) {
        const std::uint64_t at = std::uint64_t(offs[i]) + (addr - addrs[i]);
        if (at + n > dol.size()) break;
        return dol.data() + at;
      }
    char b[64];
    std::snprintf(b, sizeof b, "address %#x is not in main.dol", addr);
    throw PackError{b};
  };
  const std::uint32_t n = cfg.count;
  auto words = [&](std::uint32_t addr) {
    const std::uint8_t* p = read(addr, 4 * n);
    std::vector<std::uint32_t> w(n);
    for (std::uint32_t i = 0; i < n; ++i) w[i] = be32(p + 4 * i);
    return w;
  };
  SlotTables s;
  const auto rows = words(cfg.tid_row);
  s.ids["full"] = words(cfg.full);
  s.ids["nickname"] = words(cfg.nickname);
  s.ids["abbreviation"] = words(cfg.abbreviation);
  s.ids["city"] = words(cfg.city);
  const auto names = words(cfg.tid_names);
  for (std::size_t t = 0; t < names.size(); ++t) {
    std::uint32_t end = names[t];
    while (*read(end, 1) != 0) ++end;
    const std::uint8_t* p = end > names[t] ? read(names[t], end - names[t]) : nullptr;
    const std::string name = p ? std::string(reinterpret_cast<const char*>(p), end - names[t]) : std::string();
    if (rows[t] >= team_codes.size() || team_codes[rows[t]] != name)
      throw PackError{"main.dol tid " + std::to_string(t) + " (" + u8(name) + ") does not match team.dat"};
    s.tid_of_row[rows[t]] = t;
  }
  s.row_of_tid = rows;
  return s;
}

struct Model {
  // database.big
  std::optional<vfs::BigArchive> archive;
  std::map<std::string, Table> tables;
  std::map<std::string, std::vector<std::uint8_t>> orig_text;
  // LOC files (disc spelling), and Python's dict(entries).items() of the originals
  std::map<std::string, Loc> locs;
  std::map<std::string, std::vector<std::pair<std::uint16_t, std::string>>> loc_orig_items;
  std::map<std::string, std::map<std::uint16_t, std::string>> loc_orig;

  std::vector<std::string> order;
  std::unordered_map<std::string, Player> players;
  std::string default_key;
  std::vector<Row> teams;  // team rows without the key: [unique_team, ...]
  std::vector<std::string> team_keys;
  std::map<std::string, std::size_t> code_index;
  std::map<std::string, Row> tstat, org, managers;
  std::vector<std::string> org_order, manager_order;
  std::vector<std::string> roster_codes;  // in team order
  std::map<std::string, std::vector<Row>> rosters;  // code -> [[player key, c0, o0, ... c3, o3]]
  std::size_t start_players = 0, start_pitchers = 0;

  DiscFiles* disc = nullptr;
  const SlotConfig* slot_cfg = nullptr;
  std::optional<SlotTables> slots;

  Player* player(const std::string& name) {
    auto it = players.find(key_of(name));
    return it != players.end() && it->second.name == name ? &it->second : nullptr;
  }
  Row* team_row(const std::string& code) {
    auto it = code_index.find(code);
    return it == code_index.end() ? nullptr : &teams[it->second];
  }
  std::int64_t team_league(const std::string& code) {
    return to_int(teams[code_index.at(code)][static_cast<std::size_t>(col("team", "team_league"))]);
  }
  std::optional<std::string> manager_key(const std::string& name) {
    const std::string k = key_of(name);
    auto it = managers.find(k);
    if (it != managers.end() && it->second[1] + "," + it->second[0] == name) return k;
    return std::nullopt;
  }
  // player key -> the codes of the rosters that list him, in team order
  std::map<std::string, std::vector<std::string>> homes() const {
    std::map<std::string, std::vector<std::string>> out;
    for (const auto& code : roster_codes)
      for (const auto& e : rosters.at(code)) out[e[0]].push_back(code);
    return out;
  }
  std::size_t pitchers() const {
    std::size_t n = 0;
    for (const auto& [k, p] : players) n += p.pitcher();
    return n;
  }
};

const std::vector<std::uint8_t>& need(const std::optional<std::vector<std::uint8_t>>& v, const std::string& path,
                                      const DiscFiles& disc) {
  if (!v) throw PackError{path + " not found on " + disc.label()};
  return *v;
}

std::unique_ptr<Model> load_model(DiscFiles& disc, const SlotConfig& cfg) {
  auto m = std::make_unique<Model>();
  m->disc = &disc;
  m->slot_cfg = &cfg;
  std::string err;
  {
    auto db = disc.read(kDatabasePath);
    m->archive = vfs::BigArchive::parse(need(db, kDatabasePath, disc), &err);
    if (!m->archive) throw PackError{"cannot read the disc tables: " + err};
    for (const auto& e : m->archive->entries()) {
      if (lower(e.name).size() < 4 || lower(e.name).substr(lower(e.name).size() - 4) != ".dat") continue;
      const std::string name = e.name.substr(0, e.name.size() - 4);
      auto data = m->archive->read(e, &err);
      if (!data) throw PackError{"cannot read the disc tables: " + err};
      auto t = Table::parse(name, *data, &err);
      if (!t) throw PackError{"cannot read the disc tables: " + err};
      m->orig_text[name] = std::move(*data);
      m->tables[name] = std::move(*t);
    }
  }
  for (const char* f : kLocFiles) {
    const std::string path = std::string("/data/") + f;
    auto bytes = disc.read(path);
    auto loc = Loc::parse(need(bytes, path, disc), &err);
    if (!loc) throw PackError{"cannot read the disc tables: " + err};
    auto& items = m->loc_orig_items[f];
    auto& orig = m->loc_orig[f];
    for (const auto& [sid, text] : loc->entries) {
      if (!orig.count(sid)) items.emplace_back(sid, text);
      else
        for (auto& it : items)
          if (it.first == sid) it.second = text;
      orig[sid] = text;
    }
    m->locs[f] = std::move(*loc);
  }
  auto& t = m->tables;
  for (const auto& name : kTableOrder) {
    if (!t.count(name)) throw PackError{"database.big has no " + name + " table"};
    std::vector<std::string> want;
    for (const auto& c : schema().tables.at(name)) want.push_back(c.name);
    if (t[name].fields != want) throw PackError{name + " columns differ from format v1 (not GV4E69 rev 0?)"};
  }
  for (const auto& r : t["attrib"].rows) {
    m->order.push_back(r[0]);
    Player p;
    p.key = r[0];
    p.name = r[2] + "," + r[1];
    p.vals[0] = Row(r.begin() + 1, r.end());
    m->players[r[0]] = std::move(p);
  }
  for (std::size_t bi = 1; bi < kBatterTables.size(); ++bi) {
    const auto& name = kBatterTables[bi];
    const auto& rows = t[name].rows;
    bool same = rows.size() == m->order.size();
    for (std::size_t i = 0; same && i < rows.size(); ++i) same = rows[i][0] == m->order[i];
    if (!same) throw PackError{name + " rows are not in attrib order"};
    for (const auto& r : rows) m->players[r[0]].vals[table_index(name)] = Row(r.begin() + 1, r.end());
  }
  std::vector<std::string> pk;
  for (const auto& r : t["pitcher"].rows) pk.push_back(r[0]);
  {
    const std::set<std::string> pks(pk.begin(), pk.end());
    std::vector<std::string> sub;
    for (const auto& k : m->order)
      if (pks.count(k)) sub.push_back(k);
    if (sub != pk) throw PackError{"pitcher rows are not a subsequence of attrib"};
  }
  for (const auto& name : kPitcherTables) {
    const auto& rows = t[name].rows;
    bool same = rows.size() == pk.size();
    for (std::size_t i = 0; same && i < rows.size(); ++i) same = rows[i][0] == pk[i];
    if (!same) throw PackError{name + " rows are not in pitcher order"};
    for (const auto& r : rows) m->players[r[0]].vals[table_index(name)] = Row(r.begin() + 1, r.end());
  }
  for (const auto& k : m->order)
    if (key_of(m->players[k].name) != k) throw PackError{"player key " + k + " does not match its name"};
  m->default_key = key_of(kDefaultName);
  for (const auto& r : t["team"].rows) {
    m->teams.emplace_back(r.begin() + 1, r.end());
    m->team_keys.push_back(r[0]);
  }
  for (std::size_t i = 0; i < m->teams.size(); ++i) m->code_index[m->teams[i][0]] = i;
  for (std::size_t i = 0; i < m->teams.size(); ++i)
    if (key_of(m->teams[i][0]) != m->team_keys[i]) throw PackError{"team key does not match unique_team"};
  for (const auto& r : t["tstat"].rows) m->tstat[r[0]] = Row(r.begin() + 1, r.end());
  for (const auto& r : t["org"].rows) {
    if (!m->org.count(r[0])) m->org_order.push_back(r[0]);
    m->org[r[0]] = Row(r.begin() + 1, r.end());
  }
  for (const auto& r : t["manager"].rows) {
    m->managers[r[0]] = Row(r.begin() + 1, r.end());
    m->manager_order.push_back(r[0]);
  }
  std::map<std::string, std::string> by_team_key;
  for (std::size_t i = 0; i < m->teams.size(); ++i) by_team_key[m->team_keys[i]] = m->teams[i][0];
  for (const auto& r : m->teams)
    if (!m->rosters.count(r[0])) {
      m->rosters[r[0]];
      m->roster_codes.push_back(r[0]);
    }
  for (const auto& r : t["roster"].rows) {
    auto it = by_team_key.find(r[1]);
    if (it == by_team_key.end()) throw PackError{"roster row " + r[0] + " names an unknown team key " + r[1]};
    Row e{r[2]};
    e.insert(e.end(), r.begin() + 3, r.end());
    m->rosters[it->second].push_back(std::move(e));
  }
  m->start_players = m->players.size();
  m->start_pitchers = m->pitchers();
  return m;
}

// ---------------------------------------------------------------- the applier
class Applier {
 public:
  Applier(Model& m, Report& r, const std::map<std::string, std::set<std::string>>& deps) : m_(m), r_(r), deps_(deps) {}

  void run(const std::vector<Pack>& packs) {
    for (const auto& pack : packs) {
      pack_ = &pack;
      for (const auto& patch : pack.patches)
        for (const auto& [i, op] : patch.ops) {
          const std::string kind = op.get("op")->s;
          where_ = pack.where(patch.path, i) + " (" + kind + ")";
          if (kind == "player.add") op_player_add(op);
          else if (kind == "player.edit") op_player_edit(op);
          else if (kind == "player.remove") op_player_remove(op);
          else if (kind == "player.rename") op_player_rename(op);
          else if (kind == "roster.set") op_roster_set(op);
          else if (kind == "roster.replace") op_roster_replace(op);
          else if (kind == "roster.swap") op_roster_swap(op);
          else if (kind == "team.edit") op_team_edit(op);
          else if (kind == "manager.edit") op_manager_edit(op);
          else if (kind == "manager.rename") op_manager_rename(op);
          else if (kind == "loc.set") op_loc_set(op);
          else if (kind == "team.names") op_team_names(op);
        }
      for (const auto& a : pack.assets) {
        where_ = a.where;
        Cell c{"A", a.target.path};
        if (a.target.has_entry) c.push_back(a.target.entry);
        write(c, c);
      }
    }
  }

 private:
  Model& m_;
  Report& r_;
  const std::map<std::string, std::set<std::string>>& deps_;
  const Pack* pack_ = nullptr;
  std::string where_;
  std::map<Cell, std::string> writer_;
  std::map<Cell, std::set<std::string>> touched_;

  // ---- conflict tracking
  bool foreign(const std::string* pid) const {
    if (!pid || *pid == pack_->id) return false;
    auto it = deps_.find(pack_->id);
    return it == deps_.end() || !it->second.count(*pid);
  }
  bool write(const Cell& cell, const Cell& entity) {
    auto it = writer_.find(cell);
    if (it != writer_.end() && foreign(&it->second)) {
      r_.error("E-CONFLICT", where_,
               cell_label(cell) + " was already changed by pack " + py_repr(it->second) +
                   "; declare a dependency on it to build on it");
      return false;
    }
    writer_[cell] = pack_->id;
    touched_[entity].insert(pack_->id);
    return true;
  }
  bool use(const Cell& entity) {
    auto it = writer_.find(entity);
    if (it != writer_.end() && foreign(&it->second)) {
      r_.error("E-CONFLICT", where_,
               cell_label(entity) + " comes from pack " + py_repr(it->second) + "; declare a dependency on it");
      return false;
    }
    return true;
  }
  bool whole(const Cell& entity) {
    std::vector<std::string> bad;
    if (auto it = touched_.find(entity); it != touched_.end())
      for (const auto& p : it->second)
        if (foreign(&p)) bad.push_back(p);  // std::set iterates sorted
    if (!bad.empty()) {
      r_.error("E-CONFLICT", where_,
               cell_label(entity) + " was changed by pack(s) " + join(bad, ", ") +
                   "; declare a dependency to remove or rename it");
      return false;
    }
    writer_[entity] = pack_->id;
    touched_[entity].insert(pack_->id);
    return true;
  }
  void rekey(const std::string& kind, const std::string& old, const std::string& now) {
    std::set<std::string> t;
    if (auto it = touched_.find({kind, old}); it != touched_.end()) {
      t = std::move(it->second);
      touched_.erase(it);
    }
    t.insert(pack_->id);
    touched_[{kind, now}] = std::move(t);
    std::vector<std::pair<Cell, std::string>> moved;
    for (auto it = writer_.begin(); it != writer_.end();) {
      if (it->first.size() >= 2 && it->first[0] == kind && it->first[1] == old) {
        Cell c = it->first;
        c[1] = now;
        moved.emplace_back(std::move(c), std::move(it->second));
        it = writer_.erase(it);
      } else {
        ++it;
      }
    }
    for (auto& [c, w] : moved) writer_[c] = std::move(w);
    writer_[{kind, now}] = pack_->id;
  }

  // ---- helpers
  Player* get_player(const std::string& name, const std::string& what = "player") {
    if (name == kDefaultName) {
      r_.error("E-PROTECTED", where_, "the Default,Default row cannot be changed");
      return nullptr;
    }
    Player* p = m_.player(name);
    if (!p) {
      r_.error("E-NOT-FOUND", where_, "no " + what + " " + py_repr(name));
      return nullptr;
    }
    if (!use({"P", p->key})) return nullptr;
    return p;
  }
  std::optional<std::string> new_key(const std::string& name) {
    const std::string k = key_of(name);
    auto it = m_.players.find(k);
    if (it != m_.players.end()) {
      if (it->second.name == name)
        r_.error("E-KEY-EXISTS", where_, "player " + py_repr(name) + " already exists");
      else
        r_.error("E-KEY-EXISTS", where_,
                 py_repr(name) + " has the same key " + k + " as " + py_repr(u8(it->second.name)) +
                     " (djb2 collision); choose another spelling");
      return std::nullopt;
    }
    return k;
  }
  Row default_row(const std::string& table) { return *m_.players.at(m_.default_key).vals[table_index(table)]; }
  void set_fields(Player& p, const Json* groups) {
    if (!groups) return;
    for (const auto& [table, fields] : groups->obj) {
      auto& vals = p.vals[table_index(table)];
      if (!vals) {
        r_.error("E-OP", where_,
                 contains(kPitcherTables, table) ? u8(p.name) + " is not a pitcher; set \"pitcher\": true first"
                                                 : u8(p.name) + " has no " + table + " row");
        continue;
      }
      for (const auto& [c, v] : fields.obj)
        if (write({"P", p.key, table, c}, {"P", p.key}))
          (*p.vals[table_index(table)])[static_cast<std::size_t>(col(table, c))] = to_text(v);
    }
  }
  void make_pitcher(Player& p, bool flag) {
    if (flag == p.pitcher()) return;
    if (!write({"P", p.key, "pitcher"}, {"P", p.key})) return;
    if (flag) {
      const std::string first = (*p.vals[0])[0], last = (*p.vals[0])[1];
      for (const auto& t : kPitcherTables) {
        Row r{first, last};
        Row d = default_row(t);
        r.insert(r.end(), d.begin() + 2, d.end());
        p.vals[table_index(t)] = std::move(r);
      }
    } else {
      for (const auto& t : kPitcherTables) p.vals[table_index(t)].reset();
    }
  }
  void drop(std::string key) {  // by value: `key` may belong to the erased player
    m_.players.erase(key);
    m_.order.erase(std::find(m_.order.begin(), m_.order.end(), key));
  }
  static std::pair<std::string, std::string> split_name(const std::string& n) {
    const std::size_t c = n.find(',');
    return {n.substr(0, c), n.substr(c + 1)};
  }

  // ---- player ops
  void op_player_add(const Json& op) {
    const std::string name = op.get("player")->s;
    const auto [last, first] = split_name(name);
    auto k = new_key(name);
    if (!k || !whole({"P", *k})) return;
    Player p;
    p.key = *k;
    p.name = name;
    const Json* pit = op.get("pitcher");
    for (const auto& t : kPlayerTables) {
      if (contains(kPitcherTables, t) && !(pit && pit->truthy())) continue;
      Row r{first, last};
      Row d = default_row(t);
      r.insert(r.end(), d.begin() + 2, d.end());
      p.vals[table_index(t)] = std::move(r);
    }
    m_.players[*k] = std::move(p);
    m_.order.push_back(*k);
    set_fields(m_.players[*k], op.get("set"));
  }
  void op_player_edit(const Json& op) {
    Player* p = get_player(op.get("player")->s);
    if (!p) return;
    if (const Json* f = op.get("pitcher")) make_pitcher(*p, f->b);
    set_fields(*p, op.get("set"));
  }
  void op_player_remove(const Json& op) {
    Player* p = get_player(op.get("player")->s);
    if (!p) return;
    const auto homes = m_.homes();
    if (auto it = homes.find(p->key); it != homes.end() && !it->second.empty()) {
      r_.error("E-ROSTER", where_,
               u8(p->name) + " is still on the roster of " + join(it->second, ", ") +
                   "; replace him there first (roster.replace with \"release\": \"remove\")");
      return;
    }
    if (whole({"P", p->key})) drop(p->key);
  }
  void op_player_rename(const Json& op) {
    Player* p = get_player(op.get("player")->s);
    if (!p) return;
    const std::string to = op.get("to")->s;
    auto k = new_key(to);
    if (!k || !whole({"P", p->key}) || !whole({"P", *k})) return;
    const auto [last, first] = split_name(to);
    const std::string old = p->key;
    for (auto& v : p->vals)
      if (v) {
        (*v)[0] = first;
        (*v)[1] = last;
      }
    Player moved = std::move(*p);
    moved.key = *k;
    moved.name = to;
    m_.players.erase(old);
    m_.players[*k] = std::move(moved);
    *std::find(m_.order.begin(), m_.order.end(), old) = *k;
    for (auto& [code, entries] : m_.rosters)
      for (auto& e : entries)
        if (e[0] == old) e[0] = *k;
    rekey("P", old, *k);
  }

  // ---- roster ops
  bool team(const std::string& code) {
    if (!m_.team_row(code)) {
      r_.error("E-NOT-FOUND", where_, "no team with unique_team " + py_repr(code));
      return false;
    }
    return true;
  }
  void release(const std::vector<std::string>& players, const Json* mode) {
    if (!(mode && mode->is_str() && mode->s == "remove")) return;
    const auto homes = m_.homes();
    for (const auto& k : players) {
      if (!m_.players.count(k) || k == m_.default_key) continue;
      if (auto it = homes.find(k); it != homes.end() && !it->second.empty()) continue;
      if (whole({"P", k})) drop(k);
    }
  }
  void op_roster_set(const Json& op) {
    const std::string code = op.get("team")->s;
    if (!team(code)) return;
    Report scratch;
    auto rows = check_entries(*op.get("entries"), scratch, "");
    std::vector<Row> fresh;
    for (const auto& row : *rows) {
      Player* p = get_player(row[0]);
      if (!p) return;
      Row e{p->key};
      e.insert(e.end(), row.begin() + 1, row.end());
      fresh.push_back(std::move(e));
    }
    if (!write({"R", code}, {"R", code})) return;
    std::vector<std::string> before;
    for (const auto& e : m_.rosters[code]) before.push_back(e[0]);
    m_.rosters[code] = std::move(fresh);
    release(before, op.get("release"));
  }
  void op_roster_replace(const Json& op) {
    const std::string code = op.get("team")->s;
    if (!team(code)) return;
    Player* out = get_player(op.get("out")->s);
    Player* in = get_player(op.get("in")->s);
    if (!out || !in) return;
    const std::string out_key = out->key, in_key = in->key;
    auto& entries = m_.rosters[code];
    Row* hit = nullptr;
    for (auto& e : entries)
      if (e[0] == out_key) {
        hit = &e;
        break;
      }
    if (!hit) {
      r_.error("E-ROSTER", where_, u8(out->name) + " is not on the roster of " + code);
      return;
    }
    for (const auto& e : entries)
      if (e[0] == in_key) {
        r_.error("E-ROSTER", where_, u8(in->name) + " is already on the roster of " + code);
        return;
      }
    if (write({"R", code}, {"R", code})) {
      (*hit)[0] = in_key;
      release({out_key}, op.get("release"));
    }
  }
  void op_roster_swap(const Json& op) {
    Player* a = get_player(op.get("a")->s);
    Player* b = get_player(op.get("b")->s);
    if (!a || !b) return;
    if (a->key == b->key) {
      r_.error("E-ROSTER", where_, "a player cannot be swapped with himself");
      return;
    }
    const auto homes = m_.homes();
    auto clubs = [&](const std::string& k) {
      std::vector<std::string> out;
      if (auto it = homes.find(k); it != homes.end())
        for (const auto& c : it->second)
          if (c != "AL" && c != "NL") out.push_back(c);
      return out;
    };
    const auto ha = clubs(a->key), hb = clubs(b->key);
    if (ha.size() != 1 || hb.size() != 1) {
      r_.error("E-ROSTER", where_, "roster.swap needs both players on exactly one team other than the All-Star sides");
      return;
    }
    if (!(write({"R", ha[0]}, {"R", ha[0]}) && write({"R", hb[0]}, {"R", hb[0]}))) return;
    Row* ea = nullptr;
    Row* eb = nullptr;
    for (auto& e : m_.rosters[ha[0]])
      if (!ea && e[0] == a->key) ea = &e;
    for (auto& e : m_.rosters[hb[0]])
      if (!eb && e[0] == b->key) eb = &e;
    if (ha[0] == hb[0]) {
      Row ta(ea->begin() + 1, ea->end()), tb(eb->begin() + 1, eb->end());
      std::copy(tb.begin(), tb.end(), ea->begin() + 1);
      std::copy(ta.begin(), ta.end(), eb->begin() + 1);
    } else {
      (*ea)[0] = b->key;
      (*eb)[0] = a->key;
    }
  }

  // ---- teams, managers, text
  void op_team_edit(const Json& op) {
    const std::string code = op.get("team")->s;
    if (!team(code)) return;
    const std::string key = key_of(code);
    for (const auto& [table, fields] : op.get("set")->obj) {
      Row* row = nullptr;
      if (table == "team") row = m_.team_row(code);
      else if (table == "tstat") row = m_.tstat.count(key) ? &m_.tstat[key] : nullptr;
      else row = m_.org.count(key) ? &m_.org[key] : nullptr;
      if (!row) {
        r_.error("E-NOT-FOUND", where_, "team " + code + " has no " + table + " row");
        continue;
      }
      for (const auto& [c, v0] : fields.obj) {
        std::string text = to_text(v0);
        if (table == "org" && (c == "org_mlb_manager" || c == "org_minors_manager")) {
          auto mk = m_.manager_key(v0.s);
          if (!mk) {
            r_.error("E-NOT-FOUND", where_, "no manager " + py_repr(v0.s));
            continue;
          }
          if (!use({"M", *mk})) continue;
          text = signed_text(*mk);
        }
        if (write({"T", code, table, c}, {"T", code})) {
          (*row)[static_cast<std::size_t>(col(table, c))] = text;
          if (table == "team" && m_.code_index[code] >= m_.slot_cfg->count &&
              (c == "team_location" || c == "team_long_name" || c == "team_short_name"))
            r_.warn("W-NOT-A-SLOT", where_,
                    "team " + code + " has no slot in the game's team list; the front end shows the first slot's names");
        }
      }
    }
  }
  std::optional<std::string> get_manager(const Json& op) {
    std::string k;
    if (const Json* t = op.get("team")) {
      auto it = m_.org.find(key_of(t->s));
      if (it == m_.org.end()) {
        r_.error("E-NOT-FOUND", where_, "team " + py_repr(t->s) + " has no org row (no manager)");
        return std::nullopt;
      }
      char b[16];
      std::snprintf(b, sizeof b, "%09x",
                    static_cast<std::uint32_t>(to_int(it->second[static_cast<std::size_t>(col("org", "org_mlb_manager"))])));
      k = b;
      if (!m_.managers.count(k)) {
        r_.error("E-NOT-FOUND", where_, "the manager of " + t->s + " is not in the manager table");
        return std::nullopt;
      }
    } else {
      auto mk = m_.manager_key(op.get("manager")->s);
      if (!mk) {
        r_.error("E-NOT-FOUND", where_, "no manager " + py_repr(op.get("manager")->s));
        return std::nullopt;
      }
      k = *mk;
    }
    if (k == key_of(kDefaultName)) {
      r_.error("E-PROTECTED", where_, "the Default,Default manager cannot be changed");
      return std::nullopt;
    }
    if (!use({"M", k})) return std::nullopt;
    return k;
  }
  void op_manager_edit(const Json& op) {
    auto k = get_manager(op);
    if (!k) return;
    const Json* fields = op.get("set")->get("manager");
    if (!fields) return;
    for (const auto& [c, v] : fields->obj)
      if (write({"M", *k, c}, {"M", *k})) m_.managers[*k][static_cast<std::size_t>(col("manager", c))] = to_text(v);
  }
  void op_manager_rename(const Json& op) {
    auto k = get_manager(op);
    if (!k) return;
    const std::string to = op.get("to")->s;
    const std::string nk = key_of(to);
    if (m_.managers.count(nk)) {
      r_.error("E-KEY-EXISTS", where_, "manager key " + nk + " of " + py_repr(to) + " is taken");
      return;
    }
    if (!(whole({"M", *k}) && whole({"M", nk}))) return;
    const auto [last, first] = split_name(to);
    Row row = std::move(m_.managers[*k]);
    m_.managers.erase(*k);
    row[0] = first;
    row[1] = last;
    m_.managers[nk] = std::move(row);
    *std::find(m_.manager_order.begin(), m_.manager_order.end(), *k) = nk;
    const std::string old_s = signed_text(*k), new_s = signed_text(nk);
    for (auto& [key, r] : m_.org)
      for (const char* c : {"org_mlb_manager", "org_minors_manager"}) {
        auto& v = r[static_cast<std::size_t>(col("org", c))];
        if (v == old_s) v = new_s;
      }
    rekey("M", *k, nk);
  }
  void op_loc_set(const Json& op) {
    std::string f;
    for (const char* x : kLocFiles)
      if (upper(x) == upper(op.get("file")->s)) {
        f = x;
        break;
      }
    for (const auto& [k, text] : op.get("strings")->obj) set_string(f, static_cast<std::uint16_t>(std::stoul(k)), text.s);
  }
  void set_string(const std::string& f, std::uint16_t sid, const std::string& text) {
    Loc& L = m_.locs[f];
    std::size_t index = L.entries.size();
    for (std::size_t i = 0; i < L.entries.size(); ++i)
      if (L.entries[i].first == sid) index = i;  // the last, as Python's dict comprehension
    if (index == L.entries.size()) {
      r_.error("E-NOT-FOUND", where_, f + " has no string id " + std::to_string(sid));
      return;
    }
    const Cell c{"L", upper(f), std::to_string(sid)};
    if (write(c, c)) {
      L.entries[index].second = text;
      const std::string& orig = m_.loc_orig[f][sid];
      if (utf8_length(text) > utf8_length(orig))
        r_.warn("W-LOC-LENGTH", where_,
                f + " string " + std::to_string(sid) + " is longer than the original (" +
                    std::to_string(utf8_length(text)) + " > " + std::to_string(utf8_length(orig)) +
                    " characters); it may not fit its box");
    }
  }
  const SlotTables& slots() {
    if (!m_.slots) {
      auto dol = m_.disc->dol();
      if (!dol) throw PackError{"no main.dol (sys/main.dol) in " + m_.disc->label()};
      std::vector<std::string> codes;
      for (const auto& r : m_.teams) codes.push_back(r[0]);
      m_.slots = read_slots(*dol, codes, *m_.slot_cfg);
    }
    return *m_.slots;
  }
  void op_team_names(const Json& op) {
    const std::string code = op.get("team")->s;
    if (!team(code)) return;
    Row& row = *m_.team_row(code);
    const std::pair<const char*, const char*> fields[] = {
        {"location", "team_location"}, {"nickname", "team_long_name"}, {"abbreviation", "team_short_name"}};
    for (const auto& [field, c] : fields)
      if (const Json* v = op.get(field); v && write({"T", code, "team", c}, {"T", code}))
        row[static_cast<std::size_t>(col("team", c))] = v->s;
    const SlotTables& s = slots();
    auto tid_it = s.tid_of_row.find(m_.code_index[code]);
    if (tid_it == s.tid_of_row.end()) {
      r_.warn("W-NOT-A-SLOT", where_,
              "team " + code +
                  " has no slot in the game's team list (rows 124, 125); only team.dat changes, and the front end "
                  "shows the first slot's names and art for it");
      return;
    }
    const std::size_t tid = tid_it->second;
    const std::string loc_name = u8(row[static_cast<std::size_t>(col("team", "team_location"))]);
    const std::string nick = u8(row[static_cast<std::size_t>(col("team", "team_long_name"))]);
    std::map<std::string, std::optional<std::string>> texts;
    auto opt = [&](const char* k) -> std::optional<std::string> {
      const Json* v = op.get(k);
      return v ? std::optional<std::string>(v->s) : std::nullopt;
    };
    texts["nickname"] = opt("nickname");
    texts["abbreviation"] = opt("abbreviation");
    texts["city"] = opt("location");
    texts["full"] = opt("full_name");
    if (!texts["full"] && (op.has("location") || op.has("nickname"))) texts["full"] = loc_name + " " + nick;
    for (const char* kind : {"full", "nickname", "abbreviation", "city"}) {
      const auto& text = texts[kind];
      if (!text) continue;
      std::vector<std::string> other;
      for (std::size_t t : s.sharers(kind, tid)) other.push_back(u8(m_.teams[s.row_of_tid[t]][0]));
      if (!other.empty())
        r_.warn("W-LOC-SHARED", where_,
                std::string("the ") + kind + " text of " + code + " is shared with " + join(other, ", ") +
                    "; changing it renames them too");
      std::vector<std::string> files = {"FEENG.LOC"};
      if (std::string(kind) != "city") files.push_back("IGENG.LOC");
      for (const auto& f : files) set_string(f, static_cast<std::uint16_t>(s.ids.at(kind)[tid]), *text);
    }
  }
};

// ---------------------------------------------------------------- final validation
void check_row(const std::string& table, const Row& vals, Report& report, const std::string& where) {
  const auto& cols = schema().tables.at(table);
  for (std::size_t i = 0; i < cols.size() && i < vals.size(); ++i) {
    const Column& c = cols[i];
    if (c.kind != "int") continue;
    const std::string& v = vals[i];
    if (v == "-" && c.null) continue;
    auto n = canon_int(v);
    if (!n || *n < c.lo || *n > c.hi)
      report.error("E-VALUE", where,
                   c.name + " = " + py_repr(u8(v)) + " is outside " + std::to_string(c.lo) + "-" + std::to_string(c.hi));
  }
}

std::string pname(Model& m, const std::string& key) {
  auto it = m.players.find(key);
  return it != m.players.end() ? u8(it->second.name) : key;
}

void validate_roster(Model& m, const std::string& code, const std::vector<Row>& entries,
                     const std::set<std::string>& pitchers, Report& report, const std::string& where) {
  const std::string w = where + " roster " + code;
  const std::int64_t league = m.team_league(code);
  if (league >= 0 && league <= 10) {
    const std::size_t want = (league >= 4 && league <= 9) ? 22 : 25;
    if (entries.size() != want)
      report.error("E-ROSTER", w,
                   std::to_string(entries.size()) + " players; a team of league " + std::to_string(league) +
                       " has exactly " + std::to_string(want));
  }
  if (entries.size() > 25) report.error("E-ROSTER", w, "more than 25 players (the game keeps 25 per team)");
  std::set<std::string> seen;
  for (const auto& e : entries) {
    if (seen.count(e[0])) report.error("E-ROSTER", w, "player " + pname(m, e[0]) + " is listed twice");
    seen.insert(e[0]);
    if (!m.players.count(e[0])) {
      report.error("E-ROSTER", w, "player key " + e[0] + " does not exist");
      continue;
    }
    const std::vector<std::string> codes = {e[1], e[3], e[5], e[7]};
    std::vector<std::string> roles;
    for (const auto& c : codes)
      if (contains(kPitchRoles, c)) roles.push_back(c);
    const std::set<std::string> distinct(codes.begin(), codes.end());
    if (!roles.empty() && (roles.size() != 4 || distinct.size() != 1))
      report.error("E-ROSTER", w,
                   pname(m, e[0]) + ": a pitching role must be the same in all four lineups (the game reads it from rh_al)");
    if (!roles.empty() && !pitchers.count(e[0]))
      report.error("E-ROSTER", w, pname(m, e[0]) + " has the pitching role " + roles[0] + " but is not a pitcher");
    if (roles.empty() && pitchers.count(e[0]))
      report.warn("W-PITCHER-BENCH", w, "pitcher " + pname(m, e[0]) + " has no pitching role");
  }
  for (std::size_t li = 0; li < kLineups.size(); ++li) {
    const std::string& ln = kLineups[li];
    std::vector<std::string> codes, orders;
    for (const auto& e : entries) {
      codes.push_back(e[1 + 2 * li]);
      orders.push_back(e[2 + 2 * li]);
    }
    const bool dh = ln.size() >= 3 && ln.substr(ln.size() - 3) == "_al";
    std::vector<std::string> need = kFielders;
    need.insert(need.end(), kStarters.begin(), kStarters.end());
    need.push_back("CP");
    if (dh) need.push_back("DH");
    auto count = [&](const std::string& c) { return std::count(codes.begin(), codes.end(), c); };
    for (const auto& c : need) {
      const auto n = count(c);
      if (n != 1)
        report.error("E-ROSTER", w,
                     "lineup " + ln + " has " + std::to_string(n) + " at " + c + " (needs exactly 1)");
    }
    if (!dh && count("DH"))
      report.error("E-ROSTER", w, "lineup " + ln + " has no designated hitter; DH is not allowed");
    for (const auto& [c, lim] : std::vector<std::pair<std::string, long>>{{"LR", 3}, {"MR", 4}, {"SU", 2}})
      if (count(c) > lim)
        report.error("E-ROSTER", w,
                     "lineup " + ln + " has " + std::to_string(count(c)) + " " + c + " (at most " + std::to_string(lim) + ")");
    std::vector<std::string> batters = kFielders;
    batters.push_back(dh ? "DH" : "SP1");
    std::vector<std::string> sorted_batters = batters;
    std::sort(sorted_batters.begin(), sorted_batters.end());
    std::vector<std::int64_t> got;
    for (std::size_t k = 0; k < codes.size(); ++k) {
      if (contains(batters, codes[k])) {
        if (orders[k] == "-1")
          report.error("E-ROSTER", w, "lineup " + ln + ": " + codes[k] + " needs a batting order");
        else
          got.push_back(to_int(orders[k]));
      } else if (orders[k] != "-1") {
        report.error("E-ROSTER", w,
                     "lineup " + ln + ": " + codes[k] + " does not bat (batting order only for " +
                         join(sorted_batters, " ") + ")");
      }
    }
    std::vector<std::int64_t> sorted_got = got;
    std::sort(sorted_got.begin(), sorted_got.end());
    const std::vector<std::int64_t> one_to_nine = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (sorted_got != one_to_nine && got.size() == 9)
      report.error("E-ROSTER", w, "lineup " + ln + ": batting orders must be 1-9, each once");
  }
}

void validate_model(Model& m, Report& report, const std::string& where = "result") {
  const std::size_t n_players = m.players.size(), n_pitchers = m.pitchers();
  if (n_players > 3250)
    report.error("E-CAPACITY", where,
                 std::to_string(n_players) + " players; the game holds at most 3250 (Default row included)");
  if (n_pitchers > 1800)
    report.error("E-CAPACITY", where, std::to_string(n_pitchers) + " pitchers; the game holds at most 1800");
  if (m.managers.size() > 36)
    report.error("E-CAPACITY", where, std::to_string(m.managers.size()) + " managers; the game holds at most 36");
  const std::tuple<const char*, std::size_t, std::size_t, std::size_t> caps[] = {
      {"player", n_players, m.start_players, 3250}, {"pitcher", n_pitchers, m.start_pitchers, 1800}};
  for (const auto& [label, now, start, cap] : caps)
    if (now > start && now <= cap)
      report.warn("W-FREE-SLOTS", where,
                  std::to_string(cap - now) + " free " + label + " slots remain (the disc leaves " +
                      std::to_string(cap - start) + "); dynasty drafts and created players need free slots");
  const int i_pos = col("attrib", "playerattrib_primary_position");
  for (const auto& k : m.order) {
    Player& p = m.players.at(k);
    for (std::size_t t = 0; t < kPlayerTables.size(); ++t)
      if (p.vals[t]) check_row(kPlayerTables[t], *p.vals[t], report, where + " player " + u8(p.name) + " " + kPlayerTables[t]);
    const std::int64_t pos = to_int((*p.vals[0])[static_cast<std::size_t>(i_pos)]);
    if ((pos == 0 || pos == 10) && !p.pitcher() && k != m.default_key)
      report.error("E-PITCHER", where,
                   "player " + u8(p.name) + " has primary position " + (pos == 0 ? "SP" : "RP") +
                       " but no pitcher rows (\"pitcher\": true)");
    if (p.pitcher()) {
      const Row& vals = *p.vals[8];
      std::vector<bool> present;
      for (int n : {3, 4, 5}) {
        int none = 0;
        for (const char* s : {"type", "movement", "description", "control", "velocity"})
          none += vals[static_cast<std::size_t>(col("pitcher", "pitchattrib_pitch" + std::to_string(n) + "_" + s))] == "-";
        if (none != 0 && none != 5)
          report.error("E-VALUE", where,
                       "player " + u8(p.name) + " pitch " + std::to_string(n) + ": set all five fields or all to \"-\"");
        present.push_back(none == 0);
      }
      const std::vector<std::vector<bool>> bad = {
          {false, true, false}, {false, true, true}, {false, false, true}, {true, false, true}};
      if (std::find(bad.begin(), bad.end(), present) != bad.end())
        report.error("E-VALUE", where, "player " + u8(p.name) + ": pitches 3-5 must be filled in order");
    }
  }
  for (std::size_t i = 0; i < m.teams.size(); ++i) {
    check_row("team", m.teams[i], report, where + " team " + u8(m.teams[i][0]));
    if (auto it = m.tstat.find(m.team_keys[i]); it != m.tstat.end())
      check_row("tstat", it->second, report, where + " team " + u8(m.teams[i][0]) + " tstat");
  }
  for (const auto& k : m.manager_order) check_row("manager", m.managers.at(k), report, where + " manager " + k);
  std::map<std::string, std::vector<std::string>> homes;
  std::set<std::string> pitchers;
  for (const auto& [k, p] : m.players)
    if (p.pitcher()) pitchers.insert(k);
  for (const auto& code : m.roster_codes) {
    validate_roster(m, code, m.rosters[code], pitchers, report, where);
    for (const auto& e : m.rosters[code]) homes[e[0]].push_back(code);
  }
  for (const auto& k : m.order) {
    const auto it = homes.find(k);
    const std::vector<std::string> on = it == homes.end() ? std::vector<std::string>{} : it->second;
    const std::string name = u8(m.players.at(k).name);
    if (k == m.default_key) {
      if (!on.empty()) report.error("E-PROTECTED", where, "Default,Default must not be on a roster");
      continue;
    }
    std::vector<std::string> clubs;
    for (const auto& c : on)
      if (c != "AL" && c != "NL") clubs.push_back(c);
    if (on.empty())
      report.error("E-ROSTER-HOME", where,
                   "player " + name + " is on no roster (give him a team, or release him with \"remove\")");
    else if (clubs.size() > 1)
      report.error("E-ROSTER-HOME", where,
                   "player " + name + " is on " + join(clubs, ", ") +
                       "; a player belongs to one team (plus an All-Star side)");
    else if (clubs.empty())
      report.warn("W-ALLSTAR-ONLY", where, "player " + name + " is only on the All-Star roster " + on[0]);
  }
}

// ---------------------------------------------------------------- outputs
std::map<std::string, Table> rebuild_tables(Model& m) {
  std::map<std::string, Table> out;
  for (const auto& name : kPlayerTables) {
    Table t{name, m.tables[name].fields, {}};
    const std::size_t ti = table_index(name);
    for (const auto& k : m.order) {
      const auto& v = m.players.at(k).vals[ti];
      if (!v) continue;
      Row r{k};
      r.insert(r.end(), v->begin(), v->end());
      t.rows.push_back(std::move(r));
    }
    out[name] = std::move(t);
  }
  {
    Table t{"team", m.tables["team"].fields, {}};
    for (std::size_t i = 0; i < m.teams.size(); ++i) {
      Row r{m.team_keys[i]};
      r.insert(r.end(), m.teams[i].begin(), m.teams[i].end());
      t.rows.push_back(std::move(r));
    }
    out["team"] = std::move(t);
  }
  for (const char* name : {"tstat", "org"}) {
    auto& src = std::string(name) == "tstat" ? m.tstat : m.org;
    Table t{name, m.tables[name].fields, {}};
    for (const auto& old : m.tables[name].rows) {
      Row r{old[0]};
      const Row& v = src.at(old[0]);
      r.insert(r.end(), v.begin(), v.end());
      t.rows.push_back(std::move(r));
    }
    out[name] = std::move(t);
  }
  {
    Table t{"manager", m.tables["manager"].fields, {}};
    for (const auto& k : m.manager_order) {
      Row r{k};
      const Row& v = m.managers.at(k);
      r.insert(r.end(), v.begin(), v.end());
      t.rows.push_back(std::move(r));
    }
    out["manager"] = std::move(t);
  }
  {
    Table t{"roster", m.tables["roster"].fields, {}};
    for (std::size_t i = 0; i < m.teams.size(); ++i)
      for (const auto& e : m.rosters[m.teams[i][0]]) {
        char b[16];
        std::snprintf(b, sizeof b, "%09zx", t.rows.size());
        Row r{b, m.team_keys[i]};
        r.insert(r.end(), e.begin(), e.end());
        t.rows.push_back(std::move(r));
      }
    out["roster"] = std::move(t);
  }
  return out;
}

void apply_assets(DiscFiles& disc, const std::vector<Pack>& packs, ApplyOutput& out, Report& report) {
  std::map<std::string, std::vector<const Pack::Asset*>> by_file;
  for (const auto& p : packs)
    for (const auto& a : p.assets) by_file[a.target.path].push_back(&a);
  for (const auto& [path, items] : by_file) {
    auto real = disc.name_of(path);
    if (!real) {
      report.error("E-NOT-FOUND", items[0]->where, "the disc has no file " + path);
      continue;
    }
    if (!items[0]->target.has_entry) {
      const Pack::Asset* a = items.back();
      if (disc.read(*real) == a->data) {
        report.error("E-RETAIL-COPY", a->where, "the asset is a copy of the retail file");
        continue;
      }
      out.files[*real] = a->data;
      out.texts[path] = a->data;
      continue;
    }
    std::string err;
    auto bytes = disc.read(*real);
    auto arc = vfs::BigArchive::parse(bytes ? std::move(*bytes) : std::vector<std::uint8_t>{}, &err);
    if (!arc) {
      report.error("E-ASSET", items[0]->where, path + " is not a BIGF archive (" + err + ")");
      continue;
    }
    std::map<std::string, std::vector<std::uint8_t>> replace;
    for (const Pack::Asset* a : items) {
      const vfs::BigEntry* e = arc->find(a->target.entry);
      if (!e) {
        report.error("E-NOT-FOUND", a->where, path + " has no entry " + a->target.entry);
        continue;
      }
      auto unpacked = arc->read(*e);
      if (arc->raw(*e) == a->data || (unpacked && *unpacked == a->data)) {
        report.error("E-RETAIL-COPY", a->where, "the asset is a copy of the retail entry");
        continue;
      }
      replace[e->name] = a->data;
      out.texts[path + ":" + a->target.entry] = a->data;
    }
    if (!replace.empty()) {
      const std::uint32_t align = arc->payload_alignment();
      out.files[*real] = arc->rebuild(replace, align ? align : 4);
    }
  }
}

// ---------------------------------------------------------------- disc access
class ImageFiles final : public DiscFiles {
 public:
  explicit ImageFiles(vfs::Disc& d) : d_(d) {}
  std::optional<std::vector<std::uint8_t>> read(const std::string& path) override {
    return d_.gcm.read_file(*d_.image, path);
  }
  std::optional<std::string> name_of(const std::string& lower_path) override {
    for (const auto& e : d_.gcm.entries())
      if (!e.is_dir && lower(e.path) == lower_path) return e.path;
    return std::nullopt;
  }
  std::optional<std::vector<std::uint8_t>> dol() override { return d_.dol.bytes(); }
  std::string label() const override { return "the disc image"; }

 private:
  vfs::Disc& d_;
};

}  // namespace

std::unique_ptr<DiscFiles> image_files(vfs::Disc& disc) { return std::make_unique<ImageFiles>(disc); }

std::string result_hash(const std::map<std::string, std::vector<std::uint8_t>>& texts) {
  Json o = Json::object();
  for (const auto& [k, v] : texts) o.set(k, Json::string(sha256_hex(v)));
  return sha256_hex("mvp2005-result-hash/1\n" + canonical_json(o));
}

std::optional<ApplyOutput> apply_packs(const std::vector<Pack>& packs,
                                       const std::map<std::string, std::set<std::string>>& deps, DiscFiles& disc,
                                       Report& report, const SlotConfig& slots) {
  auto m = load_model(disc, slots);
  Applier(*m, report, deps).run(packs);
  validate_model(*m, report);
  if (!report.ok()) return std::nullopt;
  ApplyOutput out;
  auto tables = rebuild_tables(*m);
  std::map<std::string, std::vector<std::uint8_t>> replace;
  for (const auto& e : m->archive->entries()) {
    const std::string name = e.name.substr(0, e.name.size() - 4);
    std::vector<std::uint8_t> text;
    if (auto it = tables.find(name); it != tables.end()) {
      std::string err;
      auto s = it->second.serialize(&err);
      if (!s) throw PackError{err};
      text.assign(s->begin(), s->end());
    } else {
      text = m->orig_text[name];
    }
    out.texts[std::string(kDatabasePath) + ":" + lower(e.name)] = text;
    if (text != m->orig_text[name]) {
      out.changed_tables.push_back(name);
      replace[e.name] = vfs::refpack::compress(text);
    }
  }
  if (!replace.empty()) out.files[kDatabasePath] = m->archive->rebuild(replace);
  for (const char* f : kLocFiles) {
    auto data = m->locs[f].serialize();
    out.texts["/data/" + lower(f)] = data;
    if (m->locs[f].entries != m->loc_orig_items[f]) out.files[std::string("/data/") + f] = std::move(data);
  }
  apply_assets(disc, packs, out, report);
  out.result_hash = result_hash(out.texts);
  return out;
}

}  // namespace mvp::mods
