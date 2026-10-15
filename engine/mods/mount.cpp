#include "mods/mount.h"

#include "vfs/disc_check.h"
#include "vfs/overlay.h"

namespace mvp::mods {

bool PackSet::check() {
  deps = check_set_order(packs, report);
  checked = true;
  return report.ok();
}

std::string PackSet::set_hash() const { return mods::set_hash(packs); }

MountResult mount_packs(vfs::Disc& disc, PackSet& set, const SlotConfig& slots) {
  MountResult r;
  if (!set.checked) set.check();
  if (!set.report.ok()) return r;
  if (set.packs.empty()) {
    r.ok = true;
    return r;
  }
  std::optional<ApplyOutput> out;
  try {
    auto files = image_files(disc);
    out = apply_packs(set.packs, set.deps, *files, set.report, slots);
  } catch (const PackError& e) {
    r.fatal = e.message;
    return r;
  }
  if (!out || !set.report.ok()) return r;
  r.result_hash = out->result_hash;
  r.changed_tables = out->changed_tables;
  std::vector<vfs::OverlayFile> overlay;
  for (auto& [path, bytes] : out->files) {
    r.files.push_back(path);
    r.bytes += bytes.size();
    overlay.push_back({path, std::move(bytes)});
  }
  std::string err;
  if (!vfs::mount_overlay(disc, std::move(overlay), &err)) {
    r.fatal = err;
    r.files.clear();
    return r;
  }
  r.ok = true;
  return r;
}

MountResult mount_pack_paths(vfs::Disc& disc, const std::vector<std::string>& paths, std::string* log,
                             std::string* hash) {
  PackSet set;
  for (const auto& p : paths) set.add(load_pack_path(p, set.report));
  set.check();
  if (hash) *hash = set.set_hash();
  MountResult r = mount_packs(disc, set);
  if (log) {
    *log = set.report.render() + "\n";
    if (!r.fatal.empty()) *log += "error: " + r.fatal + "\n";
    for (const auto& p : set.packs) *log += "pack " + p.where() + " " + p.version_text() + " " + p.hash + "\n";
    *log += "set hash " + set.set_hash() + "\n";
    if (r.ok && !set.packs.empty()) {
      *log += "result hash " + r.result_hash + "\n";
      *log += "changed tables:";
      for (const auto& t : r.changed_tables) *log += " " + t;
      *log += "\nmounted:";
      for (const auto& f : r.files) *log += " " + f;
      *log += " (" + std::to_string(r.bytes) + " bytes)\n";
    }
  }
  return r;
}

Json set_json(const PackSet& set, const MountResult* mounted) {
  Json o = Json::object();
  const bool ok = set.report.ok() && (!mounted || mounted->ok);
  Json b;
  b.kind = Json::Kind::Bool;
  b.b = ok;
  o.set("ok", b);
  o.set("set_hash", Json::string(set.set_hash()));
  Json packs = Json::array();
  for (const auto& p : set.packs) {
    Json j = Json::object();
    j.set("label", Json::string(p.label));
    j.set("id", p.id.empty() ? Json{} : Json::string(p.id));
    j.set("name", Json::string(p.name()));
    j.set("version", Json::string(p.version_text()));
    j.set("hash", p.hash.empty() ? Json{} : Json::string(p.hash));
    packs.arr.push_back(std::move(j));
  }
  o.set("packs", std::move(packs));
  o.set("issues", set.report.to_json());
  if (mounted) {
    if (!mounted->fatal.empty()) o.set("fatal", Json::string(mounted->fatal));
    o.set("result_hash", Json::string(mounted->result_hash));
    Json t = Json::array(), f = Json::array();
    for (const auto& x : mounted->changed_tables) t.arr.push_back(Json::string(x));
    for (const auto& x : mounted->files) f.arr.push_back(Json::string(x));
    o.set("changed_tables", std::move(t));
    o.set("files", std::move(f));
    o.set("bytes", Json::integer(static_cast<std::int64_t>(mounted->bytes)));
  }
  return o;
}

}  // namespace mvp::mods
