#!/usr/bin/env python3
"""Reader/writer for the tables inside /data/database/database.big. Std lib only.

On the GameCube disc the tables are plain text, one RefPack-compressed
`<name>.dat` per BIG entry (the bit-packed layout that PC tools show is how the
game holds the tables in memory, not how they sit on disc; see docs/ROSTERS.md).

Text format (verified on all 18 tables of GV4E69 rev 0):

    <idx> <field>,<idx> <field>,...,;\\r\\n            header: fields 0..N-1 in order
    <key9>,<idx> <value>,<idx> <value>,...,;\\r\\n     one line per record

* every line ends with ",;" and CR LF, including the last one;
* <key9> is 9 lowercase hex digits (a 32-bit key with a leading 0);
* every record carries every field, in index order;
* values are ASCII text with no ',' ';' CR or LF; numbers are decimal, "-" means
  "none" (for example an absent third pitch).

The model keeps values as text so that re-serializing is exact. JSON output
turns canonical decimal integers into numbers.

    dbtables.py list   <archive>
    dbtables.py dump   <archive> <table> [--key K] [--limit N]
    dbtables.py check  <archive>                 # round-trip, prints a report
    dbtables.py ranges <archive> [table]         # observed value ranges per field
    dbtables.py write  <archive> <table> <json> -o <out.big>

<archive> is a file path, or `image.ciso:/data/database/database.big`.
"""
import json
import os
import sys

try:
    from . import big, refpack
except ImportError:  # run as a script
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import big
    import refpack

EOL = b"\r\n"


class TableError(ValueError):
    pass


def djb2(text, seed=5381):
    """The game's key hash for team abbreviations: h = h*33 + c, 32 bit.
    djb2('Ana') == 0x0B87D5F5 (the key of the Angels record in team.dat)."""
    h = seed
    for c in text.encode("latin-1"):
        h = (h * 33 + c) & 0xFFFFFFFF
    return h


def key_text(value):
    return "%09x" % value


def _canon_int(s):
    """int(s) if s is a canonical decimal integer, else None."""
    if s and (s.isdigit() or (s[0] == "-" and s[1:].isdigit())):
        n = int(s)
        if str(n) == s:
            return n
    return None


class Table:
    def __init__(self, name, fields, rows=None):
        self.name = name
        self.fields = list(fields)          # field names, index order
        self.rows = rows if rows is not None else []   # [[key, v0, v1, ...]]
        self._by_key = None
        self._fidx = {f: i for i, f in enumerate(self.fields)}

    # ---- parsing / serializing
    @classmethod
    def parse(cls, name, data):
        if not isinstance(data, (bytes, bytearray)):
            raise TableError("data must be bytes")
        text = bytes(data).decode("latin-1")
        if not text.endswith("\r\n"):
            raise TableError("%s: missing final CR LF" % name)
        lines = text[:-2].split("\r\n")
        fields = cls._parse_header(name, lines[0])
        rows = []
        n = len(fields)
        for ln, line in enumerate(lines[1:], 2):
            if not line.endswith(",;"):
                raise TableError("%s line %d: no ',;' terminator" % (name, ln))
            parts = line[:-2].split(",")
            if len(parts) != n + 1:
                raise TableError("%s line %d: %d values, expected %d"
                                 % (name, ln, len(parts) - 1, n))
            row = [parts[0]]
            for i, p in enumerate(parts[1:]):
                head, sep, val = p.partition(" ")
                if head != str(i):
                    raise TableError("%s line %d: field %s out of order (want %d)"
                                     % (name, ln, head, i))
                row.append(val)
            rows.append(row)
        return cls(name, fields, rows)

    @staticmethod
    def _parse_header(name, line):
        if not line.endswith(",;"):
            raise TableError("%s: header has no ',;' terminator" % name)
        out = []
        for i, p in enumerate(line[:-2].split(",")):
            head, sep, val = p.partition(" ")
            if head != str(i) or not sep or not val:
                raise TableError("%s: bad header field %r" % (name, p))
            out.append(val)
        return out

    def serialize(self):
        n = len(self.fields)
        out = [",".join("%d %s" % (i, f) for i, f in enumerate(self.fields)) + ",;"]
        for row in self.rows:
            if len(row) != n + 1:
                raise TableError("%s: row %r has %d values, expected %d"
                                 % (self.name, row[0], len(row) - 1, n))
            for v in row:
                if any(c in v for c in ",;\r\n"):
                    raise TableError("%s: value %r contains a separator" % (self.name, v))
            out.append(row[0] + "," + ",".join("%d %s" % (i, v)
                                               for i, v in enumerate(row[1:])) + ",;")
        return ("\r\n".join(out) + "\r\n").encode("latin-1")

    # ---- access
    def field_index(self, field):
        return self._fidx[field]

    def index(self):
        if self._by_key is None:
            self._by_key = {}
            for r in self.rows:
                self._by_key.setdefault(r[0], r)
        return self._by_key

    def get(self, key):
        return self.index().get(key)

    def value(self, key, field):
        return self.index()[key][1 + self._fidx[field]]

    def set(self, key, **changes):
        row = self.index()[key]
        for f, v in changes.items():
            row[1 + self._fidx[f]] = _to_text(v)

    def add(self, key, values):
        """Append a record. `values` is a dict (all fields) or a list in index order."""
        if key in self.index():
            raise TableError("%s: duplicate key %s" % (self.name, key))
        if isinstance(values, dict):
            missing = [f for f in self.fields if f not in values]
            if missing or len(values) != len(self.fields):
                raise TableError("%s: record must set every field (missing %s)"
                                 % (self.name, missing[:3]))
            vals = [_to_text(values[f]) for f in self.fields]
        else:
            vals = [_to_text(v) for v in values]
        row = [key] + vals
        self.rows.append(row)
        self.index()[key] = row

    def remove(self, key):
        row = self.index().pop(key)
        self.rows.remove(row)

    # ---- JSON
    def to_json(self, keys=None, limit=None):
        recs = []
        for r in self.rows:
            if keys is not None and r[0] not in keys:
                continue
            d = {"_key": r[0]}
            for f, v in zip(self.fields, r[1:]):
                n = _canon_int(v)
                d[f] = n if n is not None else v
            recs.append(d)
            if limit is not None and len(recs) >= limit:
                break
        return {"table": self.name, "fields": self.fields, "records": recs}

    @classmethod
    def from_json(cls, obj):
        t = cls(obj["table"], obj["fields"])
        for rec in obj["records"]:
            t.rows.append([rec["_key"]] + [_to_text(rec[f]) for f in t.fields])
        return t


def _to_text(v):
    if isinstance(v, bool):
        raise TableError("booleans are not valid table values")
    return v if isinstance(v, str) else str(int(v))


class Database:
    """The tables of one database.big, in archive order."""

    def __init__(self, archive):
        self.archive = archive
        self.tables = {}
        self._orig_text = {}
        for e in archive.entries:
            if not e.name.lower().endswith(".dat"):
                continue
            name = e.name[:-4]
            data = archive.read(e.name)
            self._orig_text[name] = data
            self.tables[name] = Table.parse(name, data)

    @classmethod
    def open(cls, spec):
        return cls(big.BigArchive.open(spec))

    def table(self, name):
        return self.tables[name]

    def changed(self):
        return [n for n, t in self.tables.items() if t.serialize() != self._orig_text[n]]

    def to_bytes(self):
        """Rebuild database.big. Unchanged tables keep their original compressed
        bytes (so an unmodified database reproduces the archive exactly); changed
        tables are re-serialized and recompressed with refpack.compress."""
        replace = {}
        for n in self.changed():
            replace[n + ".dat"] = refpack.compress(self.tables[n].serialize())
        return self.archive.to_bytes(replace)


# --------------------------------------------------------------------- CLI
def _open(spec):
    return Database.open(spec)


def cmd_list(a):
    db = _open(a.archive)
    print("%-10s %7s %6s %9s %9s" % ("table", "records", "fields", "text", "packed"))
    tot = 0
    for e in db.archive.entries:
        n = e.name[:-4]
        t = db.tables[n]
        print("%-10s %7d %6d %9d %9d" % (n, len(t.rows), len(t.fields),
                                          len(db._orig_text[n]), e.size))
        tot += len(t.rows)
    print("%d tables, %d records" % (len(db.tables), tot))
    return 0


def cmd_dump(a):
    db = _open(a.archive)
    t = db.table(a.table)
    keys = {a.key} if a.key else None
    json.dump(t.to_json(keys, a.limit), sys.stdout, indent=1)
    sys.stdout.write("\n")
    return 0


def cmd_ranges(a):
    db = _open(a.archive)
    names = [a.table] if a.table else list(db.tables)
    for n in names:
        t = db.table(n)
        print("== %s (%d records)" % (n, len(t.rows)))
        for i, f in enumerate(t.fields):
            vals = [r[1 + i] for r in t.rows]
            ints = [_canon_int(v) for v in vals]
            nums = [x for x in ints if x is not None]
            other = sorted({v for v, x in zip(vals, ints) if x is None})
            bits = ""
            if nums:
                lo, hi = min(nums), max(nums)
                span = hi - lo
                bits = " bits>=%d" % max(1, span.bit_length())
                desc = "min=%d max=%d%s" % (lo, hi, bits)
            else:
                desc = "text"
            if other and nums:
                desc += " +non-numeric %s" % other[:4]
            elif other:
                desc += " distinct=%d maxlen=%d" % (len(set(vals)), max(len(v) for v in vals))
            print("  %2d %-34s %s" % (i, f, desc))
    return 0


def cmd_check(a):
    arc = big.BigArchive.open(a.archive)
    ok = True
    print("archive layout:", "canonical" if not arc.check_layout() else arc.check_layout())
    db = Database(arc)
    n_ok = 0
    for e in arc.entries:
        name = e.name[:-4]
        again = db.tables[name].serialize()
        same = again == db._orig_text[name]
        rp = refpack.decompress(refpack.compress(again)) == again
        n_ok += same
        ok = ok and same and rp
        print("  %-10s records=%5d text=%8d reserialize=%s recompress-roundtrip=%s"
              % (name, len(db.tables[name].rows), len(again),
                 "IDENTICAL" if same else "DIFFERENT", "ok" if rp else "FAIL"))
    rebuilt = db.to_bytes()
    orig = arc._reader(0, arc.file_size)
    print("tables identical after parse+serialize: %d/%d" % (n_ok, len(arc.entries)))
    print("archive rebuilt unchanged == original: %s" % (rebuilt == orig))
    # full recompress of every table, then re-read through the same code path
    forced = arc.to_bytes({e.name: refpack.compress(db.tables[e.name[:-4]].serialize())
                           for e in arc.entries})
    db2 = Database(big.BigArchive.from_bytes(forced))
    same2 = all(db2.tables[n].serialize() == db._orig_text[n] for n in db.tables)
    print("archive with every table recompressed: %d bytes (original %d), "
          "all tables read back identical: %s" % (len(forced), len(orig), same2))
    return 0 if ok and rebuilt == orig and same2 else 1


def cmd_write(a):
    db = _open(a.archive)
    obj = json.load(open(a.json))
    t = Table.from_json(obj)
    if t.name not in db.tables:
        raise SystemExit("no table %s" % t.name)
    db.tables[t.name] = t
    data = db.to_bytes()
    open(a.out, "wb").write(data)
    print("wrote %s (%d bytes); changed tables: %s" % (a.out, len(data), db.changed()))
    return 0


def main(argv):
    import argparse
    ap = argparse.ArgumentParser(description="database.big table tool")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list")
    p.add_argument("archive")
    p.set_defaults(fn=cmd_list)
    p = sub.add_parser("dump")
    p.add_argument("archive")
    p.add_argument("table")
    p.add_argument("--key")
    p.add_argument("--limit", type=int)
    p.set_defaults(fn=cmd_dump)
    p = sub.add_parser("ranges")
    p.add_argument("archive")
    p.add_argument("table", nargs="?")
    p.set_defaults(fn=cmd_ranges)
    p = sub.add_parser("check")
    p.add_argument("archive")
    p.set_defaults(fn=cmd_check)
    p = sub.add_parser("write")
    p.add_argument("archive")
    p.add_argument("table")
    p.add_argument("json")
    p.add_argument("-o", "--out", required=True)
    p.set_defaults(fn=cmd_write)
    a = ap.parse_args(argv)
    return a.fn(a)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
