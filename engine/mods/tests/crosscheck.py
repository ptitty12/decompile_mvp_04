#!/usr/bin/env python3
"""Cross-check of the engine's roster-pack implementation against the reference tool.

Runs tools/rosters/pack.py (the reference, docs/MODDING.md) and the engine's mvp-pack
(engine/mods) on the same packs and the same synthetic disc, and requires identical:

- issues: severity, code, place and message of every one, in order;
- pack hashes and the set hash;
- the result hash, the changed tables and every output file, byte for byte;
- fatal errors (a non-retail main.dol).

The disc and most packs come from pack.py's own tests (tools/rosters/tests/test_pack.py:
make_disc, write_pack, new_player), so the data is synthetic: no game data is read
or written. The scenarios follow test_pack.py's cases, plus a kitchen-sink pack, the
example pack (docs/examples/packs/fictional-league), zipped packs, and the same disc
as a GameCube image, on which `mvp-pack mount-check` also mounts the packs on the
engine's virtual disc and reads every file back through it.

    python -I engine/mods/tests/crosscheck.py --mvp-pack build/engine/msvc/mods/mvp-pack.exe --repo .

Exit status: 0 all equal, 1 a difference (printed), 77 pack.py missing (skipped).
"""
import argparse
import copy
import hashlib
import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import zipfile

ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
ap.add_argument("--mvp-pack", required=True)
ap.add_argument("--repo", required=True)
ap.add_argument("--keep", action="store_true", help="keep the temporary directory")
ap.add_argument("-v", "--verbose", action="store_true")
args = ap.parse_args()
args.mvp_pack = os.path.abspath(args.mvp_pack)

ROSTERS = os.path.join(args.repo, "tools", "rosters")
if not os.path.isfile(os.path.join(ROSTERS, "pack.py")):
    print("crosscheck: no tools/rosters/pack.py; skipped")
    sys.exit(77)
sys.path.insert(0, os.path.join(ROSTERS, "tests"))
sys.path.insert(0, ROSTERS)
import pack  # noqa: E402
import test_pack as tp  # noqa: E402

EXAMPLE = os.path.join(args.repo, "docs", "examples", "packs", "fictional-league")
tmp = tempfile.mkdtemp(prefix="mods-crosscheck-")
failures = []
n_scenarios = 0


def sha(b):
    return hashlib.sha256(b).hexdigest()


# ---------------------------------------------------------------- the synthetic disc
pack.SLOT_TABLES["count"] = 3
DISC = os.path.join(tmp, "disc")
ROSTER = tp.make_disc(DISC)
SLOT_SHA1 = hashlib.sha1(tp.make_dol()).hexdigest()
pack.DOL_SHA1 = SLOT_SHA1


def make_image(root, out):
    """A GameCube disc image (GCM) of an extracted disc tree: main.dol as the boot
    DOL, every file under data/ in the FST. Synthetic, like the tree."""
    entries = []  # (path parts, is_dir)

    def walk(rel):
        full = os.path.join(root, *rel)
        for name in sorted(os.listdir(full)):
            p = rel + [name]
            if os.path.isdir(os.path.join(root, *p)):
                entries.append((p, True))
                walk(p)
            else:
                entries.append((p, False))
    walk(["data"])
    entries.insert(0, (["data"], True))
    dol = open(os.path.join(root, "sys", "main.dol"), "rb").read()
    # FST: root, then entries in walk order; a directory's second word is the index
    # one past its last descendant, its first word the parent's index.
    names = b""
    name_off = []
    for parts, _ in entries:
        name_off.append(len(names))
        names += parts[-1].encode() + b"\0"
    count = len(entries) + 1
    fst_off = 0x2440
    fst_size = count * 12 + len(names)
    pos = (fst_off + fst_size + 0x7FFF) & ~0x7FFF
    dol_off = pos
    pos = (pos + len(dol) + 0x7FFF) & ~0x7FFF
    blobs = []
    recs = [struct.pack(">BBHII", 1, 0, 0, 0, count)]
    for i, (parts, is_dir) in enumerate(entries, 1):
        if is_dir:
            parent = 0
            for j in range(i - 1, 0, -1):
                if entries[j - 1][1] and entries[j - 1][0] == parts[:-1]:
                    parent = j
                    break
            end = i + 1
            while end <= len(entries) and entries[end - 1][0][:len(parts)] == parts:
                end += 1
            recs.append(struct.pack(">I", 0x01000000 | name_off[i - 1]) + struct.pack(">II", parent, end))
        else:
            data = open(os.path.join(root, *parts), "rb").read()
            recs.append(struct.pack(">I", name_off[i - 1]) + struct.pack(">II", pos, len(data)))
            blobs.append((pos, data))
            pos = (pos + len(data) + 3) & ~3
    fst = b"".join(recs) + names
    size = (pos + 0x7FFF) & ~0x7FFF
    img = bytearray(size)
    img[0:6] = b"GTST01"
    struct.pack_into(">I", img, 0x1C, 0xC2339F3D)
    img[0x20:0x20 + 15] = b"Synthetic disc\0"
    struct.pack_into(">IIII", img, 0x420, dol_off, fst_off, fst_size, fst_size)
    img[fst_off:fst_off + fst_size] = fst
    img[dol_off:dol_off + len(dol)] = dol
    for at, data in blobs:
        img[at:at + len(data)] = data
    with open(out, "wb") as f:
        f.write(img)


IMAGE = os.path.join(tmp, "disc.iso")
make_image(DISC, IMAGE)


# ---------------------------------------------------------------- packs
pack_n = [0]


def mk(pid, patches, **manifest):
    pack_n[0] += 1
    return tp.write_pack(os.path.join(tmp, "pack%d" % pack_n[0]), pid, patches, **manifest)


def squad(code, rename=None):
    out = []
    for name, _, _, codes in ROSTER[code]:
        e = {"player": (rename or {}).get(name, name)}
        for ln, c in zip(pack.LINEUPS, codes):
            e[ln] = c
        out.append(e)
    return out


def zipped(root, top=True):
    z = root + ".zip"
    with zipfile.ZipFile(z, "w", zipfile.ZIP_DEFLATED) as zf:
        for dp, _, fns in os.walk(root):
            for fn in sorted(fns):
                full = os.path.join(dp, fn)
                rel = os.path.relpath(full, root).replace(os.sep, "/")
                zf.write(full, (os.path.basename(root) + "/" + rel) if top else rel)
    return z


# ---------------------------------------------------------------- running both
def run_py(specs, disc, dol_sha1):
    saved = pack.DOL_SHA1
    pack.DOL_SHA1 = dol_sha1
    try:
        report = pack.Report()
        static = pack.Report()
        loaded = [pack.load_pack(s, static) for s in specs]
        pack.check_set_order(loaded, static)
        res = {"packs": [[p.id, p.hash] for p in loaded]}
        if static.ok:
            res["set_hash"] = pack.set_hash(loaded)
        try:
            packs, model, out = pack.run_packs(specs, report, pack.Disc(disc) if disc else None)
        except pack.PackError as e:
            res["fatal"] = str(e)
            return res
        res["issues"] = report.to_json()
        if out is not None:
            files, texts, changed = out
            res.update(result_hash=pack.result_hash(texts), changed=changed,
                       files={k.strip("/"): sha(v) for k, v in files.items()})
        return res
    finally:
        pack.DOL_SHA1 = saved


def run_cpp(specs, disc, dol_sha1, tag):
    slot = ["--slot-sha1", dol_sha1, "--slot-count", "3"]
    v = subprocess.run([args.mvp_pack, "validate", "--json"] + specs, capture_output=True, text=True,
                       encoding="utf-8")
    res = {"packs": [[p["id"], p["hash"]] for p in json.loads(v.stdout)["packs"]]}
    h = subprocess.run([args.mvp_pack, "hash"] + specs, capture_output=True, text=True, encoding="utf-8")
    if h.returncode == 0:
        res["set_hash"] = h.stdout.strip().splitlines()[-1].split()[0]
    if disc is None:
        res["issues"] = json.loads(v.stdout)["issues"]
        return res
    out = os.path.join(tmp, "out-" + tag)
    r = subprocess.run([args.mvp_pack, "apply", "--disc", disc, "--out", out, "--json"] + slot + specs,
                       capture_output=True, text=True, encoding="utf-8")
    if r.returncode == 2:
        res["fatal"] = r.stderr.strip().replace("error: ", "", 1)
        return res
    j = json.loads(r.stdout)
    res["issues"] = j["issues"]
    if "result_hash" in j:
        files = {}
        for dp, _, fns in os.walk(out):
            for fn in fns:
                full = os.path.join(dp, fn)
                rel = os.path.relpath(full, out).replace(os.sep, "/")
                if rel != "pack-apply.json":
                    files[rel] = sha(open(full, "rb").read())
        res.update(result_hash=j["result_hash"], changed=j["changed_tables"], files=files)
        assert j["set_hash"] == res.get("set_hash"), "apply's set hash differs from hash's"
    return res


def check(name, specs, disc=DISC, dol_sha1=None, expect_ok=None, mount=False):
    """Run both; the results must be equal (and, with expect_ok, clean or not)."""
    global n_scenarios
    n_scenarios += 1
    dol_sha1 = dol_sha1 or SLOT_SHA1
    py = run_py(specs, disc, dol_sha1)
    cpp = run_cpp(specs, disc, dol_sha1, "%03d" % n_scenarios)
    if py != cpp:
        failures.append(name)
        print("DIFFERENT %s" % name)
        for k in sorted(set(py) | set(cpp)):
            if py.get(k) != cpp.get(k):
                a, b = py.get(k), cpp.get(k)
                if isinstance(a, list) and isinstance(b, list):
                    for i in range(max(len(a), len(b))):
                        if i >= len(a) or i >= len(b) or a[i] != b[i]:
                            print("  %s[%d]\n    pack.py: %s\n    engine:  %s" % (
                                k, i, a[i] if i < len(a) else "-", b[i] if i < len(b) else "-"))
                            break
                else:
                    print("  %s\n    pack.py: %s\n    engine:  %s" % (k, a, b))
        return py
    ok = "fatal" not in py and not any(i["severity"] == "error" for i in py.get("issues", []))
    if expect_ok is not None and ok != expect_ok:
        failures.append(name)
        print("UNEXPECTED %s: %s" % (name, "clean" if ok else json.dumps(py.get("issues", py.get("fatal")))[:400]))
    if mount:
        r = subprocess.run([args.mvp_pack, "mount-check", "--disc", disc, "--slot-sha1", dol_sha1, "--slot-count", "3"]
                           + specs, capture_output=True, text=True, encoding="utf-8")
        if r.returncode != 0:
            failures.append(name + " (mount-check)")
            print("MOUNT-CHECK FAILED %s\n%s%s" % (name, r.stdout, r.stderr))
        elif args.verbose:
            print("  " + r.stdout.strip())
    codes = sorted({i["code"] for i in py.get("issues", [])})
    print("same  %-46s %s%s" % (name, ("fatal: " + py["fatal"]) if "fatal" in py else
                                 ", ".join(codes) or "clean",
                                 ("  result " + py["result_hash"][:12]) if "result_hash" in py else ""))
    return py


def new_player(name, pos=2, pitcher=False, **attrib):
    return tp.new_player(name, pos, pitcher, **attrib)


# ---------------------------------------------------------------- scenarios
# Static (no disc).
check("example pack, static", [EXAMPLE], disc=None, expect_ok=True)
check("example pack on the synthetic disc", [EXAMPLE], expect_ok=False)
check("bad ops", [mk("bad-ops", [[
    {"op": "player.fly", "player": "Doe,Jane"},
    {"op": "player.add", "player": "Doe,Jane", "set": {"attrib": {"playerattrib_speed": 120}}},
    {"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"first_name": "Jo"}}},
    {"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"no_such": 1}}},
    {"op": "player.add", "player": "Doe Jane"},
    {"op": "player.add", "player": "Doe,Jane", "set": {"pitcher": {}}},
    {"op": "roster.set", "team": "Aaa", "entries": [{"player": "Doe,Jane", "pos": "QB"}]},
    {"op": "team.edit", "team": "Aaa", "set": {"team": {"team_league": 3}}},
    {"op": "loc.set", "file": "FEENG.LOC", "strings": {"12": "badé"}},
    {"op": "player.edit", "player": "Doe,Jane"},
    {"op": "manager.edit", "manager": "Boss,Alpha", "team": "Aaa", "set": {"manager": {}}},
    {"op": "roster.replace", "team": "Aaaa", "out": "A,B", "in": "C,D", "release": "drop"},
    {"op": "team.names", "team": "Aaa"},
    {"op": "team.names", "team": "Aaa", "location": " Elm", "nickname": "Very Long Nickname",
     "abbreviation": "abc", "full_name": "x" * 401},
    {"op": "player.add", "player": "Toolonglastname,X"},
    {"op": "player.add", "player": "X,Toolongfirstnm"},
    {"op": "player.add", "player": "O'Neil,Jo-Ann St."},
    {"op": "player.add", "player": "Doe,Jane  Q"},
    {"op": "player.edit", "player": "Doe,Jane", "pitcher": 1},
    {"op": "roster.set", "team": "Aaa", "entries": []},
    {"op": "roster.set", "team": "Aaa", "entries": [{"player": "Doe,Jane", "rh_al": "C:0"}, {"pos": "B"},
                                                     {"player": "A,B", "pos": "B", "extra": 1},
                                                     {"player": "A,B", "pos": "C:8", "rh_nl": None}]},
    {"op": "loc.set", "file": "XX.LOC", "strings": {"012": "a", "70000": "b", "x": 1}},
    {"op": "loc.set", "file": "mc_eng.LOC", "strings": {}},
    {"op": "team.edit", "team": "Aaa", "set": {"tstat": {"team_wins_1sthalf": "-", "team_losses_1sthalf": "x"},
                                               "org": {"org_mlb_manager": "Nobody", "org_budget": True},
                                               "roster": {}}},
    {"op": "manager.rename", "to": "New,Boss"},
    "not an op", {"op": 5},
]])], disc=None, expect_ok=False)
check("manifest errors", [mk("ok-pack", [[]], game="GV4P69-0", engine_api="1.7", extra=1)], disc=None,
      expect_ok=False)
check("manifest errors 2", [mk("Bad_Id", [[]], version="1.0", name="", description=5, authors=["a", ""],
                               license="x" * 101, meta=[], depends=[{"id": "a"}, {"id": "ab", "version": "^1.0"},
                                                                     {"id": "abc", "version": "^1.0.0"}])],
      disc=None, expect_ok=False)
root = mk("p-x", [])
with open(os.path.join(root, "pack.json"), "w") as f:
    json.dump({"id": "p-x", "name": "p", "version": "1.0.0", "game": None, "engine_api": 1, "depends": "nope",
               "patches": "p"}, f)
check("manifest errors 3", [root], disc=None, expect_ok=False)
os.makedirs(os.path.join(tmp, "a"))
with open(os.path.join(tmp, "a", "logo.gsh"), "wb") as f:
    f.write(b"authored")
root = mk("assets-bad", [[]], assets=[
    {"path": "/data/database/database.big", "entry": "attrib.dat", "file": "x.gsh"},
    {"path": "/data/frontend/logos.big", "file": "x.gsh"},
    {"path": "/data/frontend/logos.big", "entry": "l000.gsh", "file": "../a/logo.gsh"},
    {"path": "data/frontend/a.big", "entry": "e", "file": "f"},
    {"path": "/data/frontend/intro.vp6", "entry": "e", "file": "f"},
    {"path": "/data/frontend/logos.big", "entry": "bad/name", "file": "f"},
    {"path": "/data/frontend/logos.big", "entry": "l000.gsh", "file": 5},
    {"path": "/data/frontend/logos.big", "entry": "l000.gsh", "file": "ok.gsh", "extra": 1},
    {"path": "/data/frontend/Logos.big", "entry": "L001.gsh", "file": "ok.gsh"},
    {"path": "/data/frontend/logos.big", "entry": "l001.GSH", "file": "ok.gsh"},
    {"path": "/data/frontend/logos.big", "entry": "l002.gsh", "file": "arc.big"},
    {"path": "/data/frontend/logos.big", "entry": None, "file": "ok.gsh"},
])
with open(os.path.join(root, "ok.gsh"), "wb") as f:
    f.write(b"authored art")
with open(os.path.join(root, "arc.big"), "wb") as f:
    f.write(b"BIGF....")
check("asset targets", [root], disc=None, expect_ok=False)
# Bad JSON in a patch and in the manifest.
root = mk("json-bad", [[]])
with open(os.path.join(root, "patches", "p0.json"), "wb") as f:
    f.write(b'{"ops": [1.5]}')
check("bad patch JSON", [root], disc=None, expect_ok=False)
root = mk("json-bad2", [[]])
with open(os.path.join(root, "pack.json"), "wb") as f:
    f.write(b'\xef\xbb\xbf{"id": "json-bad2",\n "name": "x", "name": 2}')
check("bad manifest JSON", [root], disc=None, expect_ok=False)
check("not a pack", [os.path.join(tmp, "a", "logo.gsh"), os.path.join(tmp, "nowhere")], disc=None, expect_ok=False)

# Formatting does not change a hash; a zip hashes as the directory.
a = mk("same-pack", [[new_player("Doe,Jane")]])
b = os.path.join(tmp, "reformatted")
shutil.copytree(a, b)
for rel in ("pack.json", "patches/p0.json"):
    with open(os.path.join(a, rel), encoding="utf-8") as f:
        obj = json.load(f)
    with open(os.path.join(b, rel), "w", encoding="utf-8", newline="\r\n") as f:
        f.write("﻿" + json.dumps(obj, indent=7))
ra = check("hash of a pack", [a], disc=None)
rb = check("hash of the reformatted pack", [b], disc=None)
if ra["packs"][0][1] != rb["packs"][0][1]:
    failures.append("reformatting changed the hash")
check("zip with a top folder", [zipped(a)], disc=None)
check("zip without a top folder", [zipped(b, top=False)], disc=None)
check("zipped example", [zipped(EXAMPLE)], disc=None, expect_ok=True)

# Applying (pack.py's ApplyTests and friends).
check("empty pack", [mk("nothing", [[]])], expect_ok=True)
old = [n for n, _, _, _ in ROSTER["Bbb"]][:2]
check("add players, replace a roster", [mk("adds", [[
    new_player("Doe,Jane", pos=1, playerattrib_speed=77), new_player("Roe,Rick", pos=2),
    {"op": "roster.set", "team": "Bbb", "release": "remove",
     "entries": squad("Bbb", {old[0]: "Doe,Jane", old[1]: "Roe,Rick"})}]])], expect_ok=True)
check("names, LOC text, replace with release", [mk("twice", [[
    new_player("Doe,Jane"),
    {"op": "team.edit", "team": "Aaa", "set": {"team": {"team_location": "Elm Bay", "team_long_name": "Herons",
                                                        "team_short_name": "EBH"}}},
    {"op": "loc.set", "file": "FEENG.LOC", "strings": {"2000": "Herons"}},
    {"op": "roster.replace", "team": "Ccc", "out": ROSTER["Ccc"][9][0], "in": "Doe,Jane", "release": "remove"}]])],
      expect_ok=True)
star = ROSTER["Aaa"][0][0]
check("rename re-keys everywhere", [mk("rename", [[{"op": "player.rename", "player": star, "to": "Newname,Sam"}]])],
      expect_ok=True)
check("edit after rename", [mk("rename2", [[
    {"op": "player.rename", "player": star, "to": "Newname,Sam"},
    {"op": "player.edit", "player": star, "set": {"attrib": {"playerattrib_speed": 5}}}]])], expect_ok=False)
bc, cc, backup = ROSTER["Bbb"][0][0], ROSTER["Ccc"][0][0], ROSTER["Bbb"][9][0]
check("swaps: trade and promote", [mk("swaps", [[{"op": "roster.swap", "a": bc, "b": cc},
                                                  {"op": "roster.swap", "a": cc, "b": backup}]])], expect_ok=True)
p10 = ROSTER["Bbb"][10][0]
check("remove while on a roster", [mk("remove-one", [[{"op": "player.remove", "player": p10}]])], expect_ok=False)
check("remove after leaving", [mk("rm2", [[new_player("Doe,Jane"),
                                           {"op": "roster.replace", "team": "Bbb", "out": p10, "in": "Doe,Jane"},
                                           {"op": "player.remove", "player": p10}]])], expect_ok=True)
check("Default is protected", [mk("dflt", [[{"op": "player.edit", "player": "Default,Default",
                                              "set": {"attrib": {"playerattrib_speed": 50}}},
                                             {"op": "roster.swap", "a": "Default,Default", "b": p10},
                                             {"op": "manager.edit", "manager": "Default,Default",
                                              "set": {"manager": {"manager_hitting": 1}}}]])], expect_ok=False)
check("djb2 collision", [mk("collide", [[new_player("Smith,Ab"), new_player("Smith,BA"),
                                         new_player(ROSTER["Aaa"][3][0])]])], expect_ok=False)
check("manager by team and org link", [mk("mgr", [[
    {"op": "manager.rename", "team": "Aaa", "to": "Skipper,Ola"},
    {"op": "manager.edit", "manager": "Skipper,Ola", "set": {"manager": {"manager_hitting": 90}}},
    {"op": "team.edit", "team": "Bbb", "set": {"org": {"org_mlb_manager": "Skipper,Ola"}}}]])], expect_ok=True)
check("manager errors", [mk("mgr-bad", [[
    {"op": "manager.rename", "team": "Ccc", "to": "Skipper,Ola"},
    {"op": "manager.rename", "team": "Aaa", "to": "Boss,Beta"},
    {"op": "manager.edit", "manager": "No,Body", "set": {"manager": {"manager_hitting": 90}}},
    {"op": "team.edit", "team": "Ccc", "set": {"org": {"org_budget": 5}, "tstat": {"team_wins_1sthalf": 3}}},
    {"op": "team.edit", "team": "Zzz", "set": {"team": {"team_climatezone": 1}}}]])], expect_ok=False)
art = mk("art", [[{"op": "loc.set", "file": "igeng.loc", "strings": {"2000": "Herons"}}]],
         assets=[{"path": "/data/frontend/logos.big", "entry": "L001.gsh", "file": "logo.gsh"}])
with open(os.path.join(art, "logo.gsh"), "wb") as f:
    f.write(b"an authored logo")
check("LOC text and an asset", [art], expect_ok=True)
art2 = mk("art2", [[]], assets=[{"path": "/data/frontend/logos.big", "entry": "l001.gsh", "file": "logo.gsh"},
                                {"path": "/data/frontend/missing.big", "entry": "x.gsh", "file": "logo.gsh"},
                                {"path": "/data/frontend/logos.big", "entry": "l999.gsh", "file": "logo2.gsh"}])
with open(os.path.join(art2, "logo.gsh"), "wb") as f:
    f.write(b"synthetic logo 1")
with open(os.path.join(art2, "logo2.gsh"), "wb") as f:
    f.write(b"new")
check("asset errors: retail copy, missing file and entry", [art2], expect_ok=False)
check("loc.set unknown id", [mk("badloc", [[{"op": "loc.set", "file": "FEENG.LOC", "strings": {"31337": "x"}}]])],
      expect_ok=False)

# Final-state rules.
check("unrostered player", [mk("loose", [[new_player("Doe,Jane")]])], expect_ok=False)
check("double-rostered player", [mk("double", [[{"op": "roster.replace", "team": "Bbb", "out": ROSTER["Bbb"][9][0],
                                                 "in": ROSTER["Ccc"][9][0]}]])], expect_ok=False)
bad = squad("Bbb")
bad[2]["rh_al"] = "B"
bad[3]["rh_nl"] = "3B:2"
bad[0]["pos"] = "C"
bad[5]["lh_nl"] = "DH"
bad[16]["rh_al"] = "LR:3"
check("roster shape", [mk("shape", [[{"op": "roster.set", "team": "Bbb", "entries": bad}]])], expect_ok=False)
check("short roster", [mk("short", [[{"op": "roster.set", "team": "Ccc", "entries": squad("Ccc")[:-1],
                                      "release": "remove"}]])], expect_ok=False)
e = squad("Bbb")
e[9], e[14] = dict(e[9], player=e[14]["player"]), dict(e[14], player=e[9]["player"])
check("pitching role without pitcher rows", [mk("roles", [[{"op": "roster.set", "team": "Bbb", "entries": e}]])],
      expect_ok=False)
sp = ROSTER["Bbb"][13][0]
check("pitches fill in order", [mk("pitch", [[{"op": "player.edit", "player": sp, "set": {"pitcher": {
    "pitchattrib_pitch3_type": "-", "pitchattrib_pitch3_movement": "-", "pitchattrib_pitch3_description": "-",
    "pitchattrib_pitch3_control": "-", "pitchattrib_pitch3_velocity": "-", "pitchattrib_pitch4_type": 3}}}]])],
      expect_ok=False)
check("SP without pitcher rows", [mk("make-sp", [[{"op": "player.edit", "player": ROSTER["Bbb"][0][0],
                                                   "set": {"attrib": {"playerattrib_primary_position": 0}}}]])],
      expect_ok=False)

# Composition.
p3 = ROSTER["Bbb"][3][0]


def speed(pid, value, **manifest):
    return mk(pid, [[{"op": "player.edit", "player": p3, "set": {"attrib": {"playerattrib_speed": value}}}]],
              **manifest)


pa = speed("pack-a", 50)
pb = mk("pack-b", [[{"op": "player.edit", "player": p3, "set": {"attrib": {"playerattrib_range": 9}}}]])
check("independent packs, A then B", [pa, pb], expect_ok=True)
check("independent packs, B then A", [pb, pa], expect_ok=True)
check("same cell, no dependency", [speed("pack-a", 50), speed("pack-b", 60)], expect_ok=False)
dep = speed("pack-b", 60, depends=[{"id": "pack-a", "version": "^1.0.0"}])
check("dependent pack overrides", [pa, dep], expect_ok=True)
check("dependency later in the set", [dep, pa], expect_ok=False)
check("dependency version", [pa, speed("pack-b", 60, depends=[{"id": "pack-a", "version": "^2.0.0"}])],
      expect_ok=False)
check("dependency missing", [speed("pack-c", 61, depends=[{"id": "nope", "version": "1.0.0"}])], expect_ok=False)
check("duplicate id", [pa, speed("pack-a", 70)], expect_ok=False)
check("self dependency", [speed("pack-s", 1, depends=[{"id": "pack-s", "version": "1.0.0"}])], expect_ok=False)
adds = mk("adds", [[new_player("Doe,Jane"),
                    {"op": "roster.replace", "team": "Ccc", "out": ROSTER["Ccc"][9][0], "in": "Doe,Jane",
                     "release": "remove"}]])
use = [{"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"playerattrib_speed": 80}}}]
check("using another pack's player", [adds, mk("user", [use])], expect_ok=False)
check("... with a dependency", [adds, mk("user", [use], depends=[{"id": "adds", "version": "1.0.0"}])],
      expect_ok=True)
check("transitive dependencies", [speed("pack-a", 50),
                                  mk("pack-b", [[]], depends=[{"id": "pack-a", "version": "^1.0.0"}]),
                                  speed("pack-c", 55, depends=[{"id": "pack-b", "version": "^1.0.0"}])],
      expect_ok=True)
ent = squad("Bbb")
check("roster conflict", [mk("ros-a", [[{"op": "roster.set", "team": "Bbb", "entries": ent}]]),
                          mk("ros-b", [[{"op": "roster.set", "team": "Bbb", "entries": ent}]])], expect_ok=False)
check("removal conflict", [speed("pack-a", 50),
                           mk("remove-two", [[new_player("Doe,Jane"),
                                              {"op": "roster.replace", "team": "Bbb", "out": p3, "in": "Doe,Jane",
                                               "release": "remove"}]])], expect_ok=False)
check("rename conflict", [speed("pack-a", 50),
                          mk("ren", [[{"op": "player.rename", "player": p3, "to": "Other,Name"}]])], expect_ok=False)

# Team slots.
check("team.names through main.dol", [mk("names", [[{"op": "team.names", "team": "Bbb", "location": "Elm Bay",
                                                      "nickname": "Herons", "abbreviation": "EBH"}]])],
      expect_ok=True)
check("team.names warnings", [mk("shared", [[
    {"op": "team.names", "team": "Aaa", "location": "Elm Bay", "full_name": "The Elm Bay Nine"},
    {"op": "team.names", "team": "Ccc", "nickname": "Owls"},
    {"op": "team.edit", "team": "Ccc", "set": {"team": {"team_short_name": "OWL"}}}]])], expect_ok=True)
check("team.names needs the retail main.dol", [mk("names", [[{"op": "team.names", "team": "Bbb",
                                                              "nickname": "Owls"}]])],
      dol_sha1="0" * 40, expect_ok=False)
check("team.names vs loc.set", [mk("names-a", [[{"op": "team.names", "team": "Bbb", "nickname": "Owls"}]]),
                                mk("names-b", [[{"op": "loc.set", "file": "IGENG.LOC",
                                                 "strings": {"2001": "Hawks"}}]])], expect_ok=False)
clip = mk("clip", [[]], assets=[{"path": "/data/audio/spch_pbp/tnamedat.big", "entry": "01.dat",
                                 "file": "clip.dat"}])
with open(os.path.join(clip, "clip.dat"), "wb") as f:
    f.write(b"an authored clip that is longer than the old one")
check("asset rebuild keeps the alignment", [clip], expect_ok=True)

# A kitchen sink: many ops in two dependent packs, assets, zipped.
league = mk("kitchen-sink", [[
    new_player("Halvorsen,Bram", pos=0, pitcher=True, playerattrib_throws=1),
    {"op": "player.edit", "player": "Halvorsen,Bram", "set": {
        "pitcher": {"pitchattrib_stamina": 92, "pitchattrib_fastball_velocity": 96},
        "rhattrib": {"lrattrib_power": 12}, "career": {"batcareerstats_g": 4000}}},
    new_player("Quist,Aldo", pos=6, playerattrib_bats=2, playerattrib_speed=88),
    {"op": "player.add", "player": "Ostrander,Milo", "pitcher": True,
     "set": {"attrib": {"playerattrib_primary_position": 10}, "pitcher": {
         "pitchattrib_pitch3_type": "-", "pitchattrib_pitch3_movement": "-", "pitchattrib_pitch3_description": "-",
         "pitchattrib_pitch3_control": "-", "pitchattrib_pitch3_velocity": "-"}}},
    {"op": "roster.replace", "team": "Bbb", "out": ROSTER["Bbb"][13][0], "in": "Halvorsen,Bram",
     "release": "remove"},
    {"op": "roster.replace", "team": "Bbb", "out": ROSTER["Bbb"][5][0], "in": "Quist,Aldo", "release": "keep"},
    {"op": "roster.replace", "team": "Ccc", "out": ROSTER["Ccc"][20][0], "in": "Ostrander,Milo",
     "release": "remove"},
    {"op": "player.remove", "player": ROSTER["Bbb"][5][0]},
    {"op": "player.rename", "player": ROSTER["Ccc"][2][0], "to": "Mabry,Quillon"},
    {"op": "player.edit", "player": ROSTER["Ccc"][18][0], "pitcher": False,
     "set": {"attrib": {"playerattrib_primary_position": 2}}},
    {"op": "roster.set", "team": "Ccc", "entries": [dict(x, **({"rh_al": "B", "rh_nl": "B", "lh_al": "B",
                                                                 "lh_nl": "B"}
                                                                if x["player"] == ROSTER["Ccc"][18][0] else {}))
                                                     for x in squad("Ccc", {ROSTER["Ccc"][2][0]: "Mabry,Quillon",
                                                                            ROSTER["Ccc"][20][0]: "Ostrander,Milo"})]},
    {"op": "team.edit", "team": "Bbb", "set": {"team": {"team_steals": 2, "team_vs_nyy": 1},
                                               "tstat": {"team_wins_1sthalf": "-", "team_losses_2ndhalf": 40},
                                               "org": {"org_budget": 60000}}},
    {"op": "team.names", "team": "Bbb", "nickname": "Lanterns", "abbreviation": "HCL"},
    {"op": "manager.rename", "team": "Bbb", "to": "Quarrington,Basil"},
    {"op": "manager.edit", "team": "Bbb", "set": {"manager": {"manager_hitting": 84, "manager_birthday": 100}}},
    {"op": "loc.set", "file": "MC_ENG.LOC", "strings": {"1": "Memory card ™ …"}},
], [
    {"op": "roster.swap", "a": ROSTER["Bbb"][0][0], "b": ROSTER["Bbb"][9][0]},
    {"op": "player.edit", "player": "Quist,Aldo", "set": {"attrib": {"playerattrib_speed": 90}}},
]], description="Everything at once — synthetic", authors=["E6"], license="CC0-1.0",
    meta={"tool": {"nested": [1, True, None]}},
    assets=[{"path": "/data/frontend/logos.big", "entry": "l000.gsh", "file": "art/logo.gsh"},
            {"path": "/data/audio/spch_pbp/tnamedat.big", "entry": "02.dat", "file": "art/clip.dat"}])
os.makedirs(os.path.join(league, "art"))
with open(os.path.join(league, "art", "logo.gsh"), "wb") as f:
    f.write(b"SHPG authored logo " * 7)
with open(os.path.join(league, "art", "clip.dat"), "wb") as f:
    f.write(b"SCHl authored clip " * 13)
tweak = mk("tweak", [[{"op": "player.edit", "player": "Halvorsen,Bram", "set": {"attrib": {"playerattrib_speed": 31}}},
                      {"op": "team.edit", "team": "Bbb", "set": {"team": {"team_steals": 1}}}]],
           depends=[{"id": "kitchen-sink", "version": "^1.0.0"}])
check("kitchen sink", [league], expect_ok=True)
check("kitchen sink + dependent tweak", [league, tweak], expect_ok=True)
check("kitchen sink zipped + tweak", [zipped(league), tweak], expect_ok=True)
check("tweak without its base", [tweak], expect_ok=False)

# The same on the disc as a GameCube image (pack.py reads it through gcdisc), and the
# engine's virtual disc: the packs mounted, every file read back through it.
check("image: kitchen sink + tweak", [league, tweak], disc=IMAGE, expect_ok=True, mount=True)
check("image: add players, names, art", [mk("img", [[
    new_player("Doe,Jane", pos=1),
    {"op": "roster.replace", "team": "Ccc", "out": ROSTER["Ccc"][0][0], "in": "Doe,Jane", "release": "remove"},
    {"op": "team.names", "team": "Bbb", "location": "Harbor City", "nickname": "Lanterns"}]]), art, clip],
      disc=IMAGE, expect_ok=True, mount=True)
check("image: errors", [art2], disc=IMAGE, expect_ok=False)
check("image: empty pack", [mk("nothing", [[]])], disc=IMAGE, expect_ok=True, mount=True)

if not args.keep:
    shutil.rmtree(tmp, ignore_errors=True)
else:
    print("kept", tmp)
print("%d scenarios, %d different" % (n_scenarios, len(failures)))
if failures:
    print("FAIL: " + "; ".join(failures))
    sys.exit(1)
print("PASS: the engine and pack.py agree on every scenario")
