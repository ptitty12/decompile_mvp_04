"""Unit tests for tools/rosters. Synthetic data only: nothing here comes from the game.

Run:  python -I -m unittest discover -s tools/rosters/tests -v
"""
import os
import random
import struct
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))

import big        # noqa: E402
import dbtables   # noqa: E402
import loc        # noqa: E402
import refpack    # noqa: E402


def sample_table_text():
    """A tiny table in the on-disc text format, built by hand."""
    lines = [
        "0 first_name,1 last_name,2 score,3 note,;",
        "%09x,0 Ann,1 Able,2 10,3 -,;" % dbtables.djb2("Able,Ann"),
        "%09x,0 Bob,1 Baker,2 -4,3 x y,;" % dbtables.djb2("Baker,Bob"),
        "%09x,0 Cy,1 Cole,2 007,3 z,;" % dbtables.djb2("Cole,Cy"),
    ]
    return ("\r\n".join(lines) + "\r\n").encode("latin-1")


class RefPackTests(unittest.TestCase):
    def test_header(self):
        c = refpack.compress(b"hello hello hello hello")
        self.assertEqual(c[:2], b"\x10\xfb")
        self.assertEqual(refpack.parse_header(c)[0], 23)
        self.assertTrue(refpack.is_refpack(c))
        self.assertFalse(refpack.is_refpack(b"plain text here"))

    def test_roundtrip_edge_sizes(self):
        for n in (0, 1, 2, 3, 4, 5, 111, 112, 113, 115, 116, 1000):
            data = bytes((i * 7 + 3) & 0xFF for i in range(n))
            self.assertEqual(refpack.decompress(refpack.compress(data)), data, n)

    def test_roundtrip_repetitive(self):
        data = (b"abcd" * 5000) + b"tail" + (b"xyz" * 300)
        c = refpack.compress(data)
        self.assertLess(len(c), len(data) // 10)
        self.assertEqual(refpack.decompress(c), data)

    def test_roundtrip_random_mix(self):
        rng = random.Random(1234)
        parts = []
        for _ in range(200):
            if rng.random() < 0.5 and parts:
                parts.append(rng.choice(parts)[: rng.randint(1, 40)])
            else:
                parts.append(bytes(rng.randrange(256) for _ in range(rng.randint(1, 30))))
        data = b"".join(parts)
        self.assertEqual(refpack.decompress(refpack.compress(data)), data)

    def test_long_distance(self):
        rng = random.Random(7)
        block = bytes(rng.randrange(256) for _ in range(300))
        filler = bytes(rng.randrange(256) for _ in range(70000))
        data = block + filler + block
        self.assertEqual(refpack.decompress(refpack.compress(data)), data)

    def test_decode_hand_built_stream(self):
        # literal run of 4 ("abcd"), then 2-byte copy (len 3, dist 4), then stop+0
        stream = bytes([0x10, 0xFB, 0, 0, 7, 0xE0]) + b"abcd" + bytes([0x00, 0x03, 0xFC])
        self.assertEqual(refpack.decompress(stream), b"abcdabc")

    def test_errors(self):
        with self.assertRaises(refpack.RefPackError):
            refpack.decompress(b"\x00\x00\x00\x00\x00")
        good = refpack.compress(b"some data some data")
        with self.assertRaises(refpack.RefPackError):
            refpack.decompress(good[:-3])


class BigTests(unittest.TestCase):
    def test_build_parse_roundtrip(self):
        items = [("a.dat", b"12345"), ("b.csv", b"x" * 10), ("c.bin", b"")]
        raw = big.build(items, flag=0)
        arc = big.BigArchive.from_bytes(raw)
        self.assertEqual(arc.names(), ["a.dat", "b.csv", "c.bin"])
        self.assertEqual(arc.raw("b.csv"), b"x" * 10)
        self.assertEqual(arc.check_layout(), [])
        self.assertEqual(arc.to_bytes(), raw)
        self.assertEqual(arc.flag, 0)

    def test_layout_matches_the_documented_format(self):
        raw = big.build([("t.dat", b"abc"), ("u.dat", b"defgh")], flag=1)
        self.assertEqual(raw[:4], b"BIGF")
        self.assertEqual(struct.unpack("<I", raw[4:8])[0], len(raw))        # size: little endian
        self.assertEqual(struct.unpack(">II", raw[8:16]), (2, 16 + 8 + 6 + 8 + 6 + 8))
        off0, size0 = struct.unpack(">II", raw[16:24])
        self.assertEqual(off0 % 4, 0)
        self.assertEqual(size0, 3)
        self.assertIn(b"L234\x00\x00\x00\x01", raw)
        self.assertEqual(len(raw), 52 + 3 + 1 + 5)   # header, a, pad, b (last payload unpadded)

    def test_read_decompresses_only_refpack_payloads(self):
        text = b"hello world " * 20
        raw = big.build([("c.txt", refpack.compress(text)), ("p.txt", b"plain")], flag=1)
        arc = big.BigArchive.from_bytes(raw)
        self.assertTrue(arc.is_compressed("c.txt"))
        self.assertFalse(arc.is_compressed("p.txt"))
        self.assertEqual(arc.read("c.txt"), text)
        self.assertEqual(arc.read("p.txt"), b"plain")
        self.assertEqual(arc.read("C.TXT"), text)   # names are case-insensitive

    def test_replace_entry(self):
        raw = big.build([("a", b"one"), ("b", b"two!")])
        arc = big.BigArchive.from_bytes(raw)
        new = big.BigArchive.from_bytes(arc.to_bytes({"a": b"a much longer payload"}))
        self.assertEqual(new.raw("a"), b"a much longer payload")
        self.assertEqual(new.raw("b"), b"two!")
        self.assertEqual(new.check_layout(), [])

    def test_bad_input(self):
        with self.assertRaises(big.BigError):
            big.BigArchive.from_bytes(b"NOPE" + b"\0" * 40)
        raw = bytearray(big.build([("a", b"x")]))
        raw[-9:-5] = b"XXXX"   # corrupt the trailer tag
        with self.assertRaises(big.BigError):
            big.BigArchive.from_bytes(bytes(raw))


class TableTests(unittest.TestCase):
    def test_hash(self):
        # h = h*33 + c from 5381, 32 bit
        self.assertEqual(dbtables.djb2(""), 5381)
        self.assertEqual(dbtables.djb2("a"), 5381 * 33 + 97)
        self.assertEqual(dbtables.key_text(dbtables.djb2("ab")), "%09x" % (((5381 * 33 + 97) * 33 + 98) & 0xFFFFFFFF))
        self.assertLess(dbtables.djb2("a long string that overflows 32 bits easily"), 1 << 32)

    def test_parse_and_exact_reserialize(self):
        data = sample_table_text()
        t = dbtables.Table.parse("demo", data)
        self.assertEqual(t.fields, ["first_name", "last_name", "score", "note"])
        self.assertEqual(len(t.rows), 3)
        self.assertEqual(t.serialize(), data)

    def test_values_and_json(self):
        t = dbtables.Table.parse("demo", sample_table_text())
        key = "%09x" % dbtables.djb2("Baker,Bob")
        self.assertEqual(t.value(key, "score"), "-4")
        j = t.to_json()
        rec = {r["_key"]: r for r in j["records"]}[key]
        self.assertEqual(rec["score"], -4)             # canonical int becomes a number
        self.assertEqual(rec["note"], "x y")           # spaces survive in values
        cole = {r["_key"]: r for r in j["records"]}["%09x" % dbtables.djb2("Cole,Cy")]
        self.assertEqual(cole["score"], "007")         # non-canonical text stays text
        self.assertEqual(rec["first_name"], "Bob")
        back = dbtables.Table.from_json(j)
        self.assertEqual(back.serialize(), sample_table_text())

    def test_edit_add_remove(self):
        t = dbtables.Table.parse("demo", sample_table_text())
        k = "%09x" % dbtables.djb2("Able,Ann")
        t.set(k, score=99, note="-")
        self.assertEqual(t.value(k, "score"), "99")
        nk = "%09x" % dbtables.djb2("Dunn,Di")
        t.add(nk, {"first_name": "Di", "last_name": "Dunn", "score": 5, "note": "n"})
        self.assertEqual(len(t.rows), 4)
        again = dbtables.Table.parse("demo", t.serialize())
        self.assertEqual(again.value(nk, "last_name"), "Dunn")
        t.remove(k)
        self.assertEqual(len(t.rows), 3)
        with self.assertRaises(dbtables.TableError):
            t.add(nk, {"first_name": "x"})              # missing fields / duplicate key

    def test_rejects_separators_in_values(self):
        t = dbtables.Table.parse("demo", sample_table_text())
        k = "%09x" % dbtables.djb2("Able,Ann")
        t.set(k, note="a,b")
        with self.assertRaises(dbtables.TableError):
            t.serialize()

    def test_rejects_malformed_text(self):
        good = sample_table_text()
        for bad in (good[:-2],                                   # no final CRLF
                    good.replace(b",;\r\n", b";\r\n", 1),        # header terminator
                    good.replace(b",2 10,", b",3 10,", 1),       # field out of order
                    good.replace(b",3 -,;", b",;", 1)):          # missing value
            with self.assertRaises(dbtables.TableError):
                dbtables.Table.parse("demo", bad)


class DatabaseTests(unittest.TestCase):
    def make_archive(self):
        t1 = sample_table_text()
        t2 = (b"0 unique_team,1 team_long_name,;\r\n"
              + ("%09x,0 Ana,1 Somewhere,;\r\n" % dbtables.djb2("Ana")).encode())
        return big.build([("team.dat", refpack.compress(t2)),
                          ("attrib.dat", refpack.compress(t1)),
                          ("notes.txt", b"not a table")], flag=1)

    def test_unchanged_database_reproduces_archive(self):
        raw = self.make_archive()
        db = dbtables.Database(big.BigArchive.from_bytes(raw))
        self.assertEqual(sorted(db.tables), ["attrib", "team"])   # only *.dat entries
        self.assertEqual(db.changed(), [])
        self.assertEqual(db.to_bytes(), raw)

    def test_changed_table_is_recompressed_and_others_kept(self):
        raw = self.make_archive()
        db = dbtables.Database(big.BigArchive.from_bytes(raw))
        a = db.table("attrib")
        a.set("%09x" % dbtables.djb2("Able,Ann"), score=11)
        self.assertEqual(db.changed(), ["attrib"])
        out = db.to_bytes()
        db2 = dbtables.Database(big.BigArchive.from_bytes(out))
        self.assertEqual(db2.table("attrib").value("%09x" % dbtables.djb2("Able,Ann"), "score"), "11")
        self.assertEqual(db2.table("team").serialize(), db.table("team").serialize())
        old = big.BigArchive.from_bytes(raw)
        new = big.BigArchive.from_bytes(out)
        self.assertEqual(old.raw("team.dat"), new.raw("team.dat"))     # untouched bytes
        self.assertEqual(new.raw("notes.txt"), b"not a table")


class LocTests(unittest.TestCase):
    def test_roundtrip_and_layout(self):
        entries = [(2010, "Nick"), (9, "a"), (2050, "Full Name é"), (65535, "")]
        data = loc.Loc(entries).serialize()
        self.assertEqual(data[:4], b"LOCH")
        self.assertEqual(len(data) % 4, 0)
        self.assertEqual(data[0x14:0x18], b"LOCI")
        again = loc.Loc.parse(data)
        self.assertEqual(again.entries, entries)
        self.assertEqual(again.serialize(), data)
        self.assertEqual(again.by_id()[2050], "Full Name é")

    def test_odd_length_string_is_padded(self):
        data = loc.Loc([(1, "abc")]).serialize()    # 3 chars: 6 bytes + 4 NULs = 10, padded to 12
        self.assertEqual(len(data) % 4, 0)
        self.assertEqual(loc.Loc.parse(data).entries, [(1, "abc")])

    def test_set_and_reject(self):
        l = loc.Loc([(5, "x"), (6, "y")])
        l.set(6, "new")
        self.assertEqual(loc.Loc.parse(l.serialize()).by_id(), {5: "x", 6: "new"})
        with self.assertRaises(KeyError):
            l.set(7, "z")
        with self.assertRaises(loc.LocError):
            loc.Loc.parse(b"NOPE" + bytes(40))


if __name__ == "__main__":
    unittest.main()
