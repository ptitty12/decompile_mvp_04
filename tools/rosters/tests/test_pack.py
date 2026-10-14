"""Tests for tools/rosters/pack.py (roster and team packs, format v1).

Synthetic data only: every table, name and number here is built by the test.
Run:  python -I -m unittest discover -s tools/rosters/tests -v
"""
import hashlib
import json
import os
import shutil
import struct
import sys
import tempfile
import unittest
import zipfile

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))

import big        # noqa: E402
import dbtables   # noqa: E402
import loc        # noqa: E402
import pack       # noqa: E402
import refpack    # noqa: E402

EXAMPLE = os.path.join(HERE, "..", "..", "..", "docs", "examples", "packs", "fictional-league")

# ---------------------------------------------------------------- a synthetic disc
# Teams: two clubs (league 0 and 1, 25 players), the AL All-Star side (a copy of Aaa's
# roster) and a Double-A club (league 4, 22 players).
TEAMS = [("Aaa", 0), ("Bbb", 1), ("AL", 0), ("Ccc", 4)]
LETTERS = "abcdefghijklmnopqrstuvwxyz"


def _row(table, key, first=None, last=None, **over):
    vals = []
    for c in pack.SCHEMA[table]:
        if c.name == "first_name":
            v = first
        elif c.name == "last_name":
            v = last
        elif c.name in over:
            v = over[c.name]
        elif c.kind == "int":
            v = c.lo
        else:
            v = "x"
        vals.append(str(v))
    return [key] + vals


def _pitcher_row(key, first, last):
    over = {}
    for n in (4, 5):
        for f in ("type", "movement", "description", "control", "velocity"):
            over["pitchattrib_pitch%d_%s" % (n, f)] = "-"
    return _row("pitcher", key, first, last, **over)


def _squad(code, size):
    """[(name, primary position, is_pitcher, entry codes per lineup)]"""
    fielders = [("C", 1), ("1B", 2), ("2B", 3), ("3B", 4), ("SS", 5), ("LF", 6), ("CF", 7), ("RF", 8)]
    out = []
    for i, (c, pos) in enumerate(fielders):
        out.append((c, pos, False, ["%s:%d" % (c, i + 1)] * 4))
    out.append(("DH", 9, False, ["DH:9", "B", "DH:9", "B"]))
    for _ in range(4 if size == 25 else 2):
        out.append(("B", 2, False, ["B"] * 4))
    out.append(("SP1", 0, True, ["SP1", "SP1:9", "SP1", "SP1:9"]))
    for s in ("SP2", "SP3", "SP4", "SP5", "LR", "LR", "MR", "MR", "SU", "CP"):
        out.append((s, 0 if s.startswith("SP") else 10, True, [s] * 4))
    if size == 25:
        out.append(("MR", 10, True, ["MR"] * 4))
    assert len(out) == size, (code, len(out))
    return [("Num%s,%s" % (LETTERS[i // 26] + LETTERS[i % 26], code + "x"), pos, pit, codes)
            for i, (_, pos, pit, codes) in enumerate(out)]


def make_disc(root):
    """Write a small but complete synthetic disc tree under root."""
    tables = {n: [] for n in pack.TABLE_ORDER}
    players = [("Default,Default", 2, True)]
    rosters = {}
    for code, league in TEAMS:
        if code == "AL":
            continue
        size = pack.LEVEL_SIZE[league]
        sq = _squad(code, size)
        rosters[code] = sq
        players += [(n, pos, pit) for n, pos, pit, _ in sq]
    rosters["AL"] = rosters["Aaa"]
    for name, pos, pit in players:
        last, first = name.split(",")
        k = pack.key_of(name)
        for t in pack.BATTER_TABLES:
            over = {"playerattrib_primary_position": pos} if t == "attrib" else {}
            tables[t].append(_row(t, k, first, last, **over))
        if pit:
            tables["pitcher"].append(_pitcher_row(k, first, last))
            for t in pack.PITCHER_TABLES[1:]:
                tables[t].append(_row(t, k, first, last))
    mgrs = ["Default,Default", "Boss,Alpha", "Boss,Beta"]
    for m in mgrs:
        last, first = m.split(",")
        tables["manager"].append(_row("manager", pack.key_of(m), first, last))

    def signed(name):
        v = dbtables.djb2(name)
        return v - (1 << 32) if v >= (1 << 31) else v

    for i, (code, league) in enumerate(TEAMS):
        k = pack.key_of(code)
        tables["team"].append(_row("team", k, unique_team=code, team_location="Testville",
                                   team_long_name="Testers", team_short_name=code.upper(),
                                   team_league=league, team_artid=i + 1))
        tables["tstat"].append(_row("tstat", k, unique_team=code))
    for code, mgr in (("Aaa", "Boss,Alpha"), ("Bbb", "Boss,Beta")):
        tables["org"].append(_row("org", pack.key_of(code), unique_team=code,
                                  org_team_mlb=dbtables.djb2(code), org_team_aaa=0, org_team_aa=0,
                                  org_team_a=0, org_mlb_manager=signed(mgr),
                                  org_minors_manager=signed(mgr)))
    n = 0
    for code, _ in TEAMS:
        for name, _, _, codes in rosters[code]:
            row = ["%09x" % n, pack.key_of(code), pack.key_of(name)]
            for c in codes:
                row += list(pack.parse_slot(c))
            tables["roster"].append(row)
            n += 1
    items = []
    for name in pack.TABLE_ORDER:
        t = dbtables.Table(name, [c.name for c in pack.SCHEMA[name]], tables[name])
        items.append((name + ".dat", refpack.compress(t.serialize())))
    for d in ("database", "frontend", "audio/spch_pbp"):
        os.makedirs(os.path.join(root, "data", *d.split("/")))
    os.makedirs(os.path.join(root, "sys"))
    with open(os.path.join(root, "data", "database", "database.big"), "wb") as f:
        f.write(big.build(items, flag=1))
    names = [(i, "Team text %d" % i) for i in sorted(set(sum(SLOT_IDS.values(), [])))]
    fe = names + [(7, "Menu")]
    ig = [(i, t) for i, t in names if i not in SLOT_IDS["city"]]
    for fn, strings in (("FEENG.LOC", fe), ("IGENG.LOC", ig), ("MC_ENG.loc", [(1, "Card")])):
        with open(os.path.join(root, "data", fn), "wb") as f:
            f.write(loc.Loc(strings).serialize())
    with open(os.path.join(root, "data", "frontend", "logos.big"), "wb") as f:
        f.write(big.build([("l000.gsh", b"synthetic logo 0"), ("l001.gsh", b"synthetic logo 1")]))
    with open(os.path.join(root, "data", "audio", "spch_pbp", "tnamedat.big"), "wb") as f:
        f.write(big.build([("01.dat", b"clip one"), ("02.dat", b"clip two")], flag=2, align=128))
    with open(os.path.join(root, "sys", "main.dol"), "wb") as f:
        f.write(make_dol())
    return rosters


# Team-slot tables of the synthetic main.dol: tids 0-2 are rows 0-2 (Aaa, Bbb, AL); row 3
# (Ccc) has no tid. Aaa and AL share their city string, as some retail teams do.
SLOT_IDS = {"full": [2040, 2041, 2042], "nickname": [2000, 2001, 2002],
            "abbreviation": [7200, 7201, 7202], "city": [17618, 17619, 17618]}


def make_dol():
    """A minimal DOL whose two data sections hold the slot tables at the retail addresses."""
    st = pack.SLOT_TABLES
    n = 3
    sec0 = b"".join(struct.pack(">%dI" % n, *v) for v in (
        SLOT_IDS["full"], SLOT_IDS["nickname"], SLOT_IDS["abbreviation"], SLOT_IDS["city"],
        [0, 1, 2]))
    assert st["nickname"] - st["full"] == 0x1F0      # retail spacing: 124 words per table
    sec0 = b"".join(sec0[i * 4 * n:(i + 1) * 4 * n] + b"\0" * (0x1F0 - 4 * n) for i in range(5))
    strings = b""
    ptrs = []
    base = st["tid_names"] + 4 * n
    for code in ("Aaa", "Bbb", "AL"):
        ptrs.append(base + len(strings))
        strings += code.encode() + b"\0"
    sec1 = struct.pack(">%dI" % n, *ptrs) + strings
    head = bytearray(0x100)
    struct.pack_into(">I", head, 0x1C, 0x100)                       # data 0 offset
    struct.pack_into(">I", head, 0x20, 0x100 + len(sec0))           # data 1 offset
    struct.pack_into(">I", head, 0x64, st["full"])                  # data 0 address
    struct.pack_into(">I", head, 0x68, st["tid_names"])             # data 1 address
    struct.pack_into(">I", head, 0xAC, len(sec0))
    struct.pack_into(">I", head, 0xB0, len(sec1))
    return bytes(head) + sec0 + sec1


def write_pack(root, pid, patches, **manifest):
    os.makedirs(os.path.join(root, "patches"), exist_ok=True)
    m = {"id": pid, "name": pid, "version": "1.0.0", "game": "GV4E69-0", "engine_api": "1.0",
         "patches": []}
    m.update(manifest)
    for i, ops in enumerate(patches):
        rel = "patches/p%d.json" % i
        m["patches"].append(rel)
        with open(os.path.join(root, rel), "w", newline="\n") as f:
            json.dump({"ops": ops}, f, indent=1)
    with open(os.path.join(root, "pack.json"), "w", newline="\n") as f:
        json.dump(m, f, indent=1)
    return root


def new_player(name, pos=2, pitcher=False, **attrib):
    a = {"playerattrib_primary_position": pos}
    a.update(attrib)
    op = {"op": "player.add", "player": name, "set": {"attrib": a}}
    if pitcher:
        op["pitcher"] = True
    return op


class PackTestCase(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.mkdtemp(prefix="packtest-")
        self.disc_dir = os.path.join(self.tmp, "disc")
        self.saved = (pack.DOL_SHA1, pack.SLOT_TABLES["count"])
        pack.SLOT_TABLES["count"] = 3
        self.rosters = make_disc(self.disc_dir)
        pack.DOL_SHA1 = hashlib.sha1(make_dol()).hexdigest()
        self.disc = pack.Disc(self.disc_dir)
        self.n = 0

    def tearDown(self):
        pack.DOL_SHA1, pack.SLOT_TABLES["count"] = self.saved
        shutil.rmtree(self.tmp, ignore_errors=True)

    def mk(self, pid, patches, **manifest):
        self.n += 1
        return write_pack(os.path.join(self.tmp, "pack%d" % self.n), pid, patches, **manifest)

    def run_set(self, specs):
        report = pack.Report()
        packs, model, out = pack.run_packs(specs, report, self.disc)
        return report, packs, model, out

    def codes(self, report):
        return [i[1] for i in report.issues if i[0] == "error"]

    def assertOnlyErrors(self, report, *codes):
        self.assertTrue(report.errors, "expected errors %s" % (codes,))
        self.assertEqual(sorted(set(self.codes(report))), sorted(set(codes)), report.render())

    def assertClean(self, report):
        self.assertTrue(report.ok, report.render())

    def squad_entries(self, code, rename=None):
        """roster.set entries equal to the synthetic squad of `code`, optionally with
        some players replaced: rename = {old name: new name}."""
        out = []
        for name, _, _, codes in self.rosters[code]:
            e = {"player": (rename or {}).get(name, name)}
            for ln, c in zip(pack.LINEUPS, codes):
                e[ln] = c
            out.append(e)
        return out


# ---------------------------------------------------------------- static checks
class StaticTests(PackTestCase):
    def test_example_pack_is_valid_without_a_disc(self):
        report = pack.Report()
        p = pack.load_pack(EXAMPLE, report)
        self.assertClean(report)
        self.assertEqual(p.id, "fictional-league")
        self.assertEqual(len(p.patches), 3)
        self.assertRegex(p.hash, "^[0-9a-f]{64}$")

    def test_json_must_be_strict(self):
        for text, why in (('{"ops": [], "ops": []}', "duplicate"), ('{"ops": [1.5]}', "non-integer"),
                          ('{"ops": [NaN]}', "NaN"), ('{"ops": [9999999999]}', "32-bit")):
            with self.assertRaises(pack._JsonError) as cm:
                pack.parse_json(text.encode())
            self.assertIn(why, str(cm.exception))
        self.assertEqual(pack.parse_json(b'\xef\xbb\xbf{"a": 1}'), {"a": 1})   # BOM ignored
        with self.assertRaises(pack._JsonError):
            pack.parse_json(b'{"a": "\xff"}')

    def test_manifest_errors(self):
        root = self.mk("ok-pack", [[]], game="GV4P69-0", engine_api="1.7", extra=1)
        report = pack.Report()
        pack.load_pack(root, report)
        self.assertOnlyErrors(report, "E-GAME", "E-ENGINE-API", "E-MANIFEST")
        report = pack.Report()
        pack.load_pack(self.mk("Bad_Id", [[]], version="1.0"), report)
        msgs = " ".join(i[3] for i in report.issues)
        self.assertIn("id must be", msgs)
        self.assertIn("MAJOR.MINOR.PATCH", msgs)

    def test_op_errors_are_reported_with_their_location(self):
        ops = [
            {"op": "player.fly", "player": "Doe,Jane"},
            {"op": "player.add", "player": "Doe,Jane", "set": {"attrib": {"playerattrib_speed": 120}}},
            {"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"first_name": "Jo"}}},
            {"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"no_such": 1}}},
            {"op": "player.add", "player": "Doe Jane"},
            {"op": "player.add", "player": "Doe,Jane", "set": {"pitcher": {}}},
            {"op": "roster.set", "team": "Aaa", "entries": [{"player": "Doe,Jane", "pos": "QB"}]},
            {"op": "team.edit", "team": "Aaa", "set": {"team": {"team_league": 3}}},
            {"op": "loc.set", "file": "FEENG.LOC", "strings": {"12": "badé"}},
        ]
        report = pack.Report()
        pack.load_pack(self.mk("bad-ops", [ops]), report)
        got = [(i[1], i[2].split(":ops[")[1].split("]")[0]) for i in report.errors]
        self.assertEqual(got, [("E-OP", "0"), ("E-VALUE", "1"), ("E-FIELD", "2"), ("E-FIELD", "3"),
                               ("E-NAME", "4"), ("E-OP", "5"), ("E-ROSTER", "6"), ("E-FIELD", "7"),
                               ("E-LOC", "8")])

    def test_asset_targets(self):
        os.makedirs(os.path.join(self.tmp, "a"))
        for name, data in (("logo.gsh", b"authored"), ("arc.big", b"BIGF....")):
            with open(os.path.join(self.tmp, "a", name), "wb") as f:
                f.write(data)
        root = self.mk("assets-bad", [[]], assets=[
            {"path": "/data/database/database.big", "entry": "attrib.dat", "file": "x.gsh"},
            {"path": "/data/frontend/logos.big", "file": "x.gsh"},
            {"path": "/data/frontend/logos.big", "entry": "l000.gsh", "file": "../a/logo.gsh"},
        ])
        report = pack.Report()
        pack.load_pack(root, report)
        self.assertOnlyErrors(report, "E-ASSET", "E-PATH")

    def test_pack_hash_ignores_formatting_but_not_content(self):
        a = self.mk("same-pack", [[new_player("Doe,Jane")]])
        b = os.path.join(self.tmp, "reformatted")
        shutil.copytree(a, b)
        for rel in ("pack.json", "patches/p0.json"):
            with open(os.path.join(a, rel), encoding="utf-8") as f:
                obj = json.load(f)
            with open(os.path.join(b, rel), "w", encoding="utf-8", newline="\r\n") as f:
                f.write(json.dumps(obj, indent=7))            # CRLF line ends, other layout
        c = self.mk("same-pack", [[new_player("Doe,Janet")]])
        hashes = []
        for root in (a, b, c):
            r = pack.Report()
            hashes.append(pack.load_pack(root, r).hash)
            self.assertClean(r)
        self.assertEqual(hashes[0], hashes[1])
        self.assertNotEqual(hashes[0], hashes[2])

    def test_zip_and_directory_hash_the_same(self):
        root = self.mk("zipped", [[new_player("Doe,Jane")]])
        zpath = os.path.join(self.tmp, "zipped.zip")
        with zipfile.ZipFile(zpath, "w") as z:
            for rel in ("pack.json", "patches/p0.json"):
                z.write(os.path.join(root, rel), "zipped/" + rel)    # one top-level folder
        r1, r2 = pack.Report(), pack.Report()
        self.assertEqual(pack.load_pack(root, r1).hash, pack.load_pack(zpath, r2).hash)
        self.assertClean(r2)

    def test_set_hash_depends_on_order(self):
        a = self.mk("pack-a", [[]])
        b = self.mk("pack-b", [[]])
        r = pack.Report()
        pa, pb = pack.load_pack(a, r), pack.load_pack(b, r)
        self.assertNotEqual(pack.set_hash([pa, pb]), pack.set_hash([pb, pa]))
        self.assertEqual(pack.set_hash([pa, pb]), pack.set_hash([pa, pb]))

    def test_version_requirements(self):
        v = pack.version_matches
        self.assertTrue(v("^1.2.0", (1, 4, 0)))
        self.assertFalse(v("^1.2.0", (2, 0, 0)))
        self.assertFalse(v("^1.2.0", (1, 1, 9)))
        self.assertTrue(v("^0.2.1", (0, 2, 5)))
        self.assertFalse(v("^0.2.1", (0, 3, 0)))
        self.assertTrue(v("1.2.3", (1, 2, 3)))
        self.assertFalse(v("1.2.3", (1, 2, 4)))


# ---------------------------------------------------------------- applying
class ApplyTests(PackTestCase):
    def test_empty_set_changes_nothing(self):
        report, packs, model, (files, texts, changed) = self.run_set([self.mk("nothing", [[]])])
        self.assertClean(report)
        self.assertEqual((files, changed), ({}, []))

    def test_add_players_and_replace_a_roster(self):
        old = [n for n, _, _, _ in self.rosters["Bbb"]][:2]
        ops = [new_player("Doe,Jane", pos=1, playerattrib_speed=77),
               new_player("Roe,Rick", pos=2)]
        ops.append({"op": "roster.set", "team": "Bbb", "release": "remove",
                    "entries": self.squad_entries("Bbb", {old[0]: "Doe,Jane", old[1]: "Roe,Rick"})})
        report, packs, model, (files, texts, changed) = self.run_set([self.mk("adds", [ops])])
        self.assertClean(report)
        orig = big.BigArchive.from_bytes(self.disc.read(pack.DATABASE_PATH))
        new = big.BigArchive.from_bytes(files[pack.DATABASE_PATH])
        db = dbtables.Database(new)
        att = db.table("attrib")
        self.assertEqual(att.value(pack.key_of("Doe,Jane"), "playerattrib_speed"), "77")
        self.assertEqual(att.value(pack.key_of("Doe,Jane"), "first_name"), "Jane")
        self.assertIsNone(att.get(pack.key_of(old[0])))             # released and removed
        self.assertEqual(len(att.rows), len(dbtables.Database(orig).table("attrib").rows))
        # unset fields come from the Default row of the same table
        dflt = dbtables.Database(orig).table("rhattrib").get(pack.key_of("Default,Default"))
        self.assertEqual(db.table("rhattrib").get(pack.key_of("Roe,Rick"))[3:], dflt[3:])
        # tables the pack did not touch keep their original stored bytes
        for name in ("team", "tstat", "org", "manager"):
            self.assertEqual(new.raw(name + ".dat"), orig.raw(name + ".dat"), name)
        self.assertNotIn("team", changed)
        ros = db.table("roster")
        self.assertEqual([r[0] for r in ros.rows], ["%09x" % i for i in range(len(ros.rows))])
        self.assertIn(pack.key_of("Doe,Jane"), {r[2] for r in ros.rows})

    def test_apply_twice_gives_identical_bytes(self):
        ops = [new_player("Doe,Jane"), {"op": "team.edit", "team": "Aaa", "set": {
            "team": {"team_location": "Elm Bay", "team_long_name": "Herons", "team_short_name": "EBH"}}},
            {"op": "loc.set", "file": "FEENG.LOC", "strings": {"2000": "Herons"}},
            {"op": "roster.replace", "team": "Ccc", "out": self.rosters["Ccc"][9][0],
             "in": "Doe,Jane", "release": "remove"}]
        root = self.mk("twice", [ops])
        r1, _, _, out1 = self.run_set([root])
        r2, _, _, out2 = self.run_set([root])
        self.assertClean(r1)
        self.assertEqual(out1[0], out2[0])
        self.assertEqual(pack.result_hash(out1[1]), pack.result_hash(out2[1]))
        self.assertEqual(sorted(out1[0]), ["/data/FEENG.LOC", pack.DATABASE_PATH])

    def test_rename_rekeys_everywhere(self):
        star = self.rosters["Aaa"][0][0]              # also on the AL All-Star roster
        report, _, model, out = self.run_set([self.mk("rename", [[
            {"op": "player.rename", "player": star, "to": "Newname,Sam"}]])])
        self.assertClean(report)
        db = dbtables.Database(big.BigArchive.from_bytes(out[0][pack.DATABASE_PATH]))
        k = pack.key_of("Newname,Sam")
        for t in pack.BATTER_TABLES:
            self.assertEqual(db.table(t).get(k)[1:3], ["Sam", "Newname"], t)
            self.assertIsNone(db.table(t).get(pack.key_of(star)))
        teams = {r[1] for r in db.table("roster").rows if r[2] == k}
        self.assertEqual(teams, {pack.key_of("Aaa"), pack.key_of("AL")})
        report, *_ = self.run_set([self.mk("rename2", [[
            {"op": "player.rename", "player": star, "to": "Newname,Sam"},
            {"op": "player.edit", "player": star, "set": {"attrib": {"playerattrib_speed": 5}}}]])])
        self.assertOnlyErrors(report, "E-NOT-FOUND")

    def test_swap_trades_and_promotes(self):
        a, b = self.rosters["Bbb"][0][0], self.rosters["Ccc"][0][0]     # the two catchers
        backup = self.rosters["Bbb"][9][0]
        report, _, model, _ = self.run_set([self.mk("swaps", [[
            {"op": "roster.swap", "a": a, "b": b},
            {"op": "roster.swap", "a": b, "b": backup}]])])
        self.assertClean(report)
        bbb = {e[0]: e[1:] for e in model.rosters["Bbb"]}
        self.assertEqual(bbb[pack.key_of(backup)][0], "C")               # promoted
        self.assertEqual(bbb[pack.key_of(b)][0], "B")
        self.assertIn(pack.key_of(a), {e[0] for e in model.rosters["Ccc"]})

    def test_remove_requires_leaving_every_roster(self):
        p = self.rosters["Bbb"][10][0]
        report, *_ = self.run_set([self.mk("remove-one", [[{"op": "player.remove", "player": p}]])])
        self.assertOnlyErrors(report, "E-ROSTER")
        report, *_ = self.run_set([self.mk("rm2", [[
            new_player("Doe,Jane"),
            {"op": "roster.replace", "team": "Bbb", "out": p, "in": "Doe,Jane"},
            {"op": "player.remove", "player": p}]])])
        self.assertClean(report)

    def test_default_row_is_protected(self):
        report, *_ = self.run_set([self.mk("dflt", [[
            {"op": "player.edit", "player": "Default,Default",
             "set": {"attrib": {"playerattrib_speed": 50}}}]])])
        self.assertOnlyErrors(report, "E-PROTECTED")

    def test_djb2_collision_is_rejected(self):
        self.assertEqual(dbtables.djb2("Smith,Ab"), dbtables.djb2("Smith,BA"))
        report, *_ = self.run_set([self.mk("collide", [[new_player("Smith,Ab"), new_player("Smith,BA")]])])
        self.assertIn("E-KEY-EXISTS", self.codes(report))
        self.assertIn("collision", report.render())

    def test_manager_by_team_and_org_link(self):
        report, _, model, out = self.run_set([self.mk("mgr", [[
            {"op": "manager.rename", "team": "Aaa", "to": "Skipper,Ola"},
            {"op": "manager.edit", "manager": "Skipper,Ola", "set": {"manager": {"manager_hitting": 90}}},
            {"op": "team.edit", "team": "Bbb", "set": {"org": {"org_mlb_manager": "Skipper,Ola"}}}]])])
        self.assertClean(report)
        db = dbtables.Database(big.BigArchive.from_bytes(out[0][pack.DATABASE_PATH]))
        k = int(pack.key_of("Skipper,Ola"), 16)
        org = db.table("org")
        for code in ("Aaa", "Bbb"):
            v = int(org.value(pack.key_of(code), "org_mlb_manager"))
            self.assertEqual(v & 0xFFFFFFFF, k, code)
        self.assertEqual(db.table("manager").value("%09x" % k, "manager_hitting"), "90")

    def test_loc_and_assets(self):
        art = os.path.join(self.tmp, "art")
        root = self.mk("art", [[{"op": "loc.set", "file": "igeng.loc", "strings": {"2000": "Herons"}}]],
                       assets=[{"path": "/data/frontend/logos.big", "entry": "L001.gsh",
                                "file": "logo.gsh"}])
        with open(os.path.join(root, "logo.gsh"), "wb") as f:
            f.write(b"an authored logo")
        report, _, _, out = self.run_set([root])
        self.assertClean(report)
        arc = big.BigArchive.from_bytes(out[0]["/data/frontend/logos.big"])
        self.assertEqual(arc.raw("l001.gsh"), b"an authored logo")
        self.assertEqual(arc.raw("l000.gsh"), b"synthetic logo 0")
        self.assertEqual(dict(loc.Loc.parse(out[0]["/data/IGENG.LOC"]).entries)[2000], "Herons")
        with open(os.path.join(root, "logo.gsh"), "wb") as f:
            f.write(b"synthetic logo 1")                      # a copy of the "retail" entry
        report, *_ = self.run_set([root])
        self.assertOnlyErrors(report, "E-RETAIL-COPY")
        report, *_ = self.run_set([self.mk("badloc", [[
            {"op": "loc.set", "file": "FEENG.LOC", "strings": {"31337": "x"}}]])])
        self.assertOnlyErrors(report, "E-NOT-FOUND")


# ---------------------------------------------------------------- final-state rules
class RuleTests(PackTestCase):
    def test_capacity_limits(self):
        start = 1 + 25 + 25 + 22
        saved = dict(pack.LIMITS)
        try:
            pack.LIMITS["players"] = start + 1
            ops = [new_player("Doe,Jane"), new_player("Roe,Rick")]
            report, _, model, _ = self.run_set([self.mk("cap", [ops])])
            self.assertOnlyErrors(report, "E-CAPACITY", "E-ROSTER-HOME")
            self.assertIn("%d players" % (start + 2), report.render())
            pack.LIMITS["players"] = 3250
            pack.LIMITS["pitchers"] = 1 + 12 + 12 + 11
            report, *_ = self.run_set([self.mk("cap2", [[new_player("Arm,Strong", pos=10, pitcher=True)]])])
            self.assertIn("E-CAPACITY", self.codes(report))
        finally:
            pack.LIMITS.clear()
            pack.LIMITS.update(saved)

    def test_real_capacities_are_the_documented_ones(self):
        self.assertEqual(pack.LIMITS, {"players": 3250, "pitchers": 1800, "teams": 126,
                                       "managers": 36})

    def test_unrostered_and_double_rostered_players(self):
        report, *_ = self.run_set([self.mk("loose", [[new_player("Doe,Jane")]])])
        self.assertOnlyErrors(report, "E-ROSTER-HOME")
        b0 = self.rosters["Bbb"][9][0]
        c0 = self.rosters["Ccc"][9][0]
        report, *_ = self.run_set([self.mk("double", [[
            {"op": "roster.replace", "team": "Bbb", "out": b0, "in": c0}]])])
        self.assertIn("E-ROSTER-HOME", self.codes(report))        # c0 now on Bbb and Ccc

    def test_roster_shape(self):
        bad = self.squad_entries("Bbb")
        bad[2]["rh_al"] = "B"                                     # no 2B against RHP (DH)
        bad[3]["rh_nl"] = "3B:2"                                  # two #2 hitters
        bad[0]["pos"] = "C"                                       # harmless: lineup keys win
        report, *_ = self.run_set([self.mk("shape", [[
            {"op": "roster.set", "team": "Bbb", "entries": bad}]])])
        msgs = report.render()
        self.assertOnlyErrors(report, "E-ROSTER")
        self.assertIn("lineup rh_al has 0 at 2B", msgs)
        self.assertIn("batting orders must be 1-9", msgs)
        short = self.squad_entries("Ccc")[:-1]
        report, *_ = self.run_set([self.mk("short", [[
            {"op": "roster.set", "team": "Ccc", "entries": short, "release": "remove"}]])])
        self.assertIn("21 players; a team of league 4 has exactly 22", report.render())

    def test_pitching_role_needs_a_pitcher(self):
        e = self.squad_entries("Bbb")
        e[9], e[14] = dict(e[9], player=e[14]["player"]), dict(e[14], player=e[9]["player"])
        report, *_ = self.run_set([self.mk("roles", [[{"op": "roster.set", "team": "Bbb", "entries": e}]])])
        self.assertIn("is not a pitcher", report.render())
        self.assertIn("W-PITCHER-BENCH", [i[1] for i in report.issues])

    def test_pitches_fill_in_order(self):
        sp = self.rosters["Bbb"][13][0]
        report, *_ = self.run_set([self.mk("pitch", [[
            {"op": "player.edit", "player": sp, "set": {"pitcher": {
                "pitchattrib_pitch3_type": "-", "pitchattrib_pitch3_movement": "-",
                "pitchattrib_pitch3_description": "-", "pitchattrib_pitch3_control": "-",
                "pitchattrib_pitch3_velocity": "-", "pitchattrib_pitch4_type": 3}}}]])])
        self.assertOnlyErrors(report, "E-VALUE")

    def test_primary_position_pitcher_needs_pitcher_rows(self):
        report, *_ = self.run_set([self.mk("make-sp", [[
            {"op": "player.edit", "player": self.rosters["Bbb"][0][0],
             "set": {"attrib": {"playerattrib_primary_position": 0}}}]])])
        self.assertOnlyErrors(report, "E-PITCHER")


# ---------------------------------------------------------------- composition
class CompositionTests(PackTestCase):
    def setUp(self):
        super().setUp()
        self.p = self.rosters["Bbb"][3][0]

    def speed(self, pid, value, **manifest):
        return self.mk(pid, [[{"op": "player.edit", "player": self.p,
                               "set": {"attrib": {"playerattrib_speed": value}}}]], **manifest)

    def test_independent_packs_on_different_fields_compose(self):
        a = self.speed("pack-a", 50)
        b = self.mk("pack-b", [[{"op": "player.edit", "player": self.p,
                                 "set": {"attrib": {"playerattrib_range": 9}}}]])
        report, _, model, _ = self.run_set([a, b])
        self.assertClean(report)
        report2, _, model2, _ = self.run_set([b, a])
        self.assertClean(report2)
        k = pack.key_of(self.p)
        self.assertEqual(model.players[k].vals, model2.players[k].vals)

    def test_same_cell_from_independent_packs_is_a_conflict(self):
        report, *_ = self.run_set([self.speed("pack-a", 50), self.speed("pack-b", 60)])
        self.assertOnlyErrors(report, "E-CONFLICT")
        self.assertIn("pack 'pack-a'", report.render())

    def test_a_dependent_pack_overrides_in_order(self):
        a = self.speed("pack-a", 50)
        b = self.speed("pack-b", 60, depends=[{"id": "pack-a", "version": "^1.0.0"}])
        report, _, model, _ = self.run_set([a, b])
        self.assertClean(report)
        k = pack.key_of(self.p)
        self.assertEqual(model.players[k].vals["attrib"][pack.COL_INDEX["attrib"]["playerattrib_speed"]], "60")
        report, *_ = self.run_set([b, a])
        self.assertOnlyErrors(report, "E-DEPENDENCY")

    def test_dependency_version_and_presence(self):
        a = self.speed("pack-a", 50)
        b = self.speed("pack-b", 60, depends=[{"id": "pack-a", "version": "^2.0.0"}])
        report, *_ = self.run_set([a, b])
        self.assertOnlyErrors(report, "E-DEPENDENCY")
        report, *_ = self.run_set([self.speed("pack-c", 61, depends=[{"id": "nope", "version": "1.0.0"}])])
        self.assertIn("is not in the set", report.render())
        report, *_ = self.run_set([a, self.speed("pack-a", 70)])
        self.assertIn("E-DUPLICATE", self.codes(report))

    def test_using_another_packs_player_needs_a_dependency(self):
        out = self.rosters["Bbb"][10][0]
        a = self.mk("adds", [[new_player("Doe,Jane"),
                              {"op": "roster.replace", "team": "Ccc", "out": self.rosters["Ccc"][9][0],
                               "in": "Doe,Jane", "release": "remove"}]])
        use = [{"op": "player.edit", "player": "Doe,Jane", "set": {"attrib": {"playerattrib_speed": 80}}}]
        report, *_ = self.run_set([a, self.mk("user", [use])])
        self.assertOnlyErrors(report, "E-CONFLICT")
        report, *_ = self.run_set([a, self.mk("user", [use], depends=[{"id": "adds", "version": "1.0.0"}])])
        self.assertClean(report)
        del out

    def test_transitive_dependencies_count(self):
        a = self.speed("pack-a", 50)
        b = self.mk("pack-b", [[]], depends=[{"id": "pack-a", "version": "^1.0.0"}])
        c = self.speed("pack-c", 55, depends=[{"id": "pack-b", "version": "^1.0.0"}])
        report, *_ = self.run_set([a, b, c])
        self.assertClean(report)

    def test_roster_conflict_and_removal_conflict(self):
        e = self.squad_entries("Bbb")
        a = self.mk("ros-a", [[{"op": "roster.set", "team": "Bbb", "entries": e}]])
        b = self.mk("ros-b", [[{"op": "roster.set", "team": "Bbb", "entries": e}]])
        report, *_ = self.run_set([a, b])
        self.assertOnlyErrors(report, "E-CONFLICT")
        edit = self.speed("pack-a", 50)
        rm = self.mk("remove-two", [[new_player("Doe,Jane"),
                             {"op": "roster.replace", "team": "Bbb", "out": self.p, "in": "Doe,Jane",
                              "release": "remove"}]])
        report, *_ = self.run_set([edit, rm])
        self.assertEqual(self.codes(report)[0], "E-CONFLICT", report.render())


class SlotTests(PackTestCase):
    def loc(self, out, fn):
        data = out[0].get("/data/" + fn) or self.disc.read("/data/" + fn)
        return dict(loc.Loc.parse(data).entries)

    def test_team_names_sets_table_and_loc_through_main_dol(self):
        report, _, model, out = self.run_set([self.mk("names", [[
            {"op": "team.names", "team": "Bbb", "location": "Elm Bay", "nickname": "Herons",
             "abbreviation": "EBH"}]])])
        self.assertClean(report)
        row = model.team_row("Bbb")
        self.assertEqual(row[1:4], ["Elm Bay", "Herons", "EBH"])
        fe, ig = self.loc(out, "FEENG.LOC"), self.loc(out, "IGENG.LOC")
        for d in (fe, ig):
            self.assertEqual((d[2041], d[2001], d[7201]), ("Elm Bay Herons", "Herons", "EBH"))
            self.assertEqual(d[2040], "Team text 2040")              # other slots untouched
        self.assertEqual(fe[17619], "Elm Bay")                       # city: FEENG only
        self.assertNotIn(17619, ig)

    def test_team_names_warnings(self):
        report, _, _, out = self.run_set([self.mk("shared", [[
            {"op": "team.names", "team": "Aaa", "location": "Elm Bay", "full_name": "The Elm Bay Nine"},
            {"op": "team.names", "team": "Ccc", "nickname": "Owls"}]])])
        self.assertClean(report)
        warns = [i[1] for i in report.issues]
        self.assertIn("W-LOC-SHARED", warns)                         # Aaa's city is AL's too
        self.assertIn("W-NOT-A-SLOT", warns)                         # Ccc has no tid
        self.assertEqual(self.loc(out, "FEENG.LOC")[2040], "The Elm Bay Nine")

    def test_team_names_needs_the_retail_main_dol(self):
        pack.DOL_SHA1 = "0" * 40
        with self.assertRaises(pack.PackError):
            self.run_set([self.mk("names", [[{"op": "team.names", "team": "Bbb", "nickname": "Owls"}]])])

    def test_team_names_conflicts_with_loc_set(self):
        a = self.mk("names-a", [[{"op": "team.names", "team": "Bbb", "nickname": "Owls"}]])
        b = self.mk("names-b", [[{"op": "loc.set", "file": "IGENG.LOC", "strings": {"2001": "Hawks"}}]])
        report, *_ = self.run_set([a, b])
        self.assertOnlyErrors(report, "E-CONFLICT")

    def test_asset_rebuild_keeps_the_archive_alignment(self):
        root = self.mk("clip", [[]], assets=[{"path": "/data/audio/spch_pbp/tnamedat.big",
                                              "entry": "01.dat", "file": "clip.dat"}])
        with open(os.path.join(root, "clip.dat"), "wb") as f:
            f.write(b"an authored clip that is longer than the old one")
        report, _, _, out = self.run_set([root])
        self.assertClean(report)
        arc = big.BigArchive.from_bytes(out[0]["/data/audio/spch_pbp/tnamedat.big"])
        self.assertEqual([e.offset % 128 for e in arc.entries], [0, 0])
        self.assertEqual(arc.payload_alignment(), 128)
        self.assertEqual(arc.raw("02.dat"), b"clip two")


class CliTests(PackTestCase):
    def test_hash_and_validate_commands(self):
        root = self.mk("cli-pack", [[]])
        import contextlib
        import io
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            self.assertEqual(pack.main(["hash", root]), 0)
            self.assertEqual(pack.main(["validate", "--disc", self.disc_dir, root]), 0)
        self.assertIn("cli-pack 1.0.0", buf.getvalue())

    def test_new_scaffold_validates(self):
        import contextlib
        import io
        d = os.path.join(self.tmp, "scaffold")
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(pack.main(["new", d, "--id", "my-pack"]), 0)
        r = pack.Report()
        pack.load_pack(d, r)
        self.assertClean(r)

    def test_apply_writes_mirrored_paths(self):
        import contextlib
        import io
        root = self.mk("cli-apply", [[{"op": "loc.set", "file": "FEENG.LOC", "strings": {"7": "Play"}}]])
        out = os.path.join(self.tmp, "out")
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(pack.main(["apply", "--disc", self.disc_dir, "--out", out, root]), 0)
        self.assertTrue(os.path.isfile(os.path.join(out, "data", "FEENG.LOC")))
        with open(os.path.join(out, "pack-apply.json"), encoding="utf-8") as f:
            rep = json.load(f)
        self.assertRegex(rep["result_hash"], "^[0-9a-f]{64}$")


if __name__ == "__main__":
    unittest.main()
